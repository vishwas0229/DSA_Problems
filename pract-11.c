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

void bubble_sort(struct array *arr)
{
    for (int i = 0; i < arr->total_size; i++)
    {
        for (int j = 0; j < arr->total_size - i - 1; j++)
        {
            if (arr->ptr[j] > arr->ptr[j + 1])
            {
                int temp = arr->ptr[j];
                arr->ptr[j] = arr->ptr[j + 1];
                arr->ptr[j + 1] = temp;
            }
        }
    }
}

void displayArray(struct array *arr)
{
    printf("Array: ");
    for (int i = 0; i < arr->total_size; i++)
    {
        printf("%d ", arr->ptr[i]);
    }
    printf("\n");
}

void linearSearch(struct array *arr, int value)
{
    for (int i = 0; i < arr->total_size; i++)
    {
        if (arr->ptr[i] == value)
        {
            printf("%d at index %d\n", value, i);
            return;
        }
    }
    printf("%d is not present in this array\n", value);
}

void binarySearch(struct array *arr, int value, int low, int high)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr->ptr[mid] == value)
        {
            printf("%d at index %d\n", value, mid);
            return;
        }
        else
        {
            if (value < arr->ptr[mid])
            {
                high = mid - 1;
                binarySearch(arr, value, low, high);
            }
            else
            {
                low = mid + 1;
                binarySearch(arr, value, low, high);
            }
        }
    }
    else
    {
        printf("%d is not present in this array\n", value);
    }
}

int main()
{
    int uSize, value, op;
    struct array arr;
    printf("Operations!!\n");
    printf("1. Linear Search\n2. Binary Search\nSelect any one from 1 & 2: ");
    scanf("%d", &op);
    switch (op)
    {
    default:
        printf("Select correct operation\n");
        break;
    case 1:
        printf("Enter size of array: ");
        scanf("%d", &uSize);
        createArray(&arr, uSize);
        getArray(&arr, uSize);
        printf("Enter element you want to find? ");
        scanf("%d", &value);
        linearSearch(&arr, value);
        displayArray(&arr);
        break;
    case 2:
        printf("Enter size of array: ");
        scanf("%d", &uSize);
        createArray(&arr, uSize);
        getArray(&arr, uSize);
        bubble_sort(&arr);
        printf("Enter element you want to find? ");
        scanf("%d", &value);
        displayArray(&arr);
        binarySearch(&arr, value, 0, uSize - 1);
        break;
    }
    return 0;
}