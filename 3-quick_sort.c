#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Function to swap two elements in an array
 * @element_1: first element
 * @element_2: second element
 */
void swap(int *element_1, int *element_2)
{
	int tmp = *element_1;
	*element_1 = *element_2;
	*element_2 = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme algorithm
 * @array: the array to sort
 * @size: size of the array
 * @low: low element
 * @high: high element
 *
 * Return: pivot index
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * q_sort_lomuto - sort using recursion
 * @array: the array to sort
 * @size: size of the array
 * @low: low element
 * @high: the highest index
 * Return: Void (Nothing)
 */
void q_sort_lomuto(int *array, size_t size, int low, int high)
{
	int index;

	if (low < high)
	{
		index = lomuto_partition(array, size, low, high);

		q_sort_lomuto(array, size, low, index - 1);
		q_sort_lomuto(array, size, index + 1, high);
	}
}

/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 *
 * @array: The array to sort
 * @size: size of the array
 * Return: Void (Nothing)
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;

	q_sort_lomuto(array, size, 0, size - 1);
}
