#include "../include/sorting.h"
#include "../include/utils.h"
#include <math.h>

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

void radix_sort_helper(int arr[], int n, int k) {
  // k represents the maximum number of digits
  for (int i = 0; i < k; i++) {
    sort_aux(arr, n, i);
  }
}

void radix_sort(int arr[], int n) {
  // maximum number of digits is the number of digits of the largest number
  int imax = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i] > arr[imax]) {
      imax = i;
    }
  }

  int k = (int)log10(arr[imax]) + 1;
  radix_sort_helper(arr, n, k);
}
