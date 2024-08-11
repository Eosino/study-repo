# 1. 行列式
## 1.1. 定义
1. 逆序数：在一个排列中，如果一个大的数排在小的数之前，则称这两个数逆序，一个排列的逆序总数称为逆序数，用 $\tau(j_1j_2...j_n)$ 表示。
    * 示例：$\tau(54321)=10$
    * 偶排列：逆序数为偶数。
    * 奇排列：逆序数为奇数。
2. $n$ 阶行列式：$\begin{vmatrix}
    a_{11} && a_{12} && \dots  && a_{1n} \\
    a_{21} && a_{22} && \dots  && a_{2n} \\
    \vdots && \vdots &&        && \vdots \\
    a_{n1} && a_{n2} && \dots  && a_{nn} \\
\end{vmatrix}=\displaystyle\sum_{j_1j_2...j_n}(-1)^{\tau(j_1j_2...j_n)}a_{1j_1}a_{2j_2}...a_{nj_n}$
    * 行列式为 $n!$ 项不同行不同列的元素乘积的代数和。
    * $2$ 阶行列式：$\begin{vmatrix}
        a && b \\
        c && d \\
    \end{vmatrix}=ad-bc$；几何意义：以其行向量为邻边的平行四边形的面积。
    * $3$ 阶行列式：$\begin{vmatrix}
        a_1 && a_2 && a_3 \\
        b_1 && b_2 && b_3 \\
        c_1 && c_2 && c_3 \\
    \end{vmatrix}=a_1b_2c_3+a_2b_3c_1+a_3b_1c_2-a_3b_2c_1-a_1b_3c_2-a_2b_1c_3$；几何意义：以其行向量为邻边的平行六面体的体积。

## 1.2. 性质
1. 转置相等
2. 换行（列）反号
3. 数乘乘行（列）
4. 拆分拆行（列）
5. 倍加不变
6. 零性质：
    * 两行（列）成比例，行列式为零
    * 两行（列）相等，行列式为零
    * 一行（列）为零，行列式为零

> 注1：在行列式的性质中，行、列的地位是平等的，具有相同的性质。  
> 注2：拆分拆行可推导：
>   1. $|A|=\displaystyle\prod_{i=1}^n\lambda_i$
>   2. $\displaystyle\sum_{i=1}^na_{ii}=\displaystyle\sum_{i=1}^n\lambda_i$

## 1.3. 计算
1. 展开：
    * 余子式：去掉 $a_{ij}$ 所在的行与列，剩下的行列式为 $a_{ij}$ 的余子式，记为 $M_{ij}$
    * 代数余子式：带有正负号 $(-1)^{i+j}$ 的余子式称为 $a_{ij}$ 的代数余子式，记为 $A_{ij}$，即：$A_{ij}=(-1)^{i+j}M_{ij}$
    * 行列式展开：$\displaystyle\sum_{i=1}^na_{ik}A_{jk}=\begin{cases}
        |A|, \quad i=j \\
        0, \quad i \ne j \\
    \end{cases}$
2. 三角行列式
    * $\begin{vmatrix}
        a_{11} && a_{12} && \dots  && a_{1n} \\
               && a_{22} && \dots  && a_{2n} \\
               &&        && \ddots && \vdots \\
               &&        &&        && a_{nn} \\
    \end{vmatrix}=\begin{vmatrix}
        a_{11} &&        &&        &&        \\
        a_{21} && a_{22} &&        &&        \\
        \vdots && \vdots && \ddots &&        \\
        a_{n1} && a_{n2} && \dots  && a_{nn} \\
    \end{vmatrix}=\begin{vmatrix}
        a_{11} &&        &&        &&        \\
               && a_{22} &&        &&        \\
               &&        && \ddots &&        \\
               &&        &&        && a_{nn} \\
    \end{vmatrix}=\displaystyle\prod_{i=1}^na_{ii}$
    * $\begin{vmatrix}
               &&        &&           && a_{1n} \\
               &&        && a_{2,n-1} &&        \\
               && \dots  &&           &&        \\
        a_{n1} &&        &&           &&        \\
    \end{vmatrix}=(-1)^{\frac{n(n-1)}{2}}a_{1n}a_{2,n-1}...a_{n1}$
3. 拉普拉斯展开式（分块矩阵求行列式）
    * $\begin{vmatrix} A && 0 \\ 0 && B \\ \end{vmatrix}=\begin{vmatrix} A && C \\ 0 && B \\ \end{vmatrix}=\begin{vmatrix} A && 0 \\ C && B \\ \end{vmatrix}=|A||B|$
    * $\begin{vmatrix} 0 && A \\ B && 0 \\ \end{vmatrix}=\begin{vmatrix} C && A \\ B && 0 \\ \end{vmatrix}=\begin{vmatrix} 0 && A \\ B && C \\ \end{vmatrix}=(-1)^{mn}|A||B|$，（$m,n$ 为 $A,B$ 的阶数）
4. 范德蒙行列式：$D_n=\begin{vmatrix}
    1 && 1 && \dots && 1 \\
    x_1 && x_2 && \dots && x_n \\
    x_1^2 && x_2^2 && \dots && x_n^2 \\
    \vdots && \vdots &&  && \vdots \\
    x_1^{n-1} && x_2^{n-1} && \dots && x_n^{n-1} \\
\end{vmatrix}=\displaystyle\prod_{1\le i\le j\le n}(x_j-x_i)$
5. 行和相同
   * 行和与列和都相等（第2~n列加到第1列，提取第1列公倍数使之全为1，第1行乘-1加到其他列，成三角行列式）：  
    $D_n=\begin{vmatrix}
        a && b && b && \dots && b \\
        b && a && b && \dots && b \\
        b && b && a && \dots && b \\
        \vdots && \vdots && \vdots &&  && \vdots \\
        b && b && b && \dots && a \\
    \end{vmatrix}=(a-b)^{n-1}[a+(n-1)b]$
    * 行和值相等（处理步骤同上）：$D_n=\begin{vmatrix}
        a_1+b && a_2 && a_3 && \dots && a_n \\
        a_1 && a_2+b && a_3 && \dots && a_n \\
        a_1 && a_2 && a_3+b && \dots && a_n \\
        \vdots && \vdots && \vdots && && \vdots \\
        a_1 && a_2 && a_3 && \dots && a_n+b \\
    \end{vmatrix}=b^{n-1}(b+\displaystyle\sum_{i=1}^na_i)$
6. 爪形行列式（第2列乘$-\frac{c_2}{a_2}$加到第1列使$c_2$变为0，第3列乘$-\frac{c_3}{a_3}$加到第1列使$c_3$变为0，依此类推即可化为三角行列式）：  
    $D_n=\begin{vmatrix}
        a_1 && b_2 && b_3 && \dots && b_n \\
        c_2 && a_2 && 0 && \dots && 0 \\
        c_3 && 0 && a_3 && \dots && 0 \\
        \vdots && \vdots && \vdots &&  && \vdots \\
        c_n && 0 && 0 && \dots && a_n \\
    \end{vmatrix}=\displaystyle\prod_{i=2}^na_i(a_1-\displaystyle\sum_{j=2}^n\frac{b_jc_j}{a_j})$
7. 用定义法更简单的行列式：$D_n=\begin{vmatrix}
        a_1 && b_1 && 0 && \dots && 0 \\
        0 && a_2 && b_2 && \dots && 0 \\
        0 && 0 && a_3 && \dots && 0 \\
        \vdots && \vdots && \vdots &&  && \vdots \\
        b_n && 0 && 0 && \dots && a_n \\
    \end{vmatrix}=\displaystyle\prod_{i=1}^na_i+(-1)^{n-1}\displaystyle\prod_{j=1}^nb_j$
8. 用差分方程求三对角行列式：$D_n=\begin{vmatrix}
        a && b &&   &&        &&   &&   \\
        c && a && b &&        &&   &&   \\
          && c && a && \ddots &&   &&   \\
          &&   && c && \ddots && b &&   \\
          &&   &&   && \ddots && a && b \\
          &&   &&   &&        && c && a \\
    \end{vmatrix}$：
    * 按第一列展开：$D_n = aD_{n-1}-bcD_{n-2}$，即求二阶差分方程 $D_n-aD_{n-1}+bcD_{n-2}=0$
    * 已知 $D_1=a$，$D_2=a^2-bc$
    * 特征方程：$\lambda^2-a\lambda+bc=0$（若 $a,b,c$ 是具体数，直接解即可）
        * 当 $\Delta>0$，解得 $\lambda_1\ne\lambda_2$，那么 $D_n=c_1\lambda_1^n+c_2\lambda_2^n$：
            * $\begin{cases}
                \lambda_1+\lambda_2=a \\
                \lambda_1\lambda_2=bc \\
                D_1=a \\
                D_2=a^2-bc \\
            \end{cases}\implies\begin{cases}
                c_1\lambda_1+c_2\lambda_2=\lambda_1+\lambda_2\\
                c_1\lambda_1^2+c_2\lambda_2^2=\lambda_1^2+\lambda_2^2+\lambda_1\lambda_2\\
            \end{cases}\implies\begin{cases}
                c_1=\frac{\lambda_1}{\lambda_1-\lambda_2} \\
                c_2=\frac{\lambda_2}{\lambda_2-\lambda_1} \\
            \end{cases}$
        * 当 $\Delta=0$，解得 $\lambda_1=\lambda_2=\lambda$，那么 $D_n=(c_1+c_2n)\lambda^n$
            * $\begin{cases}
                2\lambda=a \\
                \lambda^2=bc \\
                D_1=a \\
                D_2=a^2-bc \\
            \end{cases}\implies\begin{cases}
                (c_1+c_2)\lambda=2\lambda \\
                (c_1+2c_2)\lambda^2=3\lambda^2 \\
            \end{cases}\implies c_1=c_2=1$
    * 综上：$D_n=\begin{cases}
        \frac{\lambda_1^{n+1}-\lambda_2^{n+1}}{\lambda_1-\lambda_2}, \quad a^2-4bc>0 \\
        (n+1)\lambda^n, \quad a^2-4bc=0 \\
    \end{cases}$

## 1.4. 公式
1. 行列式的拆分性质：$|\alpha_1,\alpha_2+\alpha_3,\beta|=|\alpha_1,\alpha_2,\beta|+|\alpha_1,\alpha_3,\beta|$
2. 方阵：
    * $|kA|=k^n|A|$
    * $|AB|=|BA|=|A||B|$
    * $|A^{-1}|=|A|^{-1}$
    * $|AA^*|=|A^*A|=|A|E$
    * $A^*=|A|A^{-1}$
    * $|A^*|=|A|^{n-1}$
    * 若 $A$ 可逆，则 $A^* ,(A^* )^*$ 也可逆：
        * $(A^* )^* =|A^* |(A^* )^{-1}=|A|^{n-2}A$
        * $|(A^* )^*|=|A|^{(n-1)^2}$
    * 若 $\lambda_i$ 是方阵 $A=(a_{ij})$ 的特征值，则：
        * $|A|=\displaystyle\prod_{i=1}^n\lambda_i$
        * $\displaystyle\sum_{i=1}^na_{ii}=\displaystyle\sum_{i=1}^n\lambda_i$
    * 相似 $A\sim B$ 则 $|P^{-1}AP|=|B|\implies|A|=|B|$
    * 正交 $AA^T=A^TA=E\implies |A|=\pm1$
3. 行列式与矩阵的秩：
    * $|A|=0 \iff A不可逆 \iff r(A)<n$
    * $|A|\ne 0 \iff A可逆 \iff r(A)=n$
4. :
    * $aE-A不可逆 \iff |aE-A|=0 \iff a是A的一个特征值$
    * $aA+bE不可逆(a\ne 0) \iff |-\frac{b}{a}E-A|=0 \iff -\frac{b}{a}是A的一个特征值$
5. 讨论 $|A|=0$ 的问题，以三阶非零方阵 $A_{3x3}, |A|=0$ 为例：
    1. $\iff A$ 不可逆
    2. $\iff 1\le r(A)<3$
    3. $A=(\alpha_1,\alpha_2,\alpha_3)$，向量组 $\alpha_1,\alpha_2,\alpha_3$ 线性相关
    4. $\iff Ax=0$ 有非零解
    5. $\iff AA^* =0$，且 $A^*$ 的每一列为 $Ax=0$ 的解
    6. $\iff |A|=\lambda_1\lambda_2\lambda_3=0$，则矩阵 $A$ 至少有一个特征值为零
    7. $\iff$ 二次型正交化标准型为 $f=\lambda_1 y_1^2+\lambda_2 y_2^2$ 或 $f=\lambda_1 y_1^2$
6. 证明 $|A|=0$ 的方法：
    1. 转化为齐次线性方程组 $Ax=0$ 有非零解
    2. 利用 $A^{-1}$ 找矛盾来反证
    3. $r(A)<n$
    4. 列向量组线性相关
    5. $0$ 是 $A$ 的特征值
    6. $|A|=-|A|$

## 1.5. 技巧
1. $A=(\alpha_1,\alpha_2,\alpha_3)$，则 $B=(\alpha_1+\alpha_2+\alpha_3,\alpha_1+2\alpha_2+4\alpha_3,\alpha_1+3\alpha_2+9\alpha_3)=(\alpha_1,\alpha_2,\alpha_3)\begin{pmatrix} 1 && 1 && 1 \\ 1 && 2 && 3 \\ 1 && 4 && 9 \\ \end{pmatrix}$
2. $A$ 是三阶矩阵，$\alpha_1,\alpha_2,\alpha_3$ 线性无关，且 $A\alpha_1=\alpha_1+\alpha_2,A\alpha_2=\alpha_2+\alpha_3,A\alpha_3=\alpha_1+\alpha_3$，则：
    * 设 $A(\alpha_1,\alpha_2,\alpha_3)=(\alpha_1+\alpha_2,\alpha_2+\alpha_3,\alpha_1+\alpha_3)=(\alpha_1,\alpha_2,\alpha_3)\begin{pmatrix}
        1 && 0 && 1 \\
        1 && 1 && 0 \\
        0 && 1 && 1 \\
    \end{pmatrix}=PB$，即 $AP=PB$
    * $\alpha_1,\alpha_2,\alpha_3$ 线性无关，所以 $P$ 可逆，所以 $P^{-1}AP=B$，即 $A\sim B$，$|A|=|B|$
3. 若所求式子中既有伴随又有逆，则利用 $A^* = |A|A^{-1}$ 化为一种再计算
4. 若所求式子中有矩阵之和，需要化和为积：
    * $AA^T=E$，则 $|A|=\pm 1$，且 $|A+E|=|A+AA^T|=|A(E+A^T)|=|A||E+A|$；当 $|A|=1$ 时 $|A+E|$ 为任意值，当 $|A|=-1$ 时 $|A+E|=0$
    * $A,B$ 为三阶可逆方阵，则 $|A+B^{-1}|=|ABB^{-1}+AA^{-1}B^{-1}|=|A(B+A^{-1})B^{-1}|=\frac{|A|}{|B|}|B+A^{-1}|$
5. 若 $A_{ij}$ 是 非零矩阵 $A=(a_{ij})_{3\times 3}$ 的代数余子式：
    * $a_{ij}=A_{ij}\implies A^T=A^* \implies |A|=|A^T|=|A^* |=|A|^2\implies |A|=1$ （非零矩阵）
    * 同理 $a_{ij}=-A_{ij}\implies A^T=-A^* \implies |A|=-1$
6. 若 $A$ 是三阶矩阵，$Ax=0$ 有非零解，矩阵 $A-E$ 与 $A+2E$ 均不可逆，求 $|A-3E|$：
    * $Ax=0$ 有非零解，则 $|A|=0$，所以 $A$ 至少有一个特征值为零
    * $A-E$ 与 $A+2E$ 均不可逆，则 $|A-E|=0,|A+2E|=0$，所以存在两个特征值：$1,-2$
    * $|A-3E|=(0-3)(1-3)(-2-3)=-30$
7. 出现条件 $A_{m\pm n}B_{n\pm s}=0$，要想到利用下面的结论：
    * $r(A)+r(B)\le n$，若 $B$ 是非零矩阵要利用 $r(B)\gt 1$ 得到 $r(A)\le n-1<n$ 即 $A$ 不可逆，$|A|=0$
    * $B$ 的每一列均是 $Ax=0$ 的解
    * 示例：
        * 设 $A,B$ 均为 $n$ 阶非零矩阵，满足 $AB=0$ ，证明 $|A|=|B|=0$：
            1. 反证：若 $|A|\ne 0$ 则 $A$ 可逆，在 $AB=0$ 两边乘 $A^{-1}$ 得 $B=0$，与已知矛盾，故必有 $|A|=0$，同理得 $|B|=0$
            2. 用秩：由 $AB=0$ 知 $r(A)+r(B)\le n$，由 $B\ne 0$ 知 $r(B)\ge 1$，那么 $r(A)\le n-1<n$，所以 $|A|=0$，同理得 $|B|=0$
            3. 用齐次方程：设 $B=(\beta_1,\beta_2,...,\beta_n)$，则 $A\beta_i=0$ 即 $\beta_i$ 是 $Ax=0$ 的解，由 $B\ne 0$ 知 至少有一个 $\beta_i\ne 0$ 即 $Ax=0$ 有非零解，所以 $|A|=0$；又由 $AB=0$ 得 $B^TA^T=0$，同理可得 $|B^T|=0$，所以 $|B|=0$
        * 设 $A$ 为 $n$ 阶矩阵，满足 $A^2=A$，且 $A\ne E$，证明 $|A|=0$：
            1. 反证：若 $|A|\ne 0$，则 $A$ 可逆，在 $A^=A$ 两边同乘 $A^{-1}$ 得 $A=E$ 与已知矛盾，所以 $|A|=0$
            2. 用秩：$A^2=A\implies A(A-E)=0\implies r(A)+r(A-E)\le n$，由 $A\ne E$ 知 $A-E\ne 0$ 即 $r(A-E)\le 1$，所以 $r(A)\le n-1<n$，故 $|A|=0$
            3. 用齐次方程：$A^2=A\implies A(A-E)=0$，可知 $A-E$ 的每一列都是 $Ax=0$ 的解，又因为 $A\ne E$，$A-E\ne 0$，所以 $Ax=0$ 有非零解，故 $|A|=0$

# 2. 矩阵
## 2.1. 秩
1. 若 $A$ 是 $m\times n$ 的矩阵，则 $r(A)\le \min\{m,n\}$
2. $r(A+B)\le r(A)+r(B)$
3. $r(AB)\le \min\{r(A),r(B)\}$
4. $r(A)=r(kA)$，$(k\ne 0)$
5. 矩阵乘可逆矩阵，秩不变
6. $r(A)=r(A^T)=r(AA^T)=r(A^TA)$
7. 若存在 $A_{m\times n},B_{n\times s},AB=0$，则 $r(A)+r(B)\le n$
8. $r(A^*)=\begin{cases}
    n, \quad r(A)=n \\
    1, \quad  r(A)=n-1 \\
    0, \quad  r(A)<n-1 \\
\end{cases}$

## 2.2. 逆
* 逆的求法：
    1. $AA^{-1}=A^{-1}A=E$
    2. $A^{-1}=\frac{A^*}{|A|}$
    3. 分块：
        * $\begin{pmatrix} A && 0 \\ 0 && B \\ \end{pmatrix}^{-1}=\begin{pmatrix} A^{-1} && 0 \\ 0 && B^{-1} \\ \end{pmatrix}$
        * $\begin{pmatrix} 0 && A \\ B && 0 \\ \end{pmatrix}^{-1}=\begin{pmatrix} 0 && B^{-1} \\ A^{-1} && 0 \\ \end{pmatrix}$
        * $\begin{pmatrix} A && C \\ 0 && B \\ \end{pmatrix}^{-1}=\begin{pmatrix} A^{-1} && -A^{-1}CB^{-1} \\ 0 && B^{-1} \\ \end{pmatrix}$
        * $\begin{pmatrix} A && 0 \\ C && B \\ \end{pmatrix}^{-1}=\begin{pmatrix} A^{-1} && 0 \\ -B^{-1}CA^{-1} && B^{-1} \\ \end{pmatrix}$
    4. $(A\vdots E) \xrightarrow{初等行变换} (E\vdots A^{-1})$
* 逆的性质：
    1. $(kA)^{-1}=\frac{1}{k}A^{-1} \quad (k\ne 0)$
    2. $(AB)^{-1}=B^{-1}A^{-1}$
    3. $|A^{-1}|=\frac{1}{|A|}$
    4. $(A^{-1})^T=(A^T)^{-1}$
    5. $(A^{-1})^{-1}=A$

## 2.3. 伴随
1. $AA^*=A^*A=|A|E$
2. $A^*=|A|A^{-1}$
3. $(AB)^* =B^* A^*$
4. $(kA)^* =k^{n-1}A^*$
5. $|A^*|=|A|^{n-1}$
6. $(A^* )^T=(A^T)*$
7. $(A^* )^{-1}=(A^{-1})^* =\frac{A}{|A|}$
8. $(A^* )^* =|A|^{n-2}A$
9. 分块：
    * $\begin{pmatrix} A && 0 \\ 0 && B \\ \end{pmatrix}^* =\begin{vmatrix} A && 0 \\ 0 && B \\ \end{vmatrix}\begin{pmatrix} A && 0 \\ 0 && B \\ \end{pmatrix}^{-1}=\begin{pmatrix} |B|A^* && 0 \\ 0 && |A|B^* \\ \end{pmatrix}$
    * $\begin{pmatrix} 0 && A_{m\times m} \\ B_{n\times n} && 0 \\ \end{pmatrix}^* =(-1)^{mn}\begin{pmatrix}  0 && |A|B^* \\ |B|A^* && 0 \\ \end{pmatrix}$

## 2.4. 初等变换与初等矩阵
* 对矩阵进行以下三种变换，称为矩阵的初等行（列）变换，统称初等变换。
    1. 两行（列）互换
    2. 一行（列）乘非零常数 $c$
    3. 一行（列）乘 $k$ 加到另一行（列）
* 单位矩阵 $E$ 经过一次初等变换所得到的矩阵称为初等矩阵。
* 性质：
    1. 初等行（列）变换相当于左（右）乘相应的初等矩阵
    2. 初等矩阵均可逆，且其逆为同类型的初等矩阵：
        * $E_{ij}^{-1}=E_{ij}$
        * $E_i^{-1}(c)=E_i(\frac{1}{c})$
        * $E_{ij}^{-1}(k)=E_{ij}(-k)$

## 2.5. 求高次幂
1. 利用矩阵乘法结合律：若矩阵 $A$ 成比例（或 $r(A)=0$），则 $A$ 可以写成一列乘一行，即 $A=\alpha\beta^T$，那么：
    * $A^n=\alpha\beta^T\alpha\beta^T...\alpha\beta^T=\alpha(\beta^T\alpha)...(\beta^T\alpha)\beta^T=k^{n-1}\alpha\beta^T=k^{n-1}A$
    * 其中 $k=\beta^T\alpha$
2. 归纳法：写出 $A^2,A^3,...$，找出规律求 $A^n$
    * 例：$A=\begin{pmatrix} 1 && a \\ 0 && 1 \\ \end{pmatrix},A^2=\begin{pmatrix} 1 && 2a \\ 0 && 1 \\ \end{pmatrix},A^3=\begin{pmatrix} 1 && 3a \\ 0 && 1 \\ \end{pmatrix}$，假设 $A^n=\begin{pmatrix} 1 && na \\ 0 && 1 \\ \end{pmatrix}$，则 $A^{n+1}=\begin{pmatrix} 1 && (n+1)a \\ 0 && 1 \\ \end{pmatrix}$，假设成立
    * 可背结论：
      * $\begin{pmatrix} 1 && a \\ 0 && 1 \\ \end{pmatrix}^n=\begin{pmatrix} 1 && na \\ 0 && 1 \\ \end{pmatrix}$
      * $\begin{pmatrix} 1 && 0 \\ a && 1 \\ \end{pmatrix}^n=\begin{pmatrix} 1 && 0 \\ na && 1 \\ \end{pmatrix}$
3. 二项式展开定理：$A^n=(E+A)^n=E^n+C_n^1E^{n-1}B+C_n^2E^{n-2}B^2+...+C_n^{n-1}EB^{n-1}+C_n^nB^n$
    * 常用于 $A$ 可分解为 $E$ 和一个移位矩阵的和
    * 移位矩阵可以在某次幂后全为零，如：$B=\begin{pmatrix} 0 && 2 && 3 \\ 0 && 0 && 4 \\ 0 && 0 && 0 \\ \end{pmatrix},B^2=\begin{pmatrix} 0 && 0 && 8 \\ 0 && 0 && 0 \\ 0 && 0 && 0 \\ \end{pmatrix},B^i=0\space(i\ge 3)$
    * $C_n^k=\frac{n(n-1)...(n-k+1)}{k!}$
4. 分块矩阵法：$\begin{pmatrix} A && 0 \\ 0 && B \\ \end{pmatrix}^n=\begin{pmatrix} A^n && 0 \\ 0 && B^n \\ \end{pmatrix}$
5. 相似对角化：若 $A$ 可相似对角化，则 $A^n=P\Lambda P^{-1}P\Lambda P^{-1}...P\Lambda P^{-1}=P\Lambda (P^{-1}P)\Lambda ...\Lambda P^{-1}=P\Lambda^nP^{-1}$

# 3. 向量
## 3.1. 基础
1. 设 $n$ 维向量 $\alpha=(a_1,a_2,...,a_n)^T,\beta=(b_1,b_2,...,b_n)^T$，则：
    * 加法：$\alpha+\beta=(a_1+b_1,a_2+b_2,...,a_n+b_n)^T$
    * 数乘：$k\alpha=(ka_1,ka_2,...,ka_n)^T$
    * 内积：$(\alpha,\beta)=\alpha^T\beta=\beta^T\alpha=a_1b_1+a_2b_2+...+a_nb_n$
        1. 内积为零的两个向量正交（垂直）：$(\alpha,\beta)=0\iff\alpha,\beta$ 正交
        2. 与自己的内积为零的向量是零向量：$\alpha^T\alpha=0\iff\alpha=0$
           * 零向量与任意向量正交
    * 向量的模（长度）：$||\alpha||=\sqrt{\alpha^T\alpha}=\sqrt{a_1^2+a_2^2+...+a_n^2}$
        * 向量的单位化：$\alpha\to\frac{1}{||\alpha||}\alpha$
2. 方阵 $A$ 与非零向量 $\alpha$ 满足 $\alpha^TA^TA\alpha=0 \implies (A\alpha)^T(A\alpha)=0 \implies A\alpha=0$ 有非零解 $\implies \begin{cases}
            A 不可逆 \\
            |A|=0 \\
            r(A)<n \\
            0为A的特征值 \\
        \end{cases}$
3. 施密特正交化：设向量组 $\alpha_1,\alpha_2,\alpha_3$ 线性无关，令：$\begin{cases}
        \beta_1=\alpha_1 \\
        \beta_2=\alpha_2-\frac{(\alpha_2,\beta_1)}{(\beta_1,\beta_1)}\beta_1 \\
        \beta_3=\alpha_3-\frac{(\alpha_3,\beta_1)}{(\beta_1,\beta_1)}\beta_1-\frac{(\alpha_3,\beta_2)}{(\beta_2,\beta_2)}\beta_2 \\
    \end{cases}$ 则 $\beta_1,\beta_2,\beta_3$ 两两正交（正交向量组），然后单位化：$\gamma$$\begin{cases}
        \gamma_1=\frac{\beta_1}{||\beta_1||} \\
        \gamma_2=\frac{\beta_2}{||\beta_2||} \\
        \gamma_3=\frac{\beta_3}{||\beta_3||} \\
    \end{cases}$
4. 正交矩阵：若 $n$ 阶矩阵 $A$ 满足 $AA^T=A^TA=E$，则称 $A$ 为正交矩阵。
    * 充要条件：
        1. $A^T=A^{-1}$
        2. $A$ 的行（列）向量组为单位正交向量组
    * 性质：
        1. $|A|^2=1$
        2. $A^T,A^{-1},A^* ,A^2$ 均为正交矩阵
        3. $A,B$ 为正交矩阵，则 $AB$ 仍为正交矩阵

## 3.2. 线性
1. 若 $\beta=k_1\alpha_1+k_2\alpha_2+...+k_n\alpha_n$，则称 $\beta$ 是 $\alpha_1,\alpha_2,...,\alpha_n$ 的一个线性组合，或称 $\beta$ 可由 $\alpha_1,\alpha_2,...,\alpha_n,$ 线性表示（线性表出）。
   1. 判断向量组 $\alpha_1,\alpha_2,...,\alpha_n$ 能否表示 $\beta$：
      1. 设 $x_1\alpha_1+x_2\alpha_2+...+x_n\alpha_n=\beta$，即 $(\alpha_1,\alpha_2,...,\alpha_n)\begin{pmatrix} x_1 \\ x_2 \\ \vdots \\ x_n \end{pmatrix}=\beta$
      2. 令 $A=(\alpha_1,\alpha_2,...,\alpha_n),X=(x_1,x_2,...,x_n)^T$，解方程 $AX=\beta$
         1. 若 $r(A)=r(A|\beta)=n$，$AX=\beta$ 有唯一解，即 $\beta$ 可由 $\alpha_1,\alpha_2,...,\alpha_n$ 线性表示，且表示方法唯一
         2. 若 $r(A)=r(A|\beta)<n$，$AX=\beta$ 有无穷多解，即 $\beta$ 可由 $\alpha_1,\alpha_2,...,\alpha_n$ 线性表示，且表示方法无穷多种
         3. 若 $r(A)\ne r(A|\beta)$，$AX=\beta$ 无解，即 $\beta$ 不可由 $\alpha_1,\alpha_2,...,\alpha_n$ 线性表示
   2. 若 $\beta_1,\beta_2,...,\beta_t$ 可由 $\alpha_1,\alpha_2,...,\alpha_s$ 线性表示，则：$r(\beta_1,\beta_2,...,\beta_t)\le r(\alpha_1,\alpha_2,...,\alpha_s)$
   1. 两个向量组可以互相线性表示，则称向量组等价
      * 向量组等价 $\implies$ 秩相等
      * 向量组(Ⅰ)可由向量组(Ⅱ)线性表示，且 $r(Ⅰ)=r(Ⅱ)\iff$ 向量组等价
   2. $\alpha_1,\alpha_2,...,\alpha_n$ 线性无关，且 $\alpha_1,\alpha_2,...,\alpha_n,\beta$ 线性相关，令 $A=(\alpha_1,\alpha_2,...,\alpha_n)$，则：
      * $r(A)=r(A|\beta)=n$，即 $\beta$ 可由 $\alpha_1,\alpha_2,...,\alpha_n$ 线性表示，且表示方法唯一
      * 推论：$n$ 个无关的 $n$ 维向量可以表示任何一个 $n$ 维向量
2. 若存在一组不全为零的 $k_1,k_2,...,k_n$ 使 $k_1\alpha_1+k_2\alpha_2+...+k_n\alpha_n=0$，则称向量组 $\alpha_1,\alpha_2,...,\alpha_n$ 线性相关，否则线性无关。
   1. 线性无关，指向量之间没有任何关系，即：组内任何一个向量均不可由其余向量线性表示
   2. 线性相关，指向量之间存在某种关系，即：组内至少有一个向量可由其余向量线性表示
   3. 特殊向量组的线性相关性：
      1. 只有一个向量的向量组，若是零向量则线性相关，否则线性无关
      2. 只有两个向量的向量组，若成比例则线性相关，否则线性无关
      3. 一个向量组中若包含零向量，必线性相关
      4. 部分相关，整体相关（整体无关，部分无关）
      5. 高维相关，低维相关（低维无关，高维无关）
      6. 若 $\alpha_1,\alpha_2,...,\alpha_n,\alpha_{n+1}$ 线性相关，而 $\alpha_1,\alpha_2,...,\alpha_n$ 线性无关，则 $\alpha_{n+1}$ 可由 $\alpha_1,\alpha_2,...,\alpha_n$ 线性表示，且表示法唯一
      7. 多数向量若能由少数向量线性表示，则前者必相关（反之，若 $\alpha_1,...,\alpha_s$ 可由 $\beta_1,...,\beta_t$ 线性表示，若前者线性无关，则 $s\le t$）
      8. $n+1$ 个 $n$ 维向量必线性相关（即：向量组的个数大于维数时必相关）
      9. 设 $A$ 是 $n \times n$ 向量组构成的矩阵，若向量组线性无关，则 $|A|\ne 0$，若线性相关，则 $|A|=0$
      10. 两两正交的非零向量组必无关
      11. 不同特征值的特征向量线性无关
   4. 判断 $s$ 个 $n$ 维向量 $\alpha_1,\alpha_2,...,\alpha_s$ 的相关性：设 $x_1\alpha_1+x_2\alpha_2+...+x_s\alpha_s=0$，令 $A=(\alpha_1,\alpha_2,...,\alpha_s),X=(x_1,x_2,...,x_s)^T$，解方程 $AX=0$：
      1. 若 $n<s$，必相关（方程个数<未知数个数时，$AX=0$ 必有非零解）
      2. 若 $n=s$，当 $|A|=0$ 则相关，否则无关
      3. 若 $n>s$，两个方法：
         1. 通过变化 $A$ 为阶梯形判断 $AX=0$ 有非零解则相关，否则无关
         2. 求秩，若 $r(A)<s$ 则相关，否则无关
## 3.3. 秩与极大线性无关组
1. 向量组的极大线性无关组一般不唯一，只由一个零向量组成的向量组不存在极大线性无关组，一个线性无关组的极大线性无关组就是该向量组本身。
2. 极大线性无关组中向量的个数就是向量组的秩。
3. 三秩相等：$r(A)$（矩阵的行列式秩）$=A$ 的行秩（$A$ 的行向量组的秩）$=A$ 的列秩（$A$ 的列向量组的秩）
4. 初等变换不改变矩阵的秩
5. 有关等式与不等式，设 $A$ 是 $m\times n$ 的矩阵，$B$ 是满足有关矩阵运算要求的矩阵，则：
   1. $r(A)\le \min(m,n)$
   2. $r(A)=r(A^T)=r(AA^T)=r(A^TA)$
   3. $r(kA)=r(A)$（$k\ne 0$）
   4. $r(A\pm B)\le r(A)+r(B)$
   5. ：
      1. $r(AB)\le \min(r(A),r(B))$
      2. $r(AB)\ge r(A)+r(B)-n$
      3. 若 $AB=0$，则 $r(A)+r(B)\le n$（$n$ 是 $A$ 的列数，$B$ 的行数）
   6. $r(A^* )=\begin{cases} n, \quad r(A)=n \\ 1, \quad  r(A)=n-1 \\ 0, \quad  r(A)<n-1 \\ \end{cases}$
   7. :
      1. 若 $r(A_{m\times n})=n$，则 $r(B_{n\times s})=r(AB)$
      2. 若 $r(B_{n\times s})=n$，则 $r(A_{m\times n})=r(AB)$
   8. $r(A,B)\le r(A)+r(B)$，$r\begin{pmatrix} A \\ B \end{pmatrix} \le r(A)+r(B)$
   9. $r\begin{pmatrix} A && 0 \\ 0 && B \end{pmatrix}=r(A)+r(B)$
   10. $r\begin{pmatrix} A && C \\ 0 && B \end{pmatrix}\ge r(A)+r(B)$，$r\begin{pmatrix} A && 0 \\ C && B \end{pmatrix}\ge r(A)+r(B)$
   11. 若 $AB=C$，且 $B$ 可逆，则 $C$ 的列向量组与 $A$ 的列向量组等价（将 $A,C$ 按列分块可证）
       1.  推论1：$AB$ 的列向量可由 $A$ 的列向量组线性表示，即 $(A,AB)$ 可经列变换化为 $(A,0)$
       2.  推论2：$BA$ 的行向量可由 $A$ 的行向量组线性表示，即 $\begin{pmatrix} A \\ BA \end{pmatrix}$ 可经列变换化为 $\begin{pmatrix} A \\ 0 \end{pmatrix}$
       3.  显然秩都相等：$r(A)=r(A,AB)=r\begin{pmatrix} A \\ BA \end{pmatrix}$
## 3.4. 向量空间
1. 若向量空间 $V$ 中任意向量 $\beta$ 均可由 $m$ 个线性无关的向量 $\alpha_1,\alpha_2,...,\alpha_m$ 线性表示，即：$\beta=x_1\alpha_1+x_2\alpha_2+...+x_m\alpha_m$，则称 $\alpha_1,\alpha_2,...,\alpha_m$ 为 $V$ 的一组基，$m$ 为 $V$ 的维数（$dimV=m$），$x_1,x_2,...,x_m$ 为 $\beta$ 在基 $\alpha_1,\alpha_2,...,\alpha_m$ 下的坐标。
   * 基与维数，相当于向量组的极大线性无关组与秩。
   * 齐次线性方程组 $Ax=0$ 的解向量的集合，称为解空间，解空间的维数是 $n-r(A)$，基础解系则为解空间的一组基。
2. 设 $E_1,E_2,...,E_m$ 是向量空间的一组基，若满足：$(E_i,E_j)=\begin{cases} 1,\quad i=j \\ 0,\quad i\ne j \end{cases}$，则称其为规范正交基。
   * 求规范正交基就是把基内向量正交化。
3. 同空间的两个基 $\alpha_1,\alpha_2,...,\alpha_m$（设为 $A$）和 $\beta_1,\beta_2,...,\beta_m$（设为 $B$），则存在一个可逆矩阵 $P$ 使 $B=AP$，$P$ 称为 $A$ 到 $B$ 的过渡矩阵。
   * $P=A^{-1}B$（计算技巧：$(A\vdots B)\xrightarrow{初等行变换} (E\vdots A^{-1}B)$）
   * 设向量 $\gamma$ 在 $A,B$ 的坐标分别是 $x_1,x_2,...,x_m$ 和 $y_1,y_2,...,y_m$，则：$\begin{pmatrix} x_1 \\ x_2 \\ \vdots \\ x_m \end{pmatrix}=P\begin{pmatrix} y_1 \\ y_2 \\ \vdots \\ y_m \end{pmatrix}$

# 4. 线性方程
## 4.1. 解的判定
1. 齐次方程组 $A_{m\times n}x=0$
   1. 必有解，至少有零解
   2. $\begin{cases} r(A)=n,\quad 只有零解 \\ r(A)<n,\quad 有非零解\end{cases}$
   3. 当 $m=n$ 时可以通过行列式判断：$\begin{cases} |A|\ne 0,\quad 只有零解 \\ |A|=0,\quad 有非零解\end{cases}$
   4. 当 $m<n$ 时，$r(A)\le m<n$，必有非零解
   5. 基础解系：所有解的极大线性无关组
      1. 基础解系中包含 $n-r(A)$ 个解向量
      2. 基础解系不唯一
   6. 通解：基础解系的全体线性组合，表示齐次方程组的全部解。
      * 设 $\alpha_1,\alpha_2,...,\alpha_s$ 为一个基础解系，则通解为：$k_1\alpha_1+k_2\alpha_2+...+k_s\alpha_s$，其中 $k_1,k_2,...,k_s$ 是任意常数
2. 非齐次方程组 $A_{m\times n}x=b$
   1. $\begin{cases} r(A)=r(A\vdots b)=n,\quad 有唯一解 \\ r(A)=r(A\vdots b)<n,\quad 有无穷多解 \\ r(A)\ne r(A\vdots b),\quad 无解 \end{cases}$
   2. 当 $m=n$ 时可以通过行列式判断：$\begin{cases} |A|\ne 0,\quad 有唯一解 \\ |A|=0,\quad 无解或无穷多解 \end{cases}$
   3. 当 $r(A)=m$ 时，$r(A)=r(A\vdots b)=m$，必有解（唯一解或无穷多解）
   4. 通解：对应齐次方程组的通解+特解
      * 设 $\alpha_1,\alpha_2,...,\alpha_s$ 为 $Ax=0$ 一个基础解系，$\beta$ 是 $Ax=b$ 的一个特解，则通解为：$k_1\alpha_1+k_2\alpha_2+...+k_s\alpha_s+\beta$，其中 $k_1,k_2,...,k_s$ 是任意常数
## 4.2. 解的性质
1. 若 $\eta_1,\eta_2$ 是 $Ax=0$ 的解，则 $k_1\eta_1+k_2\eta_2$ 也为 $Ax=0$ 的解
2. 若 $\eta_1,\eta_2$ 是 $Ax=b$ 的解，则 $\eta_1-\eta_2$ 也为 $Ax=0$ 的解
3. 若 $\eta_1,\eta_2,...,\eta_s$ 是 $Ax=b$ 的解，令 $\beta=k_1\eta_1+k_2\eta_2+...+k_s\eta_s$，则：
   1. 当 $k_1+k_2+...+k_s=0$ 时，$\beta$ 为 $Ax=0$ 的解；
   1. 当 $k_1+k_2+...+k_s=1$ 时，$\beta$ 为 $Ax=b$ 的解；
   1. 当 $k_1+k_2+...+k_s=k \quad (k\ne 0)$ 时，$\frac{\beta}{k}$ 为 $Ax=b$ 的解；
## 4.3. 公共解与同解
1. 公共解：$Ax=0$ 与 $Bx=0$ 有非零公共解 $\iff \begin{pmatrix} A \\ B \end{pmatrix}x=0$ 有非零解 $\iff r\begin{pmatrix} A \\ B \end{pmatrix}<n$
2. 同解：$Ax=0$ 与 $Bx=0$ 同解 $\iff r(A)=r(B)=r\begin{pmatrix} A \\ B \end{pmatrix}$
3. 证明：$r(A)=r(A^T)=r(A^TA)=r(AA^T)$
   1. 显然：$Ax=0$ 的每一个解都是 $A^TAx=0$ 的解；
   2. 设 $\alpha$ 是 $A^TAx=0$ 的解，可推导 $A^TA\alpha=0\implies \alpha^TA^TA\alpha=0\implies (A\alpha)^TA\alpha=0\implies A\alpha=0$，即 $\alpha$ 也是 $Ax=0$ 的解；
   3. 所以 $Ax=0$ 与 $A^TAx=0$ 同解，则 $r(A)=r(A^TA)$；
   4. 在 $r(A)=r(A^TA)$ 两边同取转置得 $r(A^T)=r(AA^T)$，所以 $r(A)=r(A^T)=r(A^TA)=r(AA^T)$。
4. 若 $A_{mxn},B_{n,s},r(A)=n$，证明 $r(AB)=r(B)$
   1. 显然 $Bx=0$ 的每一个解都是 $ABx=0$ 的解；
   2. 设 $\alpha$ 是 $ABx=0$ 的解，可推导 $AB\alpha=0\implies A(B\alpha)=0$；
   3. 由于 $r(A)=n$，所以 $Ax=0$ 只有零解，即 $B\alpha=0$，所以 $\alpha$ 也是 $Bx=0$ 的解；
   4. 所以 $Bx=0$ 与 $ABx=0$ 同解，则 $r(B)=r(AB)$

# 5. 特征值与特征向量
1. 定义：$A\alpha=\lambda\alpha \quad (\alpha\ne 0)$
2. 求法：
   * $A$ 为数值型矩阵
     1. $|\lambda E-A|=0$，求出特征值；
     2. $(\lambda E-A)x=0$，求出特征向量；
     3. 若 $(\lambda E-A)x=0$ 的基础解系为 $\alpha_1,\alpha_2,...,\alpha_t$，其中 $t=n-r(\lambda E-A)$，则特征值 $\lambda$ 对应的全部特征向量是 $k_1\alpha_1+k_2\alpha_2+...+k_t\alpha_t$，其中 $k_1,k_2,...,k_t$ 不全为零。
   * $A$ 为抽象型矩阵：用定义来求
3. 性质
   1. 不同特征值的特征向量必线性无关。
   2. ：
      * $|A|=\displaystyle\prod_{i=1}^n\lambda_i$
      * $\displaystyle\sum_{i=1}^na_{ii}=\displaystyle\sum_{i=1}^n\lambda_i=tr(A)$
   3. $k$ 重特征值对应的线性无关的特征向量个数 $\le k$
   4. 成比例的矩阵 $A_{3x3}$ 可写成 $A=\alpha\beta^T$
      * 有一个特征值是 $A$ 的迹 $tr(A)=\alpha^T\beta=\beta^T\alpha$，也就是对角线之和，对应的特征向量是 $A$ 的任一列；
      * 另两个特征值是 $0$，对应的特征向量是解任一行由 $3$ 个未知数组成的 $1$ 个方程。
   5. 行和相等的矩阵 $A_{nxn}$，则该和是 $A$ 的一个特征值，对应的特征向量有 $(1,1,...,1)^T$
   6. 矩阵 $A$ 两个不等的特征值所对应的两个特征向量 $\alpha_1,\alpha_2$，则 $\alpha_1+\alpha_2$ 一定不是 $A$ 的特征向量
      * 推广：设 $i=1,2,...,t$，$\lambda_i,\alpha_i$ 分别是矩阵 $A$ 互异的特征值及其对应的特征向量，那么对于 $\beta=k_1\alpha_1+k_2\alpha_2+...+k_t\alpha_t$：
        1. 仅 $k_i$ 中只有一个不为 $0$（其余 $t-1$ 个都为 $0$）时，$\beta$ 才是 $A$ 的特征向量；
        2. 若 $k_i$ 全为 $0$ 时，$\beta=0$，必不是 $A$ 的特征向量；
        3. 若 $k_i$ 中有两个或以上为 $0$ 时，设 $\beta$ 是 $A$ 的特征向量，会推出两个或以上特征值相等，与已知矛盾，所以此时 $\beta$ 不是 $A$ 的特征值。
   7. 若 $A$ 为正交矩阵，则当 $|A|=-1$ 时必有特征值 $-1$，当 $|A|=1$ 且 阶数 $n$ 为奇数时必有特征值 $1$
   8. ： 
      * $|A|=0 \iff 0$ 是 $A$ 的特征值
      * $A$ 可逆 $\iff A$ 所有特征值都不为零
   9.  幂等矩阵 $A^2=A$ 的特征值只可能是 $0$ 或 $1$
   10. 对合矩阵 $A^2=E$ 的特征值只可能是 $1$ 或 $-1$
4. 公式

| 矩阵 | $A$ | $A^2$ | $f(A)$ | $A^{-1}$ | $A^*$ | $P^{-1}AP$ | $PAP^{-1}$ | $A^T$ |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| 特征值 | $\lambda$ | $\lambda^2$ | $f(\lambda)$ | $\frac{1}{\lambda}$ | $\frac{\|A\|}{\lambda}$ | $\lambda$ | $\lambda$ | $\lambda$ |
| 特征向量 | $\alpha$ | $\alpha$ | $\alpha$ | $\alpha$ | $\alpha$ | $P^{-1}\alpha$ | $P\alpha$ | - |

> 设 $A_{3x3}$ 有特征值 $a,b,c$，则 $|A|=abc$，那么 $A^*$ 的特征值是 $bc,ac,ab$

# 6. 相似
## 6.1. 矩阵相似
1. 定义：$P^{-1}AP=B \iff A\sim B$
2. 必要条件：
   * $r(A)=r(B)$
   * $A,B$ 特征值相同（特征向量不一定相同）
      1. $|A|=|B|=\displaystyle\prod_{i=1}^n\lambda_i$
      2. $tr(A)=tr(B)$
      3. $|\lambda E-A|=|\lambda E-B|$
3. 若 $A\sim B$，则有结论：
   1. $B\sim A$
   2. 若 $B\sim C$ 则 $A\sim C$
   3. $A^T\sim B^T$，$A^{-1}\sim B^{-1}$，$A^* \sim B^*$
   4. $f(A)\sim f(B)$，比如 $A^2\sim B^2,A+E\sim B+E$；注：$f$ 中可以有 $A,A^{-1},A^*,A^k$，但不可有 $A^T$
4. 判断 $A,B$ 是否相似的顺序：
   1. $r(A)\ne r(B) \implies$ 不相似
   2. $|A|\ne |B|$ 或 $tr(A) \ne tr(B) \implies$ 不相似
   3. 求出两者的特征值：
      * 若特征值不全一样，不相似
      * 若特征值全都一样，且都可相似对角化，则相似（因为与同一个对角阵相似）
      * 若特征值全都一样，但不可相似对角化，则不一定

## 6.2. 相似对角化
* 充要与必要条件，同时也是判断一个矩阵是否可相似对角化的顺序：
   1. 实对称矩阵 $\implies A\sim\Lambda$
   2. 有 $n$ 个不同特征值 $\implies A\sim\Lambda$
   3. $k$ 重特征值有 $k$ 个线性无关的特征向量 $\iff A\sim\Lambda$
   4. 有 $n$ 个线性无关的特征向量 $\iff A\sim\Lambda$
* 常见的 $3$ 阶方阵 $A$，判断 $|\lambda E-A|$：
   1. 若有 $3$ 个单根，一定可以相似对角化。
   2. 若有 $1$ 个单根 $\lambda_1$、$2$ 个重根 $\lambda_2$，当 $\lambda_2 E-A$ 成比例时才可相似对角化。
   3. 若有 $3$ 个重根，只有 $A$ 本身就是对角阵才可相似对角化（这就是废话），$A$ 不是对角阵就不可以相似对角化。
* 若矩阵 $A$ 成比例：$tr(A)\ne 0 \iff A\sim \Lambda$
* 特殊矩阵：
  1. 幂零阵（$A^k=0$）
     * 特征值全为 $0$
     * $A\ne 0$ 时不能相似对角化
     * $A\pm E$ 可逆
  2. 幂幺阵（$A^k=E$）
     * 特征值为 $k$ 次单位根（复数）
     * 能相似对角化
  3. 幂等阵（$A^2=A$）
     * 特征值为 $0$ 或 $1$
     * 能相似对角化
     * $r(A)+r(A-E)=n$
  4. 对合阵（$A^2=E$）
     * 特征值为 $\pm 1$
     * 能相似对角化
     * $r(A+E)+r(A-E)=n$，证明：
       * $A^2=E \implies (A+E)(A-E)=0 \implies r(A+E)+r(A-E)\le n$
       * $r(A+E)+r(A-E) \ge r(A+E-A+E)=r(2E)=n$

# 7. 二次型
## 7.1. 实对称矩阵
1. 定义：$A=A^T$，$Q^TAQ \sim \Lambda$
2. 必要条件：
   1. 一定可以相似对角化
   2. 一定可以通过正交矩阵相似对角化（$Q^TAQ\sim \Lambda$，其中 $QQ^T=Q^TQ=E$）
   3. 不通特征值所对应的特征向量一定相互正交（$\alpha_1^T\alpha_2=0$）
   4. 特征值为实数
   5. 特征值的几何重数等于代数重数
   6. 秩等于非零特征值的个数
## 7.2. 二次型
1. $n$ 元二次齐次多项式：$\\ f(x_1,x_2,...,x_n)=a_{11}x_1^2+a_{22}x_2^2+...+a_{nn}x_n^2+ \\ \quad \quad 2a_{12}x_1x_2+2a_{13}x_1x_3+...+2a_{1n}x_1x_n+ \\ \quad \quad 2a_{23}x_2x_3+...+2a_{2n}x_2x_n+ \\ \quad \quad ...+ \\ \quad \quad 2a_{n-1,n}x_{n-1}x_n \\$ 称为 $n$ 元二次型（一般形式）
   * 标准形：只含平方项的二次型
   * 规范形：平方项系数仅含 $1,-1,0$ 的标准形
   * 取 $a_{ij}=a{ji}$，$i,j=1,2,...,n$，则二次型的矩阵形式为 $f=x^TAx$
      1. 其中 $x=(x_1,x_2,...,x_n)^T$
      2. 其中 $A=(a_{ij})$ 是对称矩阵，称为二次型的矩阵，$r(A)$ 为二次型的秩
      3. 二次型与对称矩阵 $A$ 互相唯一确定，$A$ 的对角线元素为平方项的系数，其余元素 $a_{ij}=a_{ji}$ 为交叉项 $x_{ij}$ 系数的一半
2. 二次型化标准形
   * 配方法：通过可逆线性变换 $x=Cy \quad (C可逆)$，就是通过配方、换元得到标准形及所用的可逆线性变换。
      1. 若二次型中含有平方项，依次配方 $x_1,x_2,...,x_n$，然后换元得到标准形及所用的可逆线性变换。
      2. 若二次型中不含有平方项，令 $\begin{cases} x_1=y_1-y_2 \\ x_2=y_1+y_2 \\ x_3=y_3 \end{cases}$ 化出平方项，然后再配方、换元。
   * 正交变换法：通过正交变换 $x=Qy \quad (Q为正交矩阵)$ 化为标准形。
      * 二次型矩阵的特征值就是标准形平方项的系数。
3. 惯性
   1. 在二次型的标准形中，系数为正的平方项的个数 $p$ 称为二次型的正惯性指数；系数为负的平方项的个数 $q$ 称为二次型的负惯性指数。
   2. 二次型无论怎样化为标准形，其正负惯性指数 $p,q$ 都是唯一的，从而其规范形也是唯一的。
## 7.3. 等价、相似、合同
1. 等价：$A,B$ 同型 $m\times n$，存在可逆矩阵 $P,Q$ 使 $PAQ=B$，则 $A$ 与 $B$ 等价（即：$A$ 经过有限次的初等变换得到 $B$）
   * 等价 $\iff$ 秩相等
   * 性质：
      1. 反身性：任意矩阵与自身等价
      2. 对称性：$A$ 与 $B$ 等价，则 $B$ 与 $A$ 等价
      3. 传递性：$A$ 与 $B$ 等价且 $B$ 与 $C$ 等价，则 $A$ 与 $C$ 等价
      4. $|A|=k|B| \quad (k\ne 0)$
2. 相似：$A,B$ 均为 $n$ 阶矩阵，存在可逆矩阵 $P$ 使 $P^{-1}AP=B$，则 $A$ 相似于 $B$，记作 $A\sim B$
   * 秩相等
   * 特征值相同（特征向量不一定相同）
   * 性质：
     1. 同样有反身性、对称性、传递性
     2. $A^T\sim B^T$，$A^{-1}\sim B^{-1}$，$A^* \sim B^*$
     3. $f(A)\sim f(B)$，比如 $A^2\sim B^2,A+E\sim B+E$；注：$f$ 中可以有 $A,A^{-1},A^*,A^k$，但不可有 $A^T$
3. 合同：存在可逆矩阵 $C$ 使 $C^TAC=B$，则 $A$ 与 $B$ 合同，记作 $A\simeq B$（经过可逆线性变换，二次型的矩阵合同）
   1. 合同定义没有要求 $A,B$ 为对称矩阵，但合同一般用在二次型研究中，所以通常有 $A,B$ 对称的前提。
   2. 经过可逆线性变换 $x=Cy$ 二次型的矩阵合同。
   3. 经过正交变换 $x=Qy$ 即 $Q^TAQ=Q^{-1}AQ=B$，二次型的矩阵不仅合同而且相似。
   4. $A,B$ 为 $n$ 阶实对称矩阵：
      * 充要条件
        1. $A,B$ 有相同的正、负惯性指数
        2. $x^TAx,x^TBx$ 有相同的正、负惯性指数
      * 充分条件
        1. $A\sim B$
        2. $A,B$ 有相同的特征值
      * 必要条件
        1. $r(A)=r(B)$，即 $A,B$ 等价
4. 关系
   1. 相似必等价，合同必等价
   2. 相似不一定合同，但实对称矩阵相似必合同
## 7.4. 正定
1. 定义：如果任意 $x\ne 0$ 均有 $x^TAx>0$ 则称 $x^TAx$ 为正定二次型，称对称矩阵 $A$ 是正定矩阵。
   * $x\ne 0$ 表示 $x$ 不是零向量，即 $x_1,x_2,...,x_n$ 不同时为零。
2. 充要条件
   1. $A$ 的正惯性指数为 $n$
   2. $A$ 的特征值均大于零
   3. $A\simeq E$
   4. 存在可逆矩阵 $C$ 使 $A=C^TC$
   5. $A$ 的顺序主子式均大于零（包括主对角线元素均大于零）
3. 必要条件
   1. $a_{ii}>0\quad (i=1,2,...,n)$
   2. $|A|>0$
4. 判断实对称矩阵正定
   1. 具体矩阵：由顺序主子式、主对角线元素、行列式大于零判断。
   2. 抽象矩阵：首先判断是否对称，是的话判断特征值是否大于零；若特征值不易求，考虑用正定的定义判断。
   3. 若 $A,B$ 正定，则 $kA(k>0),A^k,A^T,A^{-1},A^*$ 均正定。
      * 推广：若 $A$ 正定，则 $A,A^k,A^T,A^{-1},A^{*}$ 的任意线性组合，只要每个系数都大于零，则仍为正定矩阵。（如 $A^2+2A^* +3A^{-1}$）
