#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char name[50];
    int roll_no;
    int marks[5];
    float avg;
    char result[10];
    struct student *next;
};

void getRecord(struct student **head, int uSize)
{
    struct student *temp = NULL, *newStudent;
    printf("Enter students data\n");
    for (int i = 0; i < uSize; i++)
    {
        int total = 0;
        newStudent = (struct student *)malloc(sizeof(struct student));
        printf("Student Name: ");
        getchar();
        fgets(newStudent->name, sizeof(newStudent->name), stdin);
        newStudent->name[strcspn(newStudent->name, "\n")] = '0';
        printf("Roll No: ");
        scanf("%d", &newStudent->roll_no);
        for (int j = 0; j < 5; j++)
        {
            printf("Marks of subject %d: ", j + 1);
            scanf("%d", &newStudent->marks[j]);
            total += newStudent->marks[j];
        }
        newStudent->avg = total / (float)5;
        if (newStudent->avg < 50)
        {
            strcpy(newStudent->result, "FAIL");
        }
        else
        {
            strcpy(newStudent->result, "PASS");
        }
        printf("\n");
        newStudent->next = NULL;
        if (*head == NULL)
        {
            *head = newStudent;
            temp = newStudent;
        }
        else
        {
            temp->next = newStudent;
            temp = newStudent;
        }
        newStudent->next = NULL;
    }
}

void displayData(struct student *head)
{
    int i = 1;
    struct student *std = head;
    printf("----- Student Database -----");
    while (std != NULL)
    {
        printf("\nStudent %d", i);
        printf("\nName    : %s", std->name);
        printf("\nRoll No : %d", std->roll_no);
        printf("\nMarks   : ");
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", std->marks[j]);
        }
        printf("\nAverage : %.2f", std->avg);
        printf("\nResult  : %s", std->result);
        printf("\n----------------------------\n");
        std = std->next;
        i++;
    }
    printf("\n");
}

int main()
{
    int uSize;
    struct student *head = NULL;
    printf("Enter no of students: ");
    scanf("%d", &uSize);
    getRecord(&head, uSize);
    displayData(head);
    return 0;
}