/*Problem: Detect cycle in directed graph using DFS and recursion stack.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];
int recStack[MAX];

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

// DFS cycle detection
int dfs(int node){

    visited[node] = 1;
    recStack[node] = 1;

    struct Node* temp = adj[node];

    while(temp){
        int neighbor = temp->data;

        if(!visited[neighbor]){
            if(dfs(neighbor))
                return 1;
        }
        else if(recStack[neighbor]){
            return 1; // cycle found
        }

        temp = temp->next;
    }

    recStack[node] = 0; // remove from stack
    return 0;
}

int hasCycle(int n){

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            if(dfs(i))
                return 1;
        }
    }

    return 0;
}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        adj[i] = NULL;
        visited[i] = 0;
        recStack[i] = 0;
    }

    int u, v;

    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        addEdge(u, v); // directed
    }

    if(hasCycle(n))
        printf("YES");
    else
        printf("NO");

    return 0;
}