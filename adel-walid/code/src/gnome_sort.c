#include "../include/sorting.h"
#include "../include/utils.h"

void gnome_sort(int arr[], int n) {
  int i = 0;

  while (i < n - 1) {
    if (arr[i] <= arr[i + 1]) {
      i++;
    } else {
      swap(&arr[i], &arr[i + 1]);
      if (i > 0) {
        i--;
      } else {
        i++;
      }
    }
  }
}
