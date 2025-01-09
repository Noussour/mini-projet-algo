#include "quickSort.h"
#include <stdio.h>
#include <windows.h>

long partition(int a[], long low, long high) {
    int pivot = a[high];  // Pivot element
    long i = low - 1;     

    for (long j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

void quickSortRecursive(int a[], long low, long high) {
    if (low < high) {
        // Partition the array
        long pivotIndex = partition(a, low, high);

        // Recursively sort the elements before and after the pivot
        quickSortRecursive(a, low, pivotIndex - 1);
        quickSortRecursive(a, pivotIndex + 1, high);
    }
}
void quickSort(long size, int a[]) {
    //time
    LARGE_INTEGER frequency, start, end;
    double elapsedTime;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    // Perform Quick Sort
    quickSortRecursive(a, 0, size - 1);

    QueryPerformanceCounter(&end);
    elapsedTime = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    printf("\n *Quick Sorted Array: ");
    for (long i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n    ==>Sorted in: %f seconds\n", elapsedTime);
}
