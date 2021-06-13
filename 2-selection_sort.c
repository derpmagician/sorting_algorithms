#include "sort.h"

/**
 * swap - Function swap
 * @xp: pointer listint_t
 * @yp: pointer listint_t
 * Return: void
 */
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 * selection_sort - Entry point
 * @array: pointer of a integer
 * @size: size_t
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	int *min;
	size_t f, fi;

	if (array == NULL || size < 2)
		return;

	for (f = 0; f < size - 1; f++)
	{
		min = array + f;
		for (fi = f + 1; fi < size; fi++)
			min = (array[fi] < *min) ? (array + fi) : min;

		if ((array + f) != min)
		{
			swap(array + f, min);
			print_array(array, size);
		}
	}
}

