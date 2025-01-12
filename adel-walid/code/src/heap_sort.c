#include "../include/sorting.h"
#include "../include/utils.h"

void heapify(int arr[], int n, int i) {
  // Convert to 1-based indexing for calculations
  int smallest = i;
  int left = 2 * i;
  int right = 2 * i + 1;

  // Convert back to 0-based indexing for array access
  if (left <= n && arr[left - 1] < arr[smallest - 1])
    smallest = left;

  if (right <= n && arr[right - 1] < arr[smallest - 1])
    smallest = right;

  if (smallest != i) {
    swap(&arr[i - 1], &arr[smallest - 1]);
    heapify(arr, n, smallest);
  }
}

void heap_sort(int arr[], int n) {
  // Build min heap
  for (int i = n / 2; i >= 1; i--)
    heapify(arr, n, i);

  // Extract elements from heap one by one
  for (int i = n; i > 1; i--) {
    swap(&arr[0], &arr[i - 1]);
    heapify(arr, i - 1, 1);
  }
}
