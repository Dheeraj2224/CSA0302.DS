#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct Edge {
    int source, dest, weight;
} Edge;
int parent[MAX];
Edge edges[MAX];
int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}
int cmp(const void* a, const void* b) {
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}
void KruskalMST(Edge edges[], int n, int e) {
    int i, j, x, y;
    for (i = 0; i < e; i++) {
        x = find(edges[i].source);
        y = find(edges[i].dest);
        if (x != y) {
            printf("%d - %d: %d\n", edges[i].source, edges[i].dest, edges[i].weight);
            parent[x] = y;
        }
    }
}
int main() {
    int i, n, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    for (i = 0; i < n; i++)
        parent[i] = i;
    printf("Enter the source, destination and weight of each edge:\n");
    for (i = 0; i < e; i++)
        scanf("%d%d%d", &edges[i].source, &edges[i].dest, &edges[i].weight);
    qsort(edges, e, sizeof(Edge), cmp);
    printf("Minimum Spanning Tree:\n");
    KruskalMST(edges, n, e);
    return 0;
}
