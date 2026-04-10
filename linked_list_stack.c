#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *top)
{
    if (top != NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void trevLinkedList(struct Node *top)
{
    printf("Elements: ");
    while (top != NULL)
    {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

struct Node *push(struct Node *top, int data)
{
    if (isFull(top))
    {
        printf("Stack Overflow!");
    }
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = top;
    top = ptr;
    printf("Pushed %d in stack\n", top->data);
    return top;
}

int pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack underflow!");
    }
    struct Node *ptr = *top;
    *top = (*top)->next;
    int x = ptr->data;
    free(ptr);
    printf("Poped %d from Stack\n", x);
    return x;
}

int main()
{
    struct Node *top = NULL;
    top = push(top, 34);
    top = push(top, 3);
    top = push(top, 4);
    int val = pop(&top);
    val = pop(&top);
    top = push(top, 9);
    trevLinkedList(top);
    return 0;
}