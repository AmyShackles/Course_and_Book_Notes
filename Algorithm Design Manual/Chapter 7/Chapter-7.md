## Chapter 7: Combinatorial Search and Heuristic Methods

### Backtracking

Backtracking is a systematic way to iterate through all possible configurations of a search space. The configuration may represent all possible arrangements of objects (permutations) or all possible ways of building a collection of them (subsets).

Backtracking creates a tree of partial solutions where each vertex represents one partial solution. An edge exists from _x_ to _y_ if node _y_ was created by advancing from _x_. The process of constructing solutions corresponds to doing depth-first traversal of the backtrack tree.

Backtrack-DFS(A, k)

&nbsp;&nbsp;&nbsp;&nbsp;if A = (a<sub>1</sub>, a<sub>2</sub>, ...a<sub>k</sub>) is a solution, report it<br/>
&nbsp;&nbsp;&nbsp;&nbsp;else<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;k = k + 1<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;compute S<sub>k</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;while S<sub>k</sub> does not equal 0 do<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;a<sub>k</sub> = an element in S<sub>k</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;S<sub>k</sub> = S<sub>k</sub> - a<sub>k</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Backtrack-DFS(A, k)

Breadth-first would also work, but takes up more space. Current state of search represented by path from root to current search depth-first node. Requires space proportional to height of tree. In breadth-first search, the queue stores all nodes at the current level, proportional to the width of the tree.

```
bool finished = False; /* found solution yet? */
backtrack(int a[], int k, data input) {
    int c[MAXCANDIDATES]; /* candidates for next position */
    int ncandidates; /* next position candidate count */
    int i; /* counter */
    if (is_a_solution(a, k, input))
        process_solution(a, k, input);
    else {
        k = k + 1;
        construct_candidates(a, k, input, c, ncandidates);
        for (i = 0; i <= ncandidates; i++) {
            a[k] = c[i];
            make_move(a, k, input);
            backtrack(a, k, input);
            unmake_move(a, k, input);
            if (finished) return; /* terminate early */
        }
    }
}
```

Backtracking ensures correctness by enumerating all possibilities and efficiency by never visiting a state more than once.

Because each candidate array _c_ is allocated with each recursive procedure call, subsets of not-yet-considered extension candidates at each position will not interfere with each other.

The application-specific parts of the algorithm consist of five subroutines:

- _is_a_solution(a, k, input)_ - Boolean function to test whether the first _k_ elements of vector _a_ form a complete solution for the problem. The last argument, _input_, allows the passing of infomration into the routine such as the size of the target solution

- _construct_candidates(a, k, input, c, ncandidates)_ - The routine fills an array _c_ with the complete set of possible candidates for the _kth_ position of _a_, given the contents of the first _k - 1_ positions. The number of candidates returned is denoted by _ncandidates_. _input_ can be used to pass additional information to the function.

- _process_solution(a, k, input)_ - Prints, counts, or otherwise processes the complete solution once created.

- _make_move(a, k, input_ and _unmake_move(a, k, input)_ - Allows us to modify data structure based on moves and clean up if we decide to undo moves.

The global finished flag allows for early termination

### Constructing all Subsets

```
is_a_solution(int a[], int k, int n) {
    return (k == n); /* is k == n? */
}
```

```
construct_canddidates(int a[], int k, int n, int c[], int *ncandidates) {
    c[0] = True;
    c[1] = False;
    *ncandidates = 2;
}
```

```
process_candidates(int a[], int k) {
    int i; /* counter */
    printf("{");
    for (i = 1; i <= k; i++)
        if (a[i] == True) printf(" %d", i);
    printf(" }\n");
}
```

```
generate_subsets(int n) {
    int a[NMAX]; /* solution vector */
    backtrack(a, 0, n);
}
```

There are 2<sup>2</sup> subsets.

### Constructing all Permutations

Counting permutations is a necessary prerequisite to generating them.

```
construct_candidates(int a[], int k, int n, int c[], int *ncandidates) {
    int i; /* counter */
    bool in_perm[NMAX]; /* what's in the permutation */
    for (i = 1; i < NMAX; i++) in_perm[i] = False;
    for (i = 0; i < k; i++) in_perm[ a[i] ] = True;

    *ncandidates = 0;
    for (i = 1; i <= n; i++)
        if (in_perm[i] == False) {
            c[ *ncandidates] = i;
            *ncandidates = *ncandidates + 1;
        }
}
```

Testing if _i_ is a candidate for the _kth_ slot in the permutation can be done by iterating through all _k - 1_ elements and verifying none matched, but setting up a bit-vector data structure allows us to perform the legality check in O(1) time.

Completing the job requires specifying _process_solution_ and _is_a_solution_ and setting the appropriate arguments to backtrack. Essentially the same as with subsets:

```
process_solution(int a[], int k) {
    int i; /* counter */
    for (i = 1; i <= k; i++) printf(" %d", a[i]);
    printf("\n");
}
```

```
is_a_solution(int a[], int k, int n) {
    return k == n;
}
```

```
generate_permutations(int n) {
    int a[NMAX]; /* solution vector */
    backtrack(a, 0, n);
}
```

### Constructing All Paths in a Graph

Starting point of any path from _s_ to _t_ always starts with _s_ so _s_ is the only candidate for the first position and _S<sub>1</sub> = {s}_. Possible candidates for second position are vertices _v_ such that _{s, v}_ is an edge of the graph. In general, _S<sub>k</sub>_ consists of the set of vertices adjacent to _a<sub>k</sub>_ that have not been used elsewhere in the partial solution _A_.

```
construct_candidates(int a[], int k, int n, int c[], int *ncandidates) {
    int i; /* counter */
    bool in_sol[NMAX]; /* what's already in the solution */
    edgenode *p; /* temporary pointer */
    int last; /* last vertex on current path */
    for (i = 1; i < NMAX; i++) in_sol[i] = Fa;se;
    for (i = 1; i < k; i++) in_sol[a[i]] = True;
    if (k == 1) {
        c[0] = 1; /* always start from vertex 1 */
        *ncandidates = 1;
    }
    else {
        *ncandidates = 0;
        last = a[k-1];
        p = g.edges[last];
        while (p != NULL) {
            if (!in_sol[p->y]) {
                c[*ncandidates] = p->y;
                *ncandidates = *ncandidates + 1;
            }
            p = p->next;
        }
    }
}
```

```
is_a_solution(int a[], int k, int t) {
    return a[k] == t;
}
```

```
process_solution(int a[], int k) {
    solution_count++; /* count all s to t paths */
}
```

### Search Pruning

_Pruning_: A technique of cutting of search the instant it is established that a partial solution could not be extended to a full solution.

### Take Home Lesson

Combinatorial searches, when augmented with tree pruning techniques, can be used to find the optimal solution of small optimization problems. How small depends on the problem, but typical size limits are somewhere between 15 ≤ n ≤ 50 items.

### Sudoku

Backtracking lends itself to solving a Sudoku puzzle

```
#define DIMENSION 9; /* 9 x 9 board */
#define NCELLS DIMENSION * DIMENSION /* 81 cells */

typedef struct {
    int x, y; /* x and y coordinates of point */
} point;

typedef struct {
    int m[DIMENSION+1][DIMENSION+1]; /* matrix of board contents */
    int freecount; /* how many open squares left */
    point move[NCELLS+1]; /* how did we fill spaces? */
} boardtype;
```

Constructing the options for the next solution position requires picking the open square to fill next (next_square) and identifying which numbers are options to fill the square (possible_values)

```
construct_candidates(int a[], int k, boardtype *board, int c[], int *ncandidates) {
    int x, y; /* position of next move */
    int i; /* counter */
    bool possible[DIMENSION+1]; /* possible for square */
    next_square(&x, &y, board); /* which square to fill next */

    board->move[k].x = x; /* store choice for next position */
    board->move[k].y = y;
    *ncandidates = 0;

    if((x < 0) && (y <0)) return; /* error condition - no moves possible */

    possible_values(x, y, board, possible);
    for (i = 0; i <= DIMENSION; i++)
        if (possible[i] == True) {
            c[*ncandidates] = i;
            *ncandidates = *ncandidates + 1;
        }
}
```

```
make_move(int a[], int k, boardtype *board) {
    fill_board(board->move[k].x, board->move[k].y, a[k], board);
}
```

```
unmake_move(int a[], int k, boardtype *board) {
    free_space(board->move[k].x, board->move[k].y, board);
}
```

```
is_a_solution(int a[], int k, boardtype *board) {
    if (board->freecount == 0)
        return True
    else
        return False
}
```
