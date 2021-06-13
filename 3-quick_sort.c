#include "sort.h"

/**
 * quick_sort - Entry point
 * @array: pointer integer
 * @size: size_t
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick(array, 0, size - 1, size);
}

/**
 * quick - Entry point
 * @array: pointer integer
 * @size: size_t
 * @low: size_t
 * @high: size_t
 * Return: void
 */

void quick(int *array, int low, int high, size_t size)
{
	int l_p = 0;

	if (low < high)
	{
		l_p = partition(array, low, high, size);
		quick(array, low, l_p - 1, size);
		quickarray, l_p + 1, high, size);
	}
}

/**
 * partition - Entry point
 * @array: pointer integer
 * @size: size_t
 * @low: size_t
 * @high: size_t
 * Return: j
 */

int partition(int *array, int low, int high, size_t size)
{
	int *pivot, i, j;

	pivot = array + high;

	for (j = i = low; i < high; i++)
	{
		if (array[i] < *pivot)
		{
			if (j < i)
			{
				swap1(array + i, array + j);
				print_array(array, size);
			}
			j++;
		}
	}
	if (array[j] > *pivot)
	{
		swap1(array + j, pivot);
		print_array(array, size);
	}

	return (j);
}

/**
 * swap1 - Function swap1
 * @a: pointer listint_t
 * @b: pointer listint_t
 * Return: void
 */
void swap1(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
