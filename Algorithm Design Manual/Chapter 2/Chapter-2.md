## Chapter 2: Algorithm Analysis

#### Random Access Memory (RAM) Computation Model:

- Each imple operation (x, \*, -, =, if, call) takes one time step
- Loops and subroutines take `n` time steps
- Each memory access takes one time step

#### Take-Home Lesson:

Algorithms can be understood and studied in a language and machine-independent manner.

#### Best, Worst, and Average-Case Complexity

You could represent every possible instance of data to an algorithm on a graph, using the `x-axis` to represent the size of the input problem and the `y-axis` to represent the number of steps taken for that instance. We can define three interesting functions over the plot of those points:

- The `worst-case complexity` of the alorithm is the function defined by the maximum number of steps taken in any instance of size `n`. This represents the curve passing through the highest point in each column. This is the one we care the most about.

- The `best-case complexity` of the algorithm is the function defined by the minimum number of steps taken in any instance of size `n`. This represents the curve passing through the lowest point of each column.

- The `average-case complexity` of the algorithm, which is the function defined by the average number of steps over all instances of size `n`.

#### The Big Oh Notation

It is difficult to deal directly with the functions of best, worst, and average case because they tend to:

- Have too many bumps
- Require too much detail to specify precisely

Big Oh notation ignores the difference between multiplicative constants. The function f(n) = 2n and g(n) = n are identical in Big Oh analysis. Suppose a given algorithm in C ran twice as fast as one with the same algorithm written in Java. The multiplicative of two tells us nothing about the algorithm itself since both programs implement the same algorithm. We ignore such constant factors when comparing two algorithms.

Formal definitions associated with the Big Oh notation are as follows:

- _f(n)_ = _O(g(n))_ means _c <sup>.</sup> g(n)_ is an _upper bound_ on _f(n)_. Thus there exists some constant _c_ such that _f(n)_ is always <= _c <sup>.</sup> g(n)_ for large enough _n_ (i.e., _n_ >= _n<sub>0</sub>_ for some constant _n<sub>0</sub>_).

- _f(n)_ = _Ω(g(n))_ means _c <sup>.</sup> g(n)_ is a _lower bound_ on _f(n)_. Thus there exists some constant _c_ such that _f(n)_ is always >= _c <sup>.</sup> g(n)_ for all _n >= n<sub>0</sub>_.

- _f(n) = ϴ(g(n))_ means _c<sub>1</sub> <sup>.</sup> g(n)_ is an upper bound on _f(n)_ and _c<sub>2</sub> <sup>.</sup> \_g(n)_ is a lower bound on _f(n)_, for all _n_ >= _n<sub>0</sub>_. Thus there exist constants _c<sub>1</sub>_ and _c<sub>2</sub>_ such that _f(n) <= c<sub>1</sub> <sup>.</sup> g(n)_ and _f(n) >= c<sub>2</sub> <sup>.</sup> g(n)_. This means that _g(n)_ provides a nice, tight bound on _f(n)_.

#### Take-home Lesson:

The Big Oh notation and worst-case analysis are tools that greatly simplify our ability to compare the efficiency of algorithms.

#### Says to work through these examples, but I won't:

- 3n<sup>2</sup> - 100n + 6 = O(n<sup>2</sup>), because I choose _c_ = 3 and 3n<sup>2</sup> > 3n<sup>2</sup> - 100n + 6;

- 3n<sup>2</sup> - 100n + 6 = O(n<sup>3</sup>), because I choose _c_ = 1 and n<sup>3</sup> > 3n<sup>2</sup> - 100n + 6 when n > 3;

- 3n<sup>2</sup> - 100n + 6 ≠ O(n), because for any _c_ I choose c x n < 3n<sup>2</sup> when n > c;

---

- 3n<sup>2> - 100n + 6 = Ω(n<sup>2</sup>), because I choose _c_ = 2 and 2n<sup>2</sup> < 3n<sup>2</sup> - 100n + 6 when n > 100;

- 3n<sup>2</sup> - 100n + 6 ≠ Ω(n<sup>3</sup>), because I choose _c_ = 1 and 3n<sup>2</sup> - 100n + 6 < n<sup>3</sup> when n > 3;

- 3n<sup>2</sup> - 100n + 6 = Ω(n), because for any _c_ I choose _cn_ < 3n<sup>2</sup> - 100n + 6 when n > 100c;

---

- 3n<sup>2</sup> - 100n + 6 = ϴ(n<sup>2</sup>), because both O and Ω apply;

- 3n<sup>2</sup> - 100n + 6 ≠ ϴ(n<sup>3</sup>), because only O applies;

- 3n<sup>2</sup> - 100n + 6 ≠ ϴ(n), because only Ω applies;

#### Stop and think: Back to the definition:

_Problem_: Is 2<sup>n+1</sup> = ϴ(2<sup>n</sup>)?

_Solution_:
All Big Oh problems can be correctly solved by going back to the definition and working with that.

- Is 2<sup>n+1</sup> = O(2<sup>n>)? Well, _f(n)_ = _O(g(n))_ iff (if and only if) there exists a constant that for all sufficiently large _n f(n) <= c <sup>.</sup> g(n)_. Is there? The key observation is that 2<sup>n+1</sup> = 2 <sup>.</sup> 2<sup>n</sup>, so 2 <sup>.</sup> 2<sup>n</sup> <= c <sup>.</sup> 2<sup>n</sup> for any c >= 2.

- Is 2<sup>n+1</sup> = Ω(2<sup>n</sup>)? Go back to the definition. _f(n) = Ω(g(n))_ iff there exists a constant _c_ > O such that for all sufficiently large _n f(n) >= c <sup>.</sup>g(n)_. This would be satisfied for any O < c <= 2. Together the Big Oh and Ω bounds imply 2<sup>n+1</sup> = Θ(2<sup>n</sup>)

#### Stop and Think: Hip to the Squares?

_Problem_: Is (x+y)<sup>2</sup> = O(x<sup>2</sup> + y<sup>2</sup>)?

_Solution_:

Working with Big Oh means going back to the definition. By definition, the expression is valid iff we can find some _c_ such that (x+y)<sup>2</sup> <= c(x<sup>2</sup> + y<sup>2</sup>).
