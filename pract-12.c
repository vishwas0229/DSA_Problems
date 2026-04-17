#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coef, pow;
    struct Node *next;
};

struct Node *creatNode(struct Node *head, int coef, int pow)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coef = coef;
    newNode->pow = pow;
    newNode->next = NULL;
    if (head == NULL)
    {
        return newNode;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void *getPoly(struct Node *head)
{
    for (int i = 0; i < 3; i++)
    {
        int coef, pow;
        printf("Enter coefficent: ");
        scanf("%d", &coef);
        printf("Enter power: ");
        scanf("%d", &pow);
        head = creatNode(head, coef, pow);
    }
    return head;
}

struct Node *printPoly(struct Node *head)
{
    while (head)
    {
        if (head->pow == 0)
            printf("%d", head->coef);
        else if (head->pow == 1)
            printf("%dx", head->coef);
        else
            printf("%dx^%d", head->coef, head->pow);

        if (head->next)
            printf(" + ");

        head = head->next;
    }
    printf("\n");
}

struct Node *addPoly(struct Node *head, struct Node *p1, struct Node *p2)
{
    while (p1 && p2)
    {
        if (p1->pow == p2->pow)
        {
            head = creatNode(head, p1->coef + p2->coef, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->pow > p2->pow)
        {
            head = creatNode(head, p1->coef, p1->pow);
            p1 = p1->next;
        }
        else
        {
            head = creatNode(head, p2->coef, p2->pow);
            p2 = p2->next;
        }
    }

    while (p1)
    {
        head = creatNode(head, p1->coef, p1->pow);
        p1 = p1->next;
    }

    while (p2)
    {
        head = creatNode(head, p2->coef, p2->pow);
        p2 = p2->next;
    }
    return head;
}

int main()
{
    struct Node *p1 = NULL;
    struct Node *p2 = NULL;
    struct Node *result = NULL;

    printf("Enter Polynomial 1 (descending order):\n");
    p1 = getPoly(p1);
    printPoly(p1);

    printf("\nEnter Polynomial 2 (descending order):\n");
    p2 = getPoly(p2);
    printPoly(p2);

    result = addPoly(result, p1, p2);

    printf("\nResult Polynomial:\n");
    printPoly(result);

    return 0;
}