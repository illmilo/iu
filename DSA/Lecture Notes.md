----
# I. Algorithm Analysis
**Algorithm analysis** determines dependence between *resources requirements* (time (*execution speed*) and space (*memory*)) and the *size of input data*.
## Asymptotic Complexity
1. **Upper** & **lower bounds** for $T(n)$ as $n\rightarrow\infty$.
2. **Order of growth**, not particular inputs.

![[graphic.png]]
## Time-Space Trade-off
Increase **space/time** complexity $\implies$ decrease **time/space** (correspondingly) complexity.
## Asymptotic Notation
Exist constant $c$ and $n_0$ such that for all $n≥n_0$:
$$f(n)=O(g(n)) \iff f(n)≤c\cdot g(n)$$
$$f(n)=\Omega(g(n))\iff f(n)≥c\cdot g(n)$$
Exist constants $c_1, c_2$ and $n_0$ such that for all $n≥n_0$:
$$f(n)=\Theta(g(n)) \iff c_1\cdot g(n)≥f(n)≥c_2\cdot g(n)$$
-----
For any constant $c$ exists $n_0$ such that for all $n≥n_0$:
$$f(n)=o(g(n))\iff f(n)<c\cdot g(n)$$
$$f(n)=\omega(g(n)) \iff f(n)>c(g(n))$$
<img class="center" src="definition via limits.jpg" width="40%">
## Aggregate (Amortized) Analysis
$$\sum_{i=1}^n \widehat{c_i}≥\sum_{i=1}^n c_i$$
### Accounting Method
- We assign **amortized costs** for each operation. Some operations will simply **prepay** for other operations. 
- When other operation appears, it cost is already prepayed and is laid in **"bank"**.
### Potential Method
**Potential method** represents the prepaid work as **potential energy**, which can be released to pay for future operations.
- Perform $n$ operations, starting with an initial data structure $D_0$.
- For each $i = 1, …, n$, we let $c_i$ be the **actual** cost of the $i$-th operation, and $D_i$ be the data structure that **represents** after applying the $i$-th operation to $D_{i-1}$. 
- A potential function $\Phi$ will **map** each data structure $D_i$ to a **real number** $\Phi(D_i)$, which is the **potential** associated with data structure $D_i$.
- The **amortized cost** $\widehat{c_i}$ of the $i$-th operation:
$$\widehat{c_i}=c_i+\Phi(D_i)-\Phi(D_{i-1})$$
By this equation, for $n$ operations, **amortized cost** will be:
$$\sum_{i=1}^n\widehat{c_i}=\sum_{i=1}^n c_i + \Phi(D_n)-\Phi(D_0)$$
# II. Elementary Data Structures
## Abstract Data Type (ADT)
**Abstract Data Type (ADT)** is a *mathematical model*. Requirements:
- Operations
- Input-output domains for such operations
- Properties of operations
We can call it *an interface* (Java) or *an abstract class* (C++).
## Data Structures (DS)
It is a *representation of data and associated operations*. Basically, *an implementation* of [[#Abstract Data Type (ADT)]].
Ways to structure data:
- Allocation of memory
- Array-based
### List

| Operation                  | Array List (AL)               | Single-Linked List (SLL) | Double-Linked List (DLL)    |
| -------------------------- | ----------------------------- | ------------------------ | --------------------------- |
| `size()`<br>`isEmpty()`    | $$O(1)$$            | $$O(1)$$       | $$O(1)$$          |
| `get(i)`<br>`set(i, e)`    | $$O(1)$$            | $$O(i)$$       | $$O(min(i,n-i))$$ |
| `add(i, e)`<br>`remove(i)` | $$O(min(i,n-i))^*$$ | $$O(i)$$       | $$O(min(i,n-i))$$ |
| `addFirst(e)`              | $$O(n)$$            | $$O(1)$$       | $$O(1)$$          |
| `addLast(e)`               | $$O(1)^*$$          | $$O(n)$$       | $$O(1)$$          |
| `removeFirst()`            | $$O(n)$$            | $$O(i)$$       | $$O(min(i,n-i))$$ |
| `removeLast()`             | $$O(n)$$            | $$O(n)$$       | $$O(1)$$          |
### Stack & Queue

| Operation   | Array Stack or Queue | Linked Stack or Queue |
| ----------- | -------------------- | --------------------- |
| `size()`    | $$O(1)$$   | $$O(1)$$    |
| `isEmpty()` | $$O(1)$$   | $$O(1)$$    |
| `push(e)`   | $$O(1)^*$$ | $$O(1)$$    |
| `pop()`     | $$O(1)$$   | $$O(1)$$    |
| `peek()`    | $$O(1)$$   | $$O(1)$$    |
According to the table, we conclude that Array implementation of Stack and Queue is *worse* than Linked.
# III. Hash Table
**Requirements:**
- An array of size $N$
- A **hash function** $h:U\rightarrow{0,1,...,N-1}$
- A **hash collision** handling strategy
## Separate Chaining

<img class="center" src="Screenshot 2025-02-12 at 3.12.29 PM.png" width="70%">

It is a **hash collision handling strategy.**
1. Put all entries with the same key hash at the same index.
2. Store a list of entries.
3. Connect to a double list.
$$\alpha = \frac{n}{m},$$
where $\alpha$ is the **load factor**, $n$ is the **number of entries**, $m$ is the **size of the hash table**.
Average length of a chain will be equal to $\alpha$.
## Open Addressing
<img src="Screenshot 2025-02-12 at 3.40.48 PM.png" align="right" width="10%">

It is another **hash collision handling strategy**.
1. Store **at most one** entry at each slot.
2. If slot is occupied, **prove** the next slot (according to some rules).
3. For every key, we have a **probing sequence** $h(k, 0), …, h(k, m-1)$.
4. The **probing sequence** is a permutation of $\{0,1,…,m-1\}$.
### Double Hashing
Has a **probing sequence** $h(k,i)=(h_1 k + i \cdot h_2k)\mod m$
Define **hashing function** $h_1(k)$, which is a **starting index**, and $h_2(k)$, which is a **step**.
### Linear Probing
Has a **probing sequence** $h(k,i)=(h_1 k + i) \mod m$. It is a **special case of [[#Double Hashing]]** when **step** = 1.
$$\alpha=\frac{n}{m}≤1$$
Average number of probes needed will be approximately $\frac{1}{1-\alpha}$.
## Summary

| Operation       | Separate Chaining                                  | Open Addressing   |
| --------------- | -------------------------------------------------- | ----------------- |
| put(key, value) | $O(1+\alpha)$                                      | $O(1/(1-\alpha))$ |
| get(key)        | $O(1+\alpha)$                                      | $O(1/(1-\alpha))$ |
| remove(entry)   | $O(1+\alpha)$ if scan<br>$O(1)$ by reference (DLL) | $O(1)$            |
## Hash Functions
<img src="Screenshot 2025-02-12 at 4.18.20 PM.png" align="right" width="30%">

### Hash Codes
+ **Memory address** as a hash code.
	- Address of an object is an integer. 
	- Not reproducible (same keys – different hash codes)
+ **Cast** to an integer
	- Bit representation is an integer
	- Not for large keys
+ **Sum of components**
	+ Bit representation into words and sum up
	+ Different permutations (i. e., "abc", "cba", …) hash into same code
+ **Polynomial accumulation**
	- Like sum, but with coefficients of polynomial: $p(z)=a_0+a_1z+a_2z^2+…+a_nz^n$
### Compression Functions
- **Division** method
	- $h(k) = k\mod m$
- **Multiply-add** method
	- $h(k) =[(ai + b)\mod p] \mod m$, where $p$ is a *prime* ≥ $m$
	- Used in random number generation
	- Tunable parameters $a, b, p$
# IV. Divide and Conquer
Effective algorithm for solving problems via recursion.
1. **Divide** the problem into subproblems
2. **Conquer** the subproblems by solving them recursively
3. **Combine** the subproblem solutions to form a solution to the original problem
### Recursion
A function is called **recursive** if it calls itself. It contains a **base case** and a **recursive case**.
### Master Theorem
$$T(n)=aT(n/b) + f(n),$$
where $a$ is the number of recursive calls,
$b$ is the amount of division we apply to substitude our algorithm into smaller subtasks,
$f(n)$ is the cost of **divide+combine** operations we do.

**3 cases of Master Theorem**:
1. If $\exists \epsilon > 0$ such that $f(n)=O(n^{\log_b a - \epsilon})$, then $T(n)=\Theta(n^{\log_b a})$ 
2. If $\exists k≥0$ such that $f(n) = \Theta(n^{\log_b a} \lg^k n)$, then $T(n) = \Theta(n^{log_b a}\lg^{k+1}n)$ 
3. If $\exists \epsilon>0$ such that $f(n)=\Omega(n^{log_ba+\epsilon})$, and if $f(n)$ satisfies the **regularity condition** $af(n/b)≤cf(n)$ for some $c<1$ and all sufficiently large $n$, then $T(n)=\Theta(f(n))$.
