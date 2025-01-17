#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int n);
void optimized_bubble_sort(int arr[], int n);

void gnome_sort(int arr[], int n);

void sort_aux(int arr[], int n, int i);
void radix_sort_helper(int arr[], int n, int k);
void radix_sort(int arr[], int n);

int partition(int arr[], int low, int high);
void quick_sort_helper(int arr[], int low, int high);
void quick_sort(int arr[], int n);

void heapify(int arr[], int n, int i);
void heap_sort(int arr[], int n);

#endif // SORTING_H
