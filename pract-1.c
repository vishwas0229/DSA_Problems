#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct array
{
    int total_size;
    int used_size;
    int *ptr;
};

// Creat Array
void creatArr(struct array *a, int tSize, int uSize)
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
    printf("Array: ");
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
    for (int i = index; i < (a->used_size) - 1; i++)
    {
        (a->ptr[i]) = (a->ptr)[i + 1];
    }
    (a->used_size)--;
}

int main()
{
    int op, uSize, index, element;
    struct array arr;
    printf("Operations!!!\n");
    printf("1. Insertion\n2. Deletion\n3. Traversal\n4. Reverse\n5. Merge");
    printf("\nChose one Operaction(1,2,3,4,5,0): ");
    scanf("%d", &op);
    printf("Enter size of array: ");
    scanf("%d", &uSize);
    creatArr(&arr, MAX, uSize);
    switch (op)
    {
    case 1:
        // Insertion
        getArr(&arr);
        printf("Enter element you want to insert: ");
        scanf("%d", &element);
        printf("Enter index where you want to insert element: ");
        scanf("%d", &index);
        printArr(&arr);
        insert(&arr, index, element);
        printf("After Insertion!!\n");
        printArr(&arr);
        break;
    case 2:
        //Deletion
        getArr(&arr);
        printf("Enter which index you want to delete: ");
        scanf("%d", &index);
        printArr(&arr);
        del(&arr, index);
        printf("After Deletion!!\n");
        printArr(&arr);
        break;
    case 3:
        // Traversal
        getArr(&arr);
        printArr(&arr);
        break;
    case 4:
        //Reverse
        break;
    case 5:
        break;
    }
}