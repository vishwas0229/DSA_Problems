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

// Inserting at the end
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Inserting after a given Node
struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

// Deleting the first node
struct Node *deleteAtFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Deleting the node at the index
struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 1; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

// Deleting the last node
struct Node *deleteAtEnd(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = NULL;
    free(q);
    return head;
}

// Deleting the first node with a given value
struct Node *deleteByValue(struct Node *head, int value)
{
    struct Node *ptr = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }
    if (q->data == value)
    {
        ptr->next = q->next;
        free(q);
    }
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
    printf("\n1. Traversal\n2. Inserting at the beginning\n3. Inserting in between\n4. Inserting at the end\n5. Inserting after a given Node\n6. Deleting the first node\n7. Deleting the node at the index\n8. Deleting the last node\n9. Deleting the first node with a given value");
    printf("\nChose a Operation(1 to 9): ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        trevLinkedList(head);
        break;
    case 2:
        printf("Enter element you want to insert: ");
        scanf("%d", &data);
        printf("Linked list before insertion\n");
        trevLinkedList(head);
        head = insertAtFirst(head, data);
        printf("\nLinked list after insertion\n");
        trevLinkedList(head);
        break;
    case 3:
        printf("Enter element you want to insert: ");
        scanf("%d", &data);
        printf("Enter index you want to insert: ");
        scanf("%d", &index);
        printf("Linked list before insertion\n");
        trevLinkedList(head);
        head = insertAtIndex(head, data, index);
        printf("\nLinked list after insertion\n");
        trevLinkedList(head);
        break;
    case 4:
        printf("Enter element you want to insert: ");
        scanf("%d", &data);
        printf("Linked list before insertion\n");
        trevLinkedList(head);
        head = insertAtEnd(head, data);
        printf("\nLinked list after insertion\n");
        trevLinkedList(head);
        break;
    case 5:
        printf("Enter element you want to insert: ");
        scanf("%d", &data);
        printf("Enter node after you want to insert (1 to 4): ");
        scanf("%d", &index);
        switch (index)
        {
        case 1:
            printf("Linked list before insertion\n");
            trevLinkedList(head);
            head = insertAfterNode(head, head, data);
            printf("\nLinked list after insertion\n");
            trevLinkedList(head);
            break;
        case 2:
            printf("Linked list before insertion\n");
            trevLinkedList(head);
            head = insertAfterNode(head, second, data);
            printf("\nLinked list after insertion\n");
            trevLinkedList(head);
            break;
        case 3:
            printf("Linked list before insertion\n");
            trevLinkedList(head);
            head = insertAfterNode(head, third, data);
            printf("\nLinked list after insertion\n");
            trevLinkedList(head);
            break;
        case 4:
            printf("Linked list before insertion\n");
            trevLinkedList(head);
            head = insertAfterNode(head, fourth, data);
            printf("\nLinked list after insertion\n");
            trevLinkedList(head);
            break;
        default:
            printf("Node not exist at this point.");
            break;
        }
        break;
    case 6:
        printf("Linked list before deletion\n");
        trevLinkedList(head);
        head = deleteAtFirst(head);
        printf("\nLinked list after deletion\n");
        trevLinkedList(head);
        break;
    case 7:
        printf("Enter index you want to delete: ");
        scanf("%d", &index);
        printf("Linked list before deletion\n");
        trevLinkedList(head);
        head = deleteAtIndex(head, index);
        printf("\nLinked list after deletion\n");
        trevLinkedList(head);
        break;
    case 8:
        printf("Linked list before deletion\n");
        trevLinkedList(head);
        head = deleteAtEnd(head);
        printf("\nLinked list after deletion\n");
        trevLinkedList(head);
        break;
    case 9:
        printf("Enter element you want to delete: ");
        scanf("%d", &data);
        printf("Linked list before deletion\n");
        trevLinkedList(head);
        head = deleteByValue(head, data);
        printf("\nLinked list after deletion\n");
        trevLinkedList(head);
        break;
    default:
        printf("Chose correct operation!");
        break;
    }
    return 0;
}