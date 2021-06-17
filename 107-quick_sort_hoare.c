#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps integers at positions `i` and `j` in `array`
 * @array: array to swap positions
 * @i: left index
 * @j: right index
 */
void swaparr(int *array, int i, int j)
{
	int tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

/**
 * partit - partition subarray of `array` around pivot using
 * Hoare method (always choose right element).
 * @array: array to partition
 * @left: left end of subarray
 * @right: right end of subarray
 * @size: size of array
 * Return: index of pivot after it has been sorted
 */
int partit(int *array, int left, int right, size_t size)
{
	int i, j, pivot;

	if (left >= right)
		return (left);
	swaparr(array, left, right);
	print_array(array, size);
	pivot = array[left];
	i = left;
	j = right + 1;
	while (1)
	{
		do {
			i++;
		} while (array[i] <= pivot && i < right);

		do {
			j--;
		} while (array[j] > pivot && j > i);

		if (i == j)
		{
			swaparr(array, i - 1, left);
			print_array(array, size);
			return (i - 1);
		}
		if (i == right && pivot < array[right])
		{
			swaparr(array, left, right - 1);
			print_array(array, size);
			return (right - 1);
		}
		if (i == right && pivot > array[right])
		{
			swaparr(array, left, right);
			print_array(array, size);
			return (right);
		}
		swaparr(array, i, j);
		print_array(array, size);
	}
}

/**
 * rec_sort_h - recursively partition array until it is fully sorted
 * @array: array to sort
 * @left: left side of subarray for recursion
 * @right: right side of subarray for recursion
 * @size: size of array
 */
void rec_sort_h(int *array, int left, int right, size_t size)
{
	int p;

	if (left < right)
	{
		p = partit(array, left, right, size);
		rec_sort_h(array, left, p - 1, size);
		rec_sort_h(array, p + 1, right, size);
	}
}

/**
 * quick_sort_hoare - wrapper around recursive quicksort function
 * @array: array to sort
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	rec_sort_h(array, 0, (int)(size - 1), size);
}
