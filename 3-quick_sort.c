#include "sort.h"
void quick(int *array, size_t size, size_t low, size_t high);
int partition(int *array, size_t size, size_t low, size_t high);
void swap(int *a, int *b);

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

	quick(array, size, 0, size - 1);
}

/**
 * quick - Entry point
 * @array: pointer integer
 * @low: size_t
 * @high: size_t
 * Return: void
 */

void quick(int *array, size_t size, size_t low, size_t high)
{
	size_t p; //Partition index

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
 * @low: size_t
 * @high: size_t
 * Return: i + 1
 */

int partition(int *array, size_t size, size_t low, size_t high)
{
	int pivot;
	size_t j;
	size_t i = (low - 1);
	pivot = array[high];

	for (j = high; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
 * swap - Function swap
 * @xp: pointer listint_t
 * @yp: pointer listint_t
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
