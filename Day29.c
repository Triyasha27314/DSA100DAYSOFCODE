/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    int n, i, value, k;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    scanf("%d", &n);

    if (n == 0)
        return 0;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &k);

    if (k == 0)
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    int count = 1;
    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }

    k = k % count;

    if (k == 0)
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    temp->next = head;

    int steps = count - k;
    struct Node *newTail = head;

    for (i = 1; i < steps; i++)
        newTail = newTail->next;

    head = newTail->next;
    newTail->next = NULL;

    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}