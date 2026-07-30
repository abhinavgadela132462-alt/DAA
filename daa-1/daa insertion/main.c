#include <stdio.h>
#include <time.h>

int main() {
    int n, i, j, key;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Start timer
    clock_t start = clock();

    // Insertion Sort
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

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
    printf("Best Case    : O(n)\n");
    printf("Average Case : O(n^2)\n");
    printf("Worst Case   : O(n^2)\n");

    // Display execution time
    printf("\nExecution Time: %f seconds\n", execution_time);

    return 0;
}