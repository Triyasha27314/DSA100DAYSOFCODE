/*Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.*/

#include <stdio.h>
#include <stdlib.h>

// Node for linked list
struct Node {
    int data;
    struct Node* next;
};

// Graph structure
struct Graph {
    int vertices;
    struct Node** adjList;
};

// create new node
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// create graph
struct Graph* createGraph(int v){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = v;

    graph->adjList = (struct Node**)malloc(v * sizeof(struct Node*));

    for(int i = 0; i < v; i++)
        graph->adjList[i] = NULL;

    return graph;
}

// add edge (undirected)
void addEdge(struct Graph* graph, int src, int dest){

    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// print graph
void printGraph(struct Graph* graph){

    for(int i = 0; i < graph->vertices; i++){
        struct Node* temp = graph->adjList[i];
        printf("%d -> ", i);

        while(temp){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    int u, v;

    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printGraph(graph);

    return 0;
}