#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct student {
  int grade;
  int studentID;
  char *name;
} student;

struct student studentArray[] = {
    {87, 10001, "Fred"},
    {28, 10002, "Tom"},
    {100, 10003, "Alistair"},
    // {75, 10004, "Sasha"},
    // {84, 10005, "Erin"},
    {98, 10006, "Belinda"},
    {75, 10007, "Leslie"},
    // {70, 10008, "Candy"},
    // {81, 10009, "Aretha"},
};

int w = sizeof(struct student);
int size = sizeof(studentArray) / sizeof(studentArray[0]);

int lowToHigh(const void *voidA, const void *voidB) {
  int a = (*(student *)voidA).grade;
  int b = (*(student *)voidB).grade;
  if (a < b) {
    return -1;
  } else if (a > b) {
    return +1;
  } else {
    return 0;
  }
}

int mid() {
  if ((size % 2) > 0) {
    printf("Is the midpoint %d?\n", (size / 2));

    return (size / 2);
  }
  printf("Is the midpoint %d?\n", (size / 2) + 1);

  return (size / 2) + 1;
}

// int getFirstIndex(int* half, int midpoint) {
//   int halfsize = sizeof(half) / sizeof(half[0]);

//   printf("Halfsize: %d\n", halfsize);

//   if ((halfsize % 2) > 0) {
//     return (halfsize / 2) - 1;
//   }
//   return (halfsize / 2);
// }

// int getThirdIndex(int* half, int midpoint) {
//   int size = sizeof(half) / sizeof(half[0]);

//   if ((size % 2) > 0) {
//     return midpoint + (size / 2);
//   }
//   return midpoint + (size / 2) + 1;
// }

int getFirstIndex() {
  int midpoint = mid();
  qsort(studentArray, size, w, lowToHigh);
  int firstHalf[midpoint];
  for (int i = 0; i < midpoint; i++) {
    firstHalf[i] = studentArray[i].grade;
    printf("firstHalf[%d]: %d\n", i, studentArray[i].grade);
  }
  int halfsize = sizeof(firstHalf) / sizeof(firstHalf[0]);

  printf("Halfsize: %d\n", halfsize);

  if ((halfsize % 2) > 0) {
    return (halfsize / 2) + 1;
  }
  return (halfsize / 2);
}

int getThirdIndex() {
  int midpoint = mid();
  printf("Is the middle value %d\n", studentArray[midpoint].grade);
  int removeMedian;
  int secondHalf[midpoint];
  if ((size - midpoint) != midpoint) {
    removeMedian = midpoint + 1;
  }

  for (int i = removeMedian, j = 0; i < size; i++, j++) {
    secondHalf[j] = studentArray[i].grade;
    printf("secondHalf[%d]: %d\n", i, studentArray[i].grade);
  }
  int halfsize = sizeof(secondHalf) / sizeof(secondHalf[0]);

  if ((halfsize % 2) > 0) {
    return midpoint + (halfsize / 2);
  }
  return midpoint + (halfsize / 2) + 1;
}

int main() {
  int quarter;
  int midpoint = mid();
  qsort(studentArray, size, w, lowToHigh);

  int q1 = getFirstIndex();
  printf("Is the first index %d?\n", q1);
  if ((midpoint % 2) == 0) {
    if (((studentArray[q1 - 1].grade + studentArray[q1].grade) % 2) > 0) {
      printf("Is the first value: %d?\n",
             ((studentArray[q1 - 1].grade + studentArray[q1].grade) / 2) + 1);
    } else {
      printf("Is the first value: %d?\n",
             (studentArray[q1 - 1].grade + studentArray[q1].grade) / 2);
    }
  } else {
    printf("Is the first value %d?\n", studentArray[q1].grade);
  }

  int secondHalf[midpoint];
  printf("Is the middle value %d\n", studentArray[midpoint].grade);

  int q3 = getThirdIndex();

  printf("Is the third index %d?\n", q3);
  if ((midpoint % 2) == 0) {
    if (((studentArray[q3 - 1].grade + studentArray[q3].grade) % 2) > 0) {
      printf("Is the third value: %d?\n",
             ((studentArray[q3 - 1].grade + studentArray[q3].grade) / 2) + 1);
    } else {
      printf("Is the third value: %d?\n",
             (studentArray[q3 - 1].grade + studentArray[q3].grade) / 2);
    }
  } else {
    printf("Is the third value %d?\n", studentArray[q3].grade);
  }

  printf("The students' grades are as follows:\n");
  for (int i = 0; i < size; i++) {
    printf("Student %d: %d\n", studentArray[i].studentID,
           studentArray[i].grade);
  }

  return 0;
}