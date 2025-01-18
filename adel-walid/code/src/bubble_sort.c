#include "../include/sorting.h"
#include "../include/utils.h"

void bubble_sort(int arr[], int n) {
  int change = 1; // boolean variable
  while (change) {
    change = 0;
    for (int i = 0; i < n - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        swap(&arr[i], &arr[i + 1]);
        change = 1;
      }
    }
  }
}
