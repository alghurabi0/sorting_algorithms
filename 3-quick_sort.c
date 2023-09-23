#include "sort.h"
/**
 * quick_sort - quick sort algorithm in c
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size == 0 || array == NULL)
		return;
	quick_sort_a(array, 0, size - 1, size);
}
/**
 * quick_sort_a - quick sort algorithm in c
 * @array: array to sort
 * @lb: size of the array
 * @ub: upper bound
 * @size: size
 */
void quick_sort_a(int *array, int lb, int ub, size_t size)
{
	int loc;

	if (lb < ub)
	{
		loc = partition(array, lb, ub, size);
		quick_sort_a(array, lb, loc - 1, size);
		quick_sort_a(array, loc + 1, ub, size);
	}
}
/**
 * partition - partition function
 * @array: array
 * @lb: lb
 * @ub: ub
 * @size: size
 * Return: int
 */
int partition(int *array, int lb, int ub, size_t size)
{
	int pivot = array[ub];
	int i = lb - 1;
	int j;

	for (j = lb; j <= ub - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(array, i, j);
			if (i != j)
				print_array(array, size);
		}
	}

	swap(array, i + 1, ub);
	if (i + 1 != ub)
		print_array(array, size);

	return (i + 1);
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
