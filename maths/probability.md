# 1. 事件与概率
## 1.1. 事件关系

|事件|表示|含义|备注|
|:-|:-|:-|:-|
|包含|$A\subset B$|若 $A$ 发生则 $B$ 必发生|$A=B \iff A\subset B$ 且 $B\subset A$|
|和|$A\cup B$ 或 $A+B$|$A$ 发生或者 $B$ 发生（至少发生一个）|$A+B+C$ 表示 $A,B,C$ 至少发生一个|
|差|$A-B$ 或 $A\bar{B}$|$A$ 发生但 $B$ 不发生|$A-B-C$ 表示 $A$ 发生但 $B,C$ 均不发生<br>$A-B=A-AB$|
|积|$A\cap B$ 或 $AB$|$A$ 发生且 $B$ 发生（同时都发生）|$ABC$ 表示 $A,B,C$ 均发生|
|互斥（不相容）|$AB=\phi$|没有交集||
|对立（互逆）|$\begin{cases} AB=\phi \\ A+B=\Omega \end{cases}$ 记为 $\bar{A}=B$ 或 $A=\bar{B}$|没有交集且相加为全集|对立一定互斥，互斥不一定对立<br>$A\bar{B}=A-B=A-AB$|

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
1. 分布律：$P\{X=x_k\}=p_k$ $(k=1,2,...,n)$
   1. 非负性：$p_k \ge 0$
   2. 归一性：$\displaystyle\sum_{k=1}^np_k=1$
2. 分布函数：$F(x)=P\{X\le x\}=\displaystyle\sum_{x_i\le x}p_i$
   1. $F(x)=\begin{cases}
      0, \quad\quad\quad x<x_1 \\
      p_1, \quad\quad\quad x_1\le x<x_2 \\
      p_1+p_2, \quad\quad x_2\le x<x_3 \\
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
      * $P\{X=k\}=C_n^kp^k(1-p)^{n-k},\quad (k=0,1,...,n)$
   2. $0-1$ 分布
      * 即二项分布 $n=1$ 时的特例
      * $P\{X=k\}=p^k(1-p)^{1-k}, \quad (k=0,1)$
   3. 几何分布 $X\sim G(p)$
      * 表示在 $n$ 重伯努利试验中（每次试验成功率 $p$）第 $k$ 次才首次成功的概率
      * $P\{X=k\}=p(1-p)^{k-1}, \quad (k=0,1,...,n)$
   4. 超几何分布 $X\sim H(n,M,N)$
      * $N$ 件产品中含 $M$ 件次品，从中任取 $n$ 件（一次取 $n$ 件或一件件不放回的取 $n$ 件），则 $n$ 件中包含 $k$ 件次品的概率服从超几何分布
      * $P\{X=k\}=\frac{C_M^kC_{N-M}^{n-k}}{C_N^n},\quad (k=0,1,...,n)$
      * 注：若有放回地取 $n$ 件，则 $n$ 件中包含 $k$ 件次品的概率 $X\sim B(n,\frac{M}{N})$
   5. 泊松分布 $X\sim P(\lambda), \quad (\lambda>0)$
      * 在一段时间内电话总机接到的呼叫次数、候车的旅客数、保险索赔的次数等都服从泊松分布
      * $P\{X=k\}=\frac{\lambda^ke^{-\lambda}}{k!}, \quad (k=0,1,...,n)$
      * 泊松定理：若 $X\sim B(n,p)$，当 $n$ 充分大（$n\ge 20$）$p$ 充分小（$p\le 0.1$）时，二项分布近似泊松分布：
        * $C_n^kp^k(1-p)^{n-k}\approx \frac{\lambda^ke^{-\lambda}}{k!}, \quad (\lambda=np)$
## 2.3. 一维连续型随机变量
1. 存在 $F(x)=P\{X\le x\}=\int_{-\infty}^xf(t)dt$ 则称 $X$ 为连续型随机变量，$F(x)$ 为分布函数，$f(x)$ 为概率密度函数
2. 性质：
   1. 非负性：$f(x)\ge 0$
   2. 规范性：$\int_{-\infty}^{+\infty}f(x)dx=1$
   3. 对任意 $a<b$ 有 $P\{a<X\le b\}=\int_a^bf(x)dx$
   4. $F(x)$ 是连续函数
   5. 在 $f(x)$ 的连续点处存在 $F'(x)=f(x)$
   6. $P\{X=x_0\}=0$
3. 常见连续型分布
   1. 均匀分布 $X\sim U(a,b)$
      1. 对应几何概型
      2. $f(x)=\begin{cases} \frac{1}{b-a}, \quad a<x<b \\ 0, \quad\quad 其他 \end{cases}$
      3. $F(x)=\begin{cases} 0, \quad\quad x<a \\ \frac{x-a}{b-a}, \quad a\le x<b \\ 1, \quad\quad x\ge b \end{cases}$
   2. 指数分布 $X\sim E(\lambda),\quad (\lambda>0)$
      1. 寿命问题
      2. $f(x)=\begin{cases} \lambda e^{-\lambda x}, \quad x>0 \\ 0, \quad\quad x\le 0 \end{cases}$
      3. $F(x)=\begin{cases} 1-e^{-\lambda x}, \quad x>0 \\ 0, \quad\quad x\le 0 \end{cases}$
      4. 无记忆性：对任意 $s>0,t>0$ 有 $P\{X>s+t|X>s\}=P\{X>t\}$
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
         6. $P\{|X|\le a\}=2\varPhi(a)-1$
      3. 设 $\mu_\alpha$ 为标准正态分布的上 $\alpha$ 分位点，则：$P\{X>\mu_\alpha\}=\alpha$，即 $\varphi(x)$ 图形中 $x=\mu_\alpha$ 右边的面积为 $\alpha$
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
      1. 通过 $\begin{cases} 将 $x$ 的分段代入 $y=g(x)$ \\ 求 $y=g(x)$ 的最值 \end{cases}$ 找出自变量 $y$ 的分段点
      2. 根据分段点，分区间求 $F_Y(y)=P\{Y\le y\}=P\{g(X)\le y\}=\int_{g(x)\le y}f(x)dx$
      3. 最后 $f_Y(y)=F_Y^{'}(y)$

# 3. 二维随机变量
## 3.1. 联合分布函数
1. $F(x,y)=P\{X\le x,Y\le y\}$，表示随机事件 $\{X\le x\}$ 与 $\{Y\le y\}$ 同时发生的概率
2. 性质
   1. 非负性：对于任意 $x,y\in R$ 有 $0\le F(x,y) \le 1$
   2. 规范性：$\begin{cases} F(+\infty,+\infty)=\lim\limits_{(x,y)\to (+\infty,+\infty)}F(x,y)=1 \\ F(x,-\infty)=F(-\infty,y)=F(-\infty,-\infty)=0 \end{cases}$
   3. 单调不减性：$F(x,y)$ 关于 $x$ 和关于 $y$ 均单调不减
   4. 右连续性：$F(x,y)$ 关于 $x$ 和关于 $y$ 均右连续
   5. $P\{a<X\le b,c<Y\le d\}=F(a,c)+F(b,d)-F(a,d)-F(b,c)$
## 3.2. 边缘分布函数
* 二维随机变量关于 $X$ 和关于 $Y$ 的边缘分布函数：$\begin{cases} F_X(x)=P\{X\le x\}=P\{X\le x,Y<+\infty\}=F(x,+\infty) \\ F_Y(y)=P\{Y\le y\}=P\{X<+\infty,Y\le y\}=F(+\infty,y) \end{cases}$
* 独立性：若对于任意实数 $x,y$，有 $F(x,y)=F_X(x)F_Y(y)$，则称随机变量 $X$ 和 $Y$ 相互独立
## 3.3. 二维离散型随机变量
1. 联合分布律
   1. $P\{X=x_i,Y=y_j\}=p_{ij},\quad (i,j=1,2,...)$
   2. $p_{ij}\ge 0$
   3. $\displaystyle\sum_{i=1}^{+\infty}\sum_{j=1}^{+\infty}p_{ij}=1$
2. 边缘分布律
   1. $p_{i·}=p\{X=x_i\}=\displaystyle\sum_{j=1}^\infty p_{ij}$，表示联合分布律表中第 $i$ 行各数之和
   2. $p_{·j}=p\{Y=y_j\}=\displaystyle\sum_{i=1}^\infty p_{ij}$，表示联合分布律表中第 $j$ 列各数之和
   3. 边缘分布函数
      1. $F_X(x)=P\{X\le x\}=\displaystyle\sum_{x_i\le x} p_{i·}$
      2. $F_Y(y)=P\{Y\le y\}=\displaystyle\sum_{y_j\le y} p_{·j}$
3. 条件分布律
   1. $P\{X=x_i|Y=y_j\}=\frac{P\{X=x_i,Y=y_j\}}{P\{Y=y_j\}}=\frac{p_{ij}}{p_{·j}}$
   2. $P\{Y=y_j|X=x_i\}=\frac{P\{X=x_i,Y=y_j\}}{P\{X=x_i\}}=\frac{p_{ij}}{p_{i·}}$
4. 独立性
   1. $X,Y$ 独立 $\iff P\{X=x_i,Y=y_j\}=P\{X=x_i\}P\{Y=y_j\}$
   2. 独立，则联合分布律组成的矩阵成比例
## 3.4. 二维连续型随机变量
1. 联合概率密度
   1. $F(x,y)=\int_{-\infty}^x\int_{-\infty}^yf(u,v)dudv$
   2. 性质
      1. $f(x,y)\ge 0$
      2. $\int_{-\infty}^{+\infty}\int_{-\infty}^{+\infty}f(x,y)dxdy=1$
      3. 点 $(x,y)$ 落在任一区域 $D$ 内的概率是：$P\{(X,Y)\in D\}=\iint_D f(x,y)d\sigma$
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
   3. 性质：若 $(X,Y)$ 在区域 $G=\{(x,y)|a\le x\le b,c\le y\le d\}$ 服从均匀分布，则 $X,Y$ 相互独立，且分布服从区间 $[a,b],[c,d]$ 上的一维均匀分布
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
      5. 注：若 $X,Y$ 分布服从一维正态分布且相互独立，则 $(X,Y)$ 服从二维正态分布，且 $aX+bY\sim N(a\mu_1+b\mu_2,a^2\sigma_1^2,b^2\sigma_2^2)$；但若 $X,Y$ 分别服从一维正态分布但不独立，则 $aX+bY$ 不服从正态分布
## 3.5. 函数的分布
1. 离散型随机变量函数的分布
   1. 写出 $Z=g(X,Y)$ 的所有可能取值
   2. 求事件 $\{Z=k\}$ 发生的概率，若取值相同，则概率相加，要注意合并
2. 连续型随机变量函数的分布
   1. 一般方法（分布函数法）
      1. 函数 $Z=g(X,Y)$ 的分布函数 $F_Z(z)=P\{Z\le z\}=P\{g(X,Y)\le z\}=\iint_{g(x,y)\le z}f(x,y)dxdy$
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
1. 设 $X_1,X_2$ 相互独立，其分布函数分布为 $F_{X_1}(x_1),F_{X_2}(x_2)$，求 $M=\max\{X_1,X_2\},N=\min\{X_1,X_2\}$
2. $F_M(z)=P\{\max\{X_1,X_2\}\le z\}=P\{X_1\le z,X_2\le z\}=P\{X_1\le z\}P\{X_2\le z\}=F_{X_1}(z)F_{X_2}(z)$
3. $F_N(z)=P\{\min\{X_1,X_2\}\le z\}=1-P\{\min\{X_1,X_2\}>z\}=1-P\{X_1>z,X_2>z\}=1-P\{X_1>z\}P\{X_2>z\}=1-[1-F_{X_1}(z)][1-F_{X_2}(z)]$
4. 特别地，当 $X_1,X_2$ 独立且同分布，即 $X_1,X_2\sim F(x)$ 时：
   1. $F_M(z)=F^2(z)$
   2. $F_N(z)=1-[1-F(z)]^2$

