# 1. 简介
&emsp;&emsp;letsencrypt已经发展出很多工具或插件，比如nginx插件、给k8s用的cert-manager和kcert，都做到了自动续签证书；方便归方便，但由着这些工具自动修改nginx或k8s的配置还是不太放心，且不够通用，学习维护成本较高；所以还是建议用命令行工具certbot只负责生成证书，与证书应用的配置分开。
# 2. 安装certbot
```Shell
#官方建议工具certbot，建议用pip安装，更通用（下面是官网步骤）
dnf install python3 augeas-libs
#删除已有的certbot
dnf remove certbot
# set up a virtual environment
python3 -m venv /opt/certbot/
/opt/certbot/bin/pip install --upgrade pip
# install certbot
/opt/certbot/bin/pip install certbot certbot
ln -s /opt/certbot/bin/certbot /usr/bin/certbot
#确认安装成功
certbot version
```
# 3. 生成证书
&emsp;&emsp;生成证书需要证明域名的所有权，有两种方式：http和dns，certbot会随机生成字符串，若是http方式则放到指定路径使可以通过域名访问到，而dns方式则是到域名管理后台配置一个对应的txt解析。生成的证书默认位于目录：`/etc/letsencrypt/live/[域名]/`，建议不要挪动，需要时直接配置到这里读取即可。
## 3.1. http
```Shell
# http方式，最好在webserver所在服务器上安装certbot和进行操作，有三种用法：

#手动-manual，按提示输入邮箱、域名，并手动配置对应路径的字符串访问，可以加-d参数指定域名就不需要交互输入了
certbot certonly --manual
#评：通常学习调试时用，没把握时建议加上参数 --dry-run（下同），通过了再实际生成，因为letsencrypt对每天的调用是有限制的

#自动-standalone，意思是在自己的服务没启动的情况下，certbot临时启一个监听80端口的http服务，自动完成访问随机字符串进行验证的过程
certbot certonly --standalone
#评：很少用，因为我们自己的服务通常都是长期运行状态，为了续签证书还要停一会儿服务实在不合理

#自动-webroot，指定自己web服务的访问根目录，由certbot自动完成在其中配置访问随机字符串及验证的过程
certbot certonly --webroot -w /usr/share/nginx/html
#评：有局限性，很多web服务没有这样的目录，或是不在本机器上，或是容器化部署的等等

#总评：显然http的认证方式较难编出适应多种环境的自动化脚本，且不支持通配符域名，所以除非实在拿不到配置域名解析的权限，否则都建议用dns方式。
```
## 3.2. dns
```Shell
# dns方式，需要有域名管理权，支持通配符域名，certbot安装到任意可访问外网的机器即可

#手动-manual，按提示登录域名管理后台配置一个对应的TXT解析即可，解析生效需要1~几分钟，可以用dns查询工具确认生效了再继续下一步
certbot certonly --manual --preferred-challenges dns
#评：通常学习调试时用

#自动-hook，就是两个参数分别指定增加解析和清理解析的脚本，显然http模式也是一样可以这么用
# --manual-auth-hook 增加解析
# --manual-cleanup-hook 清理解析
certbot certonly --manual --preferred-challenges dns --manual-auth-hook /path/to/authenticator.sh --manual-cleanup-hook /path/to/cleanup.sh
#评：最适合的自动化方式
```
显然，关键是实现这两个脚本来自动增加TXT解析和清理解析，通常域名供应商都有提供API；certbot会传递如下变量到脚本中：
1. CERTBOT_DOMAIN: The domain being authenticated
2. CERTBOT_VALIDATION: The validation string
3. CERTBOT_TOKEN: Resource name part of the HTTP-01 challenge (HTTP-01 only)
4. CERTBOT_REMAINING_CHALLENGES: Number of challenges remaining after the current challenge
5. CERTBOT_ALL_DOMAINS: A comma-separated list of all domains challenged for the current certificate

下面以阿里云提供的云解析API为例，语言选择Python，在官方示例的基础上修改而来。
>官方文档：https://help.aliyun.com/document_detail/2355661.html
### 3.2.1. authenticator
首先需要安装插件：
```Shell
pip install alibabacloud_alidns20150109==3.2.0
```
certbot的hook不支持直接执行py脚本，所以先来一个shell脚本来调用py脚本：  
**/path/to/authenticator.sh**
```Shell
#!/usr/bin/bash

# Strip only the top domain
DOMAIN=$(expr match "$CERTBOT_DOMAIN" '.*\.\(.*\..*\)')
if [ -z $DOMAIN ];then  #兼容top域名和*.top域名的情况
    DOMAIN=$CERTBOT_DOMAIN
fi
# Create TXT record
CREATE_DOMAIN="_acme-challenge.$CERTBOT_DOMAIN"
#执行py脚本
python3 authenticator.py $DOMAIN $CREATE_DOMAIN $CERTBOT_VALIDATION $CERTBOT_DOMAIN
```
**/path/to/authenticator.py**
```Python
# -*- coding: utf-8 -*-
import os
import sys

from typing import List

from alibabacloud_alidns20150109.client import Client as Alidns20150109Client
from alibabacloud_tea_openapi import models as open_api_models
from alibabacloud_alidns20150109 import models as alidns_20150109_models
from alibabacloud_tea_util import models as util_models
from alibabacloud_tea_util.client import Client as UtilClient

class Sample:
    def __init__(self):
        pass

    @staticmethod
    def create_client() -> Alidns20150109Client:
        #使用access_key初始化账号Client
        config = open_api_models.Config(
            #从阿里云获取具备相关权限的access_key，并设置下面两个环境变量
            access_key_id=os.environ['ALI_DNS_ACCESS_KEY_ID'],
            access_key_secret=os.environ['ALI_DNS_ACCESS_KEY_SECRET']
        )
        # Endpoint 请参考 https://api.aliyun.com/product/Alidns
        config.endpoint = f'alidns.cn-hangzhou.aliyuncs.com'
        return Alidns20150109Client(config)

    @staticmethod
    def main(args: List[str],) -> None:
        #获取入参
        domain = args[0]
        create_domain = args[1]
        certbot_validation = args[2]
        #阿里云接口中的主机记录是待创建域名的前缀，也就是去掉后面top域名部分
        record = create_domain.replace(".%s" % domain, "")
        #兼容中文域名
        domainCN = domain.encode().decode("idna")

        client = Sample.create_client()
        add_domain_record_request = alidns_20150109_models.AddDomainRecordRequest(
            domain_name=domainCN,
            type='TXT',
            value=certbot_validation,
            rr=record
        )
        runtime = util_models.RuntimeOptions()
        try:
            ret = client.add_domain_record_with_options(add_domain_record_request, runtime)
            print("添加TXT解析，入参：")
            print("\tdomain: %s" % domain)
            print("\trecord: %s" % record)
            print("\tvalue: %s" % certbot_validation)
            print("返回：")
            print("\tstatusCode: %s" % ret.status_code)
            print("\tRecordId: %s" % ret.body.record_id)
            #保存RecordId，给清理脚本cleanup使用
            certbot_domain = args[3]
            tmpdir = "/tmp/CERTBOT_%s" % certbot_domain
            if not os.path.exists(tmpdir):
                os.makedirs(tmpdir)
            tmpfile = "%s/RECORD_ID" % tmpdir
            with open(tmpfile, "w") as f:
                f.truncate()
                f.write(ret.body.record_id)
        except Exception as error:
            # 错误 message
            print(error.message)
            # 诊断地址
            print(error.data.get("Recommend"))
            UtilClient.assert_as_string(error.message)

if __name__ == '__main__':
    Sample.main(sys.argv[1:])
```
### 3.2.2. cleanup
**/path/to/cleanup.sh**
```Shell
#!/usr/bin/bash

TMP_FILE=/tmp/CERTBOT_$CERTBOT_DOMAIN/RECORD_ID
if [ -f $TMP_FILE ]; then
    RECORD_ID=$(cat $TMP_FILE)
    rm -f $TMP_FILE
fi
if [ -z $RECORD_ID ];then
    echo "未能通过[${TMP_FILE}]发现RecortID"
    exit 1
fi
#执行py脚本
python3 cleanup.py $RECORD_ID
```
**/path/to/cleanup.py**
```Python
# -*- coding: utf-8 -*-
import os
import sys

from typing import List

from alibabacloud_alidns20150109.client import Client as Alidns20150109Client
from alibabacloud_tea_openapi import models as open_api_models
from alibabacloud_alidns20150109 import models as alidns_20150109_models
from alibabacloud_tea_util import models as util_models
from alibabacloud_tea_util.client import Client as UtilClient

class Sample:
    def __init__(self):
        pass

    @staticmethod
    def create_client() -> Alidns20150109Client:
        #使用access_key初始化账号Client
        config = open_api_models.Config(
            #从阿里云获取具备相关权限的access_key，并设置下面两个环境变量
            access_key_id=os.environ['ALI_DNS_ACCESS_KEY_ID'],
            access_key_secret=os.environ['ALI_DNS_ACCESS_KEY_SECRET']
        )
        # Endpoint 请参考 https://api.aliyun.com/product/Alidns
        config.endpoint = f'alidns.cn-hangzhou.aliyuncs.com'
        return Alidns20150109Client(config)

    @staticmethod
    def main(args: List[str],) -> None:
        #获取入参
        RecordId = args[0]
        client = Sample.create_client()
        delete_domain_record_request = alidns_20150109_models.DeleteDomainRecordRequest(
            record_id=RecordId
        )
        runtime = util_models.RuntimeOptions()
        try:
            ret = client.delete_domain_record_with_options(delete_domain_record_request, runtime)
            print("清理TXT解析，入参：")
            print("\tRecordId: %s" % RecordId)
            print("返回：")
            print("\tstatusCode: %s" % ret.status_code)
            print("")
        except Exception as error:
            # 错误 message
            print(error.message)
            # 诊断地址
            print(error.data.get("Recommend"))
            UtilClient.assert_as_string(error.message)

if __name__ == '__main__':
    Sample.main(sys.argv[1:])
```
### 3.2.3. 生成证书的命令
先用`--dry-run`验证下：
```Shell
certbot certonly --manual --preferred-challenges dns --manual-auth-hook /path/to/authenticator.sh --manual-cleanup-hook /path/to/cleanup.sh -d example.domain.cn --dry-run
```
```
Saving debug log to /var/log/letsencrypt/letsencrypt.log
Simulating renewal of an existing certificate for example.domain.cn
Hook '--manual-auth-hook' for example.domain.cn ran with output:
 添加TXT解析，入参：
        domain: domain.cn
        record: _acme-challenge.example
        value: dJfKsDYTzTWll96NJVc2RuSHzCX_mgS2D34PI4Eu5V0
 返回：
        statusCode: 200
        RecordId: 181369224425543111
Hook '--manual-cleanup-hook' for example.domain.cn ran with output:
 清理TXT解析，入参：
        RecordId: 181369224425543111
 返回：
        statusCode: 200
The dry run was successful.
```
实际生成证书，这次用通配符域名：
```Shell
certbot certonly --manual --preferred-challenges dns --manual-auth-hook /path/to/authenticator.sh --manual-cleanup-hook /path/to/cleanup.sh -d *.domain.cn
```
```
Saving debug log to /var/log/letsencrypt/letsencrypt.log
Requesting a certificate for *.domain.cn
Hook '--manual-auth-hook' for domain.cn ran with output:
 添加TXT解析，入参：
        domain: domain.cn
        record: _acme-challenge
        value: O5Yf05h1yRTschmFP2crqRxw57Zv0nliYvrqpRlosSo
 返回：
        statusCode: 200
        RecordId: 181375559443597000
Hook '--manual-cleanup-hook' for domain.cn ran with output:
 清理TXT解析，入参：
        RecordId: 181375559443597000
 返回：
        statusCode: 200

Successfully received certificate.
Certificate is saved at: /etc/letsencrypt/live/domain.cn/fullchain.pem
Key is saved at:         /etc/letsencrypt/live/domain.cn/privkey.pem
This certificate expires on 2024-06-19.
These files will be updated when the certificate renews.

NEXT STEPS:
- The certificate will need to be renewed before it expires. Certbot can automatically renew the certificate in the background, but you may need to take steps to enable that functionality. See https://certbot.org/renewal-setup for instructions.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
If you like Certbot, please consider supporting our work by:
 * Donating to ISRG / Let's Encrypt:   https://letsencrypt.org/donate
 * Donating to EFF:                    https://eff.org/donate-le
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
```
# 4. 配置证书
**nginx**
1. ssl_certificate -> fullchain.pem
2. ssl_certificate_key -> privkey.pem

**k8s**
* kubectl -n [命名空间] create secret tls [自定义名称(可直接用域名)] --key privkey.pem --cert fullchain.pem
# 5. 自动续签
# 6. 删除证书
```Shell
certbot delete --cert-name domain.cn
```