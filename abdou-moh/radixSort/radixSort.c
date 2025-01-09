#include "radixSort.h"
#include <stdio.h>
#include <windows.h>

int getMax(int a[], long size) {
    int max = a[0];
    for (long i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

void countingSort(int a[], long size, int exp) {
    int output[size];
    int count[10] = {0}; // Count array for digits (0-9)

    // Count occurrences of digits in the current place value
    for (long i = 0; i < size; i++) {
        count[(a[i] / exp) % 10]++;
    }

    // Update the count array to store positions
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (long i = size - 1; i >= 0; i--) {
        int digit = (a[i] / exp) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }

    // Copy the sorted elements back into the original array
    for (long i = 0; i < size; i++) {
        a[i] = output[i];
    }
}

void radixSort(long size, int a[]) {
    //time
    LARGE_INTEGER frequency, start, end;
    double elapsedTime;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    // Find the maximum number to determine the number of digits
    int max = getMax(a, size);

    // Perform counting sort for each digit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(a, size, exp);
    }
    QueryPerformanceCounter(&end);
    elapsedTime = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
    printf("\n *Radix Sorted Array: ");
    for (long i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n    ==>Sorted in: %f seconds\n", elapsedTime);
}
