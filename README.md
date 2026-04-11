# C Programming Practice — Detailed Guide

This repository contains multiple C practice programs for arrays, sorting/searching, linked lists, stacks, and student record management. This README includes:

- Precise function-level descriptions (purpose, parameters, pre/postconditions)
- Pseudocode and recommended safety checks
- Step-by-step execution traces (intermediate array states)
- Suggested, minimal code fixes (malloc checks, index validation, merge fix)

## Files Overview

- `pract-1.c` — dynamic array operations: create, read, print, insert, delete, reverse, merge
- `pract-2.c` — sorting algorithms: bubble sort, merge sort, insertion sort (interactive), selection sort
- `pract-3.c` — singly linked list: traversal, insert (beginning/index/end/after), delete (first/index/end/by value)
- `pract-4.c` — circular linked list: traversal and insert/delete operations in circular form
- `pract-5.c` — doubly linked list: forward/reverse traversal, insert/delete maintaining `prev` and `next`
- `pract-6.c` — static and dynamic stack implementation with array and heap-based stacks
- `pract-11.c` — array utilities: bubble sort plus linear and binary search
- `pract-14.c` — linked list partition: odd and even value separation into two lists
- `pract-15.c` — student record linked list: name, roll number, marks, average, and pass/fail status
- `linked_list_stack.c` — linked-list based stack: push/pop and traversal via linked list

---

## Quick compile & run

```bash
gcc -std=c11 -Wall -Wextra pract-1.c -o pract-1
gcc -std=c11 -Wall -Wextra pract-2.c -o pract-2
gcc -std=c11 -Wall -Wextra pract-3.c -o pract-3
gcc -std=c11 -Wall -Wextra pract-4.c -o pract-4
gcc -std=c11 -Wall -Wextra pract-5.c -o pract-5
gcc -std=c11 -Wall -Wextra pract-6.c -o pract-6
gcc -std=c11 -Wall -Wextra pract-11.c -o pract-11
gcc -std=c11 -Wall -Wextra pract-14.c -o pract-14
gcc -std=c11 -Wall -Wextra pract-15.c -o pract-15
gcc -std=c11 -Wall -Wextra linked_list_stack.c -o linked_list_stack
```

Run the compiled binaries on Linux/macOS:

```bash
./pract-1
./pract-2
./pract-3
./pract-4
./pract-5
./pract-6
./pract-11
./pract-14
./pract-15
./linked_list_stack
```

On Windows (MinGW), run the produced `.exe` files instead.

---

## 1) `pract-1.c` — Array operations (deep)

**Data structure**
- `struct array` fields:
  - `int total_size` — allocated capacity (max elements)
  - `int used_size` — current number of elements
  - `int *ptr` — pointer to allocated buffer

**Design notes**
- `createArr` allocates; other functions assume `used_size` and `ptr` are valid.
- Add checks after allocation and before reading/writing elements.

**Function reference (concise)**

- `void createArr(struct array *a, int tSize, int uSize)`
  - Purpose: allocate `tSize` ints and set `used_size = uSize`.
  - Preconditions: `tSize >= uSize`.
  - Postconditions: if allocation succeeds, `a->ptr != NULL` and `a->total_size == tSize`.
  - Recommendation: check `a->ptr == NULL` and handle failure.

- `void getArr(struct array *a)`
  - Purpose: read `a->used_size` values from stdin into `a->ptr[0..used_size-1]`.
  - Preconditions: `a->ptr` must be non-NULL and `used_size <= total_size`.

- `void printArr(struct array *a)`
  - Purpose: print `used_size` elements separated by spaces.

- `int insert(struct array *a, int index, int element)`
  - Purpose: insert `element` at `index` (0-based) shifting elements right.
  - Preconditions: `0 <= index <= used_size` and `used_size < total_size`.
  - Returns: `1` success, `-1` failure.
  - Complexity: O(n).

- `void del(struct array *a, int index)`
  - Purpose: delete element at `index`; shift left; decrement `used_size`.
  - Preconditions: `0 <= index < used_size`.
  - Complexity: O(n).

- `void reveArr(struct array *a, int uSize)`
  - Purpose: reverse first `uSize` elements in-place by swapping.
  - Complexity: O(uSize).

- `void merge(struct array *arr, struct array *arr1, int uSize, int uSize1)`
  - Purpose: append `arr1` elements to `arr` starting at index `uSize`.
  - Preconditions: `uSize + uSize1 <= arr->total_size`.
  - Complexity: O(uSize + uSize1).

**Detailed insertion example (step-by-step)**

Initial: `arr = [1, 2, 3, 5, 6]`, `used_size = 5`, `total_size >= 6`.
Insert `4` at index `3`:

1. Check: index in [0..5] and used_size < total_size.
2. For i from used_size-1 down to index:
   - i=4: arr[5] = arr[4] (6)
   - i=3: arr[4] = arr[3] (5)
3. arr[3] = 4
4. used_size++ -> 6

Result: `[1, 2, 3, 4, 5, 6]`.

**Detailed deletion example**

Initial: `[10, 20, 30, 40, 50]`, delete index `2`:

1. Check index in [0..used_size-1].
2. For i from index to used_size-2:
   - i=2: arr[2] = arr[3] (40)
   - i=3: arr[3] = arr[4] (50)
3. used_size-- -> 4

Result: `[10, 20, 40, 50]`.

**Common issues & suggested fixes (`pract-1.c`)**
- Always check `malloc` return value in `createArr`:

```c
a->ptr = malloc(tSize * sizeof(int));
if (a->ptr == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
}
```

- Validate `used_size <= total_size` before calling `getArr`.
- `insert`: require `if (a->used_size >= a->total_size) return -1;` and `if (index < 0 || index > a->used_size) return -1;`.
- `del`: require `if (index < 0 || index >= a->used_size) { printf("Deletion failed\n"); return; }`.
- Free memory when done: `free(a.ptr);` (call before exit in main when appropriate).

---

## 2) `pract-2.c` — Sorting algorithms (deep)

**Shared helpers**
- `createArray`, `getArr`, and `printArr` provide allocation, input, and printing utilities used by the sort functions.

**Algorithms: properties, pseudocode, and traces**

**Bubble Sort**
- In-place, stable
- Time: O(n²) worst/average, O(n) best (with early-exit optimization)
- Space: O(1)

Pseudocode (standard):

```
for i from 0 to n-1:
  for j from 0 to n-2-i:
    if a[j] > a[j+1]: swap(a[j], a[j+1])
```

Trace example: [64, 25, 12, 22, 11]

Pass 1:
- compare 64 & 25 -> swap -> [25,64,12,22,11]
- compare 64 & 12 -> swap -> [25,12,64,22,11]
- compare 64 & 22 -> swap -> [25,12,22,64,11]
- compare 64 & 11 -> swap -> [25,12,22,11,64]

Pass 2:
- compare 25 & 12 -> swap -> [12,25,22,11,64]
- compare 25 & 22 -> swap -> [12,22,25,11,64]
- compare 25 & 11 -> swap -> [12,22,11,25,64]

Pass 3:
- compare 12 & 22 -> no swap
- compare 22 & 11 -> swap -> [12,11,22,25,64]

Pass 4:
- compare 12 & 11 -> swap -> [11,12,22,25,64]

Final: [11,12,22,25,64]

**Insertion Sort (interactive variant in code)**
- In-place for a single array; the provided version reads elements one-by-one and maintains a sorted temp buffer, printing intermediate arrays.
- Time: O(n²) worst-case; stable.

Trace example (inputs 12,11,13,5):

- Step 1: [12]
- Step 2: insert 11 -> [11,12]
- Step 3: insert 13 -> [11,12,13]
- Step 4: insert 5 -> [5,11,12,13]

**Selection Sort**
- In-place, unstable (standard swap-based), O(n²) always

Trace example [29,10,14,37]:

1. Find min in [29,10,14,37] -> 10, swap with position 0 -> [10,29,14,37]
2. Find min in [29,14,37] -> 14, swap with position 1 -> [10,14,29,37]
3. Remaining prefix sorted.

**Merge Sort**
- Divide and conquer, O(n log n) time, O(n) extra space due to temporary buffer
- Correct merge implementation must use a temporary buffer indexed from 0..(high-low)

Correct `merge` snippet (recommended replacement):

```c
void merge(struct array *arr, int low, int mid, int high) {
    int n = high - low + 1;
    int *temp = malloc(n * sizeof(int));
    if (!temp) { perror("malloc"); exit(EXIT_FAILURE); }
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high) {
        if (arr->ptr[i] <= arr->ptr[j]) temp[k++] = arr->ptr[i++];
        else temp[k++] = arr->ptr[j++];
    }
    while (i <= mid) temp[k++] = arr->ptr[i++];
    while (j <= high) temp[k++] = arr->ptr[j++];
    for (i = 0; i < n; ++i) arr->ptr[low + i] = temp[i];
    free(temp);
}
```

**Common issues & suggested fixes (`pract-2.c`)**
- Move any `arr->ptr == NULL` checks directly after allocation — do not place them inside inner loops.
- Use the corrected `merge` above to avoid out-of-bounds indexing.
- Free temporary buffers after merge; use `malloc` for temp arrays instead of large automatic arrays when size is dynamic.

---

## 3) `pract-3.c` — Singly linked list (interactive)

**Summary**
- Implements a basic singly linked list with:
  - Traversal
  - Insert at beginning, at index, at end, and after a given node
  - Delete at first, at index, at end, and delete by value
- `main()` builds a 4-node sample list and exposes a menu (options 1–9).

**Design notes & suggestions**
- Check `malloc` return values when creating nodes.
- Validate indices and `NULL` pointers before dereferencing to avoid crashes.
- Insertion into an empty list and deletions with invalid indices should be guarded.

---

## 4) `pract-4.c` — Circular linked list (interactive)

**Summary**
- Implements a circular singly linked list with the same set of operations as the singly list but using a circular structure (do-while traversal).
- `main()` creates a 4-node circular list and presents the same menu-driven interface.

**Design notes & suggestions**
- Handle the single-node circular list as a special case in delete/insert functions.
- Ensure loops terminate correctly and avoid infinite loops by checking head conditions.

---

## 5) `pract-5.c` — Doubly linked list (interactive)

**Summary**
- Implements a doubly linked list with `prev` and `next` pointers.
- Supports forward and reverse traversal, standard insertions, and deletions.
- `main()` constructs a sample 4-node list and exposes the same menu.

**Design notes & suggestions**
- Ensure `prev` pointers are correctly updated after insertions and deletions.
- Check `malloc` return values and handle empty-list edge cases.

---

## 6) `pract-6.c` — Array utilities: sorting and search

**Functions**
- `bubble_sort(struct array *arr)` — in-place bubble sort
- `linearSearch(struct array *arr, int value)` — O(n) linear search
- `binarySearch(struct array *arr, int value, int low, int high)` — O(log n) binary search (requires sorted array)

**Preconditions**
- Binary search requires pre-sorted array.
- Linear search works on unsorted arrays.

---

## 7) `pract-11.c` — Linked list partition

**Purpose**
Split a singly linked list into two separate lists based on node values:
- First list: all nodes with odd data values
- Second list: all nodes with even data values

**Example**
Input list: 1 → 2 → 3 → 4 → 5 → NULL

Output:
- Odd list: 1 → 3 → 5 → NULL
- Even list: 2 → 4 → NULL

---

## 8) `pract-14.c` — Student record manager

**Data structure: `struct student`**
- `char name[50]` — student name
- `int roll_no` — roll number
- `int marks[5]` — marks in 5 subjects
- `float avg` — average of 5 marks
- `char result[10]` — "PASS" or "FAIL" (pass if avg >= 50)
- `struct student *next` — pointer to next student

**Operations**
- `getRecord()` — input student data via stdin, calculate average and result
- `displayData()` — pretty-print all student records in linked list

**Example output**
```
----- Student Database -----
Student 1
Name    : Alice
Roll No : 101
Marks   : 75 80 85 70 90
Average : 80.00
Result  : PASS
```

---

## 9) `pract-15.c` — Stack using linked list

**Data structure: `struct Node`**
- `int data` — stack element value
- `struct Node *next` — pointer to next node in stack

**Operations**
- `push(struct Node *top, int data)` — add element to top; returns new top
- `pop(struct Node **top)` — remove top element; returns popped value
- `trevLinkedList(struct Node *top)` — print all stack elements from top to bottom
- `isEmpty()` and `isFull()` — check stack state

**Key property**: Last-In, First-Out (LIFO)

**Example trace: push 34, push 3, push 4**
```
Stack (top to bottom): 4 → 3 → 34 → NULL
Pop returns 4
Stack: 3 → 34 → NULL
```

---

## 10) `linked_list_stack.c` — Static and dynamic stacks

**Dual implementation**

**1. Static Stack**
- Global array `int stack[MAX]` (MAX = 100)
- Global top pointer `int sTop = -1`
- Functions: `sPush(value)`, `sPop()`, `getStack(uSize)`, `displayStack()`
- Fixed memory, simple but limited capacity

**2. Dynamic Stack**
- `struct stack` with heap-allocated `int *arr`
- `int t_size` — capacity, `int dTop` — top index
- Functions: `creatStack(s, uSize)`, `dPush(s, value)`, `dPop(s)`, `getValue(s)`, `display(s)`
- Flexible memory, user-defined size

**Main menu (case 1/2)**
- Option 1: static stack operations
- Option 2: dynamic stack operations
- Option 0: exit

**Overflow/underflow handling**
- Overflow: print message when stack is full
- Underflow: print message when stack is empty and pop attempted

---

## General Notes

- Many programs use dynamic memory; add `malloc`/`free` checks when modifying or extending these files.
- Always validate user input and array bounds.
- If you add new practice files, include a brief description in this README and add the corresponding compile command above.
- Use `-Wall -Wextra` flags when compiling to catch potential issues.
