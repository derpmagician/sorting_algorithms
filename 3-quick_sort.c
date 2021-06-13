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
	int i = 0, j = 0, pivot = 0, aux = 0;

	pivot = array[higher];
	i = low;

	for (j = lower; j < high; ++j)
	{
		if (array[j] < pivot)
		{
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;

			if (aux != array[i])
				print_array(array, size);

			++i;
		}
	}
}
