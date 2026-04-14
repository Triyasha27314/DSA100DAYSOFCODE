/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/

#include <stdio.h>
#define MAX 100
#define INF 1000000

int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];

// find node with minimum distance
int findMin(int n){
    int min = INF, index = -1;

    for(int i = 0; i < n; i++){
        if(!visited[i] && dist[i] < min){
            min = dist[i];
            index = i;
        }
    }

    return index;
}

// Dijkstra
void dijkstra(int n, int src){

    for(int i = 0; i < n; i++){
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for(int i = 0; i < n; i++){

        int u = findMin(n);

        if(u == -1) break;

        visited[u] = 1;

        for(int v = 0; v < n; v++){
            if(graph[u][v] && !visited[v]){
                if(dist[u] + graph[u][v] < dist[v]){
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    // initialize graph
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            graph[i][j] = 0;
        }
    }

    int u, v, w;

    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // remove if directed
    }

    int src;
    scanf("%d", &src);

    dijkstra(n, src);

    // print distances
    for(int i = 0; i < n; i++){
        printf("%d ", dist[i]);
    }

    return 0;
}