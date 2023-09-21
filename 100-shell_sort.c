#include "sort.h"
/**
 * shell_sort - shell sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	int gap, i, j, my_size, temp;

	gap = 1;
	my_size = (int)size;
	while (gap < my_size / 3)
		gap = gap * 3 + 1;
	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < my_size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
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
