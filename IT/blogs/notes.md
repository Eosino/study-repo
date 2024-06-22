# 1. Linux
## 初始安装
以发行版 AlmaLinux 9.1 最小化安装为准，仅供参考，尤其是内核参数的调整。
### 基本
```Shell
#安装中文包
#dnf install -y glibc-langpack-zh
#包含Noto字体的中文包（较大，可选）
#dnf install -y langpacks-zh_CN
#最新的9.1中已自带安装langpacks-zh_CN

#必要的额外组件
dnf install -y wget zip unzip lrzsz telnet vim
#关闭firewalld（不建议）
#systemctl disable --now firewalld
#其实不建议无脑关闭，设置为默认放行所有即可
firewall-cmd --set-default-zone=trusted

#关闭selinux
setenforce 0
sed -i '/=enforcing/ s/=enforcing/=disabled/' /etc/selinux/config

#关闭swap（k8s需要）
swapoff -a
sed -i '/swap/ s/^/#/' /etc/fstab

#添加本机hostname的解析
cat <<EOF | tee /etc/hosts
IP地址 hostname
EOF
```
### /etc/sysctl.conf
```
kernel.sysrq = 1
vm.swappiness = 0
vm.overcommit_memory = 0
net.ipv4.neigh.default.gc_stale_time = 120
net.ipv4.conf.all.rp_filter = 0
net.ipv4.conf.default.rp_filter = 0
net.ipv4.conf.default.arp_announce = 2
net.ipv4.conf.lo.arp_announce = 2
net.ipv4.conf.all.arp_announce = 2
net.ipv4.tcp_max_tw_buckets = 262144
net.ipv4.tcp_syncookies = 1
net.ipv4.tcp_synack_retries = 2
net.ipv4.tcp_slow_start_after_idle = 0
net.ipv4.tcp_mem = 88167    117556  176334
net.netfilter.nf_conntrack_max = 262144
```
生效：sysctl -p（之后建议重启系统）
### /etc/security/limits.conf
```
```Shell
* soft nofile 65535
* hard nofile 65535
* soft nproc 29784
* hard nproc 29784
```
生效：重新登录（之后建议重启系统）
### /etc/bashrc
```Shell
HISTFILESIZE=5000
HISTSIZE=5000
HISTTIMEFORMAT="%F %T `whoami` "
export LANG=zh_CN.utf8
export TIME_STYLE=long-iso
```
### /etc/vimrc
```Shell
set nu ic scs et sw=4 ts=4 sts=4
```
## 免密登录
```Shell
ssh-keygen -t rsa
ssh-copy-id -i ~/.ssh/id_rsa.pub [username]@[ip address]
```
## 检测端口
```Shell
# tcp端口
telnet ip port
nc -zv ip port
# udp端口
nc -zvu ip port
```
## 时间同步
新版本的Linux应该都自带了。
```Shell
# ntpd方式，删除/etc/ntp.conf默认server，添加下面的：
    server 0.cn.pool.ntp.org
    server 1.cn.pool.ntp.org
    server 2.cn.pool.ntp.org
    server 3.cn.pool.ntp.org
#启动，开机自启
systemctl start ntpd
systemctl enable ntpd
```
```Shell
# ntpdate方式，每6小时同步一次
crontab -e
    0 */6 * * * ntpdate cn.pool.ntp.org > /dev/null 2>&1
```
## 定时任务
```
*    *    *    *    *
-    -    -    -    -
|    |    |    |    |
|    |    |    |    +----- 星期中星期几 (0 - 7) (星期天 为0)
|    |    |    +---------- 月份 (1 - 12) 
|    |    +--------------- 一个月中的第几天 (1 - 31)
|    +-------------------- 小时 (0 - 23)
+------------------------- 分钟 (0 - 59)
```
```Shell
#每分钟收集内存占用前10的进程（crontab中%前要加\）
* * * * * ps -eo pid=,\%mem=,rss=,cmd= --sort -\%mem | head -10 > /root/top10mem-`date +\%F-\%H-\%M`.log 2>&1
```
## 计划任务
crontab为周期性定时执行的任务，at则为一次性的计划任务。
```Shell
#查看相关服务是否启动
systemctl status atd
#设置一个12:00执行的任务，若今天已过12点就排到下一天的12点；-m 将输出的内容用邮件发给用户
at -m 12:00
  > ping baidu.com -c 10
  > <EOT>   # ctrl+d
#执行一个脚本，且指定日期
at -m -f test.sh 13:00 2021-05-18
at -f test.sh 14:00
#显示计划列表，同功能：at -l
atq
    #依次为：任务id、时间、执行队列、执行用户
    1   Tue May 17 12:00:00 2021 a root 
    2   Wed May 18 13:00:00 2021 a root
#删除id为1的计划任务，同功能：at -d 或 at -r
atrm 1
```
## 邮件
内置的邮件系统通常只用于接收本机程序或其他用户的信息。
```Shell
systemctl status postfix    #查看相关服务是否启动
mail -s "主题" root@localhost < 内容.txt    #给自己发一个邮件
mail            #进入邮箱
  &             #邮箱交互命令行，常用命令：
  & h           #即：headers，显示邮件列表，每条邮件前有一个数字id，id前若有N表示未读邮件，最前方有一个符号>指示当前光标位置
  & n           #即：next，显示当前邮件内容，光标移至下一行
  &             #不输入任何内容直接回车与n一致
  & ?           #显示帮助内容
  & 1           #邮件id，显示指定邮件的内容
  & d 1         #删除指定的邮件
  & d 1-10      #删除指定范围的邮件
  & u 1         #撤销删除
  & x           #不应用变更，退出（删除等操作不保存）
  & q           #应用变更，退出
```
postfix服务或mail命令报错：parameter inet_interfaces: no local interface found for ::1  
解决方式：打开文件/etc/postfix/main.cf，找到配置inet_interfaces，其值改为127.0.0.1或者all，重启postfix。
## vimrc
```Shell
#通用
syntax on
set number
set nobackup
set noswapfile
set ignorecase
set shiftwidth=4
set tabstop=4
set expandtab
set encoding=utf-8
#喜好
set background=dark
set t_Co=16
let g:solarized_termtrans=1
let g:solarized_termcolors=256
let g:solarized_italic=0
colorscheme solarized

#简写
set nu ic scs et sw=4 ts=4 sts=4

#gvim
set enc=utf-8
source $VIMRUNTIME/delmenu.vim
source $VIMRUNTIME/menu.vim
language messages zh_CN.utf-8
set guifont=Consolas:h11
winpos 200 50
set lines=40 columns=150
set noudf nobk

#gvim默认会设置textwidth=78，会导致每行有空格时自动换行，接受不了会很难受；
#而且在_vimrc中set textwidth是没用的；
#解决方法是在文件vimrc_example.vim中会找到如下一行内容，将其注释即可：
#    autocmd FileType text setlocal textwidth=78
```
## 压缩排除
```Shell
tar -zcf test.tar.gz test/ --exclude=.svn
zip -qr test.zip test/ -x "**/.svn**"
```
## npm
```Shell
npm config set registry https://registry.npm.taobao.org -g
npm install -g pm2
# npm install --unsafe-perm=true --allow-root
```
## yum history
使用yum安装某些包时有大量的依赖，卸载时用yum remove <包名>不会删除依赖包，若想全部清理可以用yum history：
```Shell
yum history                 #显示最近的事务，第一列就是事务id
yum history list salt-*     #可以模糊查询
yum history info <id>       #查看指定事务的详情
yum history undo <id>       #卸载指定事务的安装
yum history redo <id>       #重新安装指定的事务
```
## buff/cache清理
系统频繁大量读写文件会造成内存buff/cache过高，可以通过free查看，此时用以下命令进行清理：
```Shell
sync; echo 1 > /proc/sys/vm/drop_caches     #清理pagecache
sync; echo 2 > /proc/sys/vm/drop_caches     #清理dentries和inodes
sync; echo 3 > /proc/sys/vm/drop_caches     #都清理
```
## 统计到本机连接数前10的IP地址
```Shell
ss -nt | grep ESTAB | awk '{print $5}' | awk -F: '{print $1}' | sort | uniq -c | sort -nr | head -10
```
## 创建空的大文件
```Shell
# if=输入的文件，of=输出文件，bs=块大小 ，count=块数量
shell> dd if=/dev/zero of=bigfile bs=1M count=1024
#意思是创建一个名为bigfile、大小为1G的文件
```
## 打印指定行的内容
```Shell
awk 'NR==5' /path/to/file
sed -n '5 p' /path/to/file
awk 'NR>=1 && NR<=5' /path/to/file
sed -n '1,5 p' /path/to/file
```
## tr命令
```Shell
# 大小写转换
echo 'a b c' | tr a-z A-Z
echo 'A B C' | tr [:upper:] [:lower:]

# -d 删除
echo 'hello 123' | tr -d '0-9 ' #删除数字和空格
# -c 补集（反向删除，其实就是匹配）
echo 'hello 123' | tr -d -c '0-9\n' #删除数字和换行以外的字符，也就是只保留数字和换行符

# 生成随机密码
< /dev/urandom tr -dc [:alnum:]_ | head -c 20; echo             # 包含字母、数字、下划线
< /dev/urandom tr -dc [:alnum:][:graph:] | head -c 20; echo     # 包含字母、数字、特殊符号
```
# 2. Shell
## 变量
```Shell
v="/usr/bin/bash"
echo ${v:1:3}           # 索引1开始，长度为3，结果是：usr
echo ${v#*/}            # 结果是：usr/bin/bash
echo ${v##*/}           # 结果是：bash
echo ${v%/*}            # 结果是：/usr/bin
echo ${v%%/*}           # 结果为空
echo ${v//bash/grep}    # 结果为：/usr/bin/grep
```
## 数组
```Shell
array=("my" "name" "is")    # 初始化
echo ${array}               # 默认第1个元素
echo ${array[1]}            # 打印第2个元素
echo ${array[@]}            # 打印整个数组
echo ${#array[@]}           # 元素个数
echo ${!array[@]}           # 所有索引
array[10]="John"            # 增加元素，索引可以不连续
```
## 对比
| 表达式 | 含义 |
|-------|-------|
| [ $n -eq 0 ] | 是否等于0 |
| [ $n -ne 0 ] | 是否不等于0 |
| [ $n -gt 0 ] | 是否大于0 |
| [ $n -lt 0 ] | 是否小于0 |
| [ $n -ge 0 ] | 是否大于或等于0 |
| [ $n -le 0 ] | 是否小于或等于0 |
| [ -z $string ] | 判断字符串是否为空 |
| [ ! -n $string ] | 判断字符串是否为空 |
| [[ $string == "" ]] | 判断字符串是否为空 |
| [ -n $string ] | 判断字符串是否不为空 |
| [ ! -z $string ] | 判断字符串是否不为空 |
| [[ $string != "" ]] | 判断字符串是否不为空 |
| [[ $string == "字符串" ]] | 判断字符串是否相等 |
| [[ $string != "字符串" ]] | 判断字符串是否不相等 |
| [[ $string == 字* ]] | 判断字符串是以“字”开头 |
## 0~100中3的倍数
```Shell
for i in {0..100..3}; do echo $i; done
```
## 网段中在线的IP
```Shell
seg='192.168.0'
for i in $(seq 254)
do
    ping -c 1 ${seg}.${i} >> /dev/null
    if [ $? -eq 0 ];then
        echo "${seg}.${i} online"
    else
        echo "${seg}.${i} offline"
    fi
done
```
# 3. 编码
## 编码规则与字符集
unicode是字符集（一个标准），utf-8是使用unicode字符集的编码规则之一（标准的使用者），不过很多时候这俩角色是同一个，搞清楚得细看计算机编码发展史，下表简单介绍常见的编码：  

| 字符集/编码 | 说明 | 字节占用 |
|-------|-------|-------|
| ASCII | 最早美国发布的<美国信息交换标准代码> | 英文1个字节，早期不支持汉字，后来用2个字节兼容 |
| GB2312 | 为了支持汉字，中国最早制定的ASCII扩展字符集（GB即国标） | 英文1个字节，汉字2个字节 |
| Unicode | 国际标准，几乎包含世界上所有文字 | 全部都是2个字节 |
| GBK | 国标扩展，兼容GB2312和Unicode | 英文1个字节，汉字2个字节 |
| CP936 | 这个是指Code Page的第936页，通常认为与GBK等价 | 英文1个字节，汉字2个字节 |
| UTF-8 | 针对Unicode的一种可变长度字符编码，互联网普及后使用最广，8即8bit（1字节） | 英文1个字节，大部分汉字3个字节（少数4个字节） |
| UTF-16 | 固定16bit（2字节）的UTF，开头需要2个字节的BOM指定字节序 | 全部2个字节 |
| UTF-16BE | big-endian，低位码在前高位码在后的字节序，由低到高符合人类逻辑 | 全部2个字节 |
| UTF-16LE | little-endian，高位码在前低位码在后，符合计算机逻辑，常用的Unicode编码都是该形式 | 全部2个字节 |
| UTF-32 | 固定32bit（4字节）的UTF，开头需要4个字节的BOM指定字节序 | 全部4个字节 |
| GB18030 | 汉字太多，国标再次扩充，且支持少数民族文字、emoji等 | 英文1个字节，汉字2个字节 |

只有英文1个字节的才兼容ascii，GB系列都兼容，而utf只有8兼容，历史的惯性是巨大的，utf-8因此成了最流行的国际标准。
```Shell
# unicode编码（utf16le）转汉字
echo -e '\u4e2d\u56fd'
#汉字转unicode编码，转为常见的双字节编码utf16le，-An指offset以10进制为基数，-x指以16进制显示，sed加上unicode编码前缀\u
echo -n '中国' | iconv -t utf16le | od -An -x | sed 's/ /\\u/g'
```
## utf-8的bom标记
utf-8是变长字符编码，理论上是不需要bom的，但notepad默认带了bom，造成了不少麻烦，其编码是：\xEF\xBB\xBF
```Shell
# vim处理bom
set bomb?   #查询bom
set bomb    #设置bom
set nobomb  #删除bom

#批量删除bom，-I参数排除二进制文件，$表示转义（否则按字符串处理而不是编码）
sed -i 's/\xEF\xBB\xBF//' `grep -Ilr $'^\xEF\xBB\xBF' .`
```
## vim的编码
vim编辑文件时涉及到编码的配置有3个：
1. encoding：vim内部处理时用的编码，通过`set enc`查看；默认取系统的编码，通常为utf-8。
2. termencoding：输出到终端时的编码，通过`set tenc`查看；这个值通常为空，默认使用系统的编码。
3. fileencoding：vim读写当前文件时用的编码，通过`set fenc`查看；打开文件时vim会尝试自动识别，出现乱码通常就是这里识别失败了。

系统的编码通过命令`locale`查看，通常通过设置变量`LANG`来修改，近些年的系统通常默认为`en_US.utf8`，对中文支持是没问题的，但如果想在各种帮助信息中尽量看到中文，可以改（要确保`locale -a`中包含）：
```Shell
export LANG=zh_CN.utf8
```
当通过xshell、mobaxterm、windterm等远程连接时，应该将session的编码设置为与目标机器的系统编码一致，否则会出现输出乱码，这些工具通常默认就是utf8。
最后说回vim，打开文件出现乱码时，首先看fileencoding，自动识别编码失败时它的值通常是latin1，此时需要做的不是修改fileencoding，而是用正确的编码重新编辑或打开此文件；事先知不知道文件的编码并不重要，因为在国内遇到的基本都是国标系列编码：GB2313、GBK、GB18030，通常用GBK（因为短，好记，不行再换GB18030）：
```Shell
#重新编辑（在vim内）
:e ++enc=gbk
#重新打开（在命令行）
$ vim filename -c 'e ++enc=gbk'
```
此时应该就没乱码了，再看fileencoding=cp936，cp936就是gbk，替换到上面的命令中也是一样的。
每次都指定编码多麻烦，考虑把这个文件的编码改为utf8，此时终于轮到fileencoding了，在上面的基础上（已正确指定编码）操作：
```Shell
#在vim内
:set fenc=utf8
```
然后保存即可，后面再打开这个文件，fileencoding就是utf-8了。
## 行尾符
常见问题：win的文本以linux模式打开行尾会多个^M，反之则全成一行；其原因是：
* MacOS默认行尾符是回车：CR，即：\r
* Linux默认行尾符是换行：LF，即：\n，此时回车符（\r）会显示为^M
* Windows默认行尾符是回车+换行：CRLF，即：\r\n  
```Shell
# linux下可以通过vim配置行尾符，也就是fileformat
set ff          #查看
set ff=unix     #配置为LF
set ff=dos      #配置为CRLF
#通过vim处理^M
%s/^M$//g       #清理^M，这里的^M要这样输入：ctrl+v,ctrl+m（下同）
%s/\r$//g       #一样的效果
#通过tr处理^M，这里要另存为另一个文件
cat 1.txt | tr -d '\r' > 2.txt
#通过sed和grep批量处理
sed -i "s/^M$//" `grep "^M$" -lr .`
```
>重现^M场景：linux下将一个ff=dos的文件用echo追加一行内容，再用vim打开即可看到^M。

# 4. MySql
```sql
-- 查看数据库的字符集和排序规则
show create database d_name;

-- 查看表的字符集和排序规则
show create table t_name;

-- 查看库中所有表的字符集和排序规则
SELECT TABLE_NAME, CCSA.character_set_name, CCSA.collation_name
FROM information_schema.TABLES T,
     information_schema.COLLATION_CHARACTER_SET_APPLICABILITY CCSA
WHERE CCSA.collation_name = T.table_collation
  AND T.table_schema = 'd_name';

-- 修改库的字符集和排序规则
ALTER DATABASE d_name CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci;

-- 修改表的字符集和排序规则
ALTER TABLE t_name CONVERT TO CHARACTER SET utf8mb4;
ALTER TABLE t_name CONVERT TO CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci;
```
