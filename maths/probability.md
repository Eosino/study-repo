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
   * $\iff P(B|A)=P(B)$
   * $\iff P(B|A)=P(B|\bar{A})$
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

> 注1：所有运算中作为条件概率的事件 $A$，必须满足其概率 $P(A)>0$  
> 注2：

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
