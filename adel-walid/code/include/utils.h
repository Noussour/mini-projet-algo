#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

static inline void print_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

static inline void swap(int *x, int *y) {
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

#endif
