# 0. 常用高数知识
## 0.1. 常用公式
1. $\int_{-\infty}^{+\infty}e^{-\frac{x^2}{a}}dx=\sqrt{a\pi}$
   1. 除了积分的常规解法，还可以凑成符合 $N(0,\frac{1}{2})$ 的正态分布：
   2. $=\sqrt{a\pi}\int_{-\infty}^{+\infty}\frac{1}{\sqrt{a\pi}}e^{-\frac{x^2}{a}}dx=\sqrt{a\pi}$
2. $\int_{-\infty}^{+\infty}xe^{-{x^2}}dx=0$，（奇函数）
3. $\int_{-\infty}^{+\infty}x^2e^{-{x^2}}dx=\frac{\sqrt{\pi}}{2}$
   1. 除了积分的常规解法，还可以凑成符合 $N(0,\frac{1}{2})$ 的正态分布：
   2. $=\sqrt{\pi}\int_{-\infty}^{+\infty}x^2\frac{1}{\pi}e^{-{x^2}}dx=\frac{\sqrt{\pi}}{2}$
   3. 注：后面积分内为正态分布 $X\sim N(0,\frac{1}{2})$ 的 $E(X^2)=E^2(X)+D(X)=0+\frac{1}{2}=\frac{1}{2}$
4. $\int_0^{+\infty}x^ke^{-x}dx=k!$
## 0.2. 幂级数求和
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

# 1. 事件与概率
## 1.1. 事件关系

|事件|表示|含义|备注|
|:-|:-|:-|:-|
|包含|$A\subset B$|若 $A$ 发生则 $B$ 必发生|$A=B \iff A\subset B$ 且 $B\subset A$|
|和|$A\cup B$ 或 $A+B$|$A$ 发生或者 $B$ 发生（至少发生一个）|$A+B+C$ 表示 $A,B,C$ 至少发生一个|
|差|$A-B$ 或 $A\bar{B}$|$A$ 发生但 $B$ 不发生|$A-B-C$ 表示 $A$ 发生但 $B,C$ 均不发生<br>$A-B=A-AB$|
|积|$A\cap B$ 或 $AB$|$A$ 发生且 $B$ 发生（同时都发生）|$ABC$ 表示 $A,B,C$ 均发生|
|互斥（不相容）|$AB=\phi$|没有交集||
|对立（互逆）|$\begin{cases} AB=\phi\\ A+B=\Omega \end{cases}$ 记为 $\bar{A}=B$ 或 $A=\bar{B}$|没有交集且相加为全集|对立一定互斥，互斥不一定对立<br>$A\bar{B}=A-B=A-AB$|

## 1.2. 事件运算

1. 交换律：$A+B=B+A$，$AB=BA$
2. 结合律：$(A+B)+C=A+(B+C)$，$(AB)C=A(BC)$
3. 分配律：$(A+B)C=(AC)+(BC)$，$(AB)+C=(A+C)(B+C)$
4. 对偶律（德摩根律）：$\overline{A+B}=\bar{A}\bar{B}$，$\overline{AB}=\bar{A}+\bar{B}$
   * $\overline{A+B+C}=\bar{A}\bar{B}\bar{C}$，$\overline{ABC}=\bar{A}+\bar{B}+\bar{C}$

## 1.3. 概率
1. 表示：事件 $A$ 的概率表示为 $P(A)$，显然：
   1. $0\le P(A) \le 1$
   2. $P(\bar{A})=1-P(A)$
   3. $P(\Omega)=1$
   4. $P(\phi)=0$
   5. 若 $A\subset B$ 则 $P(A)\le P(B)$
   6. 若 $A_1,A_2,...,A_n$ 两两互斥，则 $P(A_1+A_2+...+A_n)=P(A_1)+P(A_2)+...+P(A_n)$
2. 在 $A$ 发生的条件下，$B$ 发生的条件概率 $P(B|A)=\frac{P(AB)}{P(A)}$，$P(A)>0$
3. 相互独立的 $A,B$ 满足：$P(AB)=P(A)+P(B)$
   * $\iff P(B)=P(B|A)$
   * $\iff P(B)=P(B|\bar{A})$
   * $\iff P(B|A)=P(B|\bar{A})$
   * $A,B$ 独立，则 $A$ 与 $\bar{B}$、$\bar{A}$ 与 $B$、$\bar{A}$ 与 $\bar{B}$ 均相互独立。
   * 多个事件 $A_1,A_2,...,A_n$ 相互独立，则必两两独立，反之不一定。
     * 相互独立：任意两个或多个事件相乘的概率等于事件各自概率的乘积
     * 两两独立：任意两个事件相乘的概率等于事件各自概率的乘积
   * 若 $P(A)>0,P(B)>0$，则 $A,B$ 互斥（不相容）和 $A,B$ 相互独立不能同时成立。
4. 若 $A_1,A_2,...,A_n$ 满足 $\begin{cases} 两两互斥 \\ A_1+A_2+...+A_n=\Omega \end{cases}$ 则称其为 $\Omega$ 的一个完备事件组。
   * 或称为 $\Omega$ 的一个划分
   * $\Omega$ 的划分不唯一
5. 五大公式
   1. 加法公式：$P(A+B)=P(A)+P(B)-P(AB)$
      * $P(A+B+C)=P(A)+P(B)+P(C)-P(AB)-P(AC)-P(BC)+P(ABC)$
      * $P(B+C|A)=P(B|A)+P(C|A)-P(BC|A)$
   2. 减法公式：$P(A-B)=P(A)-P(AB)$
      * $P(B-C|A)=P(B|A)-P(BC|A)$
   3. 乘法公式：$P(AB)=P(A)P(B|A)$
   4. 全概率公式：$P(B)=\displaystyle\sum_{i=1}^nP(A_i)P(B|A_i)$
   5. 贝叶斯（逆概率）公式：$P(A_j|B)=\frac{P(A_jB)}{P(B)}=\frac{P(A_j)P(B|A_j)}{\sum_{i=1}^nP(A_i)P(B|A_i)}$

> 注：所有运算中作为条件概率的事件 $A$，必须满足其概率 $P(A)>0$  

## 1.4. 三大概型
1. 古典概型
   1. 满足条件 $\begin{cases} 样本点的总数n_\Omega有限 \\ 每个样本点发生的概率相等 \end{cases}$
   2. $P(A)=\frac{n_A}{n_\Omega}=\frac{A含样本点个数}{\Omega 含样本点个数}$
2. 几何概型
   1. 满足条件 $\begin{cases} 样本空间\Omega 是某几何区域的几何度量L_\Omega（长度、面积、体积等）\\ 事件结果出现在区域内任何位置的可能性相等 \end{cases}$
   2. $P(A)=\frac{L_A}{L_\Omega}=\frac{区域A的几何度量}{区域\Omega 的几何度量}$
3. 伯努利试验
   1. 某试验只有两个结果 $A,\bar(A)$，则称为伯努利试验
   2. 把伯努利试验独立重复 $n$ 次，则称为 $n$ 重伯努利试验
   3. 设 $P(A)=p$，则 $n$ 重伯努利试验中 $A$ 发生的 $k$ 次的概率用二项概率公式计算：$C_n^kp^n(1-p)^{n-k}$

# 2. 一维随机变量
## 2.1. 分布函数
1. 性质：
   1. 非负性：$\infty0\le F(x)\le 1$
   2. 规范性：$\begin{cases} F(-\infty)=\lim\limits_{x\to -\infty}F(x)=0 \\ F(+\infty)=\lim\limits_{x\to +\infty}F(x)=1 \end{cases}$
   3. 单调不减：任意 $x_1<x_2$ 有 $F(x_1)\le F(x_2)$
   4. 右连续性：$F(x_0)=F(x_0+0)$
> 注：$F(x_0-0)=\lim\limits_{x\to x_0^-}F(x)$，$F(x_0+0)=\lim\limits_{x\to x_0^+}F(x)$
2. 运算，已知分布函数 $X\sim F(x)$ 则：
   1. $P\lbrace X\le a\rbrace=F(a)$
   2. $P\lbrace X>a\rbrace=1-F(a)$
   3. $P\lbrace X<a\rbrace=F(a-0)$
   4. $P\lbrace X\ge a\rbrace=1-F(a-0)$
   5. $P\lbrace X=a\rbrace=F(a)-F(a-0)$
   6. $P\lbrace a<X\le b\rbrace=F(b)-F(a)$
   7. $P\lbrace a\le X<b\rbrace=F(b-0)-F(a-0)$
   8. $P\lbrace a<X<b\rbrace=F(b-0)-F(a)$
   9. $P\lbrace a\le X\le b\rbrace=F(b)-F(a-0)$
## 2.2. 一维离散型随机变量
1. 分布律：$P\lbrace X=x_k\rbrace=p_k$ $(k=1,2,...,n)$
   1. 非负性：$p_k \ge 0$
   2. 归一性：$\displaystyle\sum_{k=1}^np_k=1$
2. 分布函数：$F(x)=P\lbrace X\le x\rbrace=\displaystyle\sum_{x_i\le x}p_i$
   1. $F(x)=\begin{cases}
      0, \quad\quad\quad x<x_1 \\
      p_1, \quad\quad\quad x_1\le x<x_2 \\
      p_1+p_2, \quad x_2\le x<x_3 \\
      ... \\
      1, \quad\quad\quad x\ge x_n \\
   \end{cases}$
   2. 特点：
      1. 为单位阶跃函数
      2. 分界点为随机变量 $X$ 的取值点
      3. 在分界点处产生跳跃，且跳跃高度为该点处取值的概率
3. 常见离散型分布
   1. 二项分布 $X\sim B(n,p)$
      * 表示在 $n$ 重伯努利试验中（每次试验成功率 $p$）成功 $k$ 次的概率
      * $P\lbrace X=k\rbrace=C_n^kp^k(1-p)^{n-k},\quad (k=0,1,...,n)$
   2. $0-1$ 分布
      * 即二项分布 $n=1$ 时的特例
      * $P\lbrace X=k\rbrace=p^k(1-p)^{1-k}, \quad (k=0,1)$
   3. 几何分布 $X\sim G(p)$
      * 表示在 $n$ 重伯努利试验中（每次试验成功率 $p$）第 $k$ 次才首次成功的概率
      * $P\lbrace X=k\rbrace=p(1-p)^{k-1}, \quad (k=0,1,...,n)$
   4. 超几何分布 $X\sim H(n,M,N)$
      * $N$ 件产品中含 $M$ 件次品，从中任取 $n$ 件（一次取 $n$ 件或一件件不放回的取 $n$ 件），则 $n$ 件中包含 $k$ 件次品的概率服从超几何分布
      * $P\lbrace X=k\rbrace=\frac{C_M^kC_{N-M}^{n-k}}{C_N^n},\quad (k=0,1,...,n)$
      * 注：若有放回地取 $n$ 件，则 $n$ 件中包含 $k$ 件次品的概率 $X\sim B(n,\frac{M}{N})$
   5. 泊松分布 $X\sim P(\lambda), \quad (\lambda>0)$
      * 在一段时间内电话总机接到的呼叫次数、候车的旅客数、保险索赔的次数等都服从泊松分布
      * $P\lbrace X=k\rbrace=\frac{\lambda^ke^{-\lambda}}{k!}, \quad (k=0,1,...,n)$
      * 泊松定理：若 $X\sim B(n,p)$，当 $n$ 充分大（$n\ge 20$）$p$ 充分小（$p\le 0.1$）时，二项分布近似泊松分布：
        * $C_n^kp^k(1-p)^{n-k}\approx \frac{\lambda^ke^{-\lambda}}{k!}, \quad (\lambda=np)$
## 2.3. 一维连续型随机变量
1. 存在 $F(x)=P\lbrace X\le x\rbrace=\int_{-\infty}^xf(t)dt$ 则称 $X$ 为连续型随机变量，$F(x)$ 为分布函数，$f(x)$ 为概率密度函数
2. 性质：
   1. 非负性：$f(x)\ge 0$
   2. 规范性：$\int_{-\infty}^{+\infty}f(x)dx=1$
   3. 对任意 $a<b$ 有 $P\lbrace a<X\le b\rbrace=\int_a^bf(x)dx$
   4. $F(x)$ 是连续函数
   5. 在 $f(x)$ 的连续点处存在 $F'(x)=f(x)$
   6. $P\lbrace X=x_0\rbrace=0$
3. 常见连续型分布
   1. 均匀分布 $X\sim U(a,b)$
      1. 对应几何概型
      2. $f(x)=\begin{cases} \frac{1}{b-a}, \quad a<x<b \\ 0, \quad\quad 其他 \end{cases}$
      3. $F(x)=\begin{cases} 0, \quad\quad x<a \\ \frac{x-a}{b-a}, \quad a\le x<b \\ 1, \quad\quad x\ge b \end{cases}$
   2. 指数分布 $X\sim E(\lambda),\quad (\lambda>0)$
      1. 寿命问题
      2. $f(x)=\begin{cases} \lambda e^{-\lambda x}, \quad x>0 \\ 0, \quad\quad x\le 0 \end{cases}$
      3. $F(x)=\begin{cases} 1-e^{-\lambda x}, \quad x>0 \\ 0, \quad\quad x\le 0 \end{cases}$
      4. 无记忆性：对任意 $s>0,t>0$ 有 $P\lbrace X>s+t|X>s\rbrace=P\lbrace X>t\rbrace$
         * 如果把 $X$ 理解为寿命，已知某人年龄为 $s$，则再活 $t$ 年的概率与 $s$ 无关
         * 离散型随机变量中，服从几何分布的具有无记忆性
   3. 一般正态分布 $X\sim N(\mu,\sigma^2),\quad (\sigma>0,\mu\in R)$
      1. $\mu$ 为位置参数，$\sigma$ 为形状参数
      2. $f(x)=\frac{1}{\sqrt{2\pi}\sigma}e^{-\frac{(x-\mu)^2}{2\sigma^2}},\quad (x\in R)$
   4. 标准正态分布 $X\sim N(0,1)$
      1. $\mu=0,\sigma=1$ 的正态分布即为标准正态分布
      2. 特别的，标准正态分布的密度函数用 $\varphi(x)$ 表示，分布函数用 $\varPhi(x)$ 表示
         1. $\varphi=\frac{1}{\sqrt{2\pi}}e^{-\frac{x^2}{2}}$
         2. $\varphi(-x)=\varphi(x)$
         3. $\varPhi(x_0)$ 题目可能会给出，不给出也可以认为是一个已知数
         4. $\varPhi(0)=\frac{1}{2}$
         5. $\varPhi(-x)=1-\varPhi(x)$
         6. $P\lbrace |X|\le a\rbrace=2\varPhi(a)-1$
      3. 设 $\mu_\alpha$ 为标准正态分布的上 $\alpha$ 分位点，则：$P\lbrace X>\mu_\alpha\rbrace=\alpha$，即 $\varphi(x)$ 图形中 $x=\mu_\alpha$ 右边的面积为 $\alpha$
      4. 一般正态分布 $X\sim N(\mu,\sigma^2)$ 可通过线性变换转化为标准正态分布 $Z=\frac{X-\mu}{\sigma}\sim N(0,1)$
## 2.4. 函数的分布
1. 离散型随机变量的函数 $Y=g(X)$ 的分布，需要通过函数得出 $Y$ 的取值，然取值相同则概率相加
   * 例 $\begin{cases} Y_1=g(X_1) \\ Y_2=g(X_2)=g(X_3) \end{cases}\implies \begin{cases} p_{Y_1}=p_{X_1} \\ p_{Y_2}=p_{X_2}+p_{X_3} \end{cases}$
2. 连续型随机变量的函数的概率密度
   1. 已知 $X\sim f_X(x)$ $Y=g(X)$ 求 $f_Y(x)$
   2. 方法一（公式法）
      1. 条件：$g(x)$ 为连续可导严格单调的函数
      2. 求出 $g(x)$ 的反函数 $h(y)$
      3. 求出 $g(X)$ 的值域 $(\alpha,\beta)$
      4. 公式 $f_Y(y)=\begin{cases} f_x(h(y))|h'(y)|, \quad \alpha<y<\beta \\ 0, \quad\quad 其他 \end{cases}$
   3. 方法二（分布函数法）
      1. 通过 $\begin{cases} 将 x 的分段代入 y=g(x) \\ 求 y=g(x) 的最值 \end{cases}$ 找出自变量 $y$ 的分段点
      2. 根据分段点，分区间求 $F_Y(y)=P\lbrace Y\le y\rbrace=P\lbrace g(X)\le y\rbrace=\int_{g(x)\le y}f(x)dx$
      3. 最后 $f_Y(y)=F_Y^{'}(y)$

# 3. 二维随机变量
## 3.1. 联合分布函数
1. $F(x,y)=P\lbrace X\le x,Y\le y\rbrace$，表示随机事件 $\lbrace X\le x\rbrace$ 与 $\lbrace Y\le y\rbrace$ 同时发生的概率
2. 性质
   1. 非负性：对于任意 $x,y\in R$ 有 $0\le F(x,y) \le 1$
   2. 规范性：$\begin{cases} F(+\infty,+\infty)=\lim\limits_{(x,y)\to (+\infty,+\infty)}F(x,y)=1 \\ F(x,-\infty)=F(-\infty,y)=F(-\infty,-\infty)=0 \end{cases}$
   3. 单调不减性：$F(x,y)$ 关于 $x$ 和关于 $y$ 均单调不减
   4. 右连续性：$F(x,y)$ 关于 $x$ 和关于 $y$ 均右连续
   5. $P\lbrace a<X\le b,c<Y\le d\rbrace=F(a,c)+F(b,d)-F(a,d)-F(b,c)$
## 3.2. 边缘分布函数
* 二维随机变量关于 $X$ 和关于 $Y$ 的边缘分布函数：$\begin{cases} F_X(x)=P\lbrace X\le x\rbrace=P\lbrace X\le x,Y<+\infty\rbrace=F(x,+\infty) \\ F_Y(y)=P\lbrace Y\le y\rbrace=P\lbrace X<+\infty,Y\le y\rbrace=F(+\infty,y) \end{cases}$
* 独立性：若对于任意实数 $x,y$，有 $F(x,y)=F_X(x)F_Y(y)$，则称随机变量 $X$ 和 $Y$ 相互独立
## 3.3. 二维离散型随机变量
1. 联合分布律
   1. $P\lbrace X=x_i,Y=y_j\rbrace=p_{ij},\quad (i,j=1,2,...)$
   2. $p_{ij}\ge 0$
   3. $\displaystyle\sum_{i=1}^{+\infty}\sum_{j=1}^{+\infty}p_{ij}=1$
2. 边缘分布律
   1. $p_{i·}=p\lbrace X=x_i\rbrace=\displaystyle\sum_{j=1}^\infty p_{ij}$，表示联合分布律表中第 $i$ 行各数之和
   2. $p_{·j}=p\lbrace Y=y_j\rbrace=\displaystyle\sum_{i=1}^\infty p_{ij}$，表示联合分布律表中第 $j$ 列各数之和
   3. 边缘分布函数
      1. $F_X(x)=P\lbrace X\le x\rbrace=\displaystyle\sum_{x_i\le x} p_{i·}$
      2. $F_Y(y)=P\lbrace Y\le y\rbrace=\displaystyle\sum_{y_j\le y} p_{·j}$
3. 条件分布律
   1. $P\lbrace X=x_i|Y=y_j\rbrace=\frac{P\lbrace X=x_i,Y=y_j\rbrace}{P\lbrace Y=y_j\rbrace}=\frac{p_{ij}}{p_{·j}}$
   2. $P\lbrace Y=y_j|X=x_i\rbrace=\frac{P\lbrace X=x_i,Y=y_j\rbrace}{P\lbrace X=x_i\rbrace}=\frac{p_{ij}}{p_{i·}}$
4. 独立性
   1. $X,Y$ 独立 $\iff P\lbrace X=x_i,Y=y_j\rbrace=P\lbrace X=x_i\rbrace P\lbrace Y=y_j\rbrace$
   2. 独立，则联合分布律组成的矩阵成比例
## 3.4. 二维连续型随机变量
1. 联合概率密度
   1. $F(x,y)=\int_{-\infty}^x\int_{-\infty}^yf(u,v)dudv$
   2. 性质
      1. $f(x,y)\ge 0$
      2. $\int_{-\infty}^{+\infty}\int_{-\infty}^{+\infty}f(x,y)dxdy=1$
      3. 点 $(x,y)$ 落在任一区域 $D$ 内的概率是：$P\lbrace (X,Y)\in D\rbrace=\iint_D f(x,y)d\sigma$
      4. 若 $f(x,y)$ 在点 $(x,y)$ 处连续，则有 $f(x,y)=\frac{\partial^2 F(x,y)}{\partial x\partial y}$
2. 边缘概率密度
   1. $f_X(x)=\int_{-\infty}^{+\infty}f(x,y)dy$
   2. $f_Y(y)=\int_{-\infty}^{+\infty}f(x,y)dx$
3. 条件概率密度
   1. $f_{X|Y}(x|y)=\frac{f(x,y)}{f_Y(y)}$
   2. $f_{Y|X}(y|x)=\frac{f(x,y)}{f_X(x)}$
4. 独立性
   1. $X,Y$ 相互独立 $\iff f(x,y)=f_X(x)f_Y(y)$
5. 二维均匀分布
   1. $f(x,y)=\begin{cases} \frac{1}{S_G}, \quad (x,y)\in G \\ 0, \quad\quad (x,y)\notin G \end{cases}$
   2. 其中 $S_G$ 是区域 $G$ 的面积
   3. 性质：若 $(X,Y)$ 在区域 $G=\lbrace (x,y)|a\le x\le b,c\le y\le d\rbrace$ 服从均匀分布，则 $X,Y$ 相互独立，且分布服从区间 $[a,b],[c,d]$ 上的一维均匀分布
6. 二维正态分布
   1. $f(x,y)=\frac{1}{2\pi\sigma_1\sigma_2\sqrt{1-\rho^2}}e^{\frac{-1}{2(1-\rho^2)}[\frac{(x-\mu_1)^2}{\sigma_1^2}+\frac{(y-\mu_2)^2}{\sigma_2^2}-\frac{2\rho(x-\mu_1)(y-\mu_2)}{\sigma_1\sigma_2}]}$
   2. 其中：$x,y\in R$，$\mu_1,\mu_2,\sigma_1,\sigma_2>0$，$-1<\rho<1$
   3. 记作：$(X,Y)\sim N(\mu_1,\mu_2;\sigma_1^2,\sigma_2^2;\rho)$，拥有性质：
      1. $X\sim N(\mu_1,\sigma_1^2)$，$X\sim N(\mu_2,\sigma_2^2)$
      2. $X,Y$ 独立 $\iff \rho=0$
      3. $X,Y$ 的非零线性组合仍服从正态分布，且
         1. 当 $X,Y$ 独立，$k_1X+k_2Y\sim N(k_1\mu_1+k_2\mu_2,k_1^2\sigma_1^2+k_2^2\sigma_2^2)$
         2. 当 $X,Y$ 不独立，$k_1X+k_2Y\sim N(k_1\mu_1+k_2\mu_2,k_1^2\sigma_1^2+k_2^2\sigma_2^2+2k_1k_2\rho\sigma_1\sigma_2)$
      4. $X_1,Y_1$ 是 $X,Y$ 的线性函数，则 $(X_1,Y_1)$ 也服从二维正态分布
         1. 线性函数，即可逆线性变换：$(X_1,Y_1)=(X,Y)\begin{pmatrix} a & b \\ c & d \end{pmatrix}$，其中 $\begin{vmatrix} a & b \\ c & d \end{vmatrix}\ne 0$
      5. 注：若 $X,Y$ 分布服从一维正态分布且相互独立，则 $(X,Y)$ 服从二维正态分布，且 $aX+bY\sim N(a\mu_1+b\mu_2,a^2\sigma_1^2,b^2\sigma_2^2)$；但若 $X,Y$ 分别服从一维正态分布但不独立，则 $aX+bY$ 不服从正态分布
## 3.5. 函数的分布
1. 离散型随机变量函数的分布
   1. 写出 $Z=g(X,Y)$ 的所有可能取值
   2. 求事件 $\lbrace Z=k\rbrace$ 发生的概率，若取值相同，则概率相加，要注意合并
2. 连续型随机变量函数的分布
   1. 一般方法（分布函数法）
      1. 函数 $Z=g(X,Y)$ 的分布函数 $F_Z(z)=P\lbrace Z\le z\rbrace=P\lbrace g(X,Y)\le z\rbrace=\iint_{g(x,y)\le z}f(x,y)dxdy$
   2. 四则运算公式法
      1. $Z=X+Y$
         1. $f_Z(z)=\int_{-\infty}^{+\infty}f(x,z-x)dx$
         2. $f_Z(z)=\int_{-\infty}^{+\infty}f(z-y,y)dy$
         3. 当 $X,Y$ 独立，卷积公式：
            1. $f_Z(z)=\int_{-\infty}^{+\infty}f_X(x)f_Y(z-x)dx$
            2. $f_Z(z)=\int_{-\infty}^{+\infty}f_X(z-y)f_Y(y)dx$
      2. $Z=aX+bY,\quad (a,b\ne 0)$
         1. $f_Z(z)=\int_{-\infty}^{+\infty}\frac{1}{|b|}f(x,\frac{z-ax}{b})dx$
         2. $f_Z(z)=\int_{-\infty}^{+\infty}\frac{1}{|a|}f(\frac{z-by}{a},y)dy$
      3. $Z=XY$
         1. $f_Z(z)=\int_{-\infty}^{+\infty}\frac{1}{|x|}f(x,\frac{z}{x})dx$
         2. $f_Z(z)=\int_{-\infty}^{+\infty}\frac{1}{|y|}f(\frac{z}{y},y)dy$
      4. $Z=\frac{X}{Y}$
         1. $f_Z(z)=\int_{-\infty}^{+\infty}|x|f(x,xz)dx$
      5. 【注】步骤：
         1. 根据公式写出被积函数
         2. 画出被积函数的非零区域
         3. 讨论自变量 $z$ 的范围确定积分变量的上下限，定限方法与二重积分相同，最后求出积分
3. 离散与连续混合型随机变量函数的分布
   1. 分布函数法：运用全概率公式，将离散型随机变量的所有取值作为完备事件组
## 3.6. 最值分布
1. 设 $X_1,X_2$ 相互独立，其分布函数分布为 $F_{X_1}(x_1),F_{X_2}(x_2)$，求 $M=\max\lbrace X_1,X_2\rbrace,N=\min\lbrace X_1,X_2\rbrace$
2. $F_M(z)=P\lbrace \max\lbrace X_1,X_2\rbrace\le z\rbrace=P\lbrace X_1\le z,X_2\le z\rbrace=P\lbrace X_1\le z\rbrace P\lbrace X_2\le z\rbrace=F_{X_1}(z)F_{X_2}(z)$
3. $F_N(z)=P\lbrace \min\lbrace X_1,X_2\rbrace\le z\rbrace=1-P\lbrace \min\lbrace X_1,X_2\rbrace >z\rbrace=1-P\lbrace X_1>z,X_2>z\rbrace=1-P\lbrace X_1>z\rbrace P\lbrace X_2>z\rbrace=1-[1-F_{X_1}(z)][1-F_{X_2}(z)]$
4. 特别地，当 $X_1,X_2$ 独立且同分布，即 $X_1,X_2\sim F(x)$ 时：
   1. $F_M(z)=F^2(z)$
   2. $F_N(z)=1-[1-F(z)]^2$

# 4. 随机变量的数字特征
## 4.1. 数学期望
1. 离散型随机变量 $X$ 的分布律为 $P\lbrace X=x_k \rbrace =p_k$，则其数学期望 $E(X)=\displaystyle\sum_{k=1}^\infty x_kp_k$
2. 连续型随机变量 $X$ 的概率密度为 $f(x)$，则其数学期望 $E(X)=\int_{-\infty}^{+\infty}xf(x)dx$
3. 注：数学期望存在的前提，离散型要求无穷级数绝对收敛，连续型要求广义积分绝对收敛。
4. 数学期望的性质
   1. $E(C)=C$
   2. $E(CX)=CE(X)$
   3. $E(X+C)=E(X)+C$
   4. $E(aX+b)=aE(X)+b$
   5. $E(X\pm Y)=E(X)\pm E(Y)$
   6. 若 $X,Y$ 相互独立，则 $E(XY)=E(X)E(Y)$
## 4.2. 方差
1. $D(X)=E\lbrace [X-E(X)]^2 \rbrace =E(X^2)-E^2(X)$
   1. 显然有 $D(X)\ge 0$，$\sqrt{D(X)}$ 称为 $X$ 的标准差（或均方差）
2. 方差的性质
   1. $D(C)=0$（注：$D(X)=0$ 不能得出 $X$ 为常数的结论）
   2. $D(CX)=C^2D(X)$
   3. $D(X+C)=D(X)$
   4. $D(aX+b)=a^2D(X)$
   5. $D(X\pm Y)=D(X)+D(Y)\pm 2[E(XY)-E(X)E(Y)]$
      1. $cov(X,Y)=E(XY)-E(X)E(Y)$
   6. 若 $X,Y$ 相互独立，则 $D(X\pm Y)=D(X)+D(Y)$
      1. 独立时，$E(XY)=E(X)E(Y)$
      2. 独立时可拓展为：$D(aX\pm bY)=a^2D(X)+b^2D(Y)$
      3. 不独立时，$D(aX\pm bY)=a^2D(X)+b^2D(Y)\pm 2abcov(X,Y)$
## 4.3. 函数的数学期望
1. 一维离散：设 $X$ 的分布律 $P\lbrace X=x_i\rbrace =p_i$，函数 $Y=g(x)$，则 $E(Y)=\displaystyle\sum_I g(x_i)P\lbrace X=x_i \rbrace$
2. 一维连续：设 $X$ 的概率密度 $f(x)$，函数 $Y=g(x)$，则 $E(Y)=\int_{-\infty}^{+\infty}g(x)f(x)dx$
3. 二维离散：设 $Z=g(X,Y)$，先求 $Z$ 的分布律，再求 $Z$ 的期望
4. 二维连续：设 $(X,Y)$ 的概率密度为 $f(x,y)$，且 $Z=g(X,Y)$ 则：
   1. $E(x)=\int_{-\infty}^{+\infty}xf(x,y)dxdy$
   2. $E(Y)=\int_{-\infty}^{+\infty}yf(x,y)dxdy$
   3. $E(Z)=\int_{-\infty}^{+\infty}g(x,y)f(x,y)dxdy$
   4. $D(X)=E(X^2)-E^2(X)=\int_{-\infty}^{+\infty}x^2f(x,y)dxdy-[\int_{-\infty}^{+\infty}xf(x,y)dxdy]^2$
   5. $D(Y)=E(Y^2)-E^2(Y)=\int_{-\infty}^{+\infty}y^2f(x,y)dxdy-[\int_{-\infty}^{+\infty}yf(x,y)dxdy]^2$
## 4.4. 常见分布的期望与方差

|分布|分布律或概率密度|期望|方差|
|:-:|:-|:-:|:-:|
|$(0-1)$ 分布|$P\lbrace X=k \rbrace =p^k(1-p)^{1-k},\quad (k=0,1)$|$p$|$p(1-p)$|
|二项分布|$P\lbrace X=k \rbrace =C_n^kp^k(1-p)^{n-k},\quad (k=0,1,...,n)$|$np$|$np(1-p)$|
|几何分布|$P\lbrace X=k\rbrace =p(1-p)^{1-k},\quad (k=1,2,...)$|$\frac{1}{p}$|$\frac{1-p}{p^2}$|
|泊松分布|$P\lbrace X=k \rbrace =\frac{\lambda^ke^{-\lambda}}{k!},\quad (\lambda>0,k=0,1,...)$|$\lambda$|$\lambda$|
|指数分布|$f(x)=\begin{cases} \lambda e^{-\lambda x}, \quad x>0 \\ 0, \quad\quad x\le 0 \end{cases},\quad (\lambda >0)$|$\frac{1}{\lambda}$|$\frac{1}{\lambda^2}$|
|均匀分布|$f(x)=\begin{cases} \frac{1}{b-a}, \quad a<x<b \\ 0, \quad\quad 其他 \end{cases}$|$\frac{a+b}{2}$|$\frac{(b-a)^2}{12}$|
|正态分布|$f(X)=\frac{1}{\sqrt{2\pi}\sigma}e^{-\frac{(x-\mu)^2}{2\sigma^2}},\quad (\sigma >0,x\in R)$|$\mu$|$\sigma^2$|

## 4.5. 协方差
1. 矩
   1. 随机变量 $X$ 的 $k$ 次幂的数学期望称为 $X$ 的 $k$ 阶原点矩，记为 $\nu_k,\quad (k=1,2,...)$
      1. $\nu_k=E(X^k)=\begin{cases} \displaystyle\sum_i x_i^kp_i,\quad\quad X 为离散型 \\ \int_{-\infty}^{+\infty}x^kf(x)dx,\quad X 为连续型 \end{cases}$
   2. 随机变量 $X$ 与 $E(X)$ 差的 $k$ 次幂的数学期望称为 $X$ 的 $k$ 阶中心矩，记为 $\mu_k,\quad (k=2,3,...)$
      1. $\mu_k=E\lbrace [X-E(X)]^k\rbrace =\begin{cases} \displaystyle\sum_i (x_i-E(X))^kp_i,\quad X 为离散型 \\ \int_{-\infty}^{+\infty}(x-E(X))^kf(x)dx,\quad X 为连续型 \end{cases}$
   3. 随机变量 $X,Y$ 的混合原点矩：$\nu_{kl}=E(X^kY^l)$，（如果存在）
   4. 随机变量 $X,Y$ 的混合中心矩 $\mu_{kl}=E\lbrace [X-E(X)]^k[Y-E(Y)]^l\rbrace$，（如果存在）
2. 协方差
   1. $cov(X,Y)=E\lbrace [X-E(X)][Y-E(Y)]\rbrace=E(XY)-E(X)E(Y)$
   2. 性质：
      1. $cov(X,C)=0$
      2. $cov(X,X)=D(X)$
      3. $cov(X,Y)=cov(Y,X)$
      4. $cov(aX,bY)=abcov(X,Y)$
      5. $cov(X_1\pm X_2,Y)=cov(X_1,Y)\pm cov(X_2,Y)$
      6. 若 $X,Y$ 相互独立，则 $cov(X,Y)=0$
3. 相关系数
   1. $\rho_{XY}=\frac{cov(X,Y)}{\sqrt{D(X)}\sqrt{D(Y)}}=\frac{E(XY)-E(X)E(Y)}{\sqrt{D(X)}\sqrt{D(Y)}}$
      1. $\rho_{XX}=1$
      2. $-1\le \rho_{XY}\le 1$
      3. $\rho_{XY}=\rho_{YX}$
      4. 若 $X,Y$ 相互独立，则 $\rho_{XY}=0$
      6. $|\rho_{XY}|=1 \iff X,Y$ 以概率 $1$ 线性相关，即存在常数 $a,b$ 且 $a\ne 0$ 使 $P\lbrace X=aY+b\rbrace =1$
   2. 不相关的定义：若 $X,Y$ 的相关系数 $\rho_{XY}=0$，则称 $X,Y$ 不相关
      1. 独立一定不相关，但不相关不一定独立
      2. $X,Y$ 相互独立 $\implies X,Y$ 不相关 $\iff \rho_{XY}=0$
      3. 对于二维正态随机变量 $(X,Y)$
         1. $X,Y$ 相互独立 $\iff$ $X,Y$ 不相关 $\iff \rho=0$

   3. 常用结论
      1. $D(X\pm Y)=D(X)+D(Y)\pm 2cov(X,Y)$
         1. 当 $X,Y$ 相互独立时，$D(X\pm Y)=D(X)+D(Y)$
      2. $cov(X,Y)=0\iff \rho_{XY}=0\iff E(XY)=E(X)E(Y)\iff D(X\pm Y)=D(X)+D(Y)$

# 5. 大数定律与中心极限定理

|名称|条件|内容|备注|
|:-|:-|:-|:-|
|切比雪夫不等式|期望方差均存在|$P\lbrace |X-E(X)|\ge \epsilon\rbrace \le \frac{D(X)}{\epsilon^2}$|用来估计事件发生的可能性大小|
|伯努利大数定律|$n$ 重伯努利试验|$\lim\limits_{n\to\infty}P\lbrace |\frac{n_A}{n}-p|<\epsilon \rbrace=1$|
|切比雪夫大数定律|相互独立，期望方差均存在，方差有界|$\lim\limits_{n\to\infty}P(|\frac{1}{n}\displaystyle\sum_{i=1}^nX_i-\frac{1}{n}\displaystyle\sum_{i=1}^nE(X_i)|<\epsilon)=1$||
|辛钦大数定律|独立同分布，期望存在，$E(X_i)=\mu$|$\lim\limits_{n\to\infty}P(|\frac{1}{n}\displaystyle\sum_{i=1}^nX_i-\mu|<\epsilon)=1$|辛钦是期望相等时的切比雪夫大数定律|
|$L-L$ 中心极限定理|独立同分布，期望方差均存在，$E(X_i)=\mu,D(X_i)=\sigma^2$|$\lim\limits_{n\to\infty}P[\frac{\displaystyle\sum_{i=1}^nX_i-n\mu}{\sqrt{n}\sigma}\le x]=\frac{1}{\sqrt{2\pi}}\int_{-\infty}^xe^{-\frac{t^2}{2}}dt$|意思是，当 $n$ 足够大时，独立同分布的 $X_i$ 的和 $\displaystyle\sum_{i=1}^nX_i$ 近似服从正态分布 $N(n\mu,n\sigma^2)$|
|$D-L$ 中心极限定理|$X_i$ 服从二项分布 $B(n,p)$|$\lim\limits_{n\to\infty}P(\frac{X_n-np}{\sqrt{np(1-p)}}\le x)=\frac{1}{\sqrt{2\pi}}\int_{-\infty}^xe^{-\frac{t^2}{2}}dt$|意思是，当 $n$ 足够大时，二项分布会近似服从正态分布 $N(np,np(1-p))$|

# 6. 数理统计
## 6.1. 统计量
1. 总体与样本中的各项满足`独立同分布`
2. 统计量是一个随机变量，是样本组成的、不含未知参数的函数
3. 样本的数字特征
   1. 样本均值：$\bar{X}=\frac{1}{n}\sum_{i=1}^nX_i$
      1. $E(\bar{X})=E(X)$
      2. $D(\bar{X})=\frac{D(X)}{n}$
   2. 样本方差：$S^2=\frac{1}{n-1}\sum_{i=1}^n(X_i-\bar{X})^2$
      1. $S^2=\frac{1}{n-1}(\sum_{i=1}^nX_i^2-n\bar{X}^2)$
      2. $E(S^2)=D(X)$
   3. 样本 $k$ 阶原点矩：$A_k=\frac{1}{n}\sum_{i=1}^nX_i^k,\quad\quad (k=1,2,...)$
   4. 样本 $k$ 阶中心矩：$B_k=\frac{1}{n}\sum_{i=1}^n(X_i-\bar{X})^k,\quad (k=1,2,...)$
## 6.2. 三大抽样分布
1. $\chi^2$ 分布
   1. 独立同分布的 $X_i\sim N(0,1)$，则 $\chi^2=\sum_{i=1}^nX_i^2$ 服从自由度为 $n$ 的 $\chi^2$ 分布，记为 $\chi^2\sim\chi^2(n)$
      1. $E(\chi^2)=n$
      2. $D(\chi^2)=2n$
      3. 若 $X\sim N(0,1)$ 则 $X^2\sim \chi^2(1)$
   2. 可加性：若 $\chi_1^2\sim\chi^2(n_1),\chi_2^2\sim\chi^2(n_2)$ 且 $\chi_1^2,\chi_2^2$ 相互独立，则 $\chi_1^2+\chi_2^2\sim \chi^2(n_1+n_2)$
   3. 对于给定的 $0<\alpha<1$，称满足 $P\{\chi^2>\chi_\alpha^2(n)\}=\alpha$ 的点 $\chi_\alpha^2(n)$ 是 $\chi^2(n)$ 分布的上 $\alpha$ 分位点
2. $t$ 分布
   1. 设 $X\sim N(0,1),Y\sim\chi^2(n)$，$X,Y$ 独立，则 $T=\frac{X}{\sqrt{Y/n}}\sim t(n)$
   2. $t$ 分布的概率密度函数是形状类似正态分布的偶函数，当 $n$ 充分大时，$t(n)$ 近似 $N(0,1)$
   3. $E(T)=0$
   4. 上 $\alpha$ 分位点 $t_\alpha(n),(0<\alpha<1)$，则：
      1. $P\{T>t_\alpha(n)\}=\alpha$
      2. $t_{1-\alpha}(n)=-t_\alpha(n)$
      3. $P\{|T|>t_{\frac{\alpha}{2}}(n)\}=\alpha$
3. $F$ 分布
   1. 设 $X_1\sim\chi^2(n_1),X_2\sim\chi^2(n_2)$，$X_1,X_2$ 独立，则 $F=\frac{X_1/n_1}{X_2/n_2}\sim F(n_1,n_2)$
   2. $\frac{1}{F}=F(n_2,n_1)$
   3. 上 $\alpha$ 分位点 $F_\alpha(n_1,n_2),(0<\alpha<1)$，则：
      1. $P\{F>F_\alpha(n_1,n_2)\}=\alpha$
      2. $F_{1-\alpha}(n_1,n_2)=\frac{1}{F_\alpha(n_2,n_1)}$
## 6.3. 正态总体的抽样分布
1. 一个正态总体（重点），设 $X\sim N(\mu,\sigma^2),X_1,X_2,...,X_n$ 是来自总体 $X$ 的样本，样本均值 $\bar{X}$，样本方差 $S^2$
   1. $\bar{X}\sim N(\mu,\frac{\sigma^2}{n})$
      1. $U=\frac{\bar{X}-\mu}{\sigma/\sqrt{n}}\sim N(0,1)$
   2. $\bar{X},S^2$ 相互独立，且 $\chi^2=\frac{(n-1)S^2}{\sigma^2}\sim \chi^2(n-1)$
   3. $\chi^2=\frac{1}{\sigma^2}\sum_{i=1}^n(X_i-\mu)^2\sim\chi^2(n)$
   4. $T=\frac{\bar{X}-\mu}{S/\sqrt{n}}\sim t(n-1)$
2. 两个正态总体（非重点），设 $X\sim N(\mu_1,\sigma_1^2),Y\sim N(\mu_2,\sigma_2^2),X_i,Y_i$ 分别是来自 $X,Y$ 的样本，相互独立，样本均值 $\bar{X},\bar{Y}$，样本方差 $S_1^2,S_2^2$，则：
   1. $\bar{X}-\bar{Y}\sim N(\mu_1-\mu_2,\frac{\sigma_1^2}{n_1}+\frac{\sigma_2^2}{n_2})$
   2. $U=\frac{(\bar{X}-\bar{Y})-(\mu_1-\mu_2)}{\sqrt{\frac{\sigma_1^2}{n_1}+\frac{\sigma_2^2}{n_2}}}\sim N(0,1)$
   3. $F=\frac{S_1^2/\sigma_1^2}{S_2^2/\sigma^2}\sim F(n_1-1,n_2-1)$



