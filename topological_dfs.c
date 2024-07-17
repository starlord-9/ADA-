#include <stdio.h>

#define MAX 10

int n, a[MAX][MAX], res[MAX], s[MAX], top = 0;

void dfs(int, int, int[][MAX]);
void dfs_top(int, int[][MAX]);

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    dfs_top(n, a);

    printf("Topological Sort Solution: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", res[i]);
    }
    return 0;
}

void dfs_top(int n, int a[][MAX]) {
    for (int i = 0; i < n; i++) {
        s[i] = 0; // Initialize visited array to 0 (unvisited)
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == 0) { // If the node is unvisited
            dfs(i, n, a); // Perform DFS
        }
    }
}

void dfs(int j, int n, int a[][MAX]) {
    s[j] = 1; // Mark the node as visited

    for (int i = 0; i < n; i++) {
        if (a[j][i] == 1 && s[i] == 0) { // If there's an edge and the node is unvisited
            dfs(i, n, a); // Perform DFS
        }
    }
    res[top++] = j; // Store the node in the result
}
