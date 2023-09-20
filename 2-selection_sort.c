#include "sort.h"
/**
 * selection_sort - selection sort algorithm in C
 * @array: array to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, divider;
	int idx, temp;

	idx = 0;
	divider = 0;
	while (divider < size - 1)
	{
		for (i = divider; i < size; i++)
		{
			if (array[i] < array[idx])
			{
				idx = i;
			}
		}
		temp = array[divider];
		array[divider] = array[idx];
		array[idx] = temp;
		divider += 1;
		idx = divider;
		print_array(array, size);
	}
}
