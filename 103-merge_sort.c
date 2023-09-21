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
	printf("dividing size: %ld \n", size);
	middle = size / 2;
	printf("middle: %d\n", middle);
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
	int i = 0, r = 0, l = 0, rSize;

	rSize = size - middle;
	printf("Merging...\n");
	printf("left: %d\n", *leftArr);
	printf("right: %d\n", *rightArr);
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
	printf("Done");
}
