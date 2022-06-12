#include "sort.h"

/**
 * selection_sort - function that sort an array of numeric elements
 * in ascendant order.
 *
 * Description: the algoritm finds the lower value and swaps it with the first
 * element of the array; then finds the second lower and swap it with the
 * second element and keep it doing it until the end of the array.
 *
 * @array: array that contains the numbers to be sorted
 * @size: the number of elements of the array
 * Return: void
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, k;
	int temp;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (i = 0; i < size ; i++)
	{
		temp = array[i];
		for (j = i + 1 ; j < size ; j++)
		{
			if (temp > array[j])
			{
				temp = array[j];
				k = j;
			}
		}
		if (temp != array[i])
		{
			array[k] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
