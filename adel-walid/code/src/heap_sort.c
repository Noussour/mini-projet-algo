#include "../include/sorting.h"
#include "../include/utils.h"

void heapify(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;  // Left child
  int right = 2 * i + 2; // Right child

  if (left < n && arr[left] > arr[largest]) // Changed < to >
    largest = left;

  if (right < n && arr[right] > arr[largest]) // Changed < to >
    largest = right;

  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
  }
}

void heap_sort(int arr[], int n) {
  // Build max heap
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  // Extract elements from heap one by one
  for (int i = n - 1; i > 0; i--) {
    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0);
  }
}
