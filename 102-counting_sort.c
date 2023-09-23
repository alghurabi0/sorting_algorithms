#include "sort.h"
/**
 * counting_sort - counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int biggest = array[0], i, count;
	int *res, *counts;
	size_t my_arr;

	if (array == NULL)
		return;
	else if (size < 2)
		return;
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > biggest)
			biggest = array[i];
	}
	my_arr = biggest + 1;
	counts = malloc(sizeof(int) * (biggest + 1));
	if (!counts)
		return;
	res = malloc(sizeof(int) * size);
	if (!res)
	{
		free(counts);
		return;
	}
	for (i = 0; i <= biggest; i++)
		counts[i] = 0;
	for (i = 0; i < (int)size; i++)
		counts[array[i]]++;
	for (i = 1; i <= biggest; i++)
		counts[i] += counts[i - 1];
	for (i = (int)size - 1; i >= 0; i--)
	{
		count = array[i];
		res[counts[count] - 1] = count;
		counts[count]--;
	}
	print_array(counts, my_arr);
	for (i = 0; i < (int)size; i++)
		array[i] = res[i];
	free(res);
	free(counts);
}
