#include "sort.h"
/**
 * merge_sort - merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *leftArr, *rightArr, middle, i, j = 0;
	size_t ls, rs;

	if (size <= 1)
		return;
	middle = size / 2;
	leftArr = malloc(sizeof(int) * middle);
	rightArr = malloc(sizeof(int) * (size - middle));
	for (i = 0; i < (int)size; i++)
	{
		if (i < middle)
			leftArr[i] = array[i];
		else
		{
			rightArr[j] = array[i];
			j++;
		}
	}
	ls = middle;
	rs = size - middle;
	merge_sort(leftArr, ls);
	merge_sort(rightArr, rs);
	merge(leftArr, rightArr, array, size, middle);
	free(leftArr);
	free(rightArr);
}
/**
 * merge - merge sort helper funciton
 * @leftArr: left array
 * @rightArr: right array
 * @array: array
 * @size: size
 * @middle: middle size of array
 */
void merge(int *leftArr, int *rightArr, int *array, size_t size, int middle)
{
	int i = 0, r = 0, l = 0, rSize, n;

	rSize = size - middle;
	printf("Merging...\n");
	printf("[left]: ");
	for (n = 0; n < middle; n++)
	{
		if (n == middle - 1)
			printf("%d\n", leftArr[n]);
		else
			printf("%d, ", leftArr[n]);
	}
	printf("[right]: ");
	for (n = 0; n < rSize; n++)
	{
		if (n == rSize - 1)
			printf("%d\n", rightArr[n]);
		else
			printf("%d, ", rightArr[n]);
	}
	while (l < middle && r < rSize)
	{
		if (leftArr[l] < rightArr[r])
		{
			array[i] = leftArr[l];
			i++;
			l++;
		}
		else
		{
			array[i] = rightArr[r];
			i++;
			r++;
		}
	}
	while (l < middle)
	{
		array[i] = leftArr[l];
		i++;
		l++;
	}
	while (r < rSize)
	{
		array[i] = rightArr[r];
		i++;
		r++;
	}
	printf("[Done]: ");
	for (n = 0; n < (int)size; n++)
	{
		if (n == (int)size - 1)
			printf("%d\n", array[n]);
		else
			printf("%d, ", array[n]);
	}
}
