#include "sort.h"

/**
 * quick_sort - function that sorts an array of numeric elements
 * in ascendant order using the quick sort algorithm.
 *
 * @array: list to be sorted
 * @size: size of the array to be sorted
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	int partition;

	sort(array, size, 0, (size - 1));
}

/**
 * sort - function to initialize array sorting
 * @array: array to sort
 * @size: size of array
 * @start: index of first element of the array
 * @end: index of the last element of the array
 *
 */

void sort(int *array, size_t size, int start, int end)
{
	int partition;

	if (start < end)
	{
	partition = partitioning(array, size, start, end);
	sort(array, size, start, (partition - 1));
	sort(array, size, (partition + 1), end);
	}
}


/**
 * partitioning - function that partition a sub array
 *
 * @array: array to be partitioned
 * @size: size of the array to be sorted
 * @start: index of first element of array
 * @end: index of the last element of the array.
 * Return: index of the array partition point
 */
int partitioning(int *array, size_t size, int start, int end)
{
	int i;
	int swap = start;
	int pivot = array[end];

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			swap_arr(array, size, swap, i);
			swap++;
		}
	}
swap_arr(array, size, swap, end);
return (swap);
}

/**
 * swap_arr - swaps numbers in an array
 *
 * @array: array with numbers to swap
 * @size: size of the array to be sorted
 * @start: index of first element to swap
 * @end: index of the second element to swap.
 */

void swap_arr(int *array, size_t size, int start, int end)
{
int temporal;

temporal = array[start];
array[start] = array[end];
array[end] = temporal;
if (start != end)
{
	print_array(array, size);
}

}

