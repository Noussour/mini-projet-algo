#include "../include/sorting.h"
#include "../include/utils.h"

// Uses counting sort algorithm which runs in linear time O(n)
void sort_aux(int arr[], int n, int i) {
  int *output = (int *)malloc(n * sizeof(int));
  int count[10] = {0};

  for (int j = 0; j < n; j++) {
    count[key(arr[j], i)]++;
  }
  for (int j = 1; j < 10; j++) {
    count[j] += count[j - 1];
  }
  for (int j = n - 1; j >= 0; j--) {
    output[count[key(arr[j], i)] - 1] = arr[j];
    count[key(arr[j], i)]--;
  }
  for (int j = 0; j < n; j++) {
    arr[j] = output[j];
  }

  free(output);
}

void radix_sort(int arr[], int n, int k) {
  // k represents the maximum number of digits
  for (int i = 0; i < k; i++) {
    sort_aux(arr, n, i);
  }
}
