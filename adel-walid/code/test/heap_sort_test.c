#include "../include/sorting.h"
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

void test_heap_sort() {
  int arr[] = {5, 2, 9, 1, 6};
  int expected[] = {1, 2, 5, 6, 9};
  int n = sizeof(arr) / sizeof(arr[0]);

  heap_sort(arr, n);

  for (int i = 0; i < n; i++) {
    CU_ASSERT_EQUAL(arr[i], expected[i]);
  }
}

void test_heap_sort_sorted_array() {
  int arr[] = {1, 2, 3, 4, 5};
  int expected[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  heap_sort(arr, n);

  for (int i = 0; i < n; i++) {
    CU_ASSERT_EQUAL(arr[i], expected[i]);
  }
}

int main() {
  // Initialize the CUnit test registry
  if (CUE_SUCCESS != CU_initialize_registry()) {
    return CU_get_error();
  }

  // Add a suite for Heap Sort
  CU_pSuite suite = CU_add_suite("Heap Sort Tests", NULL, NULL);
  if (NULL == suite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  // Add test cases to the suite
  if ((NULL == CU_add_test(suite, "Test Heap Sort", test_heap_sort)) ||
      (NULL ==
       CU_add_test(suite, "Test Heap Array", test_heap_sort_sorted_array))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  // Run tests using the basic interface
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();

  return CU_get_error();
}
