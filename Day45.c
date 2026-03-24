/*Problem Statement: Find the height (maximum depth) of a given binary tree.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int height(Node* root)
{
    if(root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

Node* buildTree(int arr[], int n)
{
    if(n == 0 || arr[0] == -1)
        return NULL;

    Node* root = createNode(arr[0]);

    Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while(i < n)
    {
        Node* current = queue[front++];

        if(arr[i] != -1)
        {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        if(i < n && arr[i] != -1)
        {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    return root;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    printf("%d", height(root));

    return 0;
}