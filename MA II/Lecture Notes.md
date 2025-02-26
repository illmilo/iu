----
# Series
The geometric series $$\sum_{n=1}^\infty ar^{n-1}$$
- **converges** to $0 \iff a = 0$
- **converges** to $\frac{a}{1-r}$ $\iff$ $|r|<1$
- **diverges** to $\infty$ $\iff$ $r≥1$ and $a>0$
- **diverges** to $-\infty$ $\iff r≥1$ and $a<0$
- **diverges** $\iff r≤-1$ and $a≠0$
## Convergence

## The Ratio Test
Suppose that $a_n$ and that $\rho = \lim_{n\rightarrow\infty}\frac{a_{n+1}}{a_n}$ **exists** or **is** $+\infty$.
- $0≤\rho<1\implies\sum_{n=1}^\infty a_n$ **converges**
- $1<\rho≤\infty\implies\lim_{n\rightarrow\infty}a_n=\infty$ and $\sum_{n=1}^\infty a_n$ **diverges** to $\infty$
## The Root Test
Suppose that $a_n > 0$ and $\sigma = \lim_{n\rightarrow\infty}(a_n)^\frac{1}{n}$ **exists**  or **is** $+\infty$.
- $0 ≤ \sigma < 1\implies \sum_{n=1}^\infty a_n$ **converges**
- $\sigma > 1 \implies \lim_{n\rightarrow\infty} a_n$ and $\sum_{n=1}^\infty a_n$ **diverges** to $\infty$
# P-Series
For any power series $\sum_{n=0}^\infty a_n(x-c)^n$:
- Series **converge only at** $x=c$
- Series **converge** at every $x\in\mathbb{R}$
- $\exists R\in\mathbb{R}$, such that the series **converge at every** $x$ satisfying $|x-c|<R$ or **diverge at every** $x$ satisfying $|x-c|>R$
## Convergence of P-Series
$$\sum_{n=1}^\infty n^{-p} = \sum_{n=1}^\infty \frac{1}{n^p}$$
- **converges** $\iff p > 1$
- **diverges to** $\infty \iff p ≤ 1$
## Radius of Convergence
Suppose $L=\lim_{n\rightarrow\infty}\frac{a_{n+1}}{a_n}$ **exists** or **is** $\infty$. Then **power series** $\sum_{n=0}^\infty a_n(x-c)^n$ has **radius of convergence** $R=\frac{1}{L}$. If $L=0$, then $R=\infty$; if $L=\infty$, then $R=0$.
### S