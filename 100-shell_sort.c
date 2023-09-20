#include "sort.h"
/**
 * shell_sort - shell sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	int gap, k, i, j, h;

	gap = 1;
	k = 1;
	while (gap > 0 && gap <= size)
	{
		gap = 3 ^ k - 1;
		j = gap;
		i = 0;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				swap(array, i, j);
				print_array(array, size);
				h = i - gap;
				while (h => 0)
				{
					if (array[i] < array[h])
					{
						swap(array, i, h);
						print_array(array, size);
						h -= gap;
					}
					else
						break;
				}
			}
			else
			{
				i += gap;
				j += gap;
			}
		}
		h = i - gap;
		while (h => 0)
                {
			if (array[i] < array[h])
			{
				swap(array, i, h);
				print_array(array, size);
				h -= gap;
			}
			else
				break;
		}
		k += 1;
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
