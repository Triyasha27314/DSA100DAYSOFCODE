/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

int length(struct Node* head) {
    int cnt = 0;
    while (head != NULL) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

int main() {
    int n;
    scanf("%d", &n);
    struct Node* head1 = createList(n);

    int m;
    scanf("%d", &m);
    struct Node* head2 = createList(m);

    int len1 = length(head1);
    int len2 = length(head2);

    struct Node* p1 = head1;
    struct Node* p2 = head2;

    if (len1 > len2) {
        int d = len1 - len2;
        while (d--)
            p1 = p1->next;
    } else {
        int d = len2 - len1;
        while (d--)
            p2 = p2->next;
    }

    while (p1 != NULL && p2 != NULL) {
        if (p1->data == p2->data) {
            printf("%d", p1->data);
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    printf("No Intersection");
    return 0;
}