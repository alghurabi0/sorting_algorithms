#include "sort.h"
/**
 * quick_sort_hoare - quick sort algorithm in c
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2 || array == NULL)
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
	int start = lb - 1;
	int temp, j;

	for (j = lb; j <= ub - 1; j++)
	{
		if (array[j] < pivot)
		{
			start++;
			temp = array[start];
			array[start] = array[j];
			array[j] = temp;
			if (start != j)
				print_array(array, size);
		}
	}

	temp = array[start + 1];
	array[start + 1] = array[ub];
	array[ub] = temp;
	if (start + 1 != ub)
		print_array(array, size);

	return (start + 1);
}
