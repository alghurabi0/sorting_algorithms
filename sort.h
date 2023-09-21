#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_a(int *array, int lb, int ub, size_t size);
int partition(int *array, int lb, int ub, size_t size);
void shell_sort(int *array, size_t size);
void swap(int *array, int i, int j);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *leftArr, int *rightArr, int *array, size_t size, int middle);
void heap_sort(int *array, size_t size);
void setupHeap(int *array, int n, size_t size);
void heapify(int *array, int n, int i, size_t size);
int helper(int *array, size_t size, int times, int count);
void radix_sort(int *array, size_t size);
int countDigits(int number);
#endif
