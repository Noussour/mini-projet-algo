#include "bubblesort.h"
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
//using the windows queryPerfovmancefrequency
void bubbleSort(long size, int a[]) {
    LARGE_INTEGER frequency, start, end;
    double elapsedTime;

    QueryPerformanceFrequency(&frequency);

    QueryPerformanceCounter(&start);

    bool change = true;
    while (change) {
        change = false;
        for (long j = 0; j < (size - 1); j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                change = true;
            }
        }
    }

    QueryPerformanceCounter(&end);

    elapsedTime = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    printf("\n *Bubble Sorted Array: ");
    for (long i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n    ==>Sorted in: %f seconds\n", elapsedTime);
}

void bubbleSortOpt(long size, int a[]) {
    LARGE_INTEGER frequency, start, end;
    double elapsedTime;

    QueryPerformanceFrequency(&frequency);

    QueryPerformanceCounter(&start);

    int m = size - 1;
    bool change = true;
    while (change) {
        change = false;
        for (int i = 0; i < m; i++) {
            if (a[i] > a[i + 1]) {
                int tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
                change = true;
            }
        }
        m = m - 1;
    }

    QueryPerformanceCounter(&end);

    elapsedTime = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    printf("\n *Bubble Optimized Sorted Array: ");
    for (long i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n    ==>Sorted in: %f seconds\n", elapsedTime);
}
