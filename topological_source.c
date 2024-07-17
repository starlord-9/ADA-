#include <stdio.h>

#define MAX 10

int a[MAX][MAX], n, t[MAX], indegree[MAX];
int stack[MAX], top = -1;

void computeIndegree(int, int [][MAX]);
void tps_SourceRemoval(int, int [][MAX]);

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int i, j;
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    computeIndegree(n, a);
    tps_SourceRemoval(n, a);

    printf("Topological Sort Solution: ");
    for (i = 0; i < n; i++) {
        printf("%d ", t[i]);
    }

    return 0;
}

void computeIndegree(int n, int a[][MAX]) {
    int i, j, sum;
    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = 0; j < n; j++) {
            sum += a[j][i];
        }
        indegree[i] = sum;
    }
}

void tps_SourceRemoval(int n, int a[][MAX]) {
    int i, j, v;

    // Push all nodes with indegree 0 to stack
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            stack[++top] = i;
        }
    }

    int k = 0;
    while (top != -1) {
        v = stack[top--];
        t[k++] = v;

        // For all neighbors of v, reduce their indegree by 1
        for (i = 0; i < n; i++) {
            if (a[v][i] != 0) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    stack[++top] = i;
                }
            }
        }
    }
}
