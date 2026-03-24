/*Problem Statement: Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree. */

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

struct Node* findLCA(struct Node* root, int n1, int n2) {

    if(root == NULL)
        return NULL;

    if(root->data == n1 || root->data == n2)
        return root;

    struct Node* left = findLCA(root->left, n1, n2);
    struct Node* right = findLCA(root->right, n1, n2);

    if(left != NULL && right != NULL)
        return root;

    if(left != NULL)
        return left;
    else
        return right;
}

int main() {

    int n, a, b;
    scanf("%d", &n);

    struct Node* nodes[100];

    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);

        if(x == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(x);
    }

    for(int i = 0; i < n; i++){
        if(nodes[i] != NULL){
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n)
                nodes[i]->left = nodes[left];

            if(right < n)
                nodes[i]->right = nodes[right];
        }
    }

    scanf("%d %d", &a, &b);

    struct Node* lca = findLCA(nodes[0], a, b);

    printf("%d", lca->data);

    return 0;
}