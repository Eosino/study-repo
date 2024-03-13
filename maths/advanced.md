# 1. 函数与极限
## 1.1. 抓大
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
## 泰勒