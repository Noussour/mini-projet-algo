#include "../include/sorting.h"
#include "../include/utils.h"

void optimized_bubble_sort(int arr[], int n) {
  int m = n - 1;
  int change = 1;

  while (change) {
    change = 0;
    for (int i = 0; i < m; i++) {
      if (arr[i] > arr[i + 1]) {
        swap(&arr[i], &arr[i + 1]);
        change = 1;
      }
    }
    m--;
  }
}
