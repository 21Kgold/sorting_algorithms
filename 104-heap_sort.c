#include "sort.h"

/**
 * heapify - reshape a binary tree into a Heap data
 * structure using recursion
 * @array: Array to sort
 * @heap: size of heap data
 * @i: index
 * @size: size of array
*/

void heapify(int *array, int heap, int i, int size)
{
	int largest = i, left = 2 * i + 1, right = 2 * i + 2, t;

	if (left < heap && array[left] > array[largest])
		largest = left;
	if (right < heap && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		t = array[i], array[i] = array[largest], array[largest] = t;
		print_array(array, size);
		heapify(array, heap, largest, size);
	}
}

/**
 * heap_sort - Sorts array into a heap data structure
 * Description: Heap sort is a comparison-based sorting technique based
 * on Binary Heap data structure. It is similar to selection sort where we
 * first find the minimum element and place the minimum element at the
 * beginning. We repeat the same process for the remaining elements.
 * If the parent node is stored at index I, the left child can be calculated
 * by 2 * I + 1 and the right child by 2 * I + 2 (assuming the indexing
 * starts at 0).
 * @array: array to sort
 * @size: Size of array to sort
*/

void heap_sort(int *array, size_t size)
{
	int i = size / 2 - 1, temp;

	if (array == NULL || size < 2)
		return;
	for (; i >= 0; i--)
		heapify(array, size, i, size);
	for (i = size - 1; i >= 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		if (i > 0)
			print_array(array, size);
		heapify(array, i, 0, size);
	}
}
