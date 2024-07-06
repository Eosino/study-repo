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
        * $(A^* )^* =|A^* |(A^* )^{-1}=$$|A|^{n-2}A$
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


