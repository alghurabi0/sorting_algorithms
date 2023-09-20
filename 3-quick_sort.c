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
 * Return: int
 */
int partition(int *array, int lb, int ub, size_t size)
{
	int pivot = array[lb];
	int start = lb;
	int end = ub;
	int temp;

	while (start < end)
	{
		while (array[start] <= pivot)
		{
			start++;
		}
		while (array[end] > pivot)
		{
			end--;
		}
		if (start < end)
		{
			temp = array[start];
			array[start] = array[end];
			array[end] = temp;
			print_array(array, size);
		}
	}
	temp = array[lb];
	array[lb] = array[end];
	array[end] = temp;
	return (end);
}
