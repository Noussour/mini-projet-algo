#include "gnomeSort.h"
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

//stupid sort (bubble sort marrying insertion sort)
void gnomeSort(long size, int a[]) {
    LARGE_INTEGER frequency, start, end;
    double elapsedTime;

    QueryPerformanceFrequency(&frequency);

    QueryPerformanceCounter(&start);

    long index = 0;
    while (index < size) {
        if (index == 0 || a[index] >= a[index - 1]) {
            index++; 
        } else {
            int temp = a[index];
            a[index] = a[index - 1];
            a[index - 1] = temp;

            index--; 
        }
    }

    QueryPerformanceCounter(&end);

    elapsedTime = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    printf("\n *Gnome Sorted Array: ");
    for (long i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n    ==>Sorted in: %f seconds\n", elapsedTime);
}
