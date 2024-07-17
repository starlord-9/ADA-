#include <stdio.h>

#define N 4  // Number of objects
#define W 5  // Maximum weight capacity of the knapsack

struct Object
{
    int weight;
    int profit;
};

void knapsack(struct Object objects[], int dp[][W + 1])
{
    for (int i = 0; i <= N; ++i)
    {
        for (int w = 0; w <= W; ++w)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (objects[i - 1].weight <= w)
            {
                dp[i][w] = (objects[i - 1].profit + dp[i - 1][w - objects[i - 1].weight] > dp[i - 1][w]) ?
                           objects[i - 1].profit + dp[i - 1][w - objects[i - 1].weight] : dp[i - 1][w];
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
}

void printSelectedObjects(struct Object objects[], int dp[][W + 1])
{
    int profit = dp[N][W];
    int capacity = W;

    printf("Maximum Profit: %d\n", profit);
    printf("Objects selected:\n");

    for (int i = N; i > 0 && profit > 0; --i)
    {
        if (profit != dp[i - 1][capacity])
        {
            printf("Object %d (weight = %d, profit = %d)\n", i, objects[i - 1].weight, objects[i - 1].profit);
            profit -= objects[i - 1].profit;
            capacity -= objects[i - 1].weight;
        }
    }
}

int main()
{
    struct Object objects[N] = {
        {1, 15},
        {3, 10},
        {4, 8},
        {2, 5}
    };

    int dp[N + 1][W + 1];

    knapsack(objects, dp);

    printf("DP Table:\n");
    for (int i = 0; i <= N; ++i)
    {
        for (int w = 0; w <= W; ++w)
        {
            printf("%3d ", dp[i][w]);
        }
        printf("\n");
    }
    printf("\n");

    printSelectedObjects(objects, dp);

    return 0;
}
