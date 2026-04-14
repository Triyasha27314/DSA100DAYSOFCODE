/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

struct Node* adjList[MAX];
int visited[MAX];

// create node
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

// DFS cycle detection
int dfs(int node, int parent){

    visited[node] = 1;

    struct Node* temp = adjList[node];

    while(temp){
        int neighbor = temp->data;

        if(!visited[neighbor]){
            if(dfs(neighbor, node))
                return 1;
        }
        else if(neighbor != parent){
            return 1; // cycle found
        }

        temp = temp->next;
    }

    return 0;
}

int hasCycle(int n){

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            if(dfs(i, -1))
                return 1;
        }
    }

    return 0;
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

    if(hasCycle(n))
        printf("YES");
    else
        printf("NO");

    return 0;
}