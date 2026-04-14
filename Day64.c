/*Problem: Perform BFS from a given source using queue. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

struct Node* adjList[MAX];
int visited[MAX];

// queue
int queue[MAX];
int front = 0, rear = 0;

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

// BFS function
void bfs(int s){

    visited[s] = 1;
    queue[rear++] = s;

    while(front < rear){

        int curr = queue[front++];
        printf("%d ", curr);

        struct Node* temp = adjList[curr];

        while(temp){
            int neighbor = temp->data;

            if(!visited[neighbor]){
                visited[neighbor] = 1;
                queue[rear++] = neighbor;
            }

            temp = temp->next;
        }
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

    bfs(s);

    return 0;
}