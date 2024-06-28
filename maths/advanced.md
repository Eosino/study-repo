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
| 函数 | 泰勒公式 | 幂级数 | 收敛域 |
|---|---|---|---|
| $\sin x$ | $x-\frac{1}{3!}x^3+\frac{1}{5!}x^5$ | $\displaystyle\sum_{n=0}^\infty\frac{(-1)^n}{(2n+1)!}x^{2n+1}$ | $(-\infty,+\infty)$ |
| $\arcsin x$ | $x+\frac{1}{3!}x^3+\frac{1}{5!}x^5$ | $\displaystyle\sum_{n=0}^\infty\frac{1}{(2n+1)!}x^{2n+1}$，通项非幂级数？ | $(-1,1)$，端点的敛散性？ |
| $\tan x$ | $x+\frac{1}{3}x^3+\frac{1}{5}x^5$ | $\displaystyle\sum_{n=0}^\infty\frac{1}{2n+1}x^{2n+1}$ | $(-1,1)$ |
| $\arctan x$ | $x-\frac{1}{3}x^3+\frac{1}{5}x^5$ |  $\displaystyle\sum_{n=0}^\infty\frac{(-1)^n}{2n+1}x^{2n+1}$| $[-1,1]$ |
| $\ln(1+x)$ | $x-\frac{1}{2}x^2+\frac{1}{3}x^3$ | $\displaystyle\sum_{n=0}^\infty\frac{(-1)^n}{n+1}x^{n+1}$ | $(-1,1]$ |
| $e^x$ | $1+x+\frac{1}{2}x^2+\frac{1}{3!}x^3$ | $\displaystyle\sum_{n=0}^\infty\frac{1}{n!}x^n$ | $(-\infty,+\infty)$ |
| $(1+x)^a$ | $1+ax+\frac{a(a-1)}{2}x^2$ | $\displaystyle\sum_{n=0}^\infty\frac{a(a-1)...(a-n+1)}{n!}x^n$ | $(-1,1)$，端点的敛散性？ |
| $\cos x$ | $1-\frac{1}{2}x^2+\frac{1}{4!}x^4$ | $\displaystyle\sum_{n=0}^\infty\frac{(-1)^n}{(2n)!}x^{2n}$ | $(-\infty,+\infty)$ |
| $\frac{1}{1-x}$ | $1+x+x^2+...+x^n$ | $\displaystyle\sum_{n=0}^\infty x^n$ | $(-1,1)$ |
| $\frac{1}{1+x}$ | $1-x+x^2-x^3+...+(-1)^nx^n$ | $\displaystyle\sum_{n=0}^\infty (-1)^nx^n$ | $(-1,1)$ |

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
3. $\frac{0}{0}$型的$\lim\limits_{x\to x_0}\frac{f[u(x)]-f[u(x_0)]}{g[v(x)]-g[v(x_0)]}=\lim\limits_{x\to x_0}\frac{\frac{f[u(x)]-f[u(x_0)]}{u(x)-u(x_0)}}{\frac{g[v(x)]-g[v(x_0)]}{v(x)-v(x_0)}}\frac{u(x)-u(x_0)}{v(x)-v(x_0)}=\frac{f'[u(x_0)]}{f'[v(x_0)]}\lim\limits_{x\to x_0}\frac{u(x)-u(x_0)}{v(x)-v(x_0)}$
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
4. 偶次方根：当$x\to\infty$，含偶次方根的函数式提导根号外的因子要加负号。
5. 绝对值函数：即当 $x\to a$ 时的 $|x-a|$ 。
6. 分段函数分段点的极限。
## 1.9. 极限的定义及性质
### 1.9.1. 数列的极限
>定义：设有数列${u_n}$和常数$A$，对任意给定的$\varepsilon>0$，存在整数N，使得当$n>N$时，恒有$|u_n-A|<\varepsilon$成立，则称数列${u_n}$以$A$为极限，记为：$\lim\limits_{n\to\infty}u_n=A$ 或 $u_n\to A\space(n\to\infty)$

>子列：从一个数列中抽取无穷多项，在不改变原有次序的情况下构成的新数列称为原数列的子数列，简称子列
1. $\varepsilon$表示$u_n$与$A$的接近程度，可以任意小，可以有多种形式表达，比如：$2\varepsilon$、$\varepsilon^2$、$\sqrt{\varepsilon}$等
2. $u_n$收敛于$A\iff u_n$的任意子数列也收敛于$A$
   * 注意：这里的任意子列可以理解为全部子列，不能覆盖整个$u_n$的子列收敛不能推导$u_n$收敛
3. $\lim\limits_{n\to\infty}u_n=A\iff u_n$的偶数子列和奇数子列满足$\lim\limits_{n\to\infty}u_{2n}=\lim\limits_{n\to\infty}u_{2n+1}=A$
4. $u_n$是单调数列、$\lim\limits_{n\to\infty}u_n=A \iff$存在某个子列收敛于$A$
### 1.9.2. 函数的极限
1. $x\to\infty$时函数$f(x)$的极限：设有函数$y=f(x)$和常数$A$，对任意给定的$\varepsilon>0$，若存在$M>0$，使得当$|x|>M$时，恒有$|f(x)-A|<\varepsilon$成立，则称当$x\to\infty$时，$y=f(x)$的极限为A，记为：$\lim\limits_{x\to\infty}f(x)=A$ 或 $f(x)\to A\space(x\to\infty)$
2. $x\to x_0$时函数$f(x)$的极限：设有函数$y=f(x)$和常数$A$，对任意给定的$\varepsilon>0$，若存在$M>0$，使得当$0<|x-x_0|<M$时，恒有$|f(x)-A|<\varepsilon$成立，则称当$x\to x_0$时，$y=f(x)$的极限为A，记为：$\lim\limits_{x\to x_0}f(x)=A$ 或 $f(x)\to A\space(x\to x_0)$
3. 函数极限无穷小关系定理（去极限号定理）：$\lim\limits_{x\to x_0}f(x)=A$，则 $f(x)=A+\alpha$，其中 $\alpha$ 为无穷小
### 1.9.3. 极限的性质
1. 唯一性：若极限存在，则极限值唯一
2. 有界性：极限存在，则局部有界；另两个与有界性有关联的结论：
   * 连续函数在闭区间$[a,b]$上一定有界
   * $f'(x)$在有限区间$(a,b)$上有界，则$f(x)$在$(a,b)$上有界（拉格朗日中值定理推出）
3. 保号性：设$\lim\limits_{x\to x_0}f(x)=A$，则：
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
1. 取右端点：$\int^b_af(x)dx=\lim\limits_{n\to\infty}\displaystyle\sum_{i=1}^n[f(a+\frac{b-a}{n}\cdot i)\cdot\frac{b-a}{n}]$
2. 取左端点：$\int^b_af(x)dx=\lim\limits_{n\to\infty}\displaystyle\sum_{i=1}^n\{f[a+\frac{b-a}{n}\cdot(i-1)]\cdot\frac{b-a}{n}\}$
2. 取中点：$\int^b_af(x)dx=\lim\limits_{n\to\infty}\displaystyle\sum_{i=1}^n\{f[a+\frac{b-a}{n}\cdot\frac{1}{2}\cdot(2i-1)]\cdot\frac{b-a}{n}\}$

特殊地，当$a=0、b=1$时：
1. 取右端点：$\int^1_0f(x)dx=\lim\limits_{n\to\infty}\displaystyle\sum_{i=1}^nf(\frac{i}{n})\frac{1}{n}$
2. 取左端点：$\int^1_0f(x)dx=\lim\limits_{n\to\infty}\displaystyle\sum_{i=1}^nf(\frac{i-1}{n})\frac{1}{n}$
2. 取中点：$\int^1_0f(x)dx=\lim\limits_{n\to\infty}\displaystyle\sum_{i=1}^nf(\frac{2i-1}{2n})\frac{1}{n}$
>三者的变化其实是：$i\to i-1 \to i-\frac{1}{2}$
### 1.11.2. 夹逼准则
1. 对 $u_1+u_2+...+u_n$ 进行缩放有两个常见的结论：
   * 当$n$为无穷大时，则 $n\cdot u_m\le\displaystyle\sum^{n}_{i=1}u_i\le n\cdot u_M$
   * 当$n$为有限数，且 $u_i\ge0$，则 $u_M\le\displaystyle\sum^{n}_{i=1}u_i\le n\cdot u_M$
2. $\lim\limits_{n\to\infty}\sqrt[n]{a^n_1+a^n_2+...+a^n_k}=\max\lbrace a_i\rbrace\space(i=1,2,...,k)$
### 1.11.3. 其他
* 先用夹逼准则，再用定积分定义
* 数列极限改为函数极限
## 1.12. 证明数列极限存在
>证明$\lim\limits_{n\to\infty}a_n$存在：单调有界准则，单调增加（减少）且有上（下）界。

>证明数列极限存在后，求极限：写出相邻两项（如$a_n$和$a_{n+1}$）之间的关系，并在其两端求$n\to\infty$时的极限，令$\lim\limits_{n\to\infty}a_n=A$，得到关于A的方程（应是因为$\lim\limits_{n\to\infty}a_{n+1}=\lim\limits_{n\to\infty}a_n=A$所以这里是等式方程而非不等式），解出A即得到所求极限。

证明单调性的方法：
* 定义法：
   1. $a_{n+1}-a_n\ge0\space(\le0)$
   2. $\frac{a_{n+1}}{a_n}\ge1\space(\le1)$
* 一些常用不等式的结论：
   1. $\frac{x_1+x_2+...+x_n}{n}\ge\sqrt[n]{x_1x_2...x_n},\space x_i\in R^+$
   2. $x^2+y^2\ge 2xy,\space x,y\in R$
   3. $\frac{2}{\pi}x\le\sin x\le x \le \tan x,\space x\in [0,\frac{\pi}{2})$
   4. $\frac{x}{1+x}<\ln(1+x)<x,\space x\in R^+$
      * 变形：设$n$为正整数，则：$\frac{1}{1+n}<\ln(1+\frac{1}{n})<\frac{1}{n}$
* 数学归纳法
# 2. 一元函数微分学
## 2.1. 导数的定义
### 2.1.1. 导数的两种定义形式
1. $f'(x_0)=\lim\limits_{\varDelta x\to0}\frac{f(x_0+\varDelta x)-f(x_0)}{\varDelta x}$
2. $f'(x_0)=\lim\limits_{x\to x_0}\frac{f(x)-f(x_0)}{x-x_0}$
### 2.1.2. 左右导数
1. 左导数：$f_-'(x_0)=\lim\limits_{\varDelta x\to0^-}\frac{f(x_0+\varDelta x)-f(x_0)}{\varDelta x}=\lim\limits_{x\to x_0^-}\frac{f(x)-f(x_0)}{x-x_0}$
2. 右导数：$f_+'(x_0)=\lim\limits_{\varDelta x\to0^+}\frac{f(x_0+\varDelta x)-f(x_0)}{\varDelta x}=\lim\limits_{x\to x_0^+}\frac{f(x)-f(x_0)}{x-x_0}$
### 2.1.3. 可导的条件
>一元函数在某点可导的充要条件是：**函数在该点的左右导数存在且相等**。但只知道这句话往往是不够的，还需要扩展：

设$f(x)$在$x=x_0$处可导，定义为：$f'(x_0)=\lim\limits_{x\to x_0}\frac{f[g_1(x)]-f[g_2(x)]}{g_3(x)}$，则：  
**必要条件**  
* $g_1(x)-g_2(x)=g_3(x)$
* 题目中若该等式不成立，则通常利用分子分母同乘$g_1(x)-g_2(x)$来求出极限值

**充分条件**  
1. 一动一静：分子必为一个动点减一个固定点，固定点就是$f(x_0)$  
2. 保证$f_+(x_0)=f_-(x_0)$：假设$f[g_2(x)]=f(x_0)$，当$x$由$x^-_0\to x^+_0$过程中，$g_1(x)$必由$x^-_0\to x^+_0$或$x^+_0\to x^-_0$
3. $g_1(x)-g_2(x)$为$g_3(x)$的同阶或低阶无穷小

## 2.2. 利用导数定义求导
用导数定义求导较求导法则更方便：
1. 讨论分段函数在分段点的可导性
2. 求导函数过于复杂（多项连乘、连除等）
3. 讨论抽象函数在某点的可导性

## 2.3. 有关可导性的几个常用结论
1. 设$f(x)$在$x_0$处可导，$g(x)$在$x_0$处连续但不可导，则$F(x)=f(x)g(x)$在$x_0$处可导的充要条件是$f(x_0)=0$
   * 例：$f(x)=x\max\lbrace\sin x,\cos x\rbrace$，$x\in (0,2\pi)$，有两个不可导点（$x=\frac{\pi}{4}$，$x=\frac{5\pi}{4}$），若改成$(x-\frac{\pi}{4})\max\lbrace\sin x,\cos x\rbrace$，则只剩一个不可导点（$x=\frac{5\pi}{4}$）
2. 设$f(x)=(x-x_0)^k|x-x_0|$，则：
   * 当$k=0$时，$f(x)$在$x_0$处不可导
   * 当$k=1$时，$f(x)$在$x_0$处一阶可导但二阶不可导
   * 当$k$为正整数时，$f(x)$在$x_0$处$k$阶可导但$k+1$阶不可导
   * 补：$f(x)=\varphi(x)|x-x_0|$，$\varphi(x)$在$x_0$处连续，则$f(x)$在$x_0$处：
      * 可导$\iff\varphi(x)=0$
      * 不可导$\iff\varphi(x)\ne 0$
3. 设$f(x)$在$x_0$处可导，则：
   * 当$f(x_0)\ne0$时，$y=|f(x)|$在$x_0$处可导
   * 当$f(x_0)=0$，且$f'(x_0)=0$时，$y=|f(x)|$在$x_0$处可导，且$y'|_{x=x_0}=0$
   * 当$f(x_0)=0$，且$f'(x_0)\ne0$时，$y=|f(x)|$在$x_0$处不可导
4. 奇（偶）函数的导函数是偶（奇）函数，周期函数的导函数一定是周期函数
   * 奇函数的原函数是偶函数，比如：$f(x)=x$，$F(x)=\frac{1}{2}x^2+C$
   * 偶函数的所有原函数中只有一个奇函数，比如：$f(x)=x^2$，$F(x)=\frac{1}{3}x^3+C$，仅当$C=0$时$F(x)$为奇函数
   * 周期函数的原函数不一定是周期函数，比如：$f(x)=\cos x+1$，$F(x)=\sin x+x+C$，$F(x)$不是周期函数
5. 导数极限定理：若$f(x)$在点$x_0$的左邻域$[x_0-\delta,x_0]$上连续，在$(x_0-\delta,x_0)$内可导，且$\lim\limits_{x\to x_0^-}f'(x)$存在，则$\lim\limits_{x\to x_0^-}f'(x)=f'_-(x_0)$，即：函数$f(x)$在$x_0$的左导数等于导函数$f'(x)$在$x_0$的左极限
   * 同理：若$f(x)$在点$x_0$的右邻域$[x_0,x_0+\delta]$上连续，在$(x_0,x_0+\delta)$内可导，且$\lim\limits_{x\to x_0^+}f'(x)$存在，则$\lim\limits_{x\to x_0^+}f'(x)=f'_+(x_0)$，即：函数$f(x)$在$x_0$的右导数等于导函数$f'(x)$在$x_0$的右极限
   * 用导数定义及拉格朗日中值定理即可证明，由此可以证明导函数至多有第二类间断点，即具有第一类间断点的函数一定没有原函数
6. 导数介值定理（达布定理），若$f(x)$在$[a,b]$上可导：
   * $f'$可取到$f'(a)$与$f'(b)$间的一切值，即：若$f_+'(a)<c<f_-'(b)$，则$\exists\xi\in(a,b)$使$f'(\xi)=c$
   * 若$f_+'(a)f_-'(b)<0$，则$\exists\xi\in(a,b)$使得$f'(\xi)=0$

## 2.4. 一元函数求导
### 2.4.1. 复合函数
设$y=f(u)$，$u=g(x)$均可导，则：$y'=f'[g(x)]g'(x)$
### 2.4.2. 隐函数
求方程$F(x,y)=0$确定的隐函数$y$的一阶导数$\frac{dy}{dx}$，一般有下列三种方法：
1. 视$y=y(x)$，对方程$F(x,y)=0$两端关于$x$进行复合函数求导，表达式中出现$y'$，然后解除$y'$，此时$y'$仍是$(x,y)$的函数
2. 利用$F(x,y)$的偏导数计算：$y'=\frac{dy}{dx}=-\frac{F_x'(x,y)}{F_y'(x,y)}$
3. 对方程两端求微分，然后从求得的等式中解出$\frac{dy}{dx}$

**求隐函数的二阶导**：一般先求出一阶导$\frac{dy}{dx}=\varphi(x,y)$，然后再对$\varphi(x,y)$关于$x$求导，此时表达式中会出现$y'$，将$\varphi(x,y)$代入，即可求得$\frac{d^2y}{dx^2}$
### 2.4.3. 参数方程
参数方程
$\begin{cases}
   x=x(t)\\
   y=y(t)
\end{cases}$
，则：
1. $\frac{dy}{dx}=\frac{y'(t)}{x'(t)}$
2. $\frac{d^2y}{dx^2}=\frac{d\frac{dy}{dx}}{dx}=\frac{d\frac{dy}{dx}}{dt}\cdot\frac{dt}{dx}=\frac{d\frac{dy}{dx}}{dt}\cdot\frac{1}{x'(t)}=\frac{y''(t)x'(t)-x''(t)y'(t)}{x'^3(t)}$
### 2.4.4. 反函数
设$y=f(x)$的反函数$x=\varphi(y)$，则：
* $\frac{dx}{dy}=\frac{1}{f'(x)}$
* $\frac{d^2x}{dy^2}=\frac{d\frac{dx}{dy}}{dx}\cdot\frac{dx}{dy}=-\frac{f''(x)}{f'^3(x)}$
### 2.4.5. 高阶导数
1. 归纳法：求出函数的前几阶导数，分析规律
2. 利用莱布尼茨公式求解
3. 利用泰勒公式求函数在某点的各阶导数
   1. 写出$f(x)$在点$x_0$处的泰勒公式：  
      $f(x)=f(x_0)+f'(x_0)(x-x_0)+...+\frac{f^{(n)}(x_0)}{n!}(x-x_0)^n+...$
   2. 通过化简或变量代换或利用已知的泰勒公式把$f(x)$间接展开为：  
      $f(x)=a_0+a_1(x-x_0)+a_2(x-x_0)^2+...+a_n(x-x_0)^n+...$
   3. 根据函数的泰勒公式的唯一性，相同的次幂前系数相同，可得：  
      $\frac{f^{(n)}(x_0)}{n!}=a_n\implies f^{(n)}(x_0)=a_n\cdot n!$
## 2.5. 闭区间上连续函数的性质
设 $f(x)$ 在闭区间 $[a,b]$ 上连续，则有：
1. 有界定理：$f(x)$ 在 $[a,b]$ 有界
2. 最值定理：$\forall x\in [a,b]$，$m\le f(x) \le M$
3. 介值定理：若 $f(a)=A,\space f(b)=B$，那么对于 $\forall C\in (A,B)$，$\exists c\in(a,b)$ 使 $f(c)=C$
4. 介值定理推论：若 $m\le C\le M$，则 $\exists c\in[a,b]$ 使 $f(c)=C$
5. 零点定理：若 $f(a)f(b)\lt 0$，则 $\exists c\in(a,b)$ 使 $f(c)=0$
6. 函数平均值定理：若 $a\lt x_1\lt x_2\lt ...\lt x_n\lt b$，则 $\exists \xi\in[x_1,x_n]$ 使 $f(\xi)=\frac{f(x_1)+f(x_2)+...+f(x_n)}{n}$

## 2.6. 中值定理
|  |  |  |  |
|---|---|---|---|
| 罗尔定理 | $f(x)$ 在 $[a,b]$ 上连续，在 $(a,b)$ 内可导，$f(a)=f(b)$ | $\exists \xi\in (a,b)$ | $f'(\xi)=0$ |
| 拉格朗日中值定理 | $f(x)$ 在 $[a,b]$ 上连续，在 $(a,b)$ 内可导 | $\exists \xi\in (a,b)$ | $f'(\xi)=\frac{f(b)-f(a)}{b-a}$ |
| 柯西中值定理 | $f(x),g(x)$ 在 $[a,b]$ 上连续，在 $(a,b)$ 内可导，且 $g'(x)\neq 0$ | $\exists \xi\in (a,b)$ | $\frac{f'(\xi)}{g'(\xi)}=\frac{f(b)-f(a)}{g(b)-g(a)}$ |
| 积分中值定理<br>（介值定理可证） | $F(x)=\int_a^xf(t)dt$，在 $[a,b]$ 上连续，在 $(a,b)$ 内可导 | $\exists \xi\in[a,b]$ | $\int_a^bf(x)dx=f(\xi)(b-a)$ |
| 积分中值定理<br>（升级版，拉格朗日中值定理可证） | $F(x)=\int_a^xf(t)dt$，在 $[a,b]$ 上连续，在 $(a,b)$ 内可导 | $\exists \xi\in(a,b)$ | $\int_a^bf(x)dx=f(\xi)(b-a)$ |
|  |  |  |  |

>泰勒定理：  
>$f(x)$ 在点 $a$ 处的 $n$ 阶泰勒公式：  
>$f(x)=f(a)+f'(a)(x-a)+\frac{f''(a)}{2}(x-a)^2+...+\frac{f^{(n)}(a)}{n!}(x-a)^n+R_n$  
>当 $a=0$ 时称为麦克劳林公式：  
>$f(x)=f(0)+f'(0)x+\frac{f''(0)}{2}x^2+...+\frac{f^{(n)}(0)}{n!}x^n+R_n$  
>$R_n=o(x^n)$ 为皮亚诺余项，求极限中的泰勒公式就是这种，根据不同情况取适当的 $n$  
>$R_n=\frac{f^{(n)}(\xi)}{(n+1)!}x^{n+1}$，$\xi$ 介于 $0$ 与 $x$ 之间，为拉格朗日余项，使用泰勒中值定理求高阶导数、证明等式或不等式时使用
>泰勒中值定理解题步骤：  
>1. 写出 $n$ 阶泰勒公式，按题确定 $n$，通常不超过三阶  
>2. 选择 $x,a$，通常 $x$ 选择区间的左右端点或中点，$a$ 按已知条件选择  
>3. 代入已知条件：若是证明不等式则需要适当放缩不等式；若是证明等式且已知“连续可导”则考虑联用介值定理

## 2.7. 函数的性态
| 名称 | 定义 | 必要条件 | 充分条件 |
|---|---|---|---|
| 驻点 | 导数为0的点 |  |  |
| 极值 | 比附近点大（小） | 极值+可导 $\implies f'(x_0)=0$ | 1. 左右导数异号；左正右负极大值，左负右正极小值<br>2. $f'(x_0)=0$ 且 $f''(x_0)\ne 0$ ；$f''(x_0)>0$ 极小值，$f''(x_0)<0$ 极大值<br>3. $1\sim n-1$ 阶导数都为0，$f^{(n)}(x_0)\ne 0$，且 $n$ 为偶数（仅作了解） |
| 拐点 | 凹凸分界点 | 拐点+二阶可导 $\implies f''(x_0)=0$ | 1. 二阶导数异号<br>2. $f''(x_0)=0$ 且 $f'''(x_0)\ne 0$<br>3. $1\sim n-1$ 阶都为0，$f^{(n)}(x_0)\ne 0$，且 $n$ 为奇数（仅作了解） |
|  |  |  |  |

| 函数 | 充要条件 |
|---|---|
| 凹函数 | 1. $\frac{f(a)+f(b)}{2}\ge f(\frac{a+b}{2})$ （梯形中位线大于中点函数值）<br>2. $f(x)\ge f(c)+f'(c)(x-c)$ （曲线在切线的上方）<br>3. $f''(x)>0$ |
| 凸函数 | 1. $\frac{f(a)+f(b)}{2}\le f(\frac{a+b}{2})$<br>2. $f(x)\le f(c)+f'(c)(x-c)$<br>3. $f''(x)<0$ |
|  |  |

|  |  |
|---|---|
| 曲率 | $R=\frac{\|y''\|}{(1+y'^2)^\frac{3}{2}}$ |
| 曲率半径 | $r=\frac{1}{R}$ |
|  |  |

>拐点的个数：曲线的二阶导函数的单根就是拐点。  
>求解过程：曲线 $y$ 的最高次方就是总根数，设为 $k$，其二阶导函数 $y''$ 的根数为 $k-2$，再减去 $y''$ 的重根数即为拐点的个数。  
>例一：$y=(x-1)^2(x-3)^2$，总根数 $k=4$，$y''$ 根数 $k-2=2$，$y''$ 无重根，故拐点个数就是 $2$  
>例二：$y=(x-1)(x-2)^2(x-3)^3(x-4)^4$，总根数 $k=10$，$y''$ 根数 $k-2=8$，$y''$ 有二重根 $x=4$，故拐点个数为 $k-2-2=6$

## 2.8. 方程根的讨论
证明方程根的存在性，通常首先把方程转为 $f(x)=0$ 的形式，然后：
1. 利用 $f(x)$ 在闭区间上的零点定理
2. 求出原函数，利用罗尔定理
3. 结合函数性态讨论

证明方程根的唯一性：
1. 利用 $f(x)$ 的单调性
2. 反证法
3. 罗尔定理推论的逆否命题：若 $f^{(n)}(x)=0$ 无解，则 $f(x)=0$ 最多只有 $n$ 个根
4. 结合函数性态讨论

# 3. 一元函数积分学
## 3.1. 不定积分的公式法
|  |  |
|---|---|
| $\int{e^x}dx$ | $e^x+C$ |
| $\int{a^x}dx$ | $\frac{a^x}{\ln a}+C$ |
| $\int{x^a}dx$ | $\frac{x^{a+1}}{a+1}+C\enspace(a\neq-1)$ |
| $\int{\frac{1}{x^2}}dx$ | $-\frac{1}{x}+C$ |
| $\int{\frac{1}{x}}dx$ | $ln{\|x\|}+C$ |
| $\int{\frac{1}{\sqrt{x}}}dx$ | $2\sqrt{x}+C$ |
| $\int\ln xdx$ | $x\ln x-x+C$ |
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

## 3.2. 定积分公式
1. 奇函数时：$\int_{-a}^af(x)dx=0$
2. 偶函数时：$\int_{-a}^af(x)dx=2\int_0^af(x)dx$
3. 非奇非偶时：$\int_{-a}^af(x)dx=\int_0^a[f(x)+f(-x)]dx$
4. $f(x+T)=f(x)$ 时：$\int_0^Tf(x)dx=\int_a^{a+T}f(x)dx$
5. $\int_a^bf(x)dx=\int_a^bf(a+b-x)dx$
6. $\int_0^{\frac{\pi}{2}}\sin^n xdx=\int_0^{\frac{\pi}{2}}\cos^n xdx=$
$\begin{cases}
\frac{(n-1)!!}{n!!}\qquad n为奇数  \\
\frac{(n-1)!!}{n!!}\cdot\frac{\pi}{2}\quad n为偶数  \\
\end{cases}$
7. $\int_0^{\frac{\pi}{2}}f(\sin x)dx=\int_0^{\frac{\pi}{2}}f(\cos x)dx$
8. $\int_0^\pi xf(\sin x)dx=\frac{\pi}{2}\int_0^\pi f(\sin x)dx$，$\frac{\pi}{2}$ 是 $(0,\pi)$ 的中点
9. $\int_0^a\sqrt{2ax-x^2}dx=\frac{1}{4}\pi a^2$，几何意义是以 $(a,0)$ 为圆心，$a$ 为半径的四分之一圆

## 3.3. 定积分应用
|  |  |
|---|---|
| 平面图形面积-直角坐标 | $S=\int^b_a[f(x)-g(x)]dx$ |
| 平面图形面积-参数方程 | $S=\int^d_cy(t)x'(t)dt$ |
| 平面图形面积-极坐标 | $S=\frac{1}{2}\int^\beta_\alpha r^2(\theta)d\theta$ |
| 几何体体积-自变量x函数绕x轴转 | $V=\pi\int^b_af^2(x)dx$ |
| 几何体体积-自变量x函数绕y轴转 | $V=2\pi\int^b_axf(x)dx$ |
| 曲线弧长-直角坐标 | $l=\int^b_a\sqrt{1+f'^2(x)}dx$ |
| 曲线弧长-参数方程 | $l=\int^d_c\sqrt{x'^2(t)+y'^2(t)}dt$ |
| 曲线弧长-极坐标 | $l=\int^\beta_\alpha\sqrt{r^2(\theta)+r'^2(\theta)}d\theta$ |
| 旋转曲面面积-直角坐标 | $S=2\pi\int^b_af(x)\sqrt{1+f'^2(x)}dx$ |
| 旋转曲面面积-参数方程 | $S=2\pi\int^d_cy\sqrt{x'^2(t)+y'^2(t)}dt$ |
| 旋转曲面面积-极坐标 | $S=2\pi\int^\beta_\alpha y\sqrt{r^2(\theta)+r'^2(\theta)}d\theta$ |
| 区间平均值 | $\bar{y}=\frac{1}{b-a}\int^{b}_{a}f(x)dx$ |
|  |  |

# 4. 常微分方程
## 4.1. 一阶微分方程
| 类型 | 方程 | 解法 | 备注 |
|---|---|---|---|
| 可分离变量方程 | $\frac{dy}{dx}=f(x)g(y)$ | $\int\frac{1}{g(y)}dy=\int f(x)dx$ |  |
| 齐次方程 | $\frac{dy}{dx}=f(\frac{y}{x})$ | $\int\frac{1}{f(u)-u}du=\int\frac{1}{x}dx$，$(u=\frac{y}{x})$| 存在 $x^m,y^n,x^sy^t$，当 $m=n=s+t$ 时为齐次方程 |
| 一阶线性微分方程 | $y'+p(x)y=q(x)$ | $y=e^{-\int p(x)dx}(\int q(x)e^{\int p(x)dx}dx+C)$ |  |
| 伯努利方程 | $y'+p(x)y=q(x)y^n$，$(n\ne 0,1)$ | $z'+(n-1)p(x)z=(n-1)q(x)$，$(z=y^{1-n})$ |  |
| 全微分方程 | $p(x,y)dx+q(x,y)dy=0$ | 待补充 |  |
|  |  |  |  |
## 4.2. 可降阶的高阶微分方程
| 方程 | 解法 |
|---|---|
| $y^{(n)}=f(x)$ | 两端积分n次 |
| 不显含y型 | 令 $y'=p$，则 $y''=\frac{dp}{dx}$ |
| 不显含x型 | 令 $y'=p$，则 $y''=p\frac{dp}{dy}$ |
|  |  |
## 4.3. 线性微分方程解的性质与结构
>① 设 $y''+p(x)y'+q(x)y=0$，齐次线性方程  
>② 设 $y''+p(x)y'+q(x)y=f(x)$，非齐次线性方程
1. 齐次线性方程的叠加原理：设 $y_1,y_2$ 是任意两个解，则 $y=C_1y_1+C_2y_2$ 仍是它的解。
2. 齐次线性方程的通解结构：设 $y_1,y_2$ 是任意两个无关解（$\frac{y_1}{y_2}$ 不恒为常数），则其通解为 $y=C_1y_1+C_2y_2$。
3. 非齐次线性方程的叠加原理：设 $y_1,y_2$ 分别是 $y''+p(x)y'+q(x)y=f_1(x)$，$y''+p(x)y'+q(x)y=f_2(x)$ 的解，  
   则 $ay_1+by_2$ 是 $y''+p(x)y'+q(x)y=af_1(x)+bf_2(x)$ 的解。
4. 非齐次线性方程的通解 = 齐次方程的通解 + 非齐次方程的特解，记为：$y=Y+y^*$
5. 非齐次线性方程的任意两个解之差是齐次方程的解。
6. 非齐次线性方程的多个解，各乘以一个系数后相加，比如：$k_1y_1+k_2y_2+...+k_ny_n=s$，则：
   * 若 $k_1+k_2+...+k_n=0$，则 $s$ 是齐次方程的解。
   * 若 $k_1+k_2+...+k_n=1$，则 $s$ 是非齐次方程的解。
   * 若 $k_1+k_2+...+k_n=k$，则 $\frac{s}{k}$ 是非齐次方程的解。
## 4.4. 常系数线性微分方程
二阶常系数齐次方程：$y''+py'+qy=0$，对应的特征方程是：$r^2+pr+q=0$，求出 $r1,r2$  
1. $r1,r2$ 是单根，通解：$y=C_1e^{r_1x}+C_2e^{r_2x}$
2. $r1,r2$ 是重根，通解：$y=e^{rx}(C_1+C_2x)$
3. $r1,r2$ 是复数，通解：$y=e^{\lambda x}(C_1\cos{\omega x}+C_2\sin{\omega x})$  

二阶常系数非齐次方程：$y''+py'+qy=f(x)$，通解为：$y=Y+y^*$，用待定系数法求解：
1. 当 $f(x)=e^{\lambda x}P(x)$，设 $y^*=e^{\lambda x}x^kQ(x)$，其中：
   * 当 $\lambda$ 不是特征根，$k=0$
   * 当 $\lambda$ 是单根，$k=1$
   * 当 $\lambda$ 是重根，$k=2$
   * $Q(x)$ 是 $P(x)$ 的同次完整多项式
2. 当 $f(x)=e^{\lambda x}[P_1(x)\cos{\omega x}+P_2(x)\sin{\omega x}]$，设 $y^*=e^{\lambda x}x^k[Q_1(x)\cos{\omega x}+Q_2(x)\sin{\omega x}]$，其中：
   * 当 $\lambda \pm i\omega$ 不是特征根：$k=0$
   * 当 $\lambda \pm i\omega$ 是特征根：$k=1$
   * $Q_1(x),Q_2(x)$ 是同次完整多项式，但系数要全部用不同字母表示，次幂则为 $P_1(x),P_2(x)$ 中较高者  

$n$ 阶常系数齐次方程：$y^{(n)}+P_1y^{(n-1)}+...+P_{n-1}y'+P_ny=0$，其特征方程是：$r^n+P_1r^{n-1}+...+P_{n-1}r+P_n=0$，通解：
1. 当 $r$ 是 $k$ 重根，$y=e^{rx}(C_1+C_2x+...+C_kx^{k-1})$
2. 当 $r=\lambda\pm i\omega$ 是 $k$ 重共轭复根，$y=e^{\lambda x}[(C_1+C_2x+...+C_kx^{k-1})\cos{\omega x}+(D_1+D_2x+...+D_kx^{k-1})\sin{\omega x}]$  

# 5. 多元函数微分学
## 5.1. 概念
|  |  |
|---|---|
| 二元函数 | $z=f(x,y)$ |
| 二元函数的几何意义 | 一张曲面 |
| 二元函数的极限 | 即二重极限：$\lim\limits_{(x,y)\to(x_0,y_0)}f(x,y)$<br>与一元函数只有左右极限不同，二元函数到某点的极限有无数路径，通常由两个不同路径的极限不同来反证其极限不存在<br>与本质为一元函数极限的二次极限 $\lim\limits_{x\to x_0}\lim\limits_{y\to y_0}f(x,y)$ 没有关系 |
| 二元函数连续 | $\lim\limits_{(x,y)\to(x_0,y_0)}f(x,y)=f(x_0,y_0)$ |
| 二元函数性质 | 不可用：洛必达法则、泰勒展开<br>可用：导数定义、无穷小替换、$1^\infty$<br>若在有界闭区间上连续，则有界、最值、介值 |
| 二元函数的偏导数 | $f_x'(x_0,y_0)=\lim\limits_{\Delta x\to 0}\frac{f(x_0+\Delta x,y_0)-f(x_0,y_0)}{\Delta x}$ <br> $f_y'(x_0,y_0)=\lim\limits_{\Delta y\to 0}\frac{f(x_0,y_0+\Delta y)-f(x_0,y_0)}{\Delta y}$ |
| 二元函数的偏导连续 | 对 $z=f(x,y)$ 求偏导得到的 $f'_x(x,y)$ 和 $f'_y(x,y)$ 是偏导函数，也常称为“偏导数”，而“偏导连续”则是指这里的偏导函数连续 |
| $z=f(x,y)$ 在 $(x_0,y_0)$ 可微 | $\lim\limits_{(\Delta x,\Delta y)\to (0,0)}\frac{f(x_0+\Delta x,y_0+\Delta y)-f(x_0,y_0)-\frac{\partial f}{\partial x}\Delta x-\frac{\partial f}{\partial y}\Delta y}{\sqrt{(\Delta x)^2+(\Delta y)^2}}$ <br> $\lim\limits_{(x,y)\to (x_0,y_0)}\frac{f(x,y)-f(x_0,y_0)-\frac{\partial f}{\partial x}(x-x_0)-\frac{\partial f}{\partial y}(y-y_0)}{\sqrt{(x-x_0)^2+(y-y_0)^2}}$ <br> 称 $dz=\frac{\partial f}{\partial x}dx+\frac{\partial f}{\partial y}dy$ 为全微分 |
| 关系 | 偏导连续 -> 可微 -> 连续 -> 二重极限存在 <br> 可微 -> 偏导存在 <br> 与一元函数不同，“偏导存在”与“连续”之间没有关系 |
| $f(x,y)$ 在 $(0,0)$ 可微的两个冲要条件 | $\lim\limits_{(x,y)\to(0,0)}\frac{f(x,y)-f(0,0)}{x^2+y^2} \space \exists \implies \lim\limits_{(x,y)\to(0,0)}\frac{f(x,y)-f(0,0)}{\sqrt{x^2+y^2}}=0 \implies$ 可微 |
|  |  |

## 5.2. 求偏导与全微分
1. 偏导数的项数等于中间变量的个数
2. 每项再使用复合函数求导的链式法则
3. 求二阶偏导时，注意一阶偏导数 $f_1',f_2'$ 与原函数 $f$ 具有相同的符合结构

## 5.3. 隐函数求导
隐函数存在定理，即方程 $F(x,y,z)$ 在点 $(x_0,y_0,z_0)$ 某一邻域能唯一确定一个连续且偏导连续的函数 $z=f(x,y)$，满足 $z_0=f(x_0,y_0)$：
1. $F(x,y,z)$ 在点 $(x_0,y_0,z_0)$ 的该邻域内具有连续偏导数
2. $F(x_0,y_0,z_0)=0$
3. $F_z'(x_0,y_0,z_0)\ne 0$

隐函数求导的三个方法：
1. 公式：$\frac{\partial z}{\partial x}=-\frac{F_x'}{F_z'}$，$\frac{\partial z}{\partial y}=-\frac{F_y'}{F_z'}$
2. 等式两端求导：$F_x'+F_z'\frac{\partial z}{\partial x}=0$，$F_y'+f_z'\frac{\partial z}{\partial y}=0$
3. 利用微分形式不变性：$F_x'dx+F_y'dy+F_z'dz=0$

## 5.4. 多元函数的极值与最值
### 5.4.1. 无条件极值
必要条件：
$\begin{cases}
   一阶偏导存在 \\
   达到极值
\end{cases}\implies \begin{cases}
   f_x'(x_0,y_0)=0 \\
   f_y'(x_0,y_0)=0
\end{cases}$，即 $(x_0,y_0)$ 为驻点  
充分条件：
1. 具有一阶及二阶连续偏导
2. $\begin{cases}
   f_x'(x_0,y_0)=0 \\
   f_y'(x_0,y_0)=0
\end{cases}$
3. 令 $A=f_{xx}''(x_0,y_0),B=f_{xy}''(x_0,y_0),C=f_{yy}''(x_0,y_0)$，则：
   1. $B^2-AC<0$ 时，为极值，$A<0$ 极大值，$A>0$ 极小值
   2. $B^2-AC>0$ 时，非极值
   3. $B^2-AC=0$ 时，不确定

### 5.4.2. 条件极值
求 $z=f(x,y)$ 在约束条件 $g(x,y)=0$ 与 $h(x,y)=0$ 下的极值，方法为拉格朗日乘法的
1. 令 $F(x,y,\lambda,\mu)=f(x,y)+\lambda g(x,y)+\mu h(x,y)$
2. 求偏导，解方程：$\begin{cases}
   F_x'=0 \\
   F_y'=0 \\
   F_\lambda '=0 \\
   F_\mu '=0 \\
\end{cases}$  

### 5.4.3. 闭区间最值
1. 求驻点
2. 边界上的最值（条件极值）
3. 对比 1 和 2 的结果，最大的为最大值，最小的为最小值

# 6. 二重积分
* 定义：$\iint_Df(x,y)dxdy=\lim\limits_{n\to\infty}\displaystyle\sum_{i=1}^n\displaystyle\sum_{j=1}^nf(\frac{i}{n},\frac{j}{n})\frac{1}{n^2}$
* 二重积分中值定理：$\exists\space(\xi,\eta)$ 使 $\iint_Df(x,y)dxdy=f(\xi,\eta)S_D$
* 偏心圆：
  1. 右偏心圆：$\theta\in(-\frac{\pi}{2},\frac{\pi}{2})$，$r\in(0,2a\cos\theta)$
  2. 上偏心圆：$\theta\in(0,\pi)$，$r\in(0,2a\sin\theta)$
  3. 左偏心圆：$\theta\in(\frac{\pi}{2},\frac{3}{2}\pi)$，$r\in(0,-2a\cos\theta)$
  4. 下偏心圆：$\theta\in(-\pi,0)$，$r\in(0,-2a\sin\theta)$
* 轮换对称：若区域 $D$ 关于 $y=x$ 对称，则：$\iint_Df(x,y)dxdy=\iint_Df(y,x)dxdy=\frac{1}{2}\iint_D[f(x,y)+f(y,x)]dxdy$
* 质心坐标：若区域 $D$ 的几何中心坐标为 $(\bar X,\bar Y)$ 则：
   1. $\bar X=\frac{\iint_Dxdxdy}{S_D}$，$\bar Y=\frac{\iint_Dydxdy}{S_D}$
   2. $\iint_Dxdxdy=\bar X \cdot S_D$，$\iint_Dydxdy=\bar Y \cdot S_D$

# 7. 无穷级数
## 7.1. 常数项级数
1. $\lim\limits_{n\to \infty}a_n$ 存在 $\iff \displaystyle\sum_{n=1}^\infty(a_{n+1}-a_n)$ 收敛
2. 若 $k\ne 0$，$\displaystyle\sum_{n=1}^\infty a_n$ 与 $\displaystyle\sum_{n=1}^\infty ka_n$ 有相同的敛散性，若 $\displaystyle\sum_{n=1}^\infty a_n=S$ 则 $\displaystyle\sum_{n=1}^\infty ka_n=kS$
3. 若两个收敛级数 $\displaystyle\sum_{n=1}^\infty a_n=A$、$\displaystyle\sum_{n=1}^\infty b_n=B$，则任给常数 $a,b$ 有 $\displaystyle\sum_{n=1}^\infty (aa_n+bb_n)=aA+bB$，此为收敛级数的线性性质
   * 收敛+收敛=收敛；收敛+发散=发散；发散+发散=不一定发散
4. 若 $\displaystyle\sum_{n=1}^\infty a_n$ 收敛，则 $\lim\limits_{n\to\infty}a_n=0$，因此若 $\lim\limits_{n\to\infty}a_n\ne 0$ 则 $\displaystyle\sum_{n=1}^\infty a_n$ 一定发散（通项的极限为零是级数收敛的必要非充分条件）
5. ：
   * 前面增加或去掉有限项，级数的收敛性不变（可能改变级数的和）
   * 收敛级数在不改变次序的情况下可以任意加括号，收敛性不变且其和不变
   * 收敛级数去掉括号后不一定收敛
   * 若级数加上括号后发散，则原级数必发散

### 7.1.1. 正项级数
1. 比较判别法
   * 小于收敛的必收敛，大于发散的必发散
   * P级数 $\displaystyle\sum_{n=1}^\infty\frac{1}{n^p}=\begin{cases}收敛，p>1 \\ 发散，p\le 1 \end{cases}$
   * 等比级数 $\displaystyle\sum_{n=1}^\infty aq^n=\begin{cases}收敛，\frac{a}{1-q}，|q|<1 \\ 发散，|q|\ge 1 \end{cases}$ $(a\ne 0)$
2. 比较判别法的极限形式；若 $\lim\limits_{n\to\infty}\frac{a_n}{b_n}=k$，则 $\displaystyle\sum_{n=1}^\infty a_n$ 和 $\displaystyle\sum_{n=1}^\infty b_n$：
   * $0<k<+\infty$ 时，同敛散
   * $k=0$ 时，同收敛
   * $k=+\infty$ 时，同发散
3. ：
   * 比值判别法 $\displaystyle\sum_{n=1}^\infty\frac{a_{n+1}}{a_n}=k$
   * 根值判别法 $\displaystyle\sum_{n=1}^\infty\sqrt[n]{a_n}=k$
   * 比值是根值的充分条件：$\displaystyle\sum_{n=1}^\infty\frac{a_{n+1}}{a_n}=k \implies \displaystyle\sum_{n=1}^\infty\sqrt[n]{a_n}=k$
   * $k<1$ 时，收敛
   * $k>1$ 时，发散
   * $k=1$ 时，不确定
4. 积分判别法：若 $f(x)=a_n$，则广义积分 $\int_1^{+\infty}f(x)dx$ 与 $\displaystyle\sum_{n=1}^\infty{a_n}$ 同敛散
5. 补充：
   * 若正项级数 $\displaystyle\sum_{n=1}^\infty a_n$ 收敛，则 $\displaystyle\sum_{n=1}^\infty a_n^2$、$\displaystyle\sum_{n=1}^\infty\frac{\sqrt{a_n}}{n}$、$\displaystyle\sum_{n=1}^\infty\frac{a_n}{1+a_n}$ 均收敛

### 7.1.2. 交错与任意级数
>若 $a_n>0$，称 $\displaystyle\sum_{n=1}^\infty(-1)^na_n$ 或 $\displaystyle\sum_{n=1}^\infty(-1)^{n-1}a_n$ 为交错级数  
>若级数各项可正、可负、可零，称之为任意项级数  
1. 莱布尼茨判别法：满足 ① $a_{n+1}\le a_n$，即单调递减；② $\lim\limits_{n\to\infty}a_n=0$；则交错级数 $\displaystyle\sum_{n=1}^\infty(-1)^na_n$ 收敛。
   * 注：条件①为充分非必要，当②满足但①不满足时不能保证发散，要改用其他方法（定义、性质等）判断。
2. 若 $\displaystyle\sum_{n=1}^\infty |a_n|$ 收敛，则称 $\displaystyle\sum_{n=1}^\infty a_n$ 绝对收敛，绝对收敛则原级数收敛。
3. 若 $\displaystyle\sum_{n=1}^\infty a_n$ 收敛，但 $\displaystyle\sum_{n=1}^\infty |a_n|$ 发散，则称 $\displaystyle\sum_{n=1}^\infty a_n$ 条件收敛。
4. 熟记 $\displaystyle\sum_{n=1}^\infty(-1)^n\frac{1}{n}$、$\displaystyle\sum_{n=1}^\infty(-1)^n\frac{1}{\sqrt{n}}$ 条件收敛，$\displaystyle\sum_{n=1}^\infty(-1)^n\frac{1}{n^2}$ 绝对收敛（选择题找特例的材料）。
   * $\displaystyle\sum_{n=1}^\infty(-1)^n\frac{1}{n^p}$=$\begin{cases}
      绝对收敛，p>1\\
      条件收敛，0< p \le 1\\
      发散，p < 0
   \end{cases}$
5. 若 $\displaystyle\sum_{n=1}^\infty a_n$ 绝对收敛，则 $\displaystyle\sum_{n=1}^\infty\frac{1}{2}(a_n+|a_n|)$ 和 $\displaystyle\sum_{n=1}^\infty\frac{1}{2}(a_n+|a_n|)$ 都收敛。（前者是提取所有正数项，后者是提取所有负数项）

## 7.2. 幂级数
### 7.2.1. 收敛半径和收敛域
1. 阿贝尔定理：设 $\displaystyle\sum_{n=1}^\infty a_nx^n$ 在 $x=a$ $a\ne 0$ 点：
   * 若收敛，则在 $|x|<|a|$ 绝对收敛
   * 若发散，则在 $|x|>|a|$ 发散 
2. 不缺项幂级数（如：$\displaystyle\sum_{n=1}^\infty a_nx^n$）的收敛半径：$r=\lim\limits_{n\to\infty}|\frac{a_n}{a_{n+1}}|$ 或 $r=\lim\limits_{n\to\infty}\frac{1}{\sqrt[n]{|a_n|}}$
3. 缺项幂级数（如：$\displaystyle\sum_{n=1}^\infty a_nx^{2n}$）的收敛半径：$r=\lim\limits_{n\to\infty}|\frac{a_{n+1}x2(n+1)}{a_nx^{2n}}|<1$，解出 $x$ 的范围来确定收敛半径和收敛域。
4. $x$ 的范围是收敛区间，收敛域=区间+端点，端点的敛散性需要带入原级数后按常数项级数来判断。
5. $\displaystyle\sum_{n=1}^\infty a_n(x-x_0)^n$ ：
   * 若在 $x_1$ 收敛，则收敛半径 $r\ge |x_1-x_0|$
   * 若在 $x_1$ 发散，则收敛半径 $r\le |x_1-x_0|$
   * 若在 $x_1$ 条件收敛，则收敛半径 $r=|x_1-x_0|$
6. ：
   * 对级数提出或乘以因式 $(x-x_0)^k$，或者平移等，收敛半径不变
   * 对级数逐项求导，收敛半径不变，收敛域可能缩小（区间大小不变，端点可能改变）
   * 对级数逐项积分，收敛半径不变，收敛域可能扩大（区间大小不变，端点可能改变）

### 7.2.2. 求和函数
|  |  |  |
|--|--|--|
| $\displaystyle\sum_{n=0}^\infty x^n$ | $\frac{1}{1-x}$ | $\|x\|<1$ |
| $\displaystyle\sum_{n=0}^\infty (-1)^nx^n$ | $\frac{1}{1+x}$ | $\|x\|<1$ |
| $\displaystyle\sum_{n=1}^\infty x^n$ | $\frac{x}{1-x}$ | $\|x\|<1$ |
| $\displaystyle\sum_{n=1}^\infty (-1)^nx^n$ | $\frac{-x}{1+x}$ | $\|x\|<1$ |
| $\displaystyle\sum_{n=1}^\infty nx^n$ | $\frac{x}{(1-x)^2}$ | $\|x\|<1$ |
| $\displaystyle\sum_{n=1}^\infty n^2x^n$ | $\frac{x(1+x)}{(1-x)^3}$ | $\|x\|<1$ |
| $\displaystyle\sum_{n=2}^\infty n(n-1)x^{n-2}$ | $\frac{2}{(1-x)^3}$ | $\|x\|<1$ |
| $\displaystyle\sum_{n=1}^\infty \frac{1}{n}x^n$ | $-\ln(1-x)$ | $x\in[-1,1)$ |
|  |  |  |

>基本原则：
>1. 系数在分母，求导，如：$\displaystyle\sum_{n=1}^\infty\frac{1}{n}x^n$；
>2. 系数在分子，积分，如：$\displaystyle\sum_{n=1}^\infty nx^n$；
>3. 其他，变形为上述两者；

求数项级数的和：构造一个相应的幂级数求和，把所求和的常数项级数看作幂级数在 $x$ 取某一值时所得。

### 7.2.3. 求含阶乘因子的和函数
1. 看到分母为 $n!$ 要联系 $e^x$ 的展开式；
2. 看到分母为 $(2n)!$ 要联系 $\cos x$ 的展开式；
3. 看到分母为 $(2n+1)!$ 要联系 $\sin x$ 的展开式；
4. 下标恒等变形：$\displaystyle\sum_{n=1}^\infty a_nx^n=\displaystyle\sum_{n=0}^\infty a_{n+1}x^{n+1}=\displaystyle\sum_{n=2}^\infty a_{n-1}x^{n-1}$

# 8. 数一专题
## 8.1. 傅里叶级数
1. 以 $T=2t$ 为周期，在 $[-t,t]$ 可积的 $f(x)$ 的傅里叶级数：$f(x)\sim\frac{a_0}{2}+\displaystyle\sum_{n=1}^\infty(a_n\cos{\frac{n\pi x}{t}}+b_n\sin{\frac{n\pi x}{t}})$，其中：
   * $a_0=\frac{1}{t}\int_{-t}^tf(x)dx$ &emsp; $(n=1,2,3,...)$
   * $a_n=\frac{1}{t}\int_{-t}^tf(x)\cos{\frac{n\pi x}{t}}dx$ &emsp; $(n=1,2,3,...)$
   * $b_n=\frac{1}{t}\int_{-t}^tf(x)\sin{\frac{n\pi x}{t}}dx$ &emsp; $(n=1,2,3,...)$
2. 若 $T=2\pi$ 即 $t=\pi$，则 $f(x)\sim\frac{a_0}{2}+\displaystyle\sum_{n=1}^\infty(a_n\cos nx+b_n\sin nx)$，其中：
   * $a_0=\frac{1}{\pi}\int_{-\pi}^\pi f(x)dx$ &emsp; $(n=1,2,3,...)$
   * $a_n=\frac{1}{\pi}\int_{-\pi}^\pi f(x)\cos nxdx$ &emsp; $(n=1,2,3,...)$
   * $b_n=\frac{1}{\pi}\int_{-\pi}^\pi f(x)\sin nxdx$ &emsp; $(n=1,2,3,...)$
3. 在计算 $a_n$ 与 $b_n$ 时常用结论：$n\in Z \begin{cases}
      \cos n\pi =(-1)^n \\
      \sin n\pi =0 \\
   \end{cases}$ &emsp; $n=2k+1 \begin{cases}
      \cos \frac{n\pi}{2} =0 \\
      \sin \frac{n\pi}{2} =(-1)^k \\
   \end{cases}$ &emsp; $n=2k \begin{cases}
      \cos \frac{n\pi}{2} =(-1)^k \\
      \sin \frac{n\pi}{2} =0 \\
   \end{cases}$
4. ：
   * 正弦级数：设 $f(x)$ 是以 $T=2t$ 为周期的奇函数（若是 $[0,t]$ 上的函数则奇延拓），则 $a_n=0$ 即：$f(x)\sim\frac{a_0}{2}+\displaystyle\sum_{n=1}^\infty b_n\sin\frac{n\pi x}{t}$
   * 余弦级数：设 $f(x)$ 是以 $T=2t$ 为周期的偶函数（若是 $[0,t]$ 上的函数则偶延拓），则 $b_n=0$ 即：$f(x)\sim\frac{a_0}{2}+\displaystyle\sum_{n=1}^\infty a_n\cos\frac{n\pi x}{t}$
5. 狄利克雷收敛定理：若 $f(x)$ 满足：①连续，或只有有限个第一类间断点；②只有有限个极值点；则其傅里叶级数就是其和函数 $S(x)$，求 $x=x_0$ 收敛的结果时：
   * $S(x_0)=\begin{cases}
      f(x_0), \space\space\space\space f(x)在x_0连续 \\
      \frac{1}{2}[f_-(x_0)+f_+(x_0)], \space\space\space\space x_0是第一类间断点，左极限+右极限 \\
      \frac{1}{2}[f_+(-t)+f_-(t)], \space\space\space\space x_0是区间端点，左端点的右极限+右端点的左极限 \\
   \end{cases}$

## 8.2. 空间解析几何
1. 向量
   1. 点 $A(x_1,y_1,z_1)$ 和 $B(x_2,y_2,z_2)$，向量 $\overrightarrow{AB}=(x_2-x_1,\space y_2-y_1,\space z_2-z_1)$
   2. 向量的模，即向量的长度：$||\overrightarrow{AB}||=\sqrt{x^2+y^2+z^2}$
   3. 单位向量：模长为1的向量
   4. 两个向量 $\alpha,\beta$ 相乘（点乘）：$\alpha\cdot\beta=x_1x_2+y_1y_2+z_1z_2$，点乘结果为一个数，为零则表示两个向量垂直
   5. 两个向量 $\alpha,\beta$ 叉乘，也叫叉积、适量积，结果为一个向量：$\gamma=\alpha\times\beta=\begin{vmatrix}
      \overrightarrow{i} & \overrightarrow{j} & \overrightarrow{k} \\
      x_1 & y_1 & z_1 \\
      x_2 & y_2 & z_2 \\
   \end{vmatrix}$，$\gamma$ 与 $\alpha,\beta$ 都垂直，即垂直于 $\alpha,\beta$ 决定的平面；$\gamma$ 的模为 $\alpha,\beta$ 组成的平行四边形的有向面积；$\overrightarrow{i},\overrightarrow{j},\overrightarrow{k}$ 为 $x,y,z$ 轴的单位向量
   6. 两个向量的夹角 $\theta$：$\cos\theta=\frac{\alpha\cdot\beta}{||\alpha||||\beta||}$
2. 平面方程
   1. 一般式：$Ax+By+Cz+D=0$，&emsp; $(A,B,C)$ 是平面的法向量
   2. 点法式：$A(x-x_0)+B(y-y_0)+C(z-z_0)=0$，&emsp; $(A,B,C)$ 是平面的法向量
   3. 截距式：$\frac{x}{a}+\frac{y}{b}+\frac{z}{c}=1$，&emsp; $(\frac{1}{a},\frac{1}{b},\frac{1}{c})$ 是平面的法向量
3. 直线方程
   1. 一般式：$\begin{cases}
      a_1x+b_1y+c_1z+d_1=0 \\
      a_2x+b_2y+c_2z+d_2=0 \\
   \end{cases}$，两平面相交于一条直线，直线的方向向量：$(a_1,b_1,c_1)\times(a_2,b_2,c_2)$
   2. 对称式：$\frac{x-x_0}{a}=\frac{y-y_0}{b}=\frac{z-z_0}{c}$，直线的方向向量：$(a,b,c)$
   3. 参数式：$\begin{cases}
      x=x_0+at \\
      y=y_0+bt \\
      z=z_0+ct \\
   \end{cases}$，令对称式=t得到，直线的方向向量：$(a,b,c)$
   4. 点 $(x_1,y_1,z_1)$ 到直线 $\frac{x-x_0}{a}=\frac{y-y_0}{b}=\frac{z-z_0}{c}$ 的距离：$d=\frac{|(x_0-x_1,y_0-y_1,z_0-z_1)\times(a,b,c)|}{\sqrt{a^2+b^2+c^2}}$
4. 三平面的位置关系
   * $a_1x+b_1y+c_1z=d_1$
   * $a_2x+b_2y+c_2z=d_2$
   * $a_3x+b_3y+c_3z=d_3$
   * 系数矩阵：$A=\begin{pmatrix}
      a_1 & b_1 & c_1 \\
      a_2 & b_2 & c_2 \\
      a_3 & b_3 & c_3 \\
   \end{pmatrix}$，系数矩阵的增广矩阵：$\bar A=\begin{pmatrix}
      a_1 & b_1 & c_1 & d_1 \\
      a_2 & b_2 & c_2 & d_2 \\
      a_3 & b_3 & c_3 & d_3 \\
   \end{pmatrix}$
   * 三平面位置关系由 $A$ 和 $\bar A$ 的秩决定：
      1. $r(A)=r(\bar A)=1$，三平面重合（1,1  三重）
      2. $r(A)=1,r(\bar A)=2$，两平面重合并与另一平面平行（1,2  二重一平）
      3. $r(A)=1,r(\bar A)=3$，三平面平行（1,3  三平）
      4. $r(A)=r(\bar A)=2$：
         * 若 $A$ 的行向量有两个线性相关，则两平面重合并与另一平面相交于一条直线（2,2,相  二重一交）
         * 若 $A$ 的行向量任意两个都线性无关，则三平面相交于一条直线（2,2,无  三交一线）
      5. $r(A)=2,r(\bar A)=3$：
         * 若 $A$ 的行向量有两个线性相关，则两平面平行，并与另一平面相交于两条平行直线（2,3,相  二平一交）
         * 若 $A$ 的行向量任意两个都线性无关，则三平面相交于三条平行直线（2,3,无  三交三线）
      6. $r(A)=r(\bar A)=3$，三平面相交于一点（3,3  三交一点）  

| 系数矩阵的秩 | 增广矩阵的秩 | 系数矩阵行向量 | 三平面位置关系 |
|--|--|--|--|
| 1 | 1 |  | 三重 |
| 1 | 2 |  | 二重一平 |
| 1 | 3 |  | 三平 |
| 2 | 2 | 相关 | 二重一交 |
| 2 | 3 | 相关 | 二平一交 |
| 2 | 2 | 无关 | 三交一线 |
| 2 | 3 | 无关 | 三交三线 |
| 3 | 3 |  | 三交一点 |
|  |  |  |  |

5. 空间曲面：$F(x,y,z)=0$ 或 $z=F(x,y)$
6. 空间曲线：
   * 一般方程：$\begin{cases}
      F(x,y,z)=0 \\
      G(x,y,z)=0 \\
   \end{cases}$，两曲面相交于一条曲线
   * 参数方程：$\begin{cases}
      x=x(t) \\
      y=y(t) \\
      z=z(t) \\
   \end{cases}$
7. 常见二次曲面（联系线代的二次型的正负惯性指数）：
   * 椭球面：$\frac{x^2}{a^2}+\frac{y^2}{b^2}+\frac{z^2}{c^2}=1$，（三正）
   * 单叶双曲面：$\frac{x^2}{a^2}+\frac{y^2}{b^2}-\frac{z^2}{c^2}=1$，（两正一负）
   * 双叶双曲面：$\frac{x^2}{a^2}+\frac{y^2}{b^2}-\frac{z^2}{c^2}=-1$，（一正两负）
   * 椭圆抛物面：$\frac{x^2}{a^2}+\frac{y^2}{b^2}=\pm z$，（少见）
   * 双曲抛物面：$\frac{x^2}{a^2}-\frac{y^2}{b^2}=\pm z$，（少见）
8. 柱面：平行于定直线并沿定曲线 $c$ 移动的直线 $l$ 形成的轨迹为柱面，其中 $c$ 为准线，$l$ 为母线
   * 圆柱面：准线 $c$ 为 $x0y$ 上的圆 $\begin{cases}
      f(x,y) = 0 \\
      z=0
   \end{cases}$，过 $c$ 上一点且平行于 $z$ 轴的母线 $l$ 绕 $z$ 轴一周形成的轨迹为圆柱面 $f(x,y)=0$。（也可以是 $c$ 沿 $z$ 轴上下移动形成的轨迹）
9. 旋转曲面：在 $y0z$ 坐标面上的曲线 $\begin{cases}
      f(y,z)=0 \\
      x=0 \\
   \end{cases}$，绕 $z$ 轴旋转一周得到曲面 $f(\pm\sqrt{x^2+y^2},z)$，绕 $y$ 轴旋转一周得到曲面 $f(y,\pm\sqrt{x^2+z^2})$
10. 空间曲线 $L=\begin{cases}
   F(x,y,z)=0 \\
   G(x,y,z)=0 \\
\end{cases}$ 在坐标面上的投影曲线：
    * 消去 $z$ 后得到 $L$ 在 $x0y$ 上的投影曲线 $\begin{cases}
      H_1(x,y)=0 \\
      z=0 \\
   \end{cases}$，其中 $H_1(x,y)=0$ 为投影柱面
    * 消去 $y$ 后得到 $L$ 在 $x0z$ 上的投影曲线 $\begin{cases}
      H_2(x,z)=0 \\
      y=0 \\
   \end{cases}$，其中 $H_2(x,z)=0$ 为投影柱面
    * 消去 $x$ 后得到 $L$ 在 $y0z$ 上的投影曲线 $\begin{cases}
      H_3(y,z)=0 \\
      x=0 \\
   \end{cases}$，其中 $H_3(y,z)=0$ 为投影柱面

## 8.3. 多元函数的几何应用
1. 空间曲线的切线与法平面
   * 由参数方程表示的曲线：$\begin{cases}
      x=x(t) \\
      y=y(t) \\
      z=z(t) \\
   \end{cases}$，当 $t=t_0$ 时，在点 $(x_0,y_0,z_0)$：
      1. 切线方程：$\frac{x-x_0}{x'(t_0)}=\frac{y-y_0}{y'(t_0)}=\frac{z-z_0}{z'(t_0)}$
      2. 法平面：$x'(t)(x-x_0)+y'(t)(y-y_0)+z'(t)(z-z_0)=0$
   * 由两平面相交表示的曲线：$\begin{cases}
      F(x,y,z)=0 \\
      G(x,y,z)=0 \\
   \end{cases}$：
      1. 平面F的法向量：$\overrightarrow{n_1}=(F_x',F_y',F_z')$
      2. 平面G的法向量：$\overrightarrow{n_2}=(G_x',G_y',G_z')$
      3. 曲线在点 $(x_0,y_0,z_0)$ 的切向量$=\begin{vmatrix}
         \overrightarrow{i} & \overrightarrow{j} & \overrightarrow{k} \\
         F_x' & F_y' & F_z' \\
         G_x' & G_y' & G_z' \\
      \end{vmatrix}_{(x_0,y_0,z_0)}$
2. 空间曲面的切平面与法线   
   * 曲面方程为隐函数 $F(x,y,z)=0$：
      1. 曲面任意点的法向量 $=\pm(F_x',F_y',F_z')$，$\pm$ 表示两个不同的方向
      2. 曲面在点 $(x_0,y_0,z_0)$ 的：
         * 法向量 $=(F_x'(x_0,y_0,z_0),F_y'(x_0,y_0,z_0),F_z'(x_0,y_0,z_0))=(A,B,C)$
         * 切平面 $A(x-x_0)+B(y-y_0)+C(z-z_0)=0$
         * 法线：$\frac{x-x_0}{A}=\frac{y-y_0}{B}=\frac{z-z_0}{C}$
   * 曲面方程为显函数 $z=f(x,y)$：
      1. 曲面任意点的法向量 $=\pm(f_x',f_y',-1)$，$\pm$ 表示两个不同的方向
      2. 曲面在点 $(x_0,y_0,z_0),z_0=f(x_0,y_0)$ 的：
         * 法向量 $=(f_x'(x_0,y_0),f_y'(x_0,y_0),-1)=(A,B,-1)$
         * 切平面 $A(x-x_0)+B(y-y_0)-(z-z_0)=0$
         * 法线：$\frac{x-x_0}{A}=\frac{y-y_0}{B}=\frac{z-z_0}{-1}$

## 8.4. 方向导数与梯度
1. 方向导数的定义：$z=f(x,y)$ 在点 $(x,y)$ 沿某一方向 $\overrightarrow{l}$ 的方向导数为：
   * $\frac{\partial f}{\partial l}=\lim\limits_{(\Delta x,\Delta y)\to(0,0)}\frac{f(x+\Delta x,y+\Delta y)-f(x,y)}{\sqrt{\Delta x^2+\Delta y^2}}$
   * $\frac{\partial f}{\partial l}=\lim\limits_{t\to 0^+}\frac{f(x+t\cos\alpha,y+t\cos\beta)-f(x,y)}{t}$，$(\cos\alpha,\cos\beta)$ 为 $\overrightarrow{l}$ 的单位向量
2. 方向导数的常用求法：
   * 前提：若函数 $f(x,y,z) $ 在点 $(x_0,y_0,z_0)$ 可微，则函数在该点沿任一方向 $\overrightarrow{l}$ 的方向导数都存在
   1. 求偏导：$f_x'(x_0,y_0,z_0)=a$，$f_y'(x_0,y_0,z_0)=b$，$f_z'(x_0,y_0,z_0)=c$
   2. 将 $\overrightarrow{l}$ 单位化：$(A,B,C)$
   3. $\frac{\partial f}{\partial l}|_(x_0,y_0,z_0)=aA+bB+cC$
3. 梯度的定义：梯度是一个向量；某点的梯度是指该点的方向导数取得最大值的方向；导数值=梯度的模
4. 函数 $f(x,y,z)$ 在点 $(x_0,y_0,z_0)$ 的梯度的求法：
   1. 求偏导：$f_x'(x_0,y_0,z_0)=a$，$f_y'(x_0,y_0,z_0)=b$，$f_z'(x_0,y_0,z_0)=c$
   2. $\overrightarrow{grad}f(x_0,y_0)=a\overrightarrow{i}+b\overrightarrow{j}+c\overrightarrow{k}$，$\overrightarrow{i},\overrightarrow{j},\overrightarrow{k}$ 是 $x,y,z$ 轴的单位向量

## 8.5. 三重积分
1. 直角坐标
   * 积分空间 $\Omega$ 给出 $z_1(x,y)\le z\le z_2(x,y)$，先一后二投影法：$\iiint_\Omega f(x,y,z)dxdydz=\iint_D dxdy\int_{z_1(x,y)}^{z_2(x,y)}f(x,y,z)dz$
   * 积分空间 $\Omega$ 给出 $a\le z\le b$，先二后一切片法：$\iiint_\Omega f(x,y,z)dxdydz=\int_a^bdz\iint_D f(x,y,z)dxdy$
2. 柱面坐标：直角坐标与柱面坐标的转换 $\begin{cases}
   x=r\cos\theta \\
   y=r\sin\theta \\
   z=z \\
   dxdydz=rdrd\theta dz \\
\end{cases}$
3. 球面坐标：直角坐标与球面坐标的转换 $\begin{cases}
   x=r\sin\varphi\cos\theta \\
   y=r\sin\varphi\sin\theta \\
   z=r\cos\varphi \\
   dxdydz=r^2\sin\varphi drd\varphi d\theta \\
\end{cases}$
   * $\Omega：x^2+y^2+z^2\le r^2$，$\iiint_\Omega(x^2+y^2+z^2)dxdydz=\frac{4}{5}\pi r^5$
4. 三重积分有奇偶对称性、轮换对称性
5. ：
   * 当 $\iiint_VdV=V$
   * 当 $\rho(x,y,z)$ 表示空间几何体的体密度时：$m=\iiint_V\rho(x,y,z)dV$
   * 空间几何体的质心坐标：
      1. $\bar x=\frac{\iiint_Vx\rho(x,y,z)dV}{\iiint_V\rho(x,y,z)dV}$
      2. $\bar y=\frac{\iiint_Vy\rho(x,y,z)dV}{\iiint_V\rho(x,y,z)dV}$
      3. $\bar z=\frac{\iiint_Vz\rho(x,y,z)dV}{\iiint_V\rho(x,y,z)dV}$

## 8.6. 第一类曲线积分
>一代二换三计算  
1. 一代：将积分曲线代入被积函数，从而简化计算；（但要注意二重积分、三重积分不可以把积分区域边界方程代入被积函数）
2. 二换：
   * $L: y=y(x),a\le x\le b$，$\int_L f(x,y)ds=\int_a^bf(x,y(x))\sqrt{1+y'^2(x)}dx$
   * $L: x=x(y),c\le y\le d$，$\int_L f(x,y)ds=\int_c^df(x(y),y)\sqrt{1+x'^2(y)}dy$
   * $L: r=r(\theta),\alpha\le r\le \beta$，$\int_L f(x,y)ds=\int_\alpha^\beta f(r\cos\theta,r\sin\theta)\sqrt{r^2(\theta)+r'^2(\theta)}d\theta$
   * $L: \begin{cases} x=x(t) \\ y=y(t) \end{cases},\alpha\le t\le \beta$，$\int_L f(x,y)ds=\int_\alpha^\beta f(x(t),y(t))\sqrt{x'^2(t)+y'^2(t)}dt$
   * 上述公式可推广到空间曲线积分：$L: \begin{cases} x=x(t) \\ y=y(t) \\ z=z(t) \end{cases},\alpha\le t\le \beta$，$\int_L f(x,y,z)ds=\int_\alpha^\beta f(x(t),y(t),z(t))\sqrt{x'^2(t)+y'^2(t)+z'^2(t)}dt$
3. 第一类曲线积分有奇偶对称性、轮换对称性

## 8.7. 第二类曲线积分
1. 化为定积分（同样的一代二换三计算，但上下限不再按大小分，而是起点与终点）
   * $L: y=y(x),x起点a，终点b$，$\int_L Pdx+Qdy=\int_a^b[P(x,y(x))+Q(x,y(x))y'(x)]dx$
   * $L: x=x(y),y起点c，终点d$，$\int_L Pdx+Qdy=\int_c^d[P(x(y),y)x'(y)+Q(x(y),y)]dy$
   * $L: \begin{cases} x=x(t) \\ y=y(t) \end{cases},\alpha\le t\le \beta$，$\int_L Pdx+Qdy=\int_\alpha^\beta[P(x(t),y(t))x'(t)+Q(x(t),y(t))y'(t)]dt$
   * 注：
      1. 同样的一代二换三计算
      2. 上下限不再按大小分，而是起点与终点
      3. 二类曲线积分一般不用对称性化简，因为不再满足“偶倍奇零”
2. 格林公式
   * $\oint_LPdx+Qdy=\iint_D(\frac{\partial Q}{\partial x}-\frac{\partial P}{\partial y})dxdy$，区域 $D$ 是由分段光滑曲线 $L$ 围成的闭区间。
   * 公式成立的三个条件：
      1. 曲线 $L$ 封闭
      2. 正向，即逆时针（逆向时结果加负号即可）
      3. $P,Q,\frac{\partial Q}{\partial x},\frac{\partial P}{\partial y}$ 在 $D$ 内连续
   * 若 $L$ 不封闭，则添加一条辅助线 $l$ 使之封闭，则：$\oint_LPdx+Qdy=\oint_{L+l}Pdx+Qdy-\oint_lPdx+Qdy=\iint_D(\frac{\partial Q}{\partial x}-\frac{\partial P}{\partial y})dxdy-\oint_lPdx+Qdy$
   * 若不满足在区域 $D$ 上连续，通常是分母为零的点不连续：
      1. 先把曲线 $L$ 的方程代入曲线积分，看能否“去分母”。
      2. 挖点法，本质是拐弯绕过不连续的点；具体做法是在 $D$ 内作一条包含不连续点的、逆向的封闭曲线 $l$，$L,l$ 围成的区域为 $d$，那么：
         * $\oint_LPdx+Qdy=\oint_{L+l}Pdx+Qdy-\oint_lPdx+Qdy=\iint_d(\frac{\partial Q}{\partial x}-\frac{\partial P}{\partial y})-\oint_lPdx+Qdy$
         * 若 $\frac{\partial Q}{\partial x}=\frac{\partial P}{\partial y}$，则：$\oint_LPdx+Qdy=\oint_{l^-}Pdx+Qdy$，$l^-$ 表示 $l$ 的逆向：$\oint_l=-\oint_{l^-}$
         * 结论：任何一条包含不连续点的分段光滑封闭区线的积分均相等。利用这个结论解题：$\oint_L\frac{xdy-ydx}{c_1x^2+c_2y^2}$，$c_1>0,c_2>0,\frac{\partial Q}{\partial x}=\frac{\partial P}{\partial y}$：
            1. 当 $L$ 所围闭区间不包含分母为零的点 $(0,0)$，则 $\oint_L\frac{xdy-ydx}{c_1x^2+c_2y^2}=0$
            2. 当 $L$ 所围闭区间包含分母为零的点 $(0,0)$，则作曲线 $l: c_1x^2+c_2y^2=1$，代入曲线积分得 $\oint_l xdy-ydx=2\oint_l dxdy=\frac{2\pi}{\sqrt{c_1c_2}}$

## 8.8. 平面曲线积分与路径无关
* 设 $P,Q,\frac{\partial Q}{\partial x},\frac{\partial P}{\partial y}$ 在平面单连通区域 $D$ 上连续，则路径无关的六个等价条件：
   1. $\frac{\partial Q}{\partial x}=\frac{\partial P}{\partial y}$ 在 $D$ 内处处成立
   2. $D$ 内任意一条封闭曲线 $L$ 有 $\oint_LPdx+Qdy=0$
   3. $\oint_LPdx+Qdy=0$ 在 $D$ 内与路径无关，而只与 $L$ 的起点 $A$ 与终点 $B$ 有关，则该曲线积分可写为 $\int_A^BPdx+Qdy=U(x,y)|_A^B$，该等式也称为曲线积分的牛顿-莱布尼茨公式
   4. 在 $D$ 内存在某一可微的单值数量函数 $U=U(x,y)$，使 $Pdx+Qdy$ 是它的全微分，即有：$dU=Pdx+Qdy$
   5. 矢量函数 $\overrightarrow{A}=P\overrightarrow{i}+Q\overrightarrow{j}$ 为某一个单值数量函数 $U=U(x,y)$ 的梯度，即：$\overrightarrow{grad}U=A$
   6. $Pdx+Qdy=0$ 是全微分方程
* 求全微分的原函数
   1. 因曲线积分与路径无关，故选取平行于坐标轴的折线得原函数：
      * $U(x,y)=\int_{x_0}^xP(x,y_0)dx+\int_{y_0}^yQ(x,y)dy$
      * $U(x,y)=\int_{y_0}^yQ(x_0,y)dy+\int_{x_0}^xP(x,y)dx$
   2. ：
      * 先对 $\frac{\partial U}{\partial x}=P(x,y)$ 关于 $x$ 积分得：$U(x,y)=\int P(x,y)dx+\varphi(y)$
      * 再对上式两边关于 $y$ 求导：$\frac{\partial U}{\partial x}=Q(x,y)=\frac{\partial}{\partial y}\int P(x,y)dx+\varphi'(y)$
      * 求解这个 $\varphi$ 关于 $y$ 的一阶常微分方程得：$\varphi(y)=f(y)+C$
      * 故：$U(x,y)=\int P(x,y)dx+f(y)+C$
   3. 利用凑微分的方法
* 结论：曲线积分 $\oint_L\frac{(a_1x+a_2y)dx+(b_1x+b_2y)dy}{c_1x^2+c_2y^2}$，$c_1>0,c_2>0$，当 $a_2=-b_1,a_1c_2=c_1b_2$ 时，路径无关：
  1. 当 $L$ 所围区域不包含原点，曲线积分 $=0$
  2. 当 $L$ 所围区域包含原点，曲线积分 $=\frac{2b_1\pi}{\sqrt{c_1c_2}}$

## 8.9. 第一类曲面积分
1. 投影：根据积分曲面 $\Sigma$ 的表示形式，将其投影到某个坐标平面，通常是 $x0y$，表示出投影区域，比如 $D_{xy}$
2. 代替：若是投影到 $x0y$，则：$\iint_\Sigma f(x,y,z)ds=\iiint_{D_{xy}}f(x,y,z(x,y))\sqrt{1+z_x'^2+z_y'^2}dxdy$

>注：二重积分、三重积分、第一类曲线积分、第一类曲面积分都是数量函数的积分，有类似的质心坐标公式、对称性。

## 8.10. 第二类曲面积分
* 曲面的侧：其实就是指法向量的方向，包括：上侧、下侧、左侧、右侧、前侧、后侧、内侧、外侧。
* 当 $\{P,Q,R\}$ 为流速场的流速时，那么流量就等于：$\iint_\Sigma Pdydz+Qdxdz+Rdxdy$
* 计算第二类曲面积分的5个方法：
   1. 一代二换三定号
      * 一代：曲面 $\Sigma$ 的方程 $z=f(x,y)$ 代入被积函数。
      * 二换：确定曲面 $\Sigma$ 在 $x0y$ 面上的投影区域 $D_{xy}$
      * 三定号：曲面 $\Sigma$ 取上侧为正，取下侧为负
         * 若 $\Sigma$ 与 $x0y$ 垂直，则 $\iiint_\Sigma Rdxdy=0$
   2. 高斯公式：$\oint\oint_\Sigma Pdydz+Qdxdz+Rdxdy=\iiint_\Omega(\frac{\partial P}{\partial x}+\frac{\partial Q}{\partial y}+\frac{\partial R}{\partial z})dV$
      * 公式成立的三个条件：
         1. $\Sigma$ 为封闭曲面
         2. $\Sigma$ 是 $\Omega$ 的外侧
         3. $P,Q,R,\frac{\partial P}{\partial x},\frac{\partial Q}{\partial y},\frac{\partial R}{\partial z}$ 在 $\Omega$ 上连续
      * 若 $\Sigma$ 不封闭，可添辅助曲面 $\Sigma_1$，则 $\iint_\Sigma=\oiiint_{\Sigma+\Sigma_1}-\iint_{\Sigma_1}$
      * 若 $\Sigma$ 取外侧，则三重积分前加负号
      * 若 $P,Q,R,\frac{\partial P}{\partial x},\frac{\partial Q}{\partial y},\frac{\partial R}{\partial z}$ 在 $\Omega$ 上不连续，先看将曲面方程代入被积函数能否取消不连续点，若去不掉，则 $\Sigma$ 内作包含不连续点的封闭曲面 $\Sigma_1$，取内侧，那么 $\Sigma,\Sigma_1$ 形成的封闭曲面可用高斯公式，于是 $\oiint_\Sigma=\oiint_{\Sigma+\Sigma_1}-\oiint_{\Sigma_1}$
         * 技巧结论：任何一张包含不连续点在内的分段光滑闭曲面的积分均相等。
   3. 合一投影法（向量点积法）
      * $\Sigma: z=f(x,y)$，则：法向量 $(-f_x',-f_y',1)$，$\iint_\Sigma Pdydz+Qdxdz+Rdxdy=\iint_\Sigma(P,Q,R)\cdot(-f_x',-f_y',1)dxdy=\iint_{D_{xy}}(-Pf_x'-Qf_y'+R)dxdy$
      * $\Sigma: y=f(x,z)$，则：法向量 $(-f_x',1,-f_z')$，$\iint_\Sigma Pdydz+Qdxdz+Rdxdy=\iint_\Sigma(P,Q,R)\cdot(-f_x',1,-f_z')dxdz=\iint_{D_{xz}}(-Pf_x'+Q-Rf_z')dxdz$
      * $\Sigma: x=f(y,z)$，则：法向量 $(1,-f_y',-f_z')$，$\iint_\Sigma Pdydz+Qdxdz+Rdxdy=\iint_\Sigma(P,Q,R)\cdot(1,-f_y',-f_z')dxdz=\iint_{D_{yz}}(P-Qf_y'-Rf_z')dydz$
   4. 转化为第一类曲面积分：$\iint_\Sigma Pdydz+Qdxdz+Rdxdy=\iint_\Sigma(P\cos\alpha+Q\cos\beta+R\cos\gamma)ds$
      * 其中 $\cos\alpha,\cos\beta,\cos\gamma$ 是法向量的方向余弦，对法向量单位化即为 $(\cos\alpha,\cos\beta,\cos\gamma)$
   5. 对称性化简：与其他时候相反，此处为“奇倍偶零”。

## 8.11. 空间曲线积分

## 8.12. 多元函数积分学应用

## 8.13. 场论

## 8.14. 求质量、转动惯量及做功

