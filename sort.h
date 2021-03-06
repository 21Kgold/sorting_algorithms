#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Auxiliary functions*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
size_t knuth_sequence(size_t maximum);
int find_max(int *array, size_t size);

/* Sorting functions*/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

void sort(int *array, size_t size, int start, int end);
int partitioning(int *array, size_t size, int start, int end);
void swap_arr(int *array, size_t size, int start, int end);
int swap_opposite(listint_t **list, listint_t *current);
#endif
