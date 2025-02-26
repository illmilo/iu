----
# I.   Vectors
## Parallelism
Let $\lambda \in \mathbb{R}$ and $\textbf{d}$ be some vector. 
- $\lambda > 0 \implies \lambda \textbf{d}$ is _parallel_
- $\lambda < 0 \implies \lambda \textbf{d}$ is _antiparallel_
- $\lambda = 0 \implies \lambda \textbf{d} = \textbf{0}$
## Vector Space
A vector space $V$ over $\mathbb{R}$ or $\mathbb{C}$ is a _collection on vectors_, together with two operations $\forall \textbf{a}, \textbf{b} \in V$:
- $\textbf{a} + \textbf{b}$
- $\lambda\textbf{a}, \lambda\in \mathbb{R}$
### Properties
#### Addition
- $\textbf{a} + \textbf{b} = \textbf{b} + \textbf{a}$                    | commutativity
- $(\textbf{a} + \textbf{b}) + \textbf{c} = \textbf{a} + (\textbf{b} + \textbf{c})$ | associativity
- $\exists \textbf{0} : \textbf{a} + \textbf{0} = \textbf{a}$                    | identity
- $\forall \textbf{a}\ \exists (\textbf{-a}) : \textbf{a} + (\textbf{-a}) = \textbf{0}$      | inverse
#### Multiplication
- $\lambda(\textbf{a}+\textbf{b}) = \lambda\textbf{a} + \lambda\textbf{b}$
- $(\lambda + \mu)\textbf{a}=\lambda\textbf{a}+\mu\textbf{a}$
- $\lambda(\mu\textbf{a}) =(\lambda\mu)\textbf{a} = \mu\lambda\textbf{a}$
### Linear Combination
Vector $\textbf{w} \in V$ is a __linear combination__ of $\textbf{v}_1, ..., \textbf{v}_n \in V$ with some coefficients $c_k\in \mathbb{R}\ (k=1..n)$ such that $\textbf{w} = c_1\textbf{v}_1+...+c_n\textbf{v}_n$.
### Span
Let $S = \{\textbf{v}_1, ..., \textbf{v}_n\} \subset V$.
$span(S) = \{\textbf{w}\in V\}$ is the __set of all linear combinations__ of the vectors $v_1,...,v_n$.
### Linear Independence
Vectors $\textbf{v}_1, ..., \textbf{v}_n$ are **linearly independent** if $\textbf{w} = \vec{0} \iff c_1 = ... = c_n = 0$.
- Collinear vectors are **linearly dependent**.
- When you can represent one of the vectors as linear combination of the others, then this vector is **linearly dependent**.
### Basis
Set of vectors is a **basis** of $\mathbb{R}^n$ if it spans $\mathbb{R}^n$ and is linearly independent.
### Subspace
$W$ is a *subspace* of $V$ if
- $W\subset V$
- $\textbf{u}, \textbf{v} \in W \implies \textbf{u} + \textbf{v} \in W$
- $\textbf{u}\in W, \lambda\in \mathbb{R} \implies \lambda\textbf{u}\in W$
## Dot Product
**Dot product** on $V$ is a real-valued function $\textbf{u}\cdot\textbf{v}$ on $V\times V \rightarrow \mathbb{R}$, and $\textbf{u}, \textbf{v} \in V$.
Basically, **dot product** = *(length of projection $\textbf{v}$ onto $\textbf{u}$)* • $||\textbf{u}||$.
- $\textbf{u}\cdot\textbf{v}>0\implies$ same direction
- $\textbf{u}\cdot\textbf{v}=0\implies$ orthogonal
- $\textbf{u}\cdot\textbf{v}<0\implies$ negative directions
It is also a beautiful *transition* from $n$-dimensional vector to $1$-dimensional.
$$\begin{align}
\textbf{a}\cdot\textbf{b} = \sum^n_{i=1}a_i b_i = ||\textbf{a}||\ ||\textbf{b}|| \cos\theta,\\\text{where }\theta \text{ is the angle b/w }\textbf{a} \text{ and } \textbf{b}, n\text{ is the dimension of the vectors.}
\end{align}$$
### Properties
- $\textbf{u}\cdot\textbf{v}=\textbf{v}\cdot\textbf{u}$
- $\textbf{u}\cdot (\textbf{w} + \textbf{v}) = \textbf{u}\cdot\textbf{w}+\textbf{u}\cdot\textbf{v}$
- $(\lambda \textbf{u})\textbf{v}=\lambda(\textbf{u}\cdot\textbf{v})$
- $\textbf{u}^2≥0$
- $\textbf{u}^2=0\iff \textbf{u}=0$
### Projections
#### Scalar
$$\begin{align}||proj_\textbf{b} \textbf{a}|| = ||\textbf{a}||\cos\theta=\frac{\textbf{a}\cdot\textbf{b}}{||\textbf{b}||}\\
\end{align}$$
#### Orthogonal
$$\begin{align}
proj_\textbf{b} \textbf{a} =\hat{\textbf{b}}\ || \textbf{a} || \cos\theta=\frac{\textbf{b}}{||\textbf{b}||}\cdot\frac{\textbf{a}\cdot\textbf{b}}{||\textbf{b}||}\\
\textbf{a}-proj_\textbf{b}\textbf{a}
\end{align}$$
Vectors $\textbf{a},\textbf{b}\in V$ are **orthogonal** if $\textbf{a}\cdot\textbf{b}=0$.
## Norm (Length)
$||\textbf{u}||$ is a **norm** (**length**) on a vector space $V$ if $\forall \textbf{u},\textbf{v} \in V$ and $\alpha \in \mathbb{R}$:
- $||\alpha\textbf{u}|| = |\alpha|\ ||\textbf{u}||$
- $||\textbf{u}||≥0$
- $||\textbf{u}||=0\iff\textbf{u}=0$
- $||\textbf{u}+\textbf{v}||≤||\textbf{u}||+||\textbf{v}||$
## Cauchy-Schwarz Inequality
$$|\textbf{x}\cdot\textbf{y}|≤||\textbf{x}||\ ||\textbf{y}||, \forall\textbf{x},\textbf{y}\in\mathbb{R}^n$$
<u>Proof</u>. Consider $||\textbf{x}-\lambda\textbf{y}||^2 = ||\textbf{x}||^2-2\lambda\textbf{x}\cdot\textbf{y}+\lambda^2||\textbf{y}||^2=\lambda^2||\textbf{y}||^2-\lambda(2\textbf{x}\cdot\textbf{y})+||\textbf{x}||^2 ≥ 0$.
In quadratic $\lambda$, the quadratic is non-negative, $\implies$ $≤2$ different roots. 
Then $D = b^2 -4ac≤0$ $\implies b^2 ≤ 4ac$.
$4(\textbf{x}\cdot\textbf{y})^2≤4(||\textbf{y}||^2\cdot||\textbf{x}||^2)$
$(\textbf{x}\cdot\textbf{y})^2≤||\textbf{y}||^2\cdot||\textbf{x}||^2$
$|\textbf{x}\cdot\textbf{y}|≤||\textbf{x}||\ ||\textbf{y}||. \blacksquare$
## Triangle Inequality
$$||\textbf{x}+\textbf{y}||≤||\textbf{x}|| + ||\textbf{y}||$$
# II.   Matrix
## Determinant
**Determinant** represents the **multiplier of area** after applying **transition matrix** to the old coordinate system and whether the orientation of the system becomes *flipped* ($\hat{\textbf{i}}$ and $\hat{j}$ swap places, *right-hand rule* doesn't apply).
$$\begin{aligned}\det(
\begin{bmatrix}
a&b\\c&d
\end{bmatrix}
)=ad-bc\\
\det(\begin{bmatrix}
a_1&b_1&c_1\\
a_2&b_2&c_2\\
a_3&b_3&c_3
\end{bmatrix})=a_1b_2c_3+b_1c_2a_3+c_1a_2b_3-c_1b_2a_3-a_1c_2b_3-b_1a_2c_3\\
\det(A^\intercal)=\det(A)\\
\det(AB)=\det(A)\det(B)
\end{aligned}
$$
## Cross Product
**Requirement**: $\mathbb{R}^3$ space.
Let $\textbf{a},\textbf{b}\in\mathbb{R}$. Then $\textbf{a}\times \textbf{b} = \hat{\textbf{n}}||\textbf{a}||\ ||\textbf{b}||\sin\theta$, where $\hat{\textbf{n}}$ is a unit vector perpendicular to $\textbf{a}$ and $\textbf{b}$.
In the determinant way:
$$\begin{aligned}
\textbf{a}\times\textbf{b}=\det(\begin{bmatrix}
\hat{\textbf{i}}&\hat{\textbf{j}}&\hat{\textbf{k}}\\
a_1&a_2&a_3\\
b_1&b_2&b_3
\end{bmatrix})=\hat{\textbf{i}}(a_2b_3-b_2a_3)+\hat{\textbf{j}}(a_3b_1-b_3a_1)+\hat{\textbf{k}}(a_1b_2-b_1a_2)\\
\begin{bmatrix}a_1\\a_2\\a_3\end{bmatrix}\times\begin{bmatrix}b_1\\b_2\\b_3\end{bmatrix}=\begin{bmatrix}a_2b_3-b_2a_3\\a_3b_1-b_3a_1\\a_1b_2-b_1a_2\end{bmatrix}\\
||\textbf{a}\times\textbf{b}||=\text{area of parallelogram with sides }\textbf{a},\textbf{b}\\
\end{aligned}$$
$\textbf{a}\times\textbf{b}<0 \iff$right-hand rule doesn't apply.}
### Properties
- $\textbf{a}\times\textbf{b}=-\textbf{b}\times\textbf{a}$
- $\textbf{a}^2=\textbf{0}$
- $\textbf{a}\times\textbf{b}=\textbf{0}\implies \textbf{a}=\lambda\textbf{b}$ for some $\lambda \in \mathbb{R}$ (or $\textbf{b}=0$)
- $\textbf{a}\times(\lambda\textbf{b})=\lambda(\textbf{a}\times\textbf{b})$
- $\textbf{a}\times(\textbf{b}+\textbf{c})=\textbf{a}\times\textbf{b}+\textbf{a}\times\textbf{c}$
## Scalar Triple Product
$$\textbf{a}\cdot(\textbf{b}\times\textbf{c})=(\textbf{a}\times\textbf{b})\cdot\textbf{c}$$
Which is the volume of parallelepiped $V=||a\times b||(||c||\ |\cos\theta|)$ = *area* • *height*, formed by 3 vectors.
## Transposition
$$\begin{aligned}(ABCD)^\intercal=D^\intercal C^\intercal B^\intercal A^\intercal\\
\textbf{x}^\intercal A\rightarrow(m\times1)\text{ is a column vector}\\
A\textbf{x}\rightarrow(1\times m) \text{ is a row vector}\\
\end{aligned}$$
## Inverse Matrix
Let $A$ be some square matrix. Then:
$$A^{-1}A = AA^{-1}= I,$$
where $I$ is the **identity matrix**, $A^{-1}$ is the **inverse of a square matrix** that is counter to the matrix of transformation $A$.
Similarly, $AI=IA=A$.
### Properties
- For non-square matrices $A_{m\times n}, B_{n\times m}$:
	1. $BA = I\iff B$ is the **left inverse** of $A$.
	2. $AB=I\iff B$ is the **right inverse** of $A$.
- If $A$ and $B$ are invertible and $AB$ is invertible, then $(AB)^{-1}=B^{-1}A^{-1}=A^{-1}B^{-1}$.
- If $A$ is invertible, then $A^\intercal$ is invertible.
- $\det(A)=0 \implies$matrix $A$ is **non-invertible** and is **singular**.
- $AA^\intercal=A^\intercal A=I\implies A^{-1}=A^\intercal$.
- $\det(A^{-1})=\det(A)^{-1}$
- $(A^{-1})^{-1}=A$
- $(A^\intercal)^{-1}=(A^{-1})^\intercal$
- $(kA^{-1})=\frac{A^{-1}}{k}$
### Calculation
#### Classical Method
$$A^{-1}=\frac{\text{adj}(A)}{\det(A)}$$
#### Gauss-Jordan
Transform using *elementary row operations*:
$$[A|I]\rightarrow[\triangle_\text{upper}|I']\rightarrow[I|A^{-1}]$$
#### Elementary Row Operations
- Swap 2 rows
- Multiply a row by a nonzero number
- Add a multiple of one row to another
Matrices are **row-equivalent** when one can be obtained from another using elementary row operations.
## Augmented & Coefficient Matrices
- Matrix derived from the *coefficients* and *constant* terms of the system is **augmented matrix**.
- Matrix that contains only coefficients of the system is **coefficient matrix**.
## Change of Basis
$$\textbf{v}=O+\textbf{w}A$$where $A$ is the *transition* matrix from the "old" system to a "new" one, $\textbf{v}$ is a vector in the old system, $\textbf{w}$ is the corresponding vector in a new system, $O$ is the new origin coordinates.
# III.   Space
## Line in Plane
| Equation                     | Formula                                                                                                                                                                                                                          |
| ---------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **General**                  | $$Ax+By+C=0$$                                                                                                                                                                                                                    |
| **Slope-intercept**          | $$y=kx+b$$                                                                                                                                                                                                                       |
| **Passing through 2 points** | $$\frac{y-y_1}{x-x_1}=\frac{y_2-y_1}{x_2-x_1}$$                                                                                                                                                                                  |
| **Canonical**                | Let $\textbf{a}=\begin{bmatrix}a_x\\a_y\end{bmatrix}$ be the vector that indicates the direction of the line passing through the point $p=\begin{pmatrix}x_0\\y_0\end{pmatrix}$. Then<br>$$\frac{x-x_0}{y-y_0}=\frac{a_x}{a_y}$$ |
| **Parametric**               | Let $\textbf{r}-\textbf{r}_0 = \begin{bmatrix}x-x_0\\y-y_0\\z-z_0\end{bmatrix}, q=\begin{bmatrix}q_x\\q_y\\q_z\end{bmatrix}$. Then<br>$$\textbf{r}-\textbf{r}_0=t\textbf{q}$$                                                    |
| **Using normal line**        | $$(\textbf{r}-\textbf{r}_0)\cdot\textbf{n}=0,$$<br>where $\textbf{r}=\begin{bmatrix}x\\y\end{bmatrix}, \textbf{r}_0=\begin{bmatrix}x_0\\y_0\end{bmatrix}$.                                                                       |
## Plane

| Equation         | Formula                                                                                                                             |
| ---------------- | ----------------------------------------------------------------------------------------------------------------------------------- |
| **General**      | $$Ax+By+Cz+D=0$$                                                                                                                    |
| **Point-normal** | $$(\textbf{r}-\textbf{r}_0)\cdot\textbf{n}=0,$$<br>where $\textbf{r}-\textbf{r}_0=\begin{bmatrix}x-x_0\\y-y_0\\z-z_0\end{bmatrix}.$ |
| **In segments**  | $$\frac{x}{a}+\frac{y}{b}+\frac{z}{c}=1,$$<br>where $$                                                                              |
|                  |                                                                                                                                     |
