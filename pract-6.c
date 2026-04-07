#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int sTop = -1;
int stack[MAX];

struct stack
{
    int t_size;
    int dTop;
    int *arr;
};

void creatStack(struct stack *s, int uSize)
{
    if (s->arr != NULL)
    {
        free(s->arr);
    }
    s->t_size = uSize;
    s->dTop = -1;
    s->arr = (int *)malloc(s->t_size * sizeof(int));
    if (s->arr == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

void sPush(int value)
{
    if (sTop == MAX - 1)
    {
        printf("Stack overflow!\n");
    }
    else
    {
        sTop++;
        stack[sTop] = value;
        printf("Pushed %d in stack\n", value);
    }
}

int sPop()
{
    if (sTop == -1)
    {
        printf("Stack underflow!\n");
        return -1;
    }
    else
    {
        int value = stack[sTop];
        sTop--;
        return value;
    }
}

void getStack(int uSize)
{
    int value;
    for (int i = 0; i < uSize; i++)
    {
        printf("Enter value %d : ", i);
        scanf("%d", &value);
        sPush(value);
    }
}

void displayStack()
{
    if (sTop == -1)
    {
        printf("Stack is empty!\n");
    }
    printf("Stack: ");
    for (int i = sTop; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n\n");
}

int isEmpty(struct stack *s)
{
    if (s->dTop == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *s)
{
    if (s->dTop == s->t_size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void dPush(struct stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack overflow! can\'t pushed %d in stack\n\n", value);
    }
    else
    {
        s->dTop++;
        s->arr[s->dTop] = value;
        printf("Pushed %d in stack\n", value);
    }
}

int dPop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow! can\'t popped from the stack\n");
        return -1;
    }
    else
    {
        int value = s->arr[s->dTop];
        s->dTop--;
        return value;
    }
}

void getValue(struct stack *s)
{
    int value;
    for (int i = 0; i < s->t_size; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &value);
        dPush(s, value);
    }
}

void display(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack: ");
    for (int i = s->dTop; i >= 0; i--)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n\n");
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->arr = NULL;
    int op, uSize;
    char choice;

    while (1)
    {
        printf("Operations!!");
        printf("\n1. Static Stack\n2. Dynamic Stack\n0. Exit");
        printf("\nSelect any one (0, 1, 2): ");
        scanf("%d", &op);
        if (op == 0)
        {
            if (s->arr != NULL)
            {
                free(s->arr);
            }
            free(s);
            printf("Exiting Programe...");
            return 0;
        }
        switch (op)
        {
        default:
            printf("Invalid Choise!!");
            break;
        case 2:
            printf("Enter how many elements you want to push: ");
            scanf("%d", &uSize);
            if (uSize <= 0)
            {
                printf("Invalid sise!!\n");
                break;
            }
            creatStack(s, uSize);
            getValue(s);
            printf("Stack after push!\n");
            display(s);
            while (1)
            {
                printf("Do you want to pop from stack (y/n): ");
                scanf(" %c", &choice);
                if (choice == 'y')
                {
                    int value = dPop(s);
                    if (value != -1)
                    {
                        printf("Popped %d from stack!\n", value);
                    }
                }
                else
                {
                    break;
                }
            }
            printf("Stack after pop!\n");
            display(s);
            break;
        case 1:
            printf("Enter how many elements you want to push: ");
            scanf("%d", &uSize);
            if (uSize <= 0)
            {
                printf("Invalid sise!!\n");
                break;
            }
            getStack(uSize);
            printf("Stack after push!\n");
            displayStack();
            while (1)
            {
                printf("Do you want to pop from stack (y/n): ");
                scanf(" %c", &choice);
                if (choice == 'y')
                {
                    int value = sPop();
                    if (value != -1)
                    {
                        printf("Popped %d from stack!\n", value);
                    }
                }
                else
                {
                    break;
                }
            }
            printf("Stack after pop!\n");
            displayStack();
            break;
        }
    }
    return 0;
}