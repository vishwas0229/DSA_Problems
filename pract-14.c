#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void getArray(struct Node **head, int uSize)
{
    struct Node *temp = NULL, *newNode;
    for (int i = 0; i < uSize; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter element %d: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (*head == NULL)
        {
            *head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
}

void origenalLinkedList(struct Node *head)
{
    struct Node *ptr = head;
    printf("Linked list: ");
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void displayLinkedList(struct Node *head)
{
    struct Node *ptr = head;
    printf("First linked list: ");
    while (ptr != NULL)
    {
        if ((ptr->data % 2) != 0)
        {
            printf("%d -> ", ptr->data);
        }
        ptr = ptr->next;
    }
    printf("NULL\n");
    ptr = head;
    printf("Second linked list: ");
    while (ptr != NULL)
    {
        if ((ptr->data % 2) == 0)
        {
            printf("%d -> ", ptr->data);
        }
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main()
{
    int uSize;
    struct Node *head = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &uSize);
    getArray(&head, uSize);
    origenalLinkedList(head);
    displayLinkedList(head);
    return 0;
}