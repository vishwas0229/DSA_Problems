#include <stdio.h>
#include <stdlib.h>

struct array
{
    int total_size;
    int *ptr;
};

void createArray(struct array *arr, int uSize)
{
    arr->total_size = uSize;
    arr->ptr = (int *)malloc(uSize * sizeof(int));
}

void getArray(struct array *arr, int uSize)
{
    int n;
    for (int i = 0; i < arr->total_size; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &n);
        arr->ptr[i] = n;
    }
}

void displayArray(struct array *arr)
{
    printf("Array: ");
    for (int i = 0; i < arr->total_size; i++)
    {
        printf("%d", arr->ptr[i]);
    }
}

void linearSearch(struct array *arr, int value)
{
    int count = 0, i;
    for (i = 0; i < arr->total_size; i++)
    {
        if (arr->ptr[i] == value)
        {
            count = 1;
            break;
        }
    }
    if (count == 1)
    {
        printf("%d at index %d\n", value, i);
    }
    else
    {
        printf("%d is not present in this array\n", value);
    }
}

int main()
{
    int uSize, value;
    struct array arr;
    printf("Enter size of array: ");
    scanf("%d", &uSize);
    createArray(&arr, uSize);
    getArray(&arr, uSize);
    printf("Enter element you want to find? ");
    scanf("%d", &value);
    linearSearch(&arr, value);
    displayArray(&arr);
    return 0;
}