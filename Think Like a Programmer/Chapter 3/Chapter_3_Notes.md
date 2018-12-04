# Chapter 3: Solving Problems with Arrays

We'll primarily deal with actual arrays, that is, those declared with the built-in C++ syntax such as: `int tenIntegerArray[10]`

Techniques discussed apply to data structures with similar attributes. Moxst common of these structures is a _vector_.

The term _vector_ is often used as a synonym for any array of a single dimension, but we'll use it here in the more specific sense of a structure that has the attributes of an array without a specified maximum number of elements (An array is of a fixed size, a vector can grow or shrink automatically as needed).

This chapter will have restrictions that allow us to use structures with a fixed number of elements but problems without such restrictions can use vectors.

**Array**: Collection of variables of the same type organized under one name, where individual variables are denoted by a number (subscript).

**Random access**: Any element can be accessed at any time.

## List of Basic Operations of Arrays:

**1) Store: Assigning values**
To assign integer 5 to first element of previously declared array: `tenIntegerArray[0] = 5`

_Note_: Values of the elements are "garbage" until particular values are assigned, so arrays should be initialized before use.

**Assigning a value to every element**:

```
int tenIntegerArray[10] = {4, 5, 9, 12, -4, 0, -57, 27, 3, 1}
```

**Setting every element in 10-element array to -1**:

```
int integerArray[10];
for (int i = 0; i < 10; i++) tenIntegerArray[i] = -1;
```

**2) Copy: Either because need original array after manipulation or because we want to copy parts to a new array**:

```
int tenIntegerArray[10] = {4, 5, 9, 12, -4, 0, -57, 27, 3, 1}
int secondArray[10];
for (int i = 0; i < 10; i++) secondArray[i] = tenIntegerArray[i];
```

**3) Retrieval and Search**

```
int num = tenIntegerArray[0];
```

**4) Searching for a Specific Value**:

```
const int ARRAY_SIZE = 10;
int intArray[ARRAY_SIZE] = {4, 5, 9, 12, -4, 0, -27, 30987, -287, 1};
int targetValue = 12;
int targetPos = 0;
while ((intArray[targetPos] != targetValue) && (targetPos < ARRAY_SIZE)) targetPos++;
```

_Note_: If targetValue is not found, targetPos will be equal to ARRAY_SIZE after the loop. This is enough to signify the event because ARRAY_SIZE is not a valid element number, but it is up to the code following it to check that. Also, this does not handle the possibility of the value appearing more than once as it will return after the first match.

**5) Criterion-based Search**:

When the value you're looking for isn't a fixed value and is instead a value based on the relationship with other values in the array - for example, largest.

```
const int ARRAY_SIZE = 10;
int intArray[ARRAY_SIZE] = {4, 5, 9, 12, -4, 0, -57, 30987, -287, 1};
int highestValue = intArray[0];
for (int i = 1; i < ARRAY_SIZE; i++) {
    if (intArray[i] > highestValue) highestValue = intArray[i];
}
```

This basic structure can be applied to all sorts of situations in which you want to look at every element and find the value that most exemplifies a given quality.

**6) Sort: Putting data in a specified order**:

For most situations, you can make do with two sorts in your toolbox - a fast, easy-to-use sort and a decent easy-to-understand sort you can modify with confidence when the need arises. For fast and easy, we'll use the standard library function qsort, and when we need something to tweak, we'll use an insertion sort.

**7) Fast-and-Easy Sorting with qsort**:

To use _qsort_, you have to write a comparator function. That function will be called by qsort whenever it needs to compare two elements in the array to see which should appear earlier in sorted order. The function is passed two void pointers which should be cast to the element type in your array. The function should return an int, either positive, negative, or zero depending on whether the first element is larger, smaller, or equal to the second element.

**Comparator function example**:

```
int compareFunc(const void* voidA, const void* voidB) {
    int* intA = (int *)(voidA);
    int* intB = (int *)(voidB);
    return *intA - *intB;
}
const int ARRAY_SIZE = 10;
int intArray[ARRAY_SIZE] = {87, 28, 100, 78, 84, 98, 75, 70, 81, 68};
qsort(intArray, ARRAY_SIZE, sizeof(int), comapreFunc);
```

**8) Easy-to-Modify Sorting with Insertion Sort**:

Basic implementation for our integer array:

```
int start = 0;
int end = SIZE_ARRAY - 1;
for (int i = start + 1; i <= end; i++) {
    for (int j = i; j > start && intArray[j-1] > intArray[j]; j--) {
        int temp = intArray[j-1];
        intArray[j-1] = intArray[j];
        intArray[j] = temp;
    }
}
```

Explanation:
Outer loop selects next 'card'. Loop initializes i to start + 1 because a list of only one element is by definition a sorted list. Inner loop puts the current value in the correct position by swapping current value with its predecessor until it's in its place.

**9) Compute Statistics**:

Similar to retrieval operation in that you need to look at every element in the array before returning a value, but instead of returning a value of one of the array elements, you return a statistic computed from all the values in the array. Examples include average, median, or mode.

**Example: Average**:

```
const int ARRAY_SIZE = 10;
int gradeArray[ARRAY_SIZE] = {87, 76, 100, 97, 64, 83, 88, 92, 74, 95};
double sum = 0;
for (int i = 0; i < ARRAY_SIZE; i++) {
    sum += gradeArray[i];
}
double average = sum / ARRAY_SIZE;
```

**Example: Data Validation**:

Array of double values represents payments to vendors. Only positive values are valid, so negative values indicate data integrity problems. As part of validation report, you might write a loop to count the number of negative values in the array.

```
const int ARRAY_SIZE = 10;
int countNegative = 0;
for (int i = 0; i < ARRAY_SIZE; i++) {
    if (vendorPayments[i] < 0) countNegative__;
}
```
