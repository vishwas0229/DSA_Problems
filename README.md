# C Programming Practice — Detailed Guide

This repository contains two instructional C programs for learning array operations and classic sorting algorithms. This README now includes:

- Precise function-level descriptions (purpose, parameters, pre/postconditions)
- Pseudocode and recommended safety checks
- Step-by-step execution traces (intermediate array states)
- Suggested, minimal code fixes (malloc checks, index validation, merge fix)

Files
- `pract-1.c` — dynamic array operations: create, read, print, insert, delete, reverse, merge
- `pract-2.c` — sorting algorithms: bubble sort, merge sort, insertion sort (interactive), selection sort

---

## Quick: compile & run
```bash
gcc -std=c11 -Wall -Wextra pract-1.c -o pract-1
gcc -std=c11 -Wall -Wextra pract-2.c -o pract-2

# Run (Linux/macOS)
./pract-1
./pract-2
```

On Windows (MinGW) run the produced `.exe` files.

---

## 1) `pract-1.c` — Array operations (deep)

Data structure
- `struct array` fields:
  - `int total_size` — allocated capacity (max elements)
  - `int used_size` — current number of elements
  - `int *ptr` — pointer to allocated buffer

Design notes
- `createArr` allocates; other functions assume `used_size` and `ptr` are valid.
- Add checks after allocation and before reading/writing elements.

Function reference (concise)

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

Detailed insertion example (step-by-step)

Initial: `arr = [1, 2, 3, 5, 6]`, `used_size = 5`, `total_size >= 6`.
Insert `4` at index `3`:

1. Check: index in [0..5] and used_size < total_size.
2. For i from used_size-1 down to index:
   - i=4: arr[5] = arr[4] (6)
   - i=3: arr[4] = arr[3] (5)
3. arr[3] = 4
4. used_size++ -> 6

Result: `[1, 2, 3, 4, 5, 6]`.

Detailed deletion example

Initial: `[10, 20, 30, 40, 50]`, delete index `2`:

1. Check index in [0..used_size-1].
2. For i from index to used_size-2:
   - i=2: arr[2] = arr[3] (40)
   - i=3: arr[3] = arr[4] (50)
3. used_size-- -> 4

Result: `[10, 20, 40, 50]`.

Common issues & suggested fixes (`pract-1.c`)
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

Shared helpers
- `createArray`, `getArr`, and `printArr` provide allocation, input, and printing utilities used by the sort functions.

Algorithms: properties, pseudocode, and traces

- Bubble Sort
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

- Insertion Sort (interactive variant in code)
  - In-place for a single array; the provided version reads elements one-by-one and maintains a sorted temp buffer, printing intermediate arrays.
  - Time: O(n²) worst-case; stable.

Trace example (inputs 12,11,13,5):

- Step 1: [12]
- Step 2: insert 11 -> [11,12]
- Step 3: insert 13 -> [11,12,13]
- Step 4: insert 5 -> [5,11,12,13]

- Selection Sort
  - In-place, unstable (standard swap-based), O(n²) always

Trace example [29,10,14,37]:

1. Find min in [29,10,14,37] -> 10, swap with position 0 -> [10,29,14,37]
2. Find min in [29,14,37] -> 14, swap with position 1 -> [10,14,29,37]
3. Remaining prefix sorted.

- Merge Sort
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

Common issues & suggested fixes (`pract-2.c`)
- Move any `arr->ptr == NULL` checks directly after allocation — do not place them inside inner loops.
- Use the corrected `merge` above to avoid out-of-bounds indexing.
- Free temporary buffers after merge; use `malloc` for temp arrays instead of large automatic arrays when size is dynamic.

---

## Suggested minimal code patches (examples)

1) Add `malloc` check in `createArr` (pract-1 & pract-2):

```c
a->ptr = malloc(tSize * sizeof(int));
if (!a->ptr) { perror("malloc"); exit(EXIT_FAILURE); }
```

2) Validate indices in `insert` and `del`:

```c
if (index < 0 || index > a->used_size) return -1; // for insert
if (index < 0 || index >= a->used_size) { printf("Deletion failed\n"); return; }
```

3) Fix selection sort null-check placement:

```c
// after createArray and before calling selection_sort:
if (arr.ptr == NULL) { perror("malloc"); exit(EXIT_FAILURE); }

// inside selection_sort, remove any repeated null-checks inside loops
```

---

## Testing suggestions
- Create small input files for each example case and capture stdout. For example `pract1_insert.txt` with inputs for the insertion scenario.
- Use a shell script to run the program and compare stdout to expected output.

Example run command (Linux/macOS):

```bash
./pract-1 < pract1_insert.txt > out.txt
diff out.txt expected_insert.out
```

---

## Next steps I can take for you

- Apply the minimal code fixes to `pract-1.c` and `pract-2.c` (malloc checks, index validation, merge fix, free calls).
- Add inline comments in the C files explaining each block line-by-line.
- Produce small test input files and a run script that validates outputs automatically.

Tell me which of the next steps to perform and I'll update the code accordingly.
