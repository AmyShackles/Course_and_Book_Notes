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

## Array

- Ordered collection of items, multiple independent values contained in one named container
- Most commonly used data structure
- Support for simple arrays is usually built in
- Each element has an index
- You can get to any element knowing its index

### Simple Arrays:

- Usually, 0-based integer index
- Fixed size (immutable)
- Specific data type

Misconception: Simple Arrays are just from the olden days, should use dynamic arrays without data restrictions if you can.

- The more constraints you can put in place, the faster and smaller your data structure is able to be

_Flexibility introduces overhead_

### Using Multidimensional Arrays (Matrix/Table)

Access elements (row index, column index)
Useful for representing real-world situations

- Example: temperature readings (day/hours), chess board
  If you understand the idea of a cell phone bill for a multi-person family plan, you can grasp a multi-dimensional array

## Using Jagged Arrays

Choosing to do a little more work up front to allow logic to not have to be added later
Having internal arrays of differing sizes
Example: If you need to represent days in a month, there are varying numbers of days in a month

Pseudocode:

```
int[][] ticketSales = new int[12][]
for each month in ticketSales
    if april, june, september, november
        create array of 30 elements
    else if february and leap year
        create array of 29 elements
    else if february and not leap year
        create array of 28 elements
    else
        create array of 31 elements
    end if
    add array to ticketSales[month]
end for
```

## Resizeable (Dynamic, Mutable) Arrays

### Simple fixed-size arrays: Java

```
String[] fixedArray = new String[3];

fixedArray[0] = "This";
fixedArray[1] = "Cannot";
fixedArray[2] = "Grow";
```

### Resizable arrays: Java

```
// need to import
import java.util.*;

// create arraylist of strings
List<String> resizeable = new ArrayList<String>();

resizeable.add("This");
resizeable.add("Is");
resizeable.add("Resizeable");
```

### Fixed arrays: Objective-C

```
//NSArray used for arrays of objects - fixed size
NSArray \*myFiexedArray = @[@"one", @"two", @"three"];
```

### Resizeable arrays: Objective-C

```
// NSMutableArray is the resizeable version
NSMutableArray *resizeable = [[NSMutableArray alloc]init];

[resizeable addObject:@"one"];
[resizeable addObject:@"two"];
[resizeable addObject:@"three"];
```

### Adding new elements: location?

- Adding an element at the end is easier, faster, and takes less work
- Adding anywhere else requires moving other elements around
  - Just because something is happening in the background doesn't mean you can ignore that it's happening

## Appending items at the end of the array

| Language    | Method          |
| ----------- | --------------- |
| Java        | add(value)      |
| Objective-C | addObject:value |
| JavaScript  | push(value)     |
| Ruby        | push(value)     |
| Python      | append(value)   |

## Inserting items at a specific index

| Language    | Method                                          |
| ----------- | ----------------------------------------------- |
| Java        | add(index, value)                               |
| Objective-C | addObject:value atIndex:index                   |
| JavaScript  | splice(index, items_to_remove, items_to_insert) |
| Ruby        | insert(index, value)                            |
| Python      | insert(index, value)                            |

## Removing items from an array

| Language    | Method                    |
| ----------- | ------------------------- |
| Java        | remove(index)             |
| Objective-C | removeObjectAtIndex:index |
| JavaScript  | pop / slice               |
| Ruby        | pop / delete_at           |
| Python      | pop / remove              |

## Five requirements of any data structure

- How to **Access** (one item/ all items)
- How to **Insert** (at end/ at position)
- How to **Delete** (from end/ from position)
- How to **Find** (if exists/ what location)
- How to **Sort** (sort in place/ created sorted version)

Often won't get all five

- Most won't support search
- Many don't provide sorting behavior (others are naturally sorted and keep themselves organized)

## Sorting Arrays

Will typically use the sort built in to the language because it's battle-tested

Built-in sorting tends to look at the length of the array in order to figure out what implementation to use

Most languages will attempt to sort in-place

There are a few that create a sorted copy of the array

Need to understand which one your language is doing

Sorting is always computationally intensive - keeping conscious of how much data you have and how often you need it sorted may lead you to changing data structure

## Sorting Custom Objects

If you have an array of objects with multiple pieces of data, you want to control how that's sorted

Will need to provide a little bit of logic, comparator or compare function

Sorting is hard, comparing is easy

### Example Comparator/ Compare Function:

```
PseudoCompare (Employee a, Employee b)
    if a.lastName < b.lastname return -1 // less than
    if a.lastname > b.lastname return 1 // greater than
    if a.lastname == b.lastname
        if a.firstname < b.firstname return -1 // less than
        if a.firstname > b.firstname return 1 // greater than
        if a.firstname == b.firstname return 0 // equal
    end if
end
```

## Searching Arrays

### Linear (sequential) search: O(n) complexity

```
set i to 0
while i < array.length
    if array[i] == 99
        return true
    end if
    add 1 to i
end while
return false
```

Best case: element at [0]
Worst case: Not in array

If you have a simple array and the items can be in any order, a linear search may be what you have to do.

If there's no predictable order, no other option than to check all the items

If the array is ordered, there are better ways of searching

If searching is something you're going to want to do, having an order may be important

Asking a data structure to sort is computationally demanding.

- May settle for a slow search because it is less computationally exhaustive than keeping sort

## Using built-in search behavior

```
if (myArray.contains(99) ) {
    log("Yes, it exists")
}
```

```
// for specific location
int result = myArray.indexOf(99);

if ( result != -1) {
    log ("The value is located at position: " + result);
} else {
    log ("The object is not in the array")
end if
```

## Searching for existence / location

| Language    | Method for existence | Method for location |
| ----------- | -------------------- | ------------------- |
| Java        | contains             | indexOf             |
| Objective-C | containsObject       | indexOfObject       |
| JavaScript  |                      | indexOf             |
| Ruby        |                      | index / find_index  |
| Python      |                      | index               |
| C#          | contains             | indexOf             |

## Binary Searching

If the values in your array are in descending or ascending order

- Calculate midpoint of list rounded down
- Check if value we're searching for is at the midpoint
- If not:
  - If number at midpoint is lower than the value searching for, can ignore indexes following it
    - Advance upper index to midpoint, calculate new midpoint
  - If number at midpoint is higher than the value searching for, can ignore indexes preceding it
    - Advance lower index to midpoint, calculate new midpoint

## Binary Searching - Language Support

| Language    | Method                       |
| ----------- | ---------------------------- |
| Java        | binarySearch                 |
| C#          | Array.BinarySearch           |
| JavaScript  | n/a                          |
| Ruby        | bsearch                      |
| C++         | binary_search                |
| Objective-C | indexOfObject:inSortedRange: |

Although binary search is great for sorted array, we'll see it again going forward because it's not just useful for arrays

## Lists

In Python, fundamental data type

In Java, list is an interface (abstract definition)

In Objective-C, programmers write it themselves

In Ruby, unlikely to talk about lists

Both arrays and lists are collections (ways to collect items into one group with a name)

## Understanding Lists

If arrays are about direct access, lists are about sequential access.

Structure does not have strict numeric index

Elements can be stored anywhere in memory

When you access a list, you get the first element (first node).

A list node is a simple wrapper object (struct) that holds the element and the link to the next node.

Last element contains a terminal/sentinel node or null reference

Downside, have to access elements sequentially

### Adding / Removing Elements

While adding/removing in the middle of an array requires moving everything past that element

To add a node at the start of a list, create a new node and point it to the previous start of the list

To add to the end, create a node at the end of the list, pointing the previous end of the list to the new node.

Removing is just as easy, changing pointers.

## Comparison of Arrays and Linked Lists

|                 |                  Arrays                   |          Linked Lists           |
| :-------------: | :---------------------------------------: | :-----------------------------: |
|  Direct Access  |      **Good** <br />fixed time O(1)       | **Poor** <br />linear time O(n) |
| Adding/Removing |      **Poor** <br />linear time O(n)      | **Good** <br />fixed time O(1)  |
|    Searching    | O(n) linear search O(log n) binary search |       O(n) linear search        |

## Linked Lists

Singly linked lists - reference to next node

Doubly linked lists - reference to previous and next node

Circular doubly linked list - last element points to first element, first element's previous is last element

## Lists in Languages

Java - interface (describes behavior that another class can implement)

- Class LinkedList is a doubly-linked-list implementation
- Operations that index into the list will traverse the list from the beginning to the end or the end, whichever is closer to the specific index.

## Language Support for Linked Lists

| Language    | Support                                                |
| ----------- | ------------------------------------------------------ |
| Java        | LinkedList in java.util                                |
| C#          | LinkedList in System.Collections.Generic               |
| Objective-C | n/a                                                    |
| Ruby        | n/a                                                    |
| Python      | n/a - "lists" are dynamic arrays, **not** linked lists |
| C++         | std::list                                              |

## Stacks

Last element added to the stack is the first one out (LIFO/FILO)

Things you can do with a stack:

- Push items onto the stack
- Pop items off and return
- Peek() - look at last element added to stack without removing

## Language Support for Stacks

| Language    | Support                   |
| ----------- | ------------------------- |
| Java        | Stack (push / pop / peek) |
| C#          | Stack (Push / Pop / Peek) |
| Objective-C | use NSMutableArray        |
| Ruby        | use Array (push / pop)    |
| Python      | use lists (append / pop)  |
| C++         | std::stack (push / pop)   |

## Abstract Data Types

Stacks and Queues

- Has expected, defined behavior
- Implementation is abstracted away
- Could be implemented behind the scenes using a dynamic array
- Could also be implemented behind the scenes using a linked list

Abstract data types are not the same as an abstract class

## Using Queues

First element in is the first element out (FIFO)

Sending jobs to a printer is an example of a queue

Used in multithreading and concurrency situations

## Language Support for Queue

| Language    | Support                                            |
| ----------- | -------------------------------------------------- |
| Java        | LinkedList (add / remove)                          |
| C#          | Queue (enqueue / dequeue)                          |
| Objective-C | NSMutableArray (addObject / removeObjectAtIndex:0) |
| Ruby        | use Array (push / shift)                           |
| Python      | queue (put / get)                                  |
| C++         | std::queue (push_back / pop_front)                 |

## Priority Queues

Typically requires a comparator or compare function

Allows you to add elements to the array that can be moved closer to the front of the queue if they have a higher priority than the elements already in the queue.

## Language Support for Priority Queues

| Language    | Support             |
| ----------- | ------------------- |
| Java        | PriorityQueue       |
| C#          | n/a                 |
| Objective-C | CFBinaryHeap        |
| Ruby        | n/a                 |
| Python      | n/a                 |
| C++         | std::priority_queue |

NOTE:
Course says n/a for Python, but Python website indicates there is a PriorityQueue class:

[Priority Queue](https://docs.python.org/3.7/library/asyncio-queue.html?highlight=priority%20queue) <br />
class asyncio.PriorityQueue <br />A variant of Queue; retrieves entries in priority order (lowest first). <br />Entries are typically tuples of the form (priority_number, data).

## Using a Deque (Double-ended queue)

Can add to either end

Can remove from front or end

Can behave like a stack or a queue

**Caution** Deque (specialized kind of queue) vs. Dequeue (method to remove item from queue)

## Language Support for Deque

| Language    | Support                             |
| ----------- | ----------------------------------- |
| Java        | LinkedList implements Deque         |
| C#          | n/a - use LinkedList for equivalent |
| Objective-C | n/a - use NSMutableArray            |
| Ruby        | n/a - use Array                     |
| Python      | collections.deque                   |
| C++         | std::deque                          |

## Associative Arrays

- Pairs of keys and values
- Keys must be unique, values do not have to be
- Keys do not need to be in order
- Values can be objects
- Common to use a string as a key, but can use any type

## Language Support for Associative Arrays

| Language    | Support               |
| ----------- | --------------------- |
| Java        | HashMap, HashTable    |
| C#          | Hashtable, Dictionary |
| Objective-C | NSDictionary          |
| Ruby        | Hash                  |
| Python      | dict                  |
| C++         | std::unordered_map    |
| Javascript  | objects               |

Behind the scenes, most associative arrays are implemented using a hash table

To understand a hash table, we first need to understand a hash.
