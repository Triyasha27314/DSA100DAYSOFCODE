/*Problem Statement: Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {

    if(root == NULL)
        return createNode(data);

    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

int findLCA(struct Node* root, int n1, int n2) {

    while(root != NULL) {

        if(n1 < root->data && n2 < root->data)
            root = root->left;

        else if(n1 > root->data && n2 > root->data)
            root = root->right;

        else
            return root->data;
    }

    return -1;
}

int main() {

    int n, x;
    struct Node* root = NULL;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    printf("%d", findLCA(root, n1, n2));

    return 0;
}