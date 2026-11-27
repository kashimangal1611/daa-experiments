#include <stdio.h>

#define INF 99999

struct Edge
{
    int source;
    int destination;
    int weight;
};

int main()
{
    int V, E, i, j, source;
    int distance[100];
    struct Edge edge[100];

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter source, destination and weight of each edge:\n");

    for (i = 0; i < E; i++)
    {
        scanf("%d %d %d",
              &edge[i].source,
              &edge[i].destination,
              &edge[i].weight);
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    for (i = 0; i < V; i++)
        distance[i] = INF;

    distance[source] = 0;

    /* Relax all edges V-1 times */
    for (i = 1; i <= V - 1; i++)
    {
        for (j = 0; j < E; j++)
        {
            int u = edge[j].source;
            int v = edge[j].destination;
            int w = edge[j].weight;

            if (distance[u] != INF &&
                distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
            }
        }
    }

    /* Check for negative weight cycle */
    for (j = 0; j < E; j++)
    {
        int u = edge[j].source;
        int v = edge[j].destination;
        int w = edge[j].weight;

        if (distance[u] != INF &&
            distance[u] + w < distance[v])
        {
            printf("Graph contains a negative weight cycle.\n");
            return 0;
        }
    }

    printf("\nShortest distances from source vertex %d:\n", source);

    for (i = 0; i < V; i++)
    {
        printf("To vertex %d = %d\n", i, distance[i]);
    }

    return 0;
}
