/*Problem Statement: Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed 
left-to-right and right-to-left. */

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

void zigzagTraversal(struct Node* root){

    if(root == NULL)
        return;

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int leftToRight = 1;

    while(front < rear){

        int size = rear - front;
        int level[100];

        for(int i = 0; i < size; i++){

            struct Node* node = queue[front++];
            level[i] = node->data;

            if(node->left)
                queue[rear++] = node->left;

            if(node->right)
                queue[rear++] = node->right;
        }

        if(leftToRight){
            for(int i = 0; i < size; i++)
                printf("%d ", level[i]);
        }
        else{
            for(int i = size-1; i >= 0; i--)
                printf("%d ", level[i]);
        }

        leftToRight = !leftToRight;
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

    zigzagTraversal(nodes[0]);

    return 0;
}