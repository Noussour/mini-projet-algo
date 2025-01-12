#include "../include/sorting.h"
#include "../include/utils.h"

int partition(int tab[], int p, int r) {
  int eltPivot = tab[p];
  int i = p;
  int j = r;

  do {
    // Find element from right that's smaller than pivot
    while (j >= p && tab[j] > eltPivot) {
      j--;
    }
    // Find element from left that's larger than pivot
    while (i <= r && tab[i] <= eltPivot) {
      i++;
    }
    // Swap elements if indexes haven't crossed
    if (j > i) {
      swap(&tab[i], &tab[j]);
      j--;
      i++;
    }
  } while (j > i);

  return j;
}

void quick_sort(int tab[], int p, int r) {
  if (p < r) {
    int q = partition(tab, p, r);
    quick_sort(tab, p, q);
    quick_sort(tab, q + 1, r);
  }
}
