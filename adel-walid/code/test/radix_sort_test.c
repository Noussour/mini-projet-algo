#include "../include/sorting.h"
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

void test_radix_sort() {
  int arr[] = {1234, 5678, 91011, 1213, 1415, 1617, 1819, 2021, 2223, 2425,
               2627, 2829, 3031,  3233, 3435, 3637, 3839, 4041, 4243, 4445};
  int expected[] = {1213, 1234, 1415, 1617, 1819, 2021, 2223,
                    2425, 2627, 2829, 3031, 3233, 3435, 3637,
                    3839, 4041, 4243, 4445, 5678, 91011};
  int n = sizeof(arr) / sizeof(arr[0]);

  radix_sort(arr, n);

  for (int i = 0; i < n; i++) {
    CU_ASSERT_EQUAL(arr[i], expected[i]);
  }
}

void test_radix_sort_sorted_array() {
  int arr[] = {1, 2, 3, 4, 5};
  int expected[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  radix_sort(arr, n);

  for (int i = 0; i < n; i++) {
    CU_ASSERT_EQUAL(arr[i], expected[i]);
  }
}

int main() {
  // Initialize the CUnit test registry
  if (CUE_SUCCESS != CU_initialize_registry()) {
    return CU_get_error();
  }

  // Add a suite for Radix Sort
  CU_pSuite suite = CU_add_suite("Radix Sort Tests", NULL, NULL);
  if (NULL == suite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  // Add test cases to the suite
  if ((NULL == CU_add_test(suite, "Test Radix Sort", test_radix_sort)) ||
      (NULL ==
       CU_add_test(suite, "Test Radix Array", test_radix_sort_sorted_array))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  // Run tests using the basic interface
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();

  return CU_get_error();
}
