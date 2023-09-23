#include "sort.h"
/**
 * radix_sort - radix sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	size_t i;
	int biggestCount;

	biggestCount = countDigits(array[0]);
	for (i = 1; i < size; i++)
	{
		if (countDigits(array[i]) > biggestCount)
			biggestCount = countDigits(array[i]);
	}
	helper(array, size, 0, biggestCount);
}
/**
 * helper - helper of radix sort
 * @array: array
 * @size: size
 * @times: number of times helper has been called
 * @count: count
 * Return: int
 */
int helper(int *array, size_t size, int times, int count)
{
	int *arr, j, l = 0, n;
	size_t i;

	if (times == count)
		return (0);
	if (times == 0)
		n = 1;
	else if (times == 1)
		n = 10;
	else if (times == 2)
		n = 100;
	else if (times == 3)
		n = 1000;
	else if (times == 4)
		n = 10000;
	else if (times == 5)
		n = 100000;
	else if (times == 6)
		n = 1000000;
	arr = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
		arr[i] = array[i];
	for (j = 0; j < 10; j++)
	{
		for (i = 0; i < size; i++)
		{
			if ((arr[i] / n) % 10 == j)
			{
				array[l] = arr[i];
				l++;
			}
		}
	}
	free(arr);
	print_array(array, size);
	return (helper(array, size, ++times, count));
}
/**
 * countDigits - counts digits in an integer
 * @number: int
 * Return: int
 */
int countDigits(int number)
{
	int count = 0;

	if (number == 0)
		return (1);
	if (number < 0)
		number = -number;
	while (number > 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}
