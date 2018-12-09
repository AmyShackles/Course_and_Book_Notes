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
