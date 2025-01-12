#include "../include/sorting.h"
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

void test_bubble_sort() {
  int arr[] = {15, 22, 9, 1,  6, 18, 3,  27, 14, 0,
               25, 19, 8, 12, 5, 21, 30, 17, 4,  10};
  int expected[] = {0,  1,  3,  4,  5,  6,  8,  9,  10, 12,
                    14, 15, 17, 18, 19, 21, 22, 25, 27, 30};
  int n = sizeof(arr) / sizeof(arr[0]);

  bubble_sort(arr, n);

  for (int i = 0; i < n; i++) {
    CU_ASSERT_EQUAL(arr[i], expected[i]);
  }
}

void test_bubble_sort_sorted_array() {
  int arr[] = {1, 2, 3, 4, 5};
  int expected[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  bubble_sort(arr, n);

  for (int i = 0; i < n; i++) {
    CU_ASSERT_EQUAL(arr[i], expected[i]);
  }
}

int main() {
  // Initialize the CUnit test registry
  if (CUE_SUCCESS != CU_initialize_registry()) {
    return CU_get_error();
  }

  // Add a suite for Bubble Sort
  CU_pSuite suite = CU_add_suite("Bubble Sort Tests", NULL, NULL);
  if (NULL == suite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  // Add test cases to the suite
  if ((NULL == CU_add_test(suite, "Test Bubble Sort", test_bubble_sort)) ||
      (NULL == CU_add_test(suite, "Test Sorted Array",
                           test_bubble_sort_sorted_array))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  // Run tests using the basic interface
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();

  return CU_get_error();
}
