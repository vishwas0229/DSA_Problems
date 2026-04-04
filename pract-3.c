#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

// Linked List Travarsal
void trevLinkedList(struct Node *ptr)
{
    printf("Enlement: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

// Inserting at the beginning
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

// Inserting in between
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

int main()
{
    int op, data, index;
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 5;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 12;
    third->next = fourth;

    fourth->data = 15;
    fourth->next = NULL;

    printf("Operation!!");
    printf("\n1. Traversal\n2. Inserting at the beginning\n3. Inserting in between\n4. Inserting at the end\n5. Inserting after a given Node");
    printf("\nChose a Operation(1 to 5): ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        trevLinkedList(head);
        break;
    case 2:
        printf("Enter element you want to insert: ");
        scanf("%d", &data);
        head = insertAtFirst(head, data);
        trevLinkedList(head);
        break;
    case 3:
        printf("Enter element you want to insert: ");
        scanf("%d", &data);
        printf("Enter index you want to insert: ");
        scanf("%d", &index);
        head = insertAtIndex(head, data, index);
        trevLinkedList(head);
        break;
    case 4:
        break;
    }
    return 0;
}