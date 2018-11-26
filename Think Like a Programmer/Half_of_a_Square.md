## Problem: Half of a Square

Write a program that uses only two output statements, cout << "#" and cout << "\n" to produce a pattern of hash symbols shaped like half of a perfect 5x5 square (or a right triangle)

```
#####
####
###
##
#
```

```
#include <iostream>
using std::cin;
using std::cout;

int main() {
  for (int j = 6; j > 0; j--) {
    for (int i = j-1; i > 0; i--) {
    std::cout << "#";
    }
    std::cout << "\n";
  }
}
```

## Reducing the Problem

### Problem: A Square (Half of a Square Reduction):

Write a problem theat uses only two output statements, cout << "#" and cout << "\n", to produce a pattern of hash symbols like a perfect 5x5 square:

```
#####
#####
#####
#####
#####
```

```
#include <iostream>
using std::cin;
using std::cout;

int main() {
  for (int col = 1 ; col <= 5; col++) {
    for (int row = 1; row <= 5; row++) {
    std::cout << "#";
    }
    std::cout << "\n";
  }
}
```

### Problem: A Line (Half of a Square - Further Reduction)

Write a program that ueses only two output statements, cout << "@" and cout "\n" to produce a line of five symbols.

```
#include <iostream>
using std::cin;
using std::cout;

int main() {
    for (int row = 1; row <= 5; row++) {
    std::cout << "#";
    }
    std::cout << "\n";
}
```

### Problem: Count Down By Counting Up

Write a line of code that goes in the desginated position in the loop in the listing below. The program redisplays the numbers 5 through 1, in that order, with each number on a separate line.

```
#include <iostream>
using std::cin;
using std::cout;

int main() {
    for (int row = 1; row <= 5; row++) {
    std::cout << 6 - row << "\n";
    }
}
```

### Problem: A Sideways Triangle

Write a program that uses only two output statements, cout << "#" and cout << "\n" to produce a pattern of hash symbols shaped like a sideways triangle:

```
#
##
###
####
#####
####
###
##
#
```
