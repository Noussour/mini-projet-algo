#include "../include/sorting.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ARRAY_SIZE 1000
#define MAX_LINE_LENGTH 10000

typedef enum {
  BUBBLE_SORT = 1 << 0,
  GNOME_SORT = 1 << 1,
  HEAP_SORT = 1 << 2,
  QUICK_SORT = 1 << 3,
  RADIX_SORT = 1 << 4,
  OPT_BUBBLE_SORT = 1 << 5,
  ALL_SORTS = (1 << 6) - 1
} SortingAlgorithm;

#define SELECTED_ALGORITHMS (ALL_SORTS)

typedef struct {
  const char *name;
  void (*func)(int[], int);
  SortingAlgorithm flag;
} SortingAlgorithmInfo;

static const SortingAlgorithmInfo algorithms[] = {
    {"Bubble Sort", bubble_sort, BUBBLE_SORT},
    {"Optmized Bubble Sort", optimized_bubble_sort, OPT_BUBBLE_SORT},
    {"Gnome Sort", gnome_sort, GNOME_SORT},
    {"Heap Sort", heap_sort, HEAP_SORT},
    {"Quick Sort", quick_sort, QUICK_SORT},
    {"Radix Sort", radix_sort, RADIX_SORT},
    {NULL, NULL, 0}};

int read_arrays_from_file(const char *filename, int arrays[][MAX_ARRAY_SIZE],
                          int *sizes, int *count) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    perror("Error opening file");
    return -1;
  }

  char line[MAX_LINE_LENGTH];
  *count = 0;
  while (fgets(line, sizeof(line), file)) {
    int index = 0;
    char *token = strtok(line, " ");
    while (token) {
      arrays[*count][index++] = atoi(token);
      token = strtok(NULL, " ");
    }
    sizes[*count] = index;
    (*count)++;
  }
  fclose(file);
  return 0;
}

void set_csv_file(FILE *file) {
  fprintf(file, "%s,%s,%s\n", "Algorithm", "Array Size", "Execution Time");
}

FILE *open_csv(const char *filename, const char *mode) {
  FILE *file = fopen(filename, mode);
  if (!file) {
    perror("Error opening CSV file");
    return NULL;
  }
  return file;
}

void write_results_to_csv(FILE *file, const char *algorithm, int array_size,
                          double execution_time) {
  fprintf(file, "%s,%d,%.6f\n", algorithm, array_size, execution_time);
}

void print_results_in_terminal(const char *algorithm, int array_size, double execution_time) {
    printf("| %-20s | %-10d | %-15.6f |\n", algorithm, array_size, execution_time);
}

double measure_sort_time(void (*sort_func)(int[], int), int arr[], int size) {
  int *temp = malloc(size * sizeof(int));
  if (!temp) {
    perror("Memory allocation error");
    return -1;
  }

  memcpy(temp, arr, size * sizeof(int));
  clock_t start = clock();
  sort_func(temp, size);
  clock_t end = clock();

  free(temp);
  return ((double)(end - start)) / CLOCKS_PER_SEC;
}

void print_enabled_algorithms(void) {
  printf("Enabled sorting algorithms:\n");
  for (int i = 0; algorithms[i].name != NULL; i++) {
    if (SELECTED_ALGORITHMS & algorithms[i].flag) {
      printf("- %s\n", algorithms[i].name);
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <input_file> <output_csv>\n", argv[0]);
    return 1;
  }

  const char *input_file = argv[1];
  const char *output_csv = argv[2];

  // Display enabled algorithms
  print_enabled_algorithms();

  // Read input arrays
  int arrays[100][MAX_ARRAY_SIZE];
  int sizes[100];
  int count;
  if (read_arrays_from_file(input_file, arrays, sizes, &count) != 0) {
    return 1;
  }

  printf("Processing %d arrays from %s...\n", count, input_file);

  // Initialize CSV file
  FILE *csv_file = open_csv(output_csv, "w");
  set_csv_file(csv_file);
  fclose(csv_file);

  // Append results
  csv_file = open_csv(output_csv, "a");

  // Run enabled sorting algorithms
    printf("|----------------------|------------|-----------------|\n");
  printf("| %-20s | %-10s | %-15s |\n", "Algorithm", "Array Size", "Execution Time");
  for (int i = 0; i < count; i++) {
        // Print the table header
    printf("|----------------------|------------|-----------------|\n");
    for (int j = 0; algorithms[j].name != NULL; j++) {
      if (SELECTED_ALGORITHMS & algorithms[j].flag) {
        double time_taken = measure_sort_time(algorithms[j].func, arrays[i], sizes[i]);
        print_results_in_terminal(algorithms[j].name, sizes[i], time_taken);
        write_results_to_csv(csv_file, algorithms[j].name, sizes[i],
                             time_taken);
      }
    }
      printf("|======================|============|=================|\n");
  }

  fclose(csv_file);
  printf("Results saved to %s.\n", output_csv);
  return 0;
}
