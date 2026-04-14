/*Problem Statement: Check whether a given binary tree satisfies the Min-Heap property.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int isMinHeap(struct Node* root){

    if(root == NULL)
        return 1;

    // check left child
    if(root->left != NULL){
        if(root->data > root->left->data)
            return 0;
    }

    // check right child
    if(root->right != NULL){
        if(root->data > root->right->data)
            return 0;
    }

    return isMinHeap(root->left) && isMinHeap(root->right);
}

int main(){

    int n;
    scanf("%d",&n);

    struct Node* nodes[n];

    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        nodes[i] = createNode(x);
    }

    for(int i=0;i<n;i++){
        int left = 2*i+1;
        int right = 2*i+2;

        if(left<n) nodes[i]->left = nodes[left];
        if(right<n) nodes[i]->right = nodes[right];
    }

    if(isMinHeap(nodes[0]))
        printf("YES");
    else
        printf("NO");

    return 0;
}