#include "sort.h"
/**
 * counting_sort - counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int biggest, i, j, count;
	int res[size];
	// find the biggest value in the array;
	biggest = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > biggest)
			biggest = array[i];
	}
	int arr = biggest + 1;
	// declare a new array with the biggest value being the number of indexes in the array	
	int counts[arr];
	for (i = 0; i < arr; i++)
	{
		counts[i] = 0;
	}
	// loop over the original array
	for (i = 0; i < size; i++)
	{
		count = 1;
	// count how many an element appear in the original array
		for (j = 0; j < size; j++)
		{
			if (array[j] == array[i] && i != j)
				count++;
		}
	// store the number of time the element appear in the second array in the index of the element's value
		counts[array[i]] = count;
	}
	// loop over the second array starting from index 1
	for (i = 1; i <= biggest; i++)
	{
	// update the value of each element to have the value of it's value summed with the value of its prev element
		counts[i] = counts[i] + counts[i - 1];
	}
	// declare a final result array with the same size of the original array
	// loop over the original array
	for (i = 0; i < size; i++)
	{
	// take each element's value
	// go check element in second array that has an index == value from first array
	// go to final array index == value from second array and store the the value of the original array in it
		res[counts[array[i]]] = array[i];
		counts[array[i]] -= 1;
	}
	print_array(res, size);
}
