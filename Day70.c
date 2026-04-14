/*Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.*/

#include <stdio.h>
#define MAX 100
#define INF 1000000

struct Edge {
    int u, v, w;
};

int dist[MAX];

void bellmanFord(int n, int m, struct Edge edges[], int src){

    // initialize
    for(int i = 0; i < n; i++){
        dist[i] = INF;
    }

    dist[src] = 0;

    // relax edges n-1 times
    for(int i = 1; i <= n-1; i++){
        for(int j = 0; j < m; j++){
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != INF && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    // check negative cycle
    for(int j = 0; j < m; j++){
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != INF && dist[u] + w < dist[v]){
            printf("NEGATIVE CYCLE\n");
            return;
        }
    }

    // print distances
    for(int i = 0; i < n; i++){
        printf("%d ", dist[i]);
    }
}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    struct Edge edges[MAX];

    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    scanf("%d", &src);

    bellmanFord(n, m, edges, src);

    return 0;
}