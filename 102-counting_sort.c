#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */

void counting_sort(int *array, size_t size)
{
	int i;
	int output[15];
	size_t max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	int count[15];

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

}
