#include "sort.h"

/**
 * counting_sort - sort, using keys in the range from 0 to max inclusive,
 * where max = larger number of the array, and range = max + 1.
 *
 * Description: counts the number of objects having distinct key values
 * (kind of hashing). Then do some arithmetic to calculate the position
 * of each object in the output sequence.
 *
 * @array: array that contains the numbers to be sorted
 * @size: the number of elements of the array
 * Return: void
*/
void counting_sort(int *array, size_t size)
{
	size_t index = 0, key = 0, position = 0, keys_range;
	int max;
	int *key_array, *ordered_array;

	if (array == NULL || size < 2)
		return;
	max = find_max(array, size);
	keys_range = (size_t)max + 1;
	key_array = malloc(sizeof(int) * keys_range);
	if (key_array == NULL)
		return;
	ordered_array = malloc(sizeof(int) * size);
	if (ordered_array == NULL)
	{
		free(key_array);
		return;
	}
	for (key = 0; key < keys_range ; key++)
		key_array[key] = 0;
	for (index = 0 ; index < size ; index++)
	{
		key = array[index];
		key_array[key] += 1;
	}
	for (key = 1 ; key < keys_range ; key++)
		key_array[key] += key_array[key - 1];
	print_array(key_array, keys_range);
	for (index = 0 ; index < size ; index++)
	{
		key = array[index];
		position = key_array[key];
		ordered_array[position - 1] = array[index];
		key_array[key] -= 1;
	}
	for (index = 0 ; index < size ; index++)
	{
		array[index] = ordered_array[index];
	}
	free(key_array);
	free(ordered_array);
}

/**
 * find_max - finds the largest number in array
 *
 * @array: array that contains the numbers to be sorted
 * @size: the number of elements of the array
 * Return: largest number of the given int array
*/

int find_max(int *array, size_t size)
{
	size_t index;
	int max = 0;

	for (index = 0 ; index < size ; index++)
	{
		if (array[index] > max)
		{
			max = array[index];
		}
	}

	return (max);
}
