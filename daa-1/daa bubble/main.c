#include <stdio.h>
#include <time.h>

int main() {
    int n, i, j, temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Start timer
    clock_t start = clock();

    // Bubble Sort
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Stop timer
    clock_t end = clock();

    // Calculate execution time
    double execution_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nTime Complexity:\n");
    printf("Best Case    : O(n^2)\n");
    printf("Average Case : O(n^2)\n");
    printf("Worst Case   : O(n^2)\n");

    printf("\nExecution Time: %f seconds\n", execution_time);

    return 0;
}