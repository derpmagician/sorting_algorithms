#include "sort.h"

/**
 * swaps- Swap two integers in an array.
 * @a: The first integer.
 * @b: The second integer.
 */
void swaps(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * parti_lomuto - Order a subset of an array of integers.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 * Return: The final partition index.
 */
int parti_lomuto(int *array, size_t size, int left, int right)
{
	int *pivote, high, low;

	pivote = array + right;
	for (high = low = left; low < right; low++)
	{
		if (array[low] < *pivote)
		{
			if (high < low)
			{
				swaps(array + low, array + high);
				print_array(array, size);
			}
			high++;
		}
	}

	if (array[high] > *pivote)
	{
		swaps(array + high, pivote);
		print_array(array, size);
	}

	return (high);
}

/**
 * sort_lomuto - Implement the quicksort algorithm
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void sort_lomuto(int *array, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
		partition = parti_lomuto(array, size, left, right);
		sort_lomuto(array, size, left, partition - 1);
		sort_lomuto(array, size, partition + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending.
 * @array:  array of integers.
 * @size: the size of the array.
 * Description: Uses the Lomuto partition scheme.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_lomuto(array, size, 0, size - 1);
}
