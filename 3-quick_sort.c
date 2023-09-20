#include "sort.h"
/**
 * quick_sort - quick sort algorithm in c
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, int lb, int ub)
{
	/* int lb = 0;*/
	/*int ub = size - 1;*/
	int loc;

	if (lb < ub)
	{
		loc = partition(array, lb, ub);
		quick_sort(array, lb, loc - 1);
		quick_sort(array, loc + 1, ub);
	}
}

int partition(int *array, int lb, int ub)
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
		}
	}
	temp = array[lb];
	array[lb] = array[end];
	array[end] = temp;
	return (end);
}
