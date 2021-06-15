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

	if (size <= 1)
		return;

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
