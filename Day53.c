/*Problem Statement: Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be 
printed together from top to bottom and from left to right.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Pair {
    struct Node* node;
    int hd;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void verticalOrder(struct Node* root){

    struct Pair queue[100];
    int front = 0, rear = 0;

    int col[200][50];
    int count[200] = {0};

    int offset = 100;

    queue[rear].node = root;
    queue[rear].hd = 0;
    rear++;

    while(front < rear){

        struct Pair temp = queue[front++];

        int hd = temp.hd;
        struct Node* node = temp.node;

        col[hd + offset][count[hd + offset]++] = node->data;

        if(node->left){
            queue[rear].node = node->left;
            queue[rear].hd = hd - 1;
            rear++;
        }

        if(node->right){
            queue[rear].node = node->right;
            queue[rear].hd = hd + 1;
            rear++;
        }
    }

    for(int i = 0; i < 200; i++){
        if(count[i] > 0){
            for(int j = 0; j < count[i]; j++)
                printf("%d ", col[i][j]);
            printf("\n");
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

    verticalOrder(nodes[0]);

    return 0;
}