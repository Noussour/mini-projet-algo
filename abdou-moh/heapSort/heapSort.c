#include "heapSort.h"
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

void heapify(int a[], long size, long i) {
    long largest = i;          // Initialize the largest as root
    long left = 2 * i + 1;     // Left child
    long right = 2 * i + 2;    // Right child

    // Check if left child exists and is greater than the root
    if (left < size && a[left] > a[largest]) {
        largest = left;
    }

    // Check if right child exists and is greater than the largest so far
    if (right < size && a[right] > a[largest]) {
        largest = right;
    }

    // If the largest is not the root, swap and recursively heapify
    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        // Recursively heapify the affected subtree
        heapify(a, size, largest);
    }
}

void heapSort(long size, int a[]) {
    //time mesure
    LARGE_INTEGER frequency, start, end;
    double elapsedTime;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);
    // Build a max heap
    for (long i = size / 2 - 1; i >= 0; i--) {
        heapify(a, size, i);
    }

    // Extract elements from the heap one by one
    for (long i = size - 1; i >= 0; i--) {
        // Move the current root (maximum element) to the end
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        // Heapify the reduced heap
        heapify(a, i, 0);
    }

    QueryPerformanceCounter(&end);
    elapsedTime = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    printf("\n *Heap Sorted Array: ");
    for (long i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n    ==>Sorted in: %f seconds\n", elapsedTime);
}
