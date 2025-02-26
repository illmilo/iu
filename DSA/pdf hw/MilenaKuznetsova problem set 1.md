# Week 1. Problem set solutions
by Milena Kuznetsova. m.kuznetsova@innopolis.university

# Problem 1. Theta Asymptotic
Compute asymptotic worst case time complexity of the following algorithm (see pseudocode conventions in [CLRS, §2.1]). You must use Θ-notation. For justification, provide execution cost and frequency count for each line in the body of the secret procedure. Optionally, you may provide the details for the computation of the running time T (n) for worst case scenario. Proof for the asymptotic bound is not required for this exercise.
```python
# A is 0-indexed array, n is the size of A
def secret(A: list, n: int) -> None:
	for i in range(1, n + 1):
		s = 1
		j = i - 1
		while j < n and A[j] >= A[i-1]:
			j += s
			s += 2
		A[i-1], A[min(j, n - 1)] = A[min(j, n - 1)], A[i-1]
```

| Line | Execution Cost | Frequency Count       |
| ---- | -------------- | --------------------- |
| 3    | $c_3$          | $n + 1$               |
| 4    | $c_4$          | $n$                   |
| 5    | $c_5$          | $n$                   |
| 6    | $c_6$          | $\sum_{i=1}^n(t_i+1)$ |
| 7    | $c_7$          | $\sum_{i=1}^n t_i$    |
| 8    | $c_8$          | $\sum_{i=1}^n t_i$    |
| 9    | $c_9$          | $n$                   |
In the above, we can see the value on each iteration: $s = 1 + 2t_i$ and $j = i - 1 + \sum_{k=1}^{t_i}(1 + 2k) = i - 1 + t_i^2$
We know that in the end of iterations $j≥n$. Hence,
$i - 1 + t_i^2 ≥ n$
$t^2_i ≥ n - i + 1$
$t_i ≥ \sqrt{n-i+1}$
$t_i≥\sqrt{n}$
<u>Answer</u>: $\Theta(n\sqrt{n})$
# Problem 2. Asymptotic Table
Indicate, for each pair of expressions $(A, B)$ in the table below whether $A= O(B),\ A= o(B),\ A = Ω(B),\ A= ω(B),$ or $A = Θ(B)$. Write your answer in the form of the table with YES or NO written in each cell:


| $A$                        | $B$                           | $A= O(B)$ | $A= o(B)$ | $A = \Omega(B)$ | $A= \omega(B)$ | $A = \Theta(B)$ |
| -------------------------- | ----------------------------- | --------- | --------- | --------------- | -------------- | --------------- |
| $1 + \sin(n)$              | $(1+\frac{1}{n})^\frac{1}{n}$ | YES       | NO        | NO              | NO             | NO              |
| $\sqrt[5]{n}$              | $\log^2_3{n}$                 | NO        | NO        | YES             | YES            | NO              |
| $n^2$                      | $\log_2^n{n}$                 | YES       | YES       | NO              | NO             | NO              |
| $(1+\frac{1}{10^{100}})^n$ | $n^{(10^{100})}$              | NO        | NO        | YES             | YES            | NO              |
| $\log_2((n+1)!)$           | $n\log_2 n$                   | YES       | NO        | YES             | NO             | YES             |
## Brief Explainations
1. $1+\sin(n)$ oscillates between values, and $\lim_{n\rightarrow \infty}1+\sin(n) = \sqrt{e} \approx 1.6$.
2. Logarithmic function grows slower than linear. Hence, it cannot be an upper-bound.
3. Here logarithmic function takes exponential growth (the power of $n$), which makes it grow faster than parabolic.
4. Again, exponential growth is faster than polynomial at some point of time.
5. Using Sterling's approximation, 

# Problem 3. 

1. Let f and g be functions from positive integers to positive reals. Assume f (n) > n for n > 2025.

Using the formal definition of asymptotic notation [CLRS, §3.2], prove formally that

min(f (n)−√n, g(n) + n) = O(f (n) + g(n))

# References
[CLRS] Cormen, T.H., Leiserson, C.E., Rivest, R.L. and Stein, C., 2022. Introduction to algorithms, Fourth Edition. MIT press.