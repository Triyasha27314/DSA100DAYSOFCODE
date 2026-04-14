/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

// create node
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// add edge (directed)
void addEdge(int u, int v){
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS for topo sort
void dfs(int node){

    visited[node] = 1;

    struct Node* temp = adj[node];

    while(temp){
        int neighbor = temp->data;

        if(!visited[neighbor]){
            dfs(neighbor);
        }

        temp = temp->next;
    }

    stack[++top] = node; // push after visiting children
}

// topo function
void topoSort(int n){

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }

    // print stack (reverse order)
    while(top != -1){
        printf("%d ", stack[top--]);
    }
}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        adj[i] = NULL;
        visited[i] = 0;
    }

    int u, v;

    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    topoSort(n);

    return 0;
}