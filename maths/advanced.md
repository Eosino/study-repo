# 1. 函数与极限
## 1.1. 必备技能
### 1.1.1. 解题思路
1. 第一步判断类型：直接带入，若能得到一个数值，则为非未定型，该值就是极限的结果；否则就是未定型。
2. 七种未定型极限：
   * $0\cdot\infty$ 形式：把求导简单的取倒数放分母变形为 $\frac{0}{\frac{1}{\infin}}=\frac{0}{0}$ 或 $\frac{\infin}{\frac{1}{0}}=\frac{\infin}{\infin}$
   * $\infin-\infin$ 形式：通分、有理化、倒代换
   * $\frac{0}{0}$ 或 $\frac{\infin}{\infin}$ 形式可以用无穷小替换、泰勒公式、洛必达法则
   * $1^\infin$ 形式：极限结果 $=e^A$
      * $\lim\limits_{x\to\forall}[1+f(x)]^{g(x)}$, 其中 $f(x)\to0, g(x)\to\infin, A=\lim\limits_{x\to\forall}f(x)g(x)$
      * $\lim\limits_{x\to\forall}f(x)^{g(x)}$, 其中 $f(x)\to1, g(x)\to\infin, A=\lim\limits_{x\to\forall}[f(x)-1]g(x)$
3. $0^0、\infty^0$ 形式：指数化，$f(x)^{g(x)}=e^{g(x)\ln{f(x)}}$
4. 出现 $f(a)-f(b)$ 考虑使用拉格朗日中值定理
### 1.1.2. 抓大
求极限时，可分别取分子分母中趋于$\infty$速度最快的无穷大项（主部，主要部分），舍弃其他，然后再计算。  
1. 当$x\to+\infty$，下列函数趋于$+\infty$的速度由慢到快：$\ln x,\enspace x^a,\enspace a^x,\enspace x^x\quad(a>0)$  
2. 当$n\to\infty\enspace(n为正整数，n\to\infty就是n\to+\infty)$：$\ln n,\enspace n^a,\enspace a^n,\enspace n^n,\enspace n^n\quad(a>0)$  
> 注1：当$x\to-\infty$时要具体问题具体分析，或用相反数代换转化为$x\to+\infty$  
 
> 注2：若分子分母均是无穷大与同一单调函数的复合，则这种复合型$\frac{\infty}{\infty}也可以“抓大”$  
## 1.2. 已知极限反求参数
1. 若$\lim\limits_{x\to\forall}{\frac{f(x)}{g(x)}}$存在，则$\lim\limits_{x\to\forall}g(x)=0\implies\lim\limits_{x\to\forall}f(x)=0$
2. 若$\lim\limits_{x\to\forall}{\frac{f(x)}{g(x)}}$存在，且不等于0
   1. $\lim\limits_{x\to\forall}f(x)=0\implies\lim\limits_{x\to\forall}g(x)=0$
   2. $\lim\limits_{x\to\forall}f(x)=0\iff\lim\limits_{x\to\forall}g(x)=0$，二者为同阶无穷大  
   3. 当$x\to\infty$时，若$g(x)$是$n$次多项式，则$f(x)$也是$n$次多项式  
3. 若$\lim\limits_{x\to\forall}[f(x)-g(x)]$存在，则$\lim\limits_{x\to\forall}f(x)=\infty\iff\lim\limits_{x\to\forall}g(x)=\infty$，二者为同阶无穷大；即：$f(x),g(x)$阶数相同，系数相反
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
   * 若$x_0=0,\ f(x_0)=a，f'(0)=\lim\limits_{h\to\infty}h[f(\frac{1}{h})-a]$
   * 若$x_0=0,\ f(x_0)=0，f'(0)=\lim\limits_{h\to\infty}hf(\frac{1}{h})$
3. $\frac{0}{0}$型的$\lim\limits_{x\to x_0}\frac{f[u(x)]-f[u(x_0)]}{g[v(x)]-g[v(x_0)]}=\lim\limits_{x\to x_0}\frac{\frac{f[u(x)]-f[u(x_0)]}{u(x)-u(x_0)}}{\frac{g[v(x)]-g[v(x_0)]}{v(x)-v(x_0)}}\frac{u(x)-u(x_0)}{v(x)-v(x_0)}=\frac{f'[u(x_0)]}{f'[v(x_0)]}\frac{u(x)-u(x_0)}{v(x)-v(x_0)}$
## 1.7. 求幂指函数极限
1. $1^\infty=e^A$, 若 $\lim{f(x)^{g(x)}}$ 为 $1^\infty$ 型，则 $A=g(x)[f(x)-1]$
2. 重要结论：$\lim\limits_{x\to\infin}(\frac{ax+b}{ax+c})^{hx+k}=e^{\frac{(b-c)h}{a}}$
3. 重要结论：$\lim\limits_{x\to0}(\frac{a^x+b^x+c^x}{3})^{\frac{1}{x}}=\sqrt[3]{abc}$
   * 等价：$\lim\limits_{n\to\infin}(\frac{\sqrt[n]{a}+\sqrt[n]{b}+\sqrt[n]{c}}{3})^n=\sqrt[3]{abc}$
## 1.8. 左右极限
需要考虑左、右极限的情况：
1. 
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