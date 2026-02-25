/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createList(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for(int i = 0; i < n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL)
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
    return head;
}

struct Node* mergeList(struct Node* a, struct Node* b)
{
    struct Node *head = NULL, *tail = NULL;

    while(a != NULL && b != NULL)
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

        if(a->data < b->data)
        {
            newNode->data = a->data;
            a = a->next;
        }
        else
        {
            newNode->data = b->data;
            b = b->next;
        }

        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    while(a != NULL)
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = a->data;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
        a = a->next;
    }

    while(b != NULL)
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = b->data;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
        b = b->next;
    }

    return head;
}

int main()
{
    int n, m;
    scanf("%d", &n);
    struct Node* head1 = createList(n);

    scanf("%d", &m);
    struct Node* head2 = createList(m);

    struct Node* merged = mergeList(head1, head2);

    while(merged != NULL)
    {
        printf("%d ", merged->data);
        merged = merged->next;
    }

    return 0;
}