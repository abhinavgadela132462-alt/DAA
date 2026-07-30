#include <stdio.h>
#include <time.h>

int main() {
    int n, i, j, min, temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Start timer
    clock_t start = clock();

    // Selection Sort
    for(i = 0; i < n - 1; i++) {
        min = i;

        for(j = i + 1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }

        if(min != i) {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
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
    printf("Best Case    : O(n^2)\n");
    printf("Average Case : O(n^2)\n");
    printf("Worst Case   : O(n^2)\n");

    // Display execution time
    printf("\nExecution Time: %f seconds\n", execution_time);

    return 0;
}