#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "./bubbleSort/bubblesort.h"
#include "./gnomeSort/gnomeSort.h"
#include "./radixSort/radixSort.h"
#include "./quickSort/quickSort.h"
#include "./heapSort/heapSort.h"
int main(int argc, char **argv){

    if (argc < 2) {
        fprintf(stderr, "USAGE: %s <size1> <size2> ...\n", argv[0]);
        exit(1);
    }
    srand(time(NULL));

    printf("Number of arrays: %d\n", argc - 1);
    //parameters for the strtol: will convert the string to long
    char *endptr;


    for (int i = 1; i < argc; i++) {


        long size = strtol(argv[i], &endptr, 10);
        if (*endptr != '\0') {
            fprintf(stderr, "Error: '%s' is not a valid number.\n", argv[1]);
            return 1;
        }
        if (size <= 0) {
            fprintf(stderr, "Invalid size for array %d: %s\n", i, argv[i]);
            exit(1);
        }

        int *array = (int *)malloc(size * sizeof(int));
        if (array == NULL) {
            fprintf(stderr, "Memory allocation failed for array %d.\n", i);
            exit(1);
        }

        // Fill the array with random numbers
        printf("Array %d (size %ld): ", i, size);
        for (int j = 0; j < size; j++) {
            array[j] = rand() % 100; // Random numbers 0 to 99
            printf("%d ", array[j]);
        }

        // copying the array into a test array
        int test[size];
        memcpy(test, array, size * sizeof(int));
        // sorting then benchmarking
        bubbleSort(size, test);

        memcpy(test, array, size * sizeof(int));
        bubbleSortOpt(size, test);

        memcpy(test, array, size * sizeof(int));
        gnomeSort(size, test);

        memcpy(test, array, size * sizeof(int));
        radixSort(size, test);

        memcpy(test, array, size * sizeof(int));
        quickSort(size, test);


        memcpy(test, array, size * sizeof(int));
        heapSort(size, test);

        printf("\n");
        printf("\n");
        // Free the allocated memory
        free(array);
    }
}
