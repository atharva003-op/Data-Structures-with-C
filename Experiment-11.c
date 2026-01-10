#include <stdio.h>
#define MAX 100

int adj[MAX][MAX], visited[MAX], n;

void createGraph() {
    int e, u, v;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter number of roads: ");
    scanf("%d", &e);

    for (int i = 0; i < e; i++) {
        printf("Enter origin and destination: ");
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
}

/* Depth First Search */
void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i])
            DFS(i);
    }
}

/* Breadth First Search */
void BFS(int start) {
    int q[MAX], front = 0, rear = 0;
    q[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int v = q[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                q[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int start, choice;

    createGraph();

    printf("Enter starting city: ");
    scanf("%d", &start);

    printf("1. DFS\n2. BFS\nChoose: ");
    scanf("%d", &choice);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    if (choice == 1)
        DFS(start);
    else if (choice == 2)
        BFS(start);
    else
        printf("Invalid choice");

    return 0;
}
