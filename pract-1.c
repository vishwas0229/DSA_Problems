#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct array
{
    int total_size;
    int used_size;
    int *ptr;
};

// Create Array
void createArr(struct array *a, int tSize, int uSize)
{
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

// Traversal
//  Get element of array
void getArr(struct array *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d :", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

// Print array
void printArr(struct array *a)
{
    for (int i = 0; i < (a->used_size); i++)
    {
        printf("%d ", (a->ptr)[i]);
    }
    printf("\n");
}

// Insertion
int insert(struct array *a, int index, int element)
{
    if (index < 0 || index > (a->used_size) || (a->used_size) > (a->total_size))
    {
        return -1;
    }
    for (int i = (a->used_size) - 1; i >= index; i--)
    {
        (a->ptr)[i + 1] = (a->ptr)[i];
    }
    (a->ptr)[index] = element;
    (a->used_size)++;
    return 1;
}

// Deletion
void del(struct array *a, int index)
{
    if (index > (a->used_size))
    {
        printf("Deletion failed...");
        return;
    }
    for (int i = index; i < (a->used_size) - 1; i++)
    {
        (a->ptr[i]) = (a->ptr)[i + 1];
    }
    (a->used_size)--;
}

// Reverse
void reveArr(struct array *a, int uSize)
{
    int temp;
    int end = uSize - 1;
    for (int i = 0; i < end; i++)
    {
        temp = (a->ptr)[i];
        (a->ptr)[i] = (a->ptr)[end];
        (a->ptr)[end] = temp;
        end--;
    }
}

// Merge
void merge(struct array *arr, struct array *arr1, int uSize, int uSize1)
{
    int j = uSize;
    if (uSize + uSize1 > MAX)
    {
        printf("Array is full!!\nMerge failed...");
        return;
    }
    for (int i = 0; i < uSize; i++)
    {
        (arr->ptr)[j] = (arr1->ptr)[i];
        j++;
    }
    (arr->used_size) = uSize + uSize1;
}

int main()
{
    int op, uSize, uSize1, index, element;
    struct array arr, arr1;
    printf("Operations!!!\n");
    printf("1. Insertion\n2. Deletion\n3. Traversal\n4. Reverse\n5. Merge");
    printf("\nChose one Operaction(1,2,3,4,5,0): ");
    scanf("%d", &op);
    if (op == 0 || op >= 6)
    {
        printf("Select right operation!!");
        return 0;
    }
    printf("Enter size of array: ");
    scanf("%d", &uSize);
    createArr(&arr, MAX, uSize);
    switch (op)
    {
    case 1:
        // Insertion
        getArr(&arr);
        printf("Enter element you want to insert: ");
        scanf("%d", &element);
        printf("Enter index where you want to insert element: ");
        scanf("%d", &index);
        printf("Array before insertion: ");
        printArr(&arr);
        insert(&arr, index, element);
        printf("Array after insertion: ");
        printArr(&arr);
        break;
    case 2:
        // Deletion
        getArr(&arr);
        printf("Enter which index you want to delete: ");
        scanf("%d", &index);
        printf("Array before deletion: ");
        printArr(&arr);
        del(&arr, index);
        printf("Array after Deletion: ");
        printArr(&arr);
        break;
    case 3:
        // Traversal
        getArr(&arr);
        printf("Array: ");
        printArr(&arr);
        break;
    case 4:
        // Reverse
        getArr(&arr);
        printf("Array before reverse: ");
        printArr(&arr);
        reveArr(&arr, uSize);
        printf("Array after reverse: ");
        printArr(&arr);
        break;
    case 5:
        // Merge
        getArr(&arr);
        printf("Enter size of array: ");
        scanf("%d", &uSize1);
        createArr(&arr1, MAX, uSize1);
        getArr(&arr1);
        printf("Array before merge!!\n");
        printf("Array 1: ");
        printArr(&arr);
        printf("Array 2: ");
        printArr(&arr1);
        merge(&arr, &arr1, uSize, uSize1);
        printArr(&arr);
        break;
    }
}