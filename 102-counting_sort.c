#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * find_max - find the max....
 * @array: - the array to find the max....
 * @size: the size of the array....
 * Return: the max.....
 */
int find_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - function that sorts an array of integers
 * in ascending order using the Counting sort algorithm
 *
 * @array: array to sort
 * @size: the size of the array
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int j, max = find_max(array, size);
	int *count_array, *tmp_array;

	if (!array || size < 2)
		return;

	count_array = malloc((max + 1) * sizeof(int));
	if (count_array == NULL)
		return;

	for (j = 0; j <= max; j++)
		count_array[j] = 0;
	for (i = 0; i < size; i++)
		count_array[array[i]]++;
	for (j = 0; j <= max; j++)
		count_array[j] += count_array[j - 1];

	print_array(count_array, max + 1);

	tmp_array = malloc(size * sizeof(int));
	if (tmp_array == NULL)
	{
		free(count_array);
		return;
	}

	for (i = 0; i < size; i++)
	{
		tmp_array[count_array[array[i]] - 1] = array[i];
		tmp_array[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = tmp_array[i];

	free(count_array);
	free(tmp_array);
}
