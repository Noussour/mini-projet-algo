#include "../include/sorting.h"
#include "../include/utils.h"

int partition(int arr[], int low, int high) {

  int p = arr[low];
  int i = low;
  int j = high;

  while (i < j) {

    while (arr[i] <= p && i <= high - 1) {
      i++;
    }

    while (arr[j] > p && j >= low + 1) {
      j--;
    }
    if (i < j) {
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[low], &arr[j]);
  return j;
}

void quick_sort_helper(int arr[], int low, int high) {
  if (low < high) {

    int pi = partition(arr, low, high);

    quick_sort_helper(arr, low, pi - 1);
    quick_sort_helper(arr, pi + 1, high);
  }
}

void quick_sort(int arr[], int n) { quick_sort_helper(arr, 0, n - 1); }
