#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - fuction that merges two arrays.....
 * @array: the array to swap....
 * @left: starting index....
 * @mid: middle index.....
 * @right: end index.....
 * @tmp_array: temporary array.....
 * @size: size of the array.......
 */
void merge(int *array, size_t left, size_t mid, size_t right, int *tmp_array)
{
	size_t i = left, j;
	size_t idx, k = 0;

	j = mid + 1;
	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
			tmp_array[k++] = array[i++];
		else
			tmp_array[k++] = array[j++];
	}

	while (i <= mid)
		tmp_array[k++] = array[i++];

	while (j <= right)
		tmp_array[k++] = array[j++];

	for (idx = 0; idx < k; idx++)
		array[left + idx] = tmp_array[idx];
}

/**
 * sorter - function that sort the left and right
 * recursively
 *
 * @array: array: to sort
 * @left: left half of the array
 * @right: the right half
 * @tmp_array: temp array
 */
void sorter(int *array, size_t left, size_t right, int *tmp_array)
{
	size_t mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;

		sorter(array, left, mid, tmp_array);
		sorter(array, mid + 1, right, tmp_array);

		printf("Merging...\n");

		printf("[left]: ");
		print_array(array + left, mid - left + 1);

		printf("[right]: ");
		print_array(array + mid + 1, right - mid);

		printf("[Done]: ");
		merge(array, left, mid, right, tmp_array);
		print_array(array + left, right - left + 1);

		printf("\n");
	}
}

/**
 * merge_sort - function that sorts an array of integers
 * in ascending order using the Merge sort algorithm
 *
 * @array: array to swap
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp_array = NULL;

	if (!array || size < 2)
		return;

	tmp_array = malloc(size * sizeof(int));
	if (tmp_array == NULL)
		return;

	sorter(array, 0, size - 1, tmp_array);
	free(tmp_array);
}
