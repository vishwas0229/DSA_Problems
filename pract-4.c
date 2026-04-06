#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *next;
    int data;
};

// Traversal
void trevLinkedList(struct Node *head)
{
    struct Node *ptr = head;
    printf("Linked List: ");
    do
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("%d", head->data);
}

// Inserting at the beginning
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

// Inserting in between
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    for (int i = 1; i < index - 1; i++)
    {
        p = p->next;
    }
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
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
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
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    head = head->next;
    p->next = head;
    free(ptr);
    return head;
}

// Deleting the node at the index
struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *ptr = head;
    struct Node *p = head->next;
    for (int i = 1; i < index - 1; i++)
    {
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = p->next;
    free(p);
    return head;
}

// Deleting the last node
struct Node *deleteAtEnd(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *p = head->next;
    while (p->next != head)
    {
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = head;
    free(p);
    return head;
}

// Deleting the first node with a given value
struct Node *deleteByValue(struct Node *head, int value)
{
    struct Node *ptr = head;
    struct Node *p = head->next;
    if (head->data == value)
    {
        head = deleteAtFirst(head);
    }
    else
    {
        while (p->data != value && p->next != head)
        {
            ptr = ptr->next;
            p = p->next;
        }
        if (p->data == value)
        {
            ptr->next = p->next;
            free(p);
        }
    }
    return head;
}

int main()
{
    int op, data, index;
    struct Node *head, *second, *third, *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 4;
    head->next = second;

    second->data = 7;
    second->next = third;

    third->data = 9;
    third->next = fourth;

    fourth->data = 18;
    fourth->next = head;

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