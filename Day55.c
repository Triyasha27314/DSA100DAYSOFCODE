/*Problem Statement: Print the nodes visible when the binary tree is viewed from the right side.*/

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

void rightView(struct Node* root){

    if(root == NULL)
        return;

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while(front < rear){

        int size = rear - front;

        for(int i = 0; i < size; i++){

            struct Node* node = queue[front++];

            // last node of level
            if(i == size - 1)
                printf("%d ", node->data);

            if(node->left)
                queue[rear++] = node->left;

            if(node->right)
                queue[rear++] = node->right;
        }
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

    rightView(nodes[0]);

    return 0;
}