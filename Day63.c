/*Problem: Perform DFS starting from a given source vertex using recursion. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

struct Node* adjList[MAX];
int visited[MAX];

// create new node
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// add edge (undirected)
void addEdge(int u, int v){

    struct Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

// DFS function
void dfs(int s){

    visited[s] = 1;
    printf("%d ", s);

    struct Node* temp = adjList[s];

    while(temp){
        int neighbor = temp->data;

        if(!visited[neighbor]){
            dfs(neighbor);
        }

        temp = temp->next;
    }
}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        adjList[i] = NULL;
        visited[i] = 0;
    }

    int u, v;

    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int s;
    scanf("%d", &s);

    dfs(s);

    return 0;
}