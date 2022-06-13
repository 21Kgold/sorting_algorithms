#include "sort.h"

/**
 * bubble_sort - function that sort an array of numeric elements in ascendant
 * order.
 *
 * Description: the algoritm check a pair of elements are in ascendent order
 * starting from the position 0 in the array, and going trought the end of the
 * array. Each time a pair of elements is not in ascending order, the elements
 * are swap. The last elements will be the one to fit in place first, so they
 * won't be checked again, once they fit in place.
 *
 * @array: array that contains the numbers to be sorted
 * @size: the number of elements of the array
 * Return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = size;
	int temp;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (; i < j ; j--)
	{
		for ( ; i < j - 1 ; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
		}
		i = 0;
	}
}
