#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct array
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct array *arr, int uSize, int tSize)
{
    arr->total_size = tSize;
    arr->used_size = uSize;
    arr->ptr = (int *)malloc(tSize * sizeof(int));
}

//  Get element of array
void getArr(struct array *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d: ", i);
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

// insertion sort
void insertion_sort(int uSize)
{
    int i, j;
    int arr[MAX];
    for (i = 0; i < uSize; i++)
    {
        printf("\nEnter Element %d: ", i);
        scanf("%d", &arr[i]);
        // shortning logic asending order
        int key = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > key; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
        // print shorted array
        printf("Array after short: ");
        for (j = 0; j <= i; j++)
        {
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
}

// selection sort
void selection_sort(struct array *arr)
{
    for (int i = 0; i < arr->used_size - 1; i++)
    {
        int key = i;
        for (int j = i + 1; j < arr->used_size; j++)
        {
            if (arr->ptr[j] < arr->ptr[key])
            {
                if (arr->ptr == NULL)
                {
                    printf("Memory allocation failed\n");
                    exit(1);
                }
                key = j;
            }
        }
        int temp = arr->ptr[i];
        arr->ptr[i] = arr->ptr[key];
        arr->ptr[key] = temp;
    }
}

// Bubble Sort
void bubble_sort(struct array *arr)
{
    for (int i = 0; i < arr->used_size; i++)
    {
        for (int j = 0; j < arr->used_size - i - 1; j++)
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

// Merge Sort
void merge(struct array *arr, int low, int mid, int high)
{
    int i = low, k = low, j = mid + 1;
    int temp[high - low + 1];
    while (i <= mid && j <= high)
    {
        if (arr->ptr[i] < arr->ptr[j])
        {
            temp[k++] = arr->ptr[i++];
        }
        else
        {
            temp[k++] = arr->ptr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr->ptr[i++];
    }
    while (j <= high)
    {
        temp[k++] = arr->ptr[j++];
    }
    for (i = low; i <= high; i++)
    {
        arr->ptr[i] = temp[i];
    }
}

void merge_sort(struct array *arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        merge_sort(arr, low, mid);      // left
        merge_sort(arr, mid + 1, high); // right

        merge(arr, low, mid, high); // merge
    }
}

int main()
{
    struct array arr;
    int uSize, tSize, op;
    while (1)
    {
        int op;
        printf("\n1.) Bubble Sort\n2.) Merge Sort\n3.) Insertion Sort \n4.) Selection Sort\n0.) Exit\nSelect Opration: ");
        scanf("%d", &op);
        if (op == 0)
        {
            printf("Programe is exiting...\n");
            return 0;
        }
        printf("Enter the size of array: ");
        scanf("%d", &uSize);
        createArray(&arr, uSize, MAX);
        switch (op)
        {
        default:
            printf("Invalid Choice!\nPlease enter correct choice.");
        case 1:
            getArr(&arr);
            printf("Array before sort: ");
            printArr(&arr);
            bubble_sort(&arr);
            printf("Array after sort: ");
            printArr(&arr);
            break;
        case 2:
            getArr(&arr);
            printf("Array before sort: ");
            printArr(&arr);
            merge_sort(&arr, 0, uSize - 1);
            printf("Array after sort: ");
            printArr(&arr);
            break;
        case 3:
            insertion_sort(uSize);
            break;
        case 4:
            getArr(&arr);
            printf("Array before sort: ");
            printArr(&arr);
            selection_sort(&arr);
            printf("Array after sort: ");
            printArr(&arr);
            break;
        }
    }

    return 0;
}