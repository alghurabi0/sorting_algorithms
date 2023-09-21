#include "sort.h"
/**
 * merge_sort - merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *leftArr, *rightArr, middle, i, j = 0;

	if (size <= 1)
		return;
	middle = (int)size / 2;
	if (middle % 2 != 0)
		middle -= 0.5;
	leftArr = malloc(sizeof(int) * middle);
	rightArr = malloc(sizeof(int) * ((int)size - middle));
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
	merge_sort(leftArr, (size_t)middle);
	merge_sort(rightArr, size - (size_t)middle);
	merge(leftArr, rightArr, array, size, middle);
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

	rSize = (int)size - middle;
	printf("Merging...");
	printf("left: %d", *leftArr);
	printf("right: %d", *rightArr);
	while (l < middle || r < rSize)
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
	printf("Done");
}
