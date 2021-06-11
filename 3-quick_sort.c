#include "sort.h"

/**
 * quick_sort - Entry point
 * @array: pointer integer
 * @size: size_t
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;

	quick(array, 0, size);
}

void quick(int *array, size_t low, size_t high)
{
	size_t p; //Partition index

	if (low < high)
	{
		p = partition(array, low, high);
		quick(array, low, p - 1);
		quick(array, p + 1, high);
		//print_array(array, size);
	}
}


int partition(int *array, int low, int high)
{
	int pivot, j;
	int i = (low - 1);
	pivot = array[high];

	for (j = high; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

