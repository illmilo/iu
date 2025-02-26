Solutions by **Milena Kuznetsova**. m.kuznetsova@innopolis.university

----
In a fictional multiplayer video game “Dragons and Pirates”, each player can select one of tree character classes: a Knight, a Pirate, or a Cook. A team of 5 players wants to optimize their chances at the game by choosing the right combination of classes for each player in the team. When multiple players take the same class, their powers overlap, leading to an uneven increase in performance. For example, in the game multiple Knights cannot attack an enemy simultaneously, so overall performance metric for three Knights is less than three times the performance of a single Knight.

The table below gives the estimated performance for each character class for each possible number of players of the same class. Total performance of a team is the sum of performances for each class.
# Problem 1
Describe a general algorithm that would find an optimal class assignments for any number P of players, any number C of classes, and table E with estimates:
- Summarize the idea for a na ̈ıve recursive algorithm.
- Clearly identify overlapping subproblems [CLRS, §14.3] (provide an explicit example for this problem).
- Write down pseudocode for the dynamic programming [CLRS, §14] algorithm that solves the problem (top-down or bottom-up). It is enough to compute the optimal performance without keeping track of the exact class assignments.
# Problem 2
Provide asymptotic worst-case time complexity with justification
- for the na ̈ıve recursive algorithm  
- for the dynamic programming algorithm
# Problem 3
Apply the dynamic programming algorithm to an instance of the problem below with 3 classes and 6 players:
- What is the best possible performance? What combination of classes gives that perfor- mance?
- Provide the table with solutions used in the dynamic programming algorithm for subprob- lems that are computed in the algorithm.

| Number of players | 0   | 1   | 2   | 3   | 4   | 5   | 6   |
| ----------------- | --- | --- | --- | --- | --- | --- | --- |
| `Knight`          | 0| 12 |23 |33 |42 |55 |62 
| `Pirate`          | 0   |13| 24 |33| 40| 45| 50 
| `Cook`            | 0   |11| 22| 34| 43| 52| 61

References

[CLRS] Cormen, T.H., Leiserson, C.E., Rivest, R.L. and Stein, C., 2022. Introduction to algo- rithms, Fourth Edition. MIT press.

Data Structures and Algorithms, Spring 2025, Innopolis University