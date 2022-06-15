#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the Shell
 * sort algorithm, using the Knuth sequence (n+1 = n * 3 + 1)
 *
 * Description: the algoritm n intervals of the array and sort each interval
 * values in ascending order, then it repeast the proces with n-1 (Knuth
 * sequence)
 *
 * @array: array that contains the numbers to be sorted
 * @size: the number of elements of the array
 * Return: void
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = size, i = 0, j = 0, l = 0;
	int temp = 0;

	if (array == NULL || size < 2)
	{
		return;
	}
	gap = knuth_sequence(gap);

	for (; gap > 0 ;)
	{
		for (j = 0 ; j + gap <= size ; j++)
		{
			for (i = j ; i + gap < size - l ;)
			{
				for ( ; i + gap < size - l ;)
				{
					if (array[i] > array[i + gap])
					{
						temp = array[i];
						array[i] = array[i + gap];
						array[i + gap] = temp;
					}
					i = i + gap;
				}
				i = j;
				l = l + gap;
			}
			l = 0;
		}
		print_array(array, size);
		gap = knuth_sequence(gap);
	}
}


/**
 * knuth_sequence - calculates the Knuth sequence value (n+1 = n * 3 + 1)
 * that is lower than a "old_gap" given value
 *
 * @old_gap: value to compare the calculated Knuth sequence value
 * Return: Knuth sequence value lower than old_gap
*/

size_t knuth_sequence(size_t old_gap)
{
	size_t new_gap = 0, temp = 0;

	for (; temp < old_gap ;)
	{
		new_gap = temp;
		temp = (new_gap * 3) + 1;
	}

	return (new_gap); 
}
