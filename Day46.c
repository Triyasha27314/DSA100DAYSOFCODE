/*Problem: Level Order Traversal. */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct queue
{
    struct node* arr[100];
    int front;
    int rear;
};

struct node* createNode(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void initQueue(struct queue* q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct queue* q)
{
    return q->front == -1;
}

void enqueue(struct queue* q, struct node* temp)
{
    if(q->rear == 99)
        return;

    if(q->front == -1)
        q->front = 0;

    q->arr[++q->rear] = temp;
}

struct node* dequeue(struct queue* q)
{
    struct node* temp = q->arr[q->front];

    if(q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front++;
    }

    return temp;
}

void levelOrder(struct node* root)
{
    struct queue q;
    initQueue(&q);

    enqueue(&q, root);

    while(!isEmpty(&q))
    {
        struct node* temp = dequeue(&q);
        printf("%d ", temp->data);

        if(temp->left != NULL)
            enqueue(&q, temp->left);

        if(temp->right != NULL)
            enqueue(&q, temp->right);
    }
}

int main()
{
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);

    printf("Level Order Traversal: ");
    levelOrder(root);

    return 0;
}