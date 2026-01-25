#include <stdio.h>
#define MAX 100

int i, j, key, arr[MAX], size_of_arr;

// insertion short
void insertion_short(int size_of_arr)
{
    for (i = 0; i < size_of_arr; i++)
    {
        printf("\nEnter Element %d: ", i + 1);
        scanf("%d", &arr[i]);
        // shortning logic asending order
        key = arr[i];
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

// selection short
int selection_short(int size_of_arr)
{
    for (i = 0; i < size_of_arr; i++)
    {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < size_of_arr - 1; ++i)
    {
        key = i;
        for (j = i + 1; j < size_of_arr; ++j)
        {
            if (arr[j] < arr[key])
            {
                key = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[key];
        arr[key] = temp;
    }
    for (i = 0; i < size_of_arr; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    while (1)
    {
        int choice;
        printf("\n1.) Bubble Short\n2.) Merge Short\n3.) Insertion Short \n4.) Selection Short\n0.) Exit\nSelect Opration:");
        scanf("%d", &choice);
        if (choice == 0)
        {
            printf("Programe is exiting...");
            return 0;
        }
        printf("Enter the size of array: ");
        scanf("%d", &size_of_arr);
        switch (choice)
        {
        default:
            printf("Invalid Choice!\nPlease enter correct choice.");
        case 3:
            insertion_short(size_of_arr);
            break;
        case 4:
            selection_short(size_of_arr);
            break;
        }
    }

    return 0;
}