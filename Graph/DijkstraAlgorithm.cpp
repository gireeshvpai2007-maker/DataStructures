#include <stdio.h>
#include <limits.h>

#define V 4

int minDistance(int dist[], int visited[])
{
    int min = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0 && dist[i] < min)
        {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(int graph[V][V], int source)
{
    int dist[V];
    int visited[V];

    /* Initialize */
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    /* Main Dijkstra loop */
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);

        visited[u] = 1;

        /* Relax neighbouring vertices */
        for (int v = 0; v < V; v++)
        {
            if (visited[v] == 0 &&
                graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    /* Print shortest distances */
    printf("Shortest distances from vertex %d:\n", source);

    for (int i = 0; i < V; i++)
    {
        printf("%d -> %d = %d\n", source, i, dist[i]);
    }
}

int main()
{
    int graph[V][V] = {
        {0, 4, 2, 0},
        {4, 0, 0, 1},
        {2, 0, 0, 3},
        {0, 1, 3, 0}
    };

    dijkstra(graph, 0);

    return 0;
}