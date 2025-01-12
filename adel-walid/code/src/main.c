#include "../include/sorting.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ARRAY_SIZE 1000
#define MAX_LINE_LENGTH 10000

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

void set_csv_file(FILE *file, const char *filename) {
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

void write_results_to_csv(FILE *file_ptr, const char *filename,
                          const char *algorithm, int array_size,
                          double execution_time) {
  FILE *file = file_ptr;
  fprintf(file, "%s,%d,%.6f\n", algorithm, array_size, execution_time);
}

double measure_sort_time(void (*sort_func)(int[], int), int arr[], int size) {
  int *temp = malloc(size * sizeof(int));
  if (!temp) {
    perror("Memory allocation error");
    return -1;
  }

  memcpy(temp, arr, size * sizeof(int)); // Copy original array
  clock_t start = clock();
  sort_func(temp, size);
  clock_t end = clock();
  free(temp);

  return ((double)(end - start)) / CLOCKS_PER_SEC;
}

int main(int argc, char *argv[]) {
  int starting = 1;

  if (argc < 3) {
    printf("Usage: %s <input_file> <output_csv>\n", argv[0]);
    return 1;
  }

  const char *input_file = argv[1];
  const char *output_csv = argv[2];

  int arrays[100][MAX_ARRAY_SIZE];
  int sizes[100];
  int count;

  if (read_arrays_from_file(input_file, arrays, sizes, &count) != 0) {
    return 1;
  }

  printf("Processing %d arrays from %s...\n", count, input_file);

  FILE *output_csv_file = open_csv(output_csv, "w");
  set_csv_file(output_csv_file, output_csv);
  fclose(output_csv_file);

  output_csv_file = open_csv(output_csv, "a");

  for (int i = 0; i < count; i++) {
    double time_taken = measure_sort_time(bubble_sort, arrays[i], sizes[i]);
    write_results_to_csv(output_csv_file, output_csv, "Bubble Sort", sizes[i],
                         time_taken);

    time_taken = measure_sort_time(gnome_sort, arrays[i], sizes[i]);
    write_results_to_csv(output_csv_file, output_csv, "Gnome Sort", sizes[i],
                         time_taken);

    time_taken = measure_sort_time(heap_sort, arrays[i], sizes[i]);
    write_results_to_csv(output_csv_file, output_csv, "Heap Sort", sizes[i],
                         time_taken);

    time_taken = measure_sort_time(quick_sort, arrays[i], sizes[i]);
    write_results_to_csv(output_csv_file, output_csv, "Quick Sort", sizes[i],
                         time_taken);

    time_taken = measure_sort_time(radix_sort, arrays[i], sizes[i]);
    write_results_to_csv(output_csv_file, output_csv, "Radix Sort", sizes[i],
                         time_taken);
  }

  fclose(output_csv_file);
  printf("Results saved to %s.\n", output_csv);
  return 0;
}
