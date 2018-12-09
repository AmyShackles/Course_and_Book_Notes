## Guidelines for Flowcharts:

- Write states and instruction steps inside rectangles
- Write decision steps, where the process might go in different directions, inside diamonds
- Never mix an instruction step with a decision step
- Connect sequential steps with arrows
- Mark the start and end of the process
  (ISO spec for how software systems diagrams should be drawn: UML - http://code.energy/UML )

#### Example: Finding maximum value between three variables:

![FlowchartExample](./flowchart.jpeg)

**Pseudocode**: Human-friendly code not understood by machines.

#### Example:

```
function maximum (A, B, C)
if A > B
    if A > C
        max <- A
    else
        max <- C
else
    if B > C
        max <- B
    else
        max <- C
print max
```

**Model**: A set of concepts that represents a problem and its characteristics

### Livestock Fence:

Your farm has two types of livestock. You have 100 units of barbed wire to make a rectangular fence for the animals with a straight division for separating them. How do you frame the fence in order to maximize the pasture area?

```
A = w x l
100 = 2w + 3l
l = (100 - 2w)/3
A = 100/3w - 2/3w^2
```

Quadratic eqautation! Set A = 0, solve the equation, and the maximum is the midway point between the two roots.

### Logic

In mathematical logic, variables and operators represent validity or truth of things.

Example statement:
"If the water is warm, I'll swim" can be broken down into two logical variables, A and B

```
A: The water is warm
B: I swim
```

Dependency between the variables is represented by a conditional operator (`->`). A->B is used to represent the idea that A = True implies B = True.

To negate ideas, use `!` operator (negation operator)

**Contrapositive**: For any two variables, A and B, `A->B = !A->!B`

**Biconditional**: If A->B and B->A, can be represented as A<->B. A->B does not necessarily mean that B->A.

|  A  |  B  | !A  | A->B | A<->B | A AND B | A OR B | A XOR B |
| :-: | :-: | :-: | :--: | :---: | :-----: | :----: | :-----: |
|  ✓  |  ✓  | ❌  |  ✓   |   ✓   |    ✓    |   ✓    |   ❌    |
|  ✓  | ❌  | ❌  |  ❌  |  ❌   |   ❌    |   ✓    |    ✓    |
| ❌  |  ✓  |  ✓  |  ✓   |  ❌   |   ❌    |   ✓    |    ✓    |
| ❌  | ❌  |  ✓  |  ✓   |   ✓   |   ❌    |   ❌   |   ❌    |

### Boolean Algebra (Simplifies logical expressions)

**Associativity**: Parentheses are irrelevant for sequences of AND or OR operations - can be calculated in any order.

```
A AND (B AND C) = (A AND B) AND C,
A OR (B OR C) = (A OR B) OR C
```

**Distributivity**: ANDing after an OR is equivalent to ORing results of ANDs and vice versa

```
A AND (B OR C) = (A AND B) OR (A AND C)
A OR (B AND C) = (A OR B) AND (A OR C)
```

**DeMorgan's Law**
"It can't be summer and winter at once, so it's either not summer or not winter. And it's not summer and not winter if and only if it's not the case it's either summer or winter" Following this logic, ANDs can be transformed into ORs and vice versa:

```
!(A AND B) = !A OR !B,
!A AND !B = !(A OR B)
```

### Problem: Hot Server

A server crashes if it's overheating while the air conditioning is off. It also crashes if it's overheating and its chassis cooler fails. In which conditions does the server work?

#### Modeling it in logical variables:

```
A:  Server overheats
B:  Air conditioning is off
C:  Chassis cooler fails
D:  Server crashes

(A AND B) OR (A AND C)->D

Distributivity: A AND (B OR C)->D
Server works when (!D)

Contrapositive: !D->!(A AND (B OR C))

DeMorgan to remove parens: !D->!A OR (B OR C)

DeMorgan again: !D->!A OR (!B AND !C)

Whenever the server works, either !A (it's not overheating)
or !B AND !C (both air conditioning and chassis cooler are working)
```

### Truth Tables

Columns for each variable, rows for possible combinations. One variable requires two rows, one for outcomes if true and one for if false.

### Problem: Fragile System

We have to create a database system with the following requirements:

```
I       If database is locked, we can save data
II      A database lock on a full write queue cannot happen
III     Either the write queue is full or the cache is loaded
IV      If the cache is loaded, the database cannot be locked

Is it possible?  Under which conditions will it work?
```

#### Model the database

```
A   The database is locked      I       A->B
B   Able to save data           II      !(A AND C)
C   Write queue is full         III     C OR D
D   Cache is loaded             IV      D->!A
```

| State # | A   | B   | C   | D   | I   | II  | III | IV  | All four |
| ------- | --- | --- | --- | --- | --- | --- | --- | --- | -------- |
| 1       | X   | X   | X   | X   | ✓   | ✓   | X   | ✓   | X        |
| 2       | X   | X   | X   | ✓   | ✓   | ✓   | ✓   | ✓   | ✓        |
| 3       | X   | X   | ✓   | X   | ✓   | ✓   | ✓   | ✓   | ✓        |
| 4       | X   | X   | ✓   | ✓   | ✓   | ✓   | ✓   | ✓   | ✓        |
| 5       | X   | ✓   | X   | X   | ✓   | ✓   | X   | ✓   | X        |
| 6       | X   | ✓   | X   | ✓   | ✓   | ✓   | ✓   | ✓   | ✓        |
| 7       | X   | ✓   | ✓   | X   | ✓   | ✓   | ✓   | ✓   | ✓        |
| 8       | X   | ✓   | ✓   | ✓   | ✓   | ✓   | ✓   | ✓   | ✓        |
| 9       | ✓   | X   | X   | X   | X   | ✓   | X   | ✓   | X        |
| 10      | ✓   | X   | X   | ✓   | X   | ✓   | ✓   | X   | X        |
| 11      | ✓   | X   | ✓   | X   | X   | X   | ✓   | ✓   | X        |
| 12      | ✓   | X   | ✓   | ✓   | X   | X   | ✓   | X   | X        |
| 13      | ✓   | ✓   | X   | X   | ✓   | ✓   | X   | ✓   | X        |
| 14      | ✓   | ✓   | X   | ✓   | ✓   | ✓   | ✓   | X   | X        |
| 15      | ✓   | ✓   | ✓   | X   | ✓   | X   | ✓   | ✓   | X        |
| 16      | ✓   | ✓   | ✓   | ✓   | ✓   | X   | ✓   | X   | X        |

All requirements are met in states 2-4 and 6-8. In those states, A = False, so database can't ever be locked. The cache will not be loaded in states 3 and 7.

### Test what you've learned by solving the Zebra Puzzle

(http://code.energy/zebra-puzzle)

#### Zebra Puzzle (15 clues, two questions):

1. There are five houses
2. The Englishman lives in the red house
3. The Spaniard owns the dog
4. The coffee is drunk in the green house
5. The Ukranian drinks tea
6. The green house is immediately to the right of the ivory house
7. The Old Gold smoker owns snails
8. Kools are smoked in the yellow house
9. Milk is drunk in the middle house
10. The Norwegian lives in the first house
11. The man who smokes Chesterfields lives in the house4 next to the man with the fox
12. Kools are smoked in the house next to the house where the horse is kept
13. The Lucky Strike smoker drinks orange juice
14. The Japanese smokes Parliaments
15. The Norwegian lives next to the blue house

Who drinks water? Who owns the zebra?
