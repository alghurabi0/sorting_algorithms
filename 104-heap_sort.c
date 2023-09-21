#include "sort.h"
/**
 * heap_sort - heap sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int n, i;

	n = (int)size;
	setupHeap(array, n, size);
	for (i = n - 1; i >= 0; i--)
	{
		swap(array, 0, i);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
/**
 * setupHeap - builds heap
 * @array: array
 * @n: n
 * @size: size
 */
void setupHeap(int *array, int n, size_t size)
{
	int i;

	for (i = n / 2 - 1; i >= 0; i--)
		heapify(array, n, i, size);
}
/**
 * heapify - heapify
 * @array: array
 * @n: int
 * @i: int
 * @size: size
 */
void heapify(int *array, int n, int i, size_t size)
{
	int l, r, max;

	l = 2 * i + 1;
	r = 2 * i + 2;
	max = i;
	if (l < n && array[l] > array[max])
		max = l;
	if (r < n && array[r] > array[max])
		max = r;
	if (max != i)
	{
		swap(array, i, max);
		print_array(array, size);
		heapify(array, n, max, size);
	}
}
/**
 * swap - swap two elements in an array
 * @array: array to swap elements in
 * @i: index
 * @j: index
 */
void swap(int *array, int i, int j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
