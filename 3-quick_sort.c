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

	quick(array, size, 0, size - 1);
}

/**
 * quick - Entry point
 * @array: pointer integer
 * @size: size_t
 * @low: size_t
 * @high: size_t
 * Return: void
 */

void quick(int *array, size_t size, int low, int high)
{
	size_t p; /* Partition index */

	if (low < high)
	{
		p = partition(array, size, low, high);
		quick(array, size, low, p - 1);
		quick(array, size, p + 1, high);
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

int partition(int *array, size_t size, int low, int high)
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
