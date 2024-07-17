#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to place the pivot element at the correct position
int partition(int arr[], int low, int high)
{
    int pivot = arr[low]; // Choose the first element as the pivot
    int i = low;
    int j = high;

    while (i < j)
    {
        // Increment i until an element greater than the pivot is found
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        // Decrement j until an element less than or equal to the pivot is found
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        // Swap elements at i and j
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    // Place pivot at the correct position
    swap(&arr[low], &arr[j]);
    return j;
}

// QuickSort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);  // Recursively sort elements before partition
        quickSort(arr, partitionIndex + 1, high); // Recursively sort elements after partition
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
