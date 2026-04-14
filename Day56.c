/*Problem Statement: Check whether a given binary tree is symmetric around its center. */

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

int isMirror(struct Node* left, struct Node* right){

    if(left == NULL && right == NULL)
        return 1;

    if(left == NULL || right == NULL)
        return 0;

    if(left->data != right->data)
        return 0;

    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

int isSymmetric(struct Node* root){
    if(root == NULL)
        return 1;

    return isMirror(root->left, root->right);
}

int main(){

    int n;
    scanf("%d",&n);

    struct Node* nodes[n];

    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);

        if(x==-1)
            nodes[i]=NULL;
        else
            nodes[i]=createNode(x);
    }

    for(int i=0;i<n;i++){
        if(nodes[i]!=NULL){
            int left = 2*i+1;
            int right = 2*i+2;

            if(left<n) nodes[i]->left = nodes[left];
            if(right<n) nodes[i]->right = nodes[right];
        }
    }

    if(isSymmetric(nodes[0]))
        printf("YES");
    else
        printf("NO");

    return 0;
}