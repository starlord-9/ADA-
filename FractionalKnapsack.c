#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
} Item;

int compare(const void* a, const void* b) {
    double r1 = (double)((Item*)a)->value / ((Item*)a)->weight;
    double r2 = (double)((Item*)b)->value / ((Item*)b)->weight;
    if (r1 < r2) return 1;
    if (r1 > r2) return -1;
    return 0;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    qsort(arr, n, sizeof(Item), compare);
    int curWeight = 0;
    double finalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        } else {
            int remain = W - curWeight;
            finalValue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    Item* arr = (Item*)malloc(n * sizeof(Item));
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].weight, &arr[i].value);
    }
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &W);
    printf("Maximum value we can obtain = %.2f\n", fractionalKnapsack(W, arr, n));
    free(arr);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
} Item;

int compare(const void* a, const void* b) {
    double r1 = (double)((Item*)a)->value / ((Item*)a)->weight;
    double r2 = (double)((Item*)b)->value / ((Item*)b)->weight;
    if (r1 < r2) return 1;
    if (r1 > r2) return -1;
    return 0;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    qsort(arr, n, sizeof(Item), compare);
    int curWeight = 0;
    double finalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        } else {
            int remain = W - curWeight;
            finalValue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    Item* arr = (Item*)malloc(n * sizeof(Item));
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].weight, &arr[i].value);
    }
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &W);
    printf("Maximum value we can obtain = %.2f\n", fractionalKnapsack(W, arr, n));
    free(arr);
    return 0;
}
