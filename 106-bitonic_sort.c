#include "sort.h"

/**
 * swap - A utility function to swap to integers
 * @a: pointer integer
 * @b: pointer integer
 * Return: void
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


/**
 * bit_merge - Merges an array with half size step
 * @array: array of ints
 * @idx: starting index
 * @size: Subarray's size
 * @direction: indicator of the sort order
*/
void bit_merge(int *array, int idx, int size, int direction)
{
	int i, step;

	if (size <= 1)
		return;

	step = size / 2;

	for (i = idx; i < idx + step; i++)
		if (direction == (array[i] > array[i + step]))
			swap(array, i, i + step);

	bit_merge(array, idx, step, direction);
	bit_merge(array, idx + step, step, direction);
}


/**
 * bit_sort - Divides an array in 2 parts
 * @array: array of ints
 * @msize: Main array's size
 * @idx: starting index
 * @size: Subarray size
 * @dir: indicator of the sort order
*/
void bit_sort(int *array, size_t msize, int idx, int size, int dir)
{
	int half = size / 2;
	char *d = "UP";

	if (size <= 1)
		return;

	if (dir == 0)
		d = "DOWN";

	printf("Merging [%d/%ld] (%s):\n", size, msize, d);
	print_array(array + idx, size);

	bit_sort(array, msize, idx, half, 1);
	bit_sort(array, msize, idx + half, half, 0);
	bit_merge(array, idx, size, d);

	printf("Result [%d/%ld] (%s):\n", size, msize, d);
	print_array(array + idx, size);
}


/**
 * bitonic_sort - Sort array using bitonic sort
 * @array: Array of ints
 * @size: Size of the array
*/
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bit_sort(array, size, 0, size, 1);
}
