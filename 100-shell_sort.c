#include "sort.h"

/**
 * shell_sort - Shell sort an array using Knuth sequence
 * @array: Array to sort
 * @size: Size of array to sort
 */
void shell_sort(int *array, size_t size)
{
	unsigned int interval = 1;
	unsigned int i, j;
	int temp = 0;

	if (!array || size < 2)
		return;
	while (interval * 3 + 1 < size)
		interval = interval * 3 + 1;
	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			for (j = i; j > interval - 1; j -= interval)
			{
				if (array[j - interval] >= array[j])
				{
					temp = array[j];
					array[j] = array[j - interval];
					array[j - interval] = temp;
				}
			}
		}
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}
