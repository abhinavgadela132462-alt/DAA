#include <stdio.h>
#include <time.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1, j, temp;

    for(j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Start timer
    clock_t start = clock();

    // Quick Sort
    quickSort(arr, 0, n - 1);

    // Stop timer
    clock_t end = clock();

    // Calculate execution time
    double execution_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Display sorted array
    printf("\nSorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Display time complexity
    printf("\n\nTime Complexity:\n");
    printf("Best Case    : O(n log n)\n");
    printf("Average Case : O(n log n)\n");
    printf("Worst Case   : O(n^2)\n");

    // Display execution time
    printf("\nExecution Time: %f seconds\n", execution_time);

    return 0;
}