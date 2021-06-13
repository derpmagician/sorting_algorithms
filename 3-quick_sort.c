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
 * @lower: int
 * @higher: int
 * @size: size_t
 * Return: void
 */

void quick(int *array, int lower, int higher, size_t size)
{
	int l_p = 0;

	if (lower < higher)
	{
		l_p = lomuto_partition(array, lower, higher, size);
		quick(array, lower, l_p - 1, size);
		quick(array, l_p + 1, higher, size);
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

int lomuto_partition(int *array, int lower, int higher, size_t size)
{
	int i = 0, j = 0, pivot = 0, aux = 0;

	pivot = array[higher];
	i = lower;

	for (j = lower; j < higher; ++j)
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

	aux = array[i];
	array[i] = array[higher];
	array[higher] = aux;

	if (aux != array[i])
		print_array(array, size);

	return (i);
}
