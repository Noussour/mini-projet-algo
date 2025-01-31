#include "../include/sorting.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#define MAX_ARRAY_SIZE 100000
typedef enum
{
  BUBBLE_SORT = 1 << 0,
  GNOME_SORT = 1 << 1,
  HEAP_SORT = 1 << 2,
  QUICK_SORT = 1 << 3,
  RADIX_SORT = 1 << 4,
  OPT_BUBBLE_SORT = 1 << 5,
  ALL_SORTS = (1 << 6) - 1
} SortingAlgorithm;

#define SELECTED_ALGORITHMS (ALL_SORTS)

typedef struct
{
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


void set_csv_file(FILE *file)
{
  fprintf(file, "%s,%s,%s\n", "Algorithm", "Array Size", "Execution Time");
}

FILE *open_csv(const char *filename, const char *mode)
{
  FILE *file = fopen(filename, mode);
  if (!file)
  {
    perror("Error opening CSV file");
    return NULL;
  }
  return file;
}

void write_results_to_csv(FILE *file, const char *algorithm, int array_size,
                          double execution_time)
{
  fprintf(file, "%s,%d,%.6f\n", algorithm, array_size, execution_time);
}

void print_results_in_terminal(const char *algorithm, int array_size, double execution_time)
{
  printf("| %-20s | %-10d | %-15.6f |\n", algorithm, array_size, execution_time);
}

double measure_sort_time(void (*sort_func)(int[], int), int arr[], int size)
{
  int *temp = malloc(size * sizeof(int));
  if (!temp)
  {
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

void print_enabled_algorithms(void)
{
  printf("Enabled sorting algorithms:\n");
  for (int i = 0; algorithms[i].name != NULL; i++)
  {
    if (SELECTED_ALGORITHMS & algorithms[i].flag)
    {
      printf("- %s\n", algorithms[i].name);
    }
  }
}

// Function to validate and convert command-line argument to a valid size
long get_array_size(const char *arg)
{
  char *endptr;
  long size = strtol(arg, &endptr, 10);

  // Check if the conversion was successful
  if (*endptr != '\0')
  {
    fprintf(stderr, "Error: '%s' is not a valid number.\n", arg);
    exit(1);
  }

  // Validate the size
  if (size <= 0)
  {
    fprintf(stderr, "Error: Size must be a positive integer. Invalid size: %s\n", arg);
    exit(1);
  }

  if (size > MAX_ARRAY_SIZE)
  {
    fprintf(stderr, "Error: Size exceeds the maximum array size of %d. Invalid size: %s\n", MAX_ARRAY_SIZE, arg);
    exit(1);
  }

  return size;
}

// Function to allocate memory for an array
int *allocate_array(long size)
{
  int *array = (int *)malloc(size * sizeof(int));
  if (array == NULL)
  {
    fprintf(stderr, "Memory allocation failed for array of size %ld.\n", size);
    exit(1);
  }
  return array;
}

// Function to fill an array with random numbers
void fill_array_with_random(int *array, long size)
{
  for (int i = 0; i < size; i++)
  {
    array[i] = rand() % (INT_MAX + 1U); // Random numbers between 0 and INT_MAX
  }
}

int main(int argc, char *argv[])
{
  if (argc < 3)
  {
    fprintf(stderr, "USAGE: %s <output_csv> <size1> <size2> ...\n", argv[0]);
    exit(1);
  }

  const char *output_csv = argv[1];

  // Seed the random number generator
  srand(time(NULL));

  // Print the number of arrays
  int num_arrays = argc - 2;
  printf("Number of arrays: %d\n", num_arrays);

  // Initialize CSV file
  FILE *csv_file = open_csv(output_csv, "w");
  set_csv_file(csv_file);
  fclose(csv_file);

  // Append results
  csv_file = open_csv(output_csv, "a");

  // Display enabled algorithms
  print_enabled_algorithms();


  // Print the table header
  printf("|----------------------|------------|-----------------|\n");
  printf("| %-20s | %-10s | %-15s |\n", "Algorithm", "Array Size", "Execution Time");
  printf("|----------------------|------------|-----------------|\n");
  for (int i = 2; i < argc; i++)
  {
    // Convert argument to size
    long size = get_array_size(argv[i]);

    // Allocate memory for the array
    int *array = allocate_array(size);

    // Fill the array with random numbers
    fill_array_with_random(array, size);

    for (int j = 0; algorithms[j].name != NULL; j++)
    {
      if (SELECTED_ALGORITHMS & algorithms[j].flag)
      {
        double time_taken = measure_sort_time(algorithms[j].func, array, size);
        print_results_in_terminal(algorithms[j].name, size, time_taken);
        write_results_to_csv(csv_file, algorithms[j].name, size,
                             time_taken);
      }
      printf("|----------------------|------------|-----------------|\n");
    }
    printf("|======================|============|=================|\n");
  }

  fclose(csv_file);
  printf("Results saved to %s.\n", output_csv);
  return 0;
}
