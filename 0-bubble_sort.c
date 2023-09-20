#include "sort.h"
/**
 * bubble_sort - bubble sort algorithm in C
 * @array: array to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int swaps = -1;
	size_t i;
	int temp;

	while (swaps != 0)
	{
		swaps = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swaps += 1;
				print_array(array, size);
			}
		}
	}
}
