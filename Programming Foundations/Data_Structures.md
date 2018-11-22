## Introduction

**Data Structure** - An intentional arrangement of data

We naturally think in collections of information.

A recipe is a data structure, as is a shopping list, a flight schedule, bank statement, etc.

Focus of this course is data structures created and held in memory in a running computer program.

## Data Structures

Basic need for data structure: Want to enforce systematic organization, group variables together and treat it as one item

In computer science:

- **Record** - is a value that itself contains other values (contains fields)
- **Field** - single piece of information within a record

In math:

- **tuple** - grouped sequence of elements

How do we implement records/fields/tuples in a programming language?

## Using C-Style structs

```
// define the struct
struct Book {
string title;
double price;
bool isPublished;
bool isHardback;
};

// create a variable with that struct type
Book first;

// set member variables
first.title = "Dark and Stormy Night";
first.price = 12.95
first.isPublished = true;
first.isHardback = false;
```

What's the difference between a struct and a class?
| struct | class |
|:---------------------------------:|:-----------------------------------:|
| only data - no behavior | behavior and data |
| simple creation | explicit instantiation (new, alloc) |
| value types | reference types |
| no object-oriented-features | polymorphism, inheritance, etc. |
| "Plain Old Data Structure" (PODS) | |

## Plain Old Data Structure: Examples

```
struct Point {
    int x;
    int y;
};

Point startPosition;
startPosition.x = 50
startPosition.y = 50;

Point finishPosition;
finishPosition.x = 500;
finishPosition.y = 100;

myObject.animate(startPosition, finishPosition);
```

```
struct Color {
    int red;
    int green;
    int blue;
    int alpha;
};

Color backgroundColor;
backgroundColor.red = 255;
backgroundColor.green = 0;
backgroundColor.blue = 0;
backgroundColor.alpha = 255;

myWindow.setBackground(backgroundColor);
```

## Language support for structs

| Language       | Support                                                |
| -------------- | ------------------------------------------------------ |
| Objective-C    | As in C, used in many Apple frameworks                 |
| C# /other .NET | Also allows basic behavior to be added                 |
| Java           | Do not exist - closest equivalent is lightweight class |
| Python         | Do not exist                                           |
| Ruby           | Exist, though implemented as lightweight class         |
