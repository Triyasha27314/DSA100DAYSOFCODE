/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int inDegree[MAX];

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

    inDegree[v]++; // important
}

// Kahn's Algorithm
void topoSort(int n){

    int queue[MAX];
    int front = 0, rear = 0;

    // push nodes with in-degree 0
    for(int i = 0; i < n; i++){
        if(inDegree[i] == 0){
            queue[rear++] = i;
        }
    }

    int count = 0;

    while(front < rear){

        int curr = queue[front++];
        printf("%d ", curr);
        count++;

        struct Node* temp = adj[curr];

        while(temp){
            int neighbor = temp->data;

            inDegree[neighbor]--;

            if(inDegree[neighbor] == 0){
                queue[rear++] = neighbor;
            }

            temp = temp->next;
        }
    }

    // cycle check
    if(count != n){
        printf("\nCycle exists → Topo not possible");
    }
}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        adj[i] = NULL;
        inDegree[i] = 0;
    }

    int u, v;

    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    topoSort(n);

    return 0;
}