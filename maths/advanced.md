# 1. 函数与极限
## 1.1. 必备技能
### 1.1.1. 解题思路
1. 第一步判断类型：直接带入，若能得到一个数值，则为非未定型，该值就是极限的结果；否则就是未定型。
2. 七种未定型极限：
   * $0\cdot\infty$ 形式：把求导简单的取倒数放分母变形为 $\frac{0}{\frac{1}{\infty}}=\frac{0}{0}$ 或 $\frac{\infty}{\frac{1}{0}}=\frac{\infty}{\infty}$
   * $\infty-\infty$ 形式：通分、有理化、倒代换
   * $\frac{0}{0}$ 或 $\frac{\infty}{\infty}$ 形式可以用无穷小替换、泰勒公式、洛必达法则
   * $1^\infty$ 形式：极限结果 $=e^A$
      * $\lim\limits_{x\to\forall}[1+f(x)]^{g(x)}$, 其中 $f(x)\to0, g(x)\to\infty, A=\lim\limits_{x\to\forall}f(x)g(x)$
      * $\lim\limits_{x\to\forall}f(x)^{g(x)}$, 其中 $f(x)\to1, g(x)\to\infty, A=\lim\limits_{x\to\forall}[f(x)-1]g(x)$
3. $0^0、\infty^0$ 形式：指数化，$f(x)^{g(x)}=e^{g(x)\ln{f(x)}}$
4. 出现 $f(a)-f(b)$ 考虑使用拉格朗日中值定理
### 1.1.2. 抓大
求极限时，可分别取分子分母中趋于$\infty$速度最快的无穷大项（主部，主要部分），舍弃其他，然后再计算。  
1. 当 $x\to+\infty$，下列函数趋于$+\infty$的速度由慢到快：$\ln x,\enspace x^a,\enspace a^x,\enspace x^x\quad(a>0)$  
2. 当 $n\to\infty\enspace(n为正整数，n\to\infty就是n\to+\infty)$：$\ln n,\enspace n^a,\enspace a^n,\enspace n^n,\enspace n^n\quad(a>0)$  
> 注1：当 $x\to-\infty$ 时要具体问题具体分析，或用相反数代换转化为 $x\to+\infty$  
 
> 注2：若分子分母均是无穷大与同一单调函数的复合，则这种复合型$\frac{\infty}{\infty}也可以“抓大”$  
## 1.2. 已知极限反求参数
1. 若 $\lim\limits_{x\to\forall}{\frac{f(x)}{g(x)}}$ 存在，则 $\lim\limits_{x\to\forall}g(x)=0\implies\lim\limits_{x\to\forall}f(x)=0$
2. 若 $\lim\limits_{x\to\forall}{\frac{f(x)}{g(x)}}$ 存在，且不等于0
   1. $\lim\limits_{x\to\forall}f(x)=0\implies\lim\limits_{x\to\forall}g(x)=0$
   2. $\lim\limits_{x\to\forall}f(x)=0\iff\lim\limits_{x\to\forall}g(x)=0$，二者为同阶无穷大  
   3. 当 $x\to\infty$ 时，若$g(x)$是$n$次多项式，则$f(x)$也是$n$次多项式  
3. 若 $\lim\limits_{x\to\forall}[f(x)-g(x)]$ 存在，则 $\lim\limits_{x\to\forall}f(x)=\infty\iff\lim\limits_{x\to\forall}g(x)=\infty$，二者为同阶无穷大；即：$f(x), g(x)$ 阶数相同，系数相反
## 1.3. 泰勒公式求极限
|  |  |  |
|---|---|---|
| $\sin x$ | $x-\frac{1}{3!}x^3+\frac{1}{5!}x^5$ | $\sum_{n=0}^\infty\frac{(-1)^n}{(2n+1)!}x^{2n+1}$ |
| $\arcsin x$ | $x+\frac{1}{3!}x^3+\frac{1}{5!}x^5$ | $\sum_{n=0}^\infty\frac{1}{(2n+1)!}x^{2n+1}$ |
| $\tan x$ | $x+\frac{1}{3}x^3+\frac{1}{5}x^5$ | $\sum_{n=0}^\infty\frac{1}{2n+1}x^{2n+1}$ |
| $\arctan x$ | $x-\frac{1}{3}x^3+\frac{1}{5}x^5$ |  $\sum_{n=0}^\infty\frac{(-1)^n}{2n+1}x^{2n+1}$|
| $\ln(1+x)$ | $x-\frac{1}{2}x^2+\frac{1}{3}x^3$ | $\sum_{n=0}^\infty\frac{(-1)^n}{n+1}x^{n+1}$ |
| $e^x$ | $1+x+\frac{1}{2}x^2+\frac{1}{3!}x^3$ | $\sum_{n=0}^\infty\frac{1}{n!}x^n$ |
| $(1+x)^a$ | $1+ax+\frac{a(a-1)}{2}x^2$ | $\sum_{n=0}^\infty\frac{a(a-1)...(a-n+1)}{n!}x^n$ |
| $\cos x$ | $1-\frac{1}{2}x^2+\frac{1}{4!}x^4$ | $\sum_{n=0}^\infty\frac{(-1)^n}{(2n)!}x^{2n}$ |
| $\frac{1}{1-x}$ | $1+x+x^2+...+x^n$ | $\sum_{n=0}^\infty x^n$ |
| $\frac{1}{1+x}$ | $1-x+x^2-x^3+...+(-1)^nx^n$ | $\sum_{n=0}^\infty (-1)^nx^n$ |

令：$y=\ln(x+\sqrt{1+x^2})$，则：$y'=(1+x^2)^{-\frac{1}{2}}\sim 1-\frac{1}{2}x^2$，所以：$y\sim x-\frac{1}{6}x^3$
## 1.4. 等价无穷小替换求极限
1. $e^x-1 \sim x$
   * $e^{f(x)}-e^{g(x)} = e^{g(x)}[e^{f(x)-g(x)}-1] \sim e^{g(x)}[f(x)-g(x)]$
2. $\ln(1+x) \sim x$
   * $\ln{f(x)} = ln[1+f(x)-1] \sim f(x)-1$
3. $(1+x)^a-1 \sim ax$
   * $[1+f(x)]^a \sim af(x)$
## 1.5. 洛必达法则求极限
1. $\frac{0}{0}$和$\frac{\infty}{\infty}$型极限可直接使用洛必达法则，但并非所有，比如$\lim\limits_{x\to+\infty}{\frac{e^x+e^{-x}}{e^x-e^{-x}}}、\lim\limits_{x\to\infty}{\frac{x+\sin x}{x-\cos x}}$和$x\to 0$时包含$\sin\frac{1}{x},\cos\frac{1}{x}$等情况不能用。
2. 法则使用前后要使用“等价无穷小”和“去非零因子“来化简。
3. $\lim\limits_{x\to\forall}{\frac{f'(x)}{g'(x)}}$不存在，不能判定$\lim\limits_{x\to\forall}{\frac{f(x)}{g(x)}}$不存在，要改用其他方法去计算。
4. n阶可导，则洛必达法则只能用n-1次，最后一次用导数定义。
5. 题目只说在某一点可导，则不能用洛必达法则，要用导数定义。
## 1.6. 利用导数定义求极限
1. $f(x)$在$x_0$处的导数定义：
   * $f'(x_0) = \lim\limits_{\Delta x\to0}\frac{f(x_0+\Delta x)-f(x_0)}{\Delta x}$  
   &emsp;&emsp;&emsp;&ensp;$=\lim\limits_{x\to x_0}\frac{f(x)-f(x_0)}{x-x_0}$  
   &emsp;&emsp;&emsp;&ensp;$=\lim\limits_{x\to x_0}\frac{f[x_0+\varphi(x)]-f(x_0)}{\varphi(x)}$&emsp;[$x\to x_0$使$\varphi(x)\to0$]
2. 令$h=\frac{1}{\Delta x}$，$f'(x_0) = \lim\limits_{h\to\infty}\frac{f(x_0+\frac{1}{h})-f(x_0)}{\frac{1}{h}} = \lim\limits_{h\to\infty}h[f(x_0+\frac{1}{h})-f(x_0)]$
   * 若$x_0=0、f(x_0)=a，f'(0)=\lim\limits_{h\to\infty}h[f(\frac{1}{h})-a]$
   * 若$x_0=0、f(x_0)=0，f'(0)=\lim\limits_{h\to\infty}hf(\frac{1}{h})$
3. $\frac{0}{0}$型的$\lim\limits_{x\to x_0}\frac{f[u(x)]-f[u(x_0)]}{g[v(x)]-g[v(x_0)]}=\lim\limits_{x\to x_0}\frac{\frac{f[u(x)]-f[u(x_0)]}{u(x)-u(x_0)}}{\frac{g[v(x)]-g[v(x_0)]}{v(x)-v(x_0)}}\frac{u(x)-u(x_0)}{v(x)-v(x_0)}=\frac{f'[u(x_0)]}{f'[v(x_0)]}\frac{u(x)-u(x_0)}{v(x)-v(x_0)}$
## 1.7. 求幂指函数极限
1. $1^\infty=e^A$, 若 $\lim{f(x)^{g(x)}}$ 为 $1^\infty$ 型，则 $A=g(x)[f(x)-1]$
2. 重要结论：$\lim\limits_{x\to\infty}(\frac{ax+b}{ax+c})^{hx+k}=e^{\frac{(b-c)h}{a}}$
3. 重要结论：$\lim\limits_{x\to0}(\frac{a^x+b^x+c^x}{3})^{\frac{1}{x}}=\sqrt[3]{abc}$
   * 等价：$\lim\limits_{n\to\infty}(\frac{\sqrt[n]{a}+\sqrt[n]{b}+\sqrt[n]{c}}{3})^n=\sqrt[3]{abc}$
   * 推广：$\lim\limits_{n\to\infty}(\frac{\sqrt[n]{a_1}+\sqrt[n]{a_2}+...+\sqrt[n]{a_m}}{m})^n=\sqrt[m]{a_1a_2...a_m}$
## 1.8. 左右极限
需要考虑左、右极限的情况：
1. 当 $x\to\infty$ 时的 $e^x$，和当 $x\to0$ 时的 $e^\frac{1}{x}$ ：
   * $\lim\limits_{x\to+\infty}e^x=+\infty$
   * $\lim\limits_{x\to-\infty}e^x=0$
   * $\lim\limits_{x\to0^+}e^{\frac{1}{x}}=+\infty$
   * $\lim\limits_{x\to0^-}e^{\frac{1}{x}}=0$
2. 当 $x\to\infty$ 时的 $\arctan x$ 和 $arccotx$ ：
   * $\lim\limits_{x\to+\infty}\arctan x=\frac{\pi}{2}$
   * $\lim\limits_{x\to-\infty}\arctan x=-\frac{\pi}{2}$
   * $\lim\limits_{x\to+\infty}arccotx=0$
   * $\lim\limits_{x\to-\infty}arccotx=\pi$
3. 取整函数 $[x]$ ，意思是取不超过x的最大整数：
   * $\lim\limits_{x\to n^+}[x]=n$
   * $\lim\limits_{x\to n^-}[x]=n-1$
4. 偶次方根：含偶次方根的函数式提导根号外的因子要加负号。
5. 绝对值函数：即当 $x\to a$ 时的 $|x-a|$ 。
6. 分段函数分段点的极限。
## 1.9. 极限的定义及性质
### 1.9.1. 数列的极限
>定义：设有数列${u_n}$和常数$A$，对任意给定的$\varepsilon>0$，存在整数N，使得当$n>N$时，恒有$|u_n-A|<\varepsilon$成立，则称数列${u_n}$以$A$为极限，记为：$\lim\limits_{n\to\infty}u_n=A$ 或 $u_n\to A\space(n\to\infty)$
1. $\varepsilon$表示$u_n$与$A$的接近程度，可以任意小，可以有多种形式表达，比如：$2\varepsilon$、$\varepsilon^2$、$\sqrt{\varepsilon}$等
2. $u_n$收敛于$A\iff u_n$的任意子数列也收敛于$A$
   * 注意：这里的任意子列可以理解为全部子列，不能覆盖整个$u_n$的子列收敛不能推导$u_n$收敛
3. $\lim\limits_{n\to\infty}u_n=A\iff u_n$的偶数子列和奇数子列满足$\lim\limits_{n\to\infty}u_{2n}=\lim\limits_{n\to\infty}u_{2n+1}=A$
4. $u_n$是单调数列、$\lim\limits_{n\to\infty}u_n=A \iff$存在某个子列收敛于$A$
### 1.9.2. 函数的极限
1. $x\to\infty$时函数$f(x)$的极限：设有函数$y=f(x)$和常数$A$，对任意给定的$\varepsilon>0$，若存在$M>0$，使得当$|x|>M$时，恒有$|f(x)-A|<\varepsilon$成立，则称当$x\to\infty$时，$y=f(x)$的极限为A，记为：$\lim\limits_{x\to\infty}f(x)=A$ 或 $f(x)\to A\space(x\to\infty)$
2. $x\to x_0$时函数$f(x)$的极限：设有函数$y=f(x)$和常数$A$，对任意给定的$\varepsilon>0$，若存在$M>0$，使得当$0<|x-x_0|<M$时，恒有$|f(x)-A|<\varepsilon$成立，则称当$x\to x_0$时，$y=f(x)$的极限为A，记为：$\lim\limits_{x\to x_0}f(x)=A$ 或 $f(x)\to A\space(x\to x_0)$
### 1.9.3. 极限的性质
1. 唯一性：若极限存在，则极限值唯一
2. 有界性：极限存在，则局部有界；另两个与有界性有关联的结论：
   * 连续函数在闭区间$[a,b]$上一定有界
   * $f'(x)$在有限区间$(a,b)$上有界，则$f(x)$在$(a,b)$上有界（拉格朗日中值定理推出）
3. 保号性：设$\lim\limits_{x\to x_0}=A$，则：
   * $A>0\implies f(x)>0$
   * $A<0\implies f(x)<0$
   * $f(x)>0\implies A\ge 0$，例：$\lim\limits_{n\to\infty}\frac{1}{n}=0$
   * $f(x)<0\implies A\le 0$
## 1.10. 极限的运用
### 1.10.1. 连续与间断点
设$f(x)$在$x=x_0$左右两侧都有定义：
* 左极限：$\lim\limits_{x\to x_0^-}f(x)$
* 右极限：$\lim\limits_{x\to x_0^+}f(x)$
* 函数值：$f(x_0)$

则：
1. 左右极限至少有一个不存在且等于$\infty$，则$x_0$为无穷间断点（第二类间断点）
2. 左右极限至少有一个不存在且振荡，则$x_0$为振荡间断点（第二类间断点）
3. 左右极限都存在，但不相等，则$x_0$为跳跃间断点（第一类间断点）
4. 左右极限都存在，且相等，但不等于函数值，则$x_0$为可去间断点（第一类间断点）
5. 左右极限都存在，且相等，且等于函数值，则$f(x)$在$x_0$连续

寻找间断点：
1. 分母为零的点
2. 无定义的点
3. 分段函数的分段点

寻找可去间断点：
* 分子为零的点是可去间断点的高度怀疑点
### 1.10.2. 渐近线
垂直渐近线：
* 若$\lim\limits_{x\to x_0}f(x)=\infty$，则直线$x=x_0$为曲线$y=f(x)$的垂直渐近线
* （注：找使分母为零的$x_0$）

水平渐近线：
* 若$\lim\limits_{x\to\infty}f(x)=A$，则直线$y=A$为曲线$y=f(x)$的水平渐近线

斜渐近线：
* 若$k=\lim\limits_{x\to\infty}\frac{f(x)}{x}$、$b=\lim\limits_{x\to\infty}[f(x)-kx]$，则$y=kx+b$为曲线$y=f(x)$的斜渐近线
* （注：同一侧水平渐近线与斜渐近线不会共存）

求斜渐近线扩展：
1. $k=\lim\limits_{x\to\infty}\frac{f(x)}{x}=^{L'}\lim\limits_{x\to\infty}f'(x)$
2. 在$x\to\infty$时，把$f(x)$展开为线性组合$kx+b$与无穷小量之和：$kx+b+o(1)$，则$y=kx+b$即为渐近线
## 1.11. 计算数列极限
### 1.11.1. 使用定积分定义
>分割、代替、求和、取极限
1. 取右端点：$\int^b_af(x)dx=\lim\limits_{n\to\infty}\sum_{i=1}^n[f(a+\frac{b-a}{n}\cdot i)\cdot\frac{b-a}{n}]$
2. 取左端点：$\int^b_af(x)dx=\lim\limits_{n\to\infty}\sum_{i=1}^n\{f[a+\frac{b-a}{n}\cdot(i-1)]\cdot\frac{b-a}{n}\}$
2. 取中点：$\int^b_af(x)dx=\lim\limits_{n\to\infty}\sum_{i=1}^n\{f[a+\frac{b-a}{n}\cdot\frac{1}{2}\cdot(2i-1)]\cdot\frac{b-a}{n}\}$

特殊地，当$a=0、b=1$时：
1. 取右端点：$\int^1_0f(x)dx=\lim\limits_{n\to\infty}\sum_{i=1}^nf(\frac{i}{n})\frac{1}{n}$
2. 取左端点：$\int^1_0f(x)dx=\lim\limits_{n\to\infty}\sum_{i=1}^nf(\frac{i-1}{n})\frac{1}{n}$
2. 取中点：$\int^1_0f(x)dx=\lim\limits_{n\to\infty}\sum_{i=1}^nf(\frac{2i-1}{2n})\frac{1}{n}$
### 1.11.2. 夹逼准则
1. 对 $u_1+u_2+...+u_n$ 进行缩放有两个常见的结论：
   * 当$n$为无穷大时，则 $n\cdot u_m\le\sum^{n}_{i=1}u_i\le n\cdot u_M$
   * 当$n$为有限数，且 $u_i\ge0$，则 $u_m\le\sum^{n}_{i=1}u_i\le n\cdot u_M$
2. $\lim\limits_{n\to\infty}\sqrt[n]{a^n_1+a^n_2+...+a^n_k}=\max(a_i)\space(i=1,2,...,k)$
### 1.11.3. 其他
* 先用夹逼准则，再用定积分定义
* 数列极限改为函数极限
## 1.12. 证明数列极限存在

# 3. 一元函数积分学
## 3.2 不定积分的公式法
|  |  |
|---|---|
| $\int{e^x}dx$ | $e^x+C$ |
| $\int{a^x}dx$ | $\frac{a^x}{lna}+C$ |
| $\int{x^a}dx$ | $\frac{x^{a+1}}{a+1}+C\enspace(a\neq-1)$ |
| $\int{\frac{1}{x^2}}dx$ | $-\frac{1}{x}+C$ |
| $\int{\frac{1}{x}}dx$ | $ln{\|x\|}+C$ |
| $\int{\frac{1}{\sqrt{x}}}dx$ | $2\sqrt{x}+C$ |
| $\int{\sin x}dx$ | $-\cos x+C$ |
| $\int{\cos x}dx$ | $\sin x+C$ |
| $\int{\tan x}dx$ | $-\ln\|\cos x\|+C$ |
| $\int{\cot x}dx$ | $\ln\|\sin x\|+C$ |
| $\int{\sec x}dx$ | $\ln\|\sec x+\tan x\|+C$ |
| $\int{\csc x}dx$ | $\ln\|\csc x-\cot x\|+C$ |
| $\int{\sec^2x}dx$ | $\tan x+C$ |
| $\int{\csc^2x}dx$ | $-\cot x+C$ |
| $\int{\sec x\tan x}dx$ | $\sec x+C$ |
| $\int{\csc x\cot x}dx$ | $-\csc x+C$ |
| $\int{\frac{1}{\sqrt{1-x^2}}}dx$ | $\arcsin x+C$ |
| $\int{\frac{1}{\sqrt{a^2-x^2}}}dx$ | $\arcsin\frac{x}{a}+C$ |
| $\int{\frac{1}{\sqrt{x^2\pm a^2}}}dx$ | $\ln\|x+\sqrt{x^2\pm a^2}\|+C$ |
| $\int{\frac{1}{1+x^2}}dx$ | $\arctan x+C$ |
| $\int{\frac{1}{a^2+x^2}}dx$ | $\frac{1}{a}\arctan\frac{x}{a}+C$ |
| $\int{\frac{1}{a^2-x^2}}dx$ | $\frac{1}{2a}\ln\|\frac{a+x}{a-x}\|+C$ |
| $\int{\frac{1}{x^2-a^2}}dx$ | $\frac{1}{2a}\ln\|\frac{x-a}{x+a}\|+C$ |
| $\int{\frac{1}{1+e^x}}dx$ | $x-\ln(1+e^x)+C$ |
| $\int{\sqrt{x^2+a^2}}dx$ | $\frac{x}{2}\sqrt{x^2+a^2}+\frac{a^2}{2}\ln(x+\sqrt{x^2+a^2})+C$ |
| $\int{\sqrt{x^2-a^2}}dx$ | $\frac{x}{2}\sqrt{x^2-a^2}-\frac{a^2}{2}\ln\|x+\sqrt{x^2-a^2}\|+C$ |
| $\int{\sqrt{a^2-x^2}}dx$ | $\frac{x}{2}\sqrt{a^2-x^2}+\frac{a^2}{2}\arcsin\frac{x}{a}+C$ |