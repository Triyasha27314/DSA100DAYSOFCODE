/*Problem Statement: Convert a binary tree into its mirror image by swapping left and right children at every node.*/

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

// mirror function
void mirror(struct Node* root){

    if(root == NULL)
        return;

    // swap left and right
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

// inorder traversal
void inorder(struct Node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
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

    mirror(nodes[0]);

    inorder(nodes[0]);

    return 0;
}