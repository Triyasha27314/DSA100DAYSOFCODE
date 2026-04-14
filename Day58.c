/*Problem Statement: Construct a binary tree from given preorder and inorder traversal arrays.*/

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

// find index in inorder
int search(int inorder[], int start, int end, int value){
    for(int i = start; i <= end; i++){
        if(inorder[i] == value)
            return i;
    }
    return -1;
}

int preIndex = 0;

// build tree
struct Node* buildTree(int preorder[], int inorder[], int start, int end){

    if(start > end)
        return NULL;

    int rootVal = preorder[preIndex++];
    struct Node* root = createNode(rootVal);

    if(start == end)
        return root;

    int inIndex = search(inorder, start, end, rootVal);

    root->left = buildTree(preorder, inorder, start, inIndex - 1);
    root->right = buildTree(preorder, inorder, inIndex + 1, end);

    return root;
}

// postorder traversal
void postorder(struct Node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main(){

    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    struct Node* root = buildTree(preorder, inorder, 0, n-1);

    postorder(root);

    return 0;
}