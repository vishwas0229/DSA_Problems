# C Programming Practice

This directory contains C programming practice exercises and implementations.

## Files

### pract-2.c
A sorting algorithm program with multiple sorting methods:
- **Insertion Sort** - Sorts array by inserting each element in its correct position
- **Selection Sort** - Sorts array by finding minimum element and placing it at the beginning

**Features:**
- Interactive menu-driven interface
- Takes user input for array elements
- Displays sorted array after each operation
- Supports multiple sorting algorithms

**How to run:**
```bash
gcc pract-2.c -o pract-2
./pract-2
```

**Menu Options:**
1. Bubble Sort (placeholder)
2. Merge Sort (placeholder)
3. Insertion Sort - Enter this to sort using insertion method
4. Selection Sort - Enter this to sort using selection method
0. Exit

## Sorting Algorithms Explained

### Insertion Sort
Builds the sorted array one item at a time by comparing new elements with already sorted elements and inserting them in the correct position.

### Selection Sort
Repeatedly finds the minimum element from unsorted portion and moves it to the beginning.

## Requirements
- GCC compiler
- Linux/Unix environment (or Windows with MinGW)

## Notes
- Global array size limited to 100 elements (MAX = 100)
- Input validation recommended for production use
- Time Complexity: O(n²) for both algorithms
