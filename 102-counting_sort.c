#include "sort.h"
/**
 * counting_sort - counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int biggest, i, j, count, *counts, my_size = (int)size;
	int *res = malloc(sizeof(int) * size);
	size_t my_arr;

	biggest = array[0];
	for (i = 0; i < my_size; i++)
	{
		if (array[i] > biggest)
			biggest = array[i];
	}
	counts = malloc(sizeof(int) * (biggest + 1));
	my_arr = biggest + 1;;
	for (i = 0; i < biggest + 1; i++)
		counts[i] = 0;
	for (i = 0; i < my_size; i++)
	{
		count = 1;
		for (j = 0; j < my_size; j++)
		{
			if (array[j] == array[i] && i != j)
				count++;
		}
		counts[array[i]] = count;
	}
	for (i = 1; i <= biggest; i++)
		counts[i] = counts[i] + counts[i - 1];
	for (i = 0; i < my_size; i++)
	{
		res[counts[array[i]]] = array[i];
		counts[array[i]] -= 1;
	}
	print_array(counts, my_arr);
	for (i = 0; i < my_size; i++)
		array[i] = res[i];
	free(res);
	free(counts);
}
