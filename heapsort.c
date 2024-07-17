#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int N, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < N && arr[l] > arr[largest])
        largest = l;

    if (r < N && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N) {
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (int i = N - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int N) {
    for (int i = 0; i < N; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int N;
    printf("Enter number of elements: ");
    scanf("%d", &N);

    int arr[N];
    printf("Enter %d elements:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    heapSort(arr, N);

    printf("Sorted array is:\n");
    printArray(arr, N);

    return 0;
}