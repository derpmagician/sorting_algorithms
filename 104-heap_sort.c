#include "sort.h"

/**
 * swap - A utility function to swap to integers
 * @a: pointer integer
 * @b: pointer integer
 * Return: void
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * heapify - build a heap tree where the head is bigger of value branches
 * @array: unsorted array of integer
 * @size: size of the array
 * @i: index of starter head
 * @print_size: size of the array to print
 *
 * Return: void
 */
void heapify(int *array, size_t size, int i, size_t print_size)
{
	int head = i;
	int id_l = 2 * i + 1;
	int id_r = 2 * i + 2;

	if (id_l < (int)size && array[id_l] > array[head])
		head = id_l;
	if (id_r < (int)size && array[id_r] > array[head])
		head = id_r;
	if (head != i)
	{
		swap(&array[i], &array[head]);
		print_array(array, print_size);
		heapify(array, size, head, print_size);
	}
}

/**
 * heap_sort - The main function to sort an array of given size
 * @array: pointer integer
 * @size: size_t
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int idx, i;
	size_t print_size = size;

	if (size <= 1 || !array)
		return;

	idx = (int)(size / 2 - 1);
	for (i = idx; i >= 0; i--)
		heapify(array, size, i, print_size);

	for (i = size - 1; i >= 0; i--)
	{
		if (i != 0)
		{
			swap(&array[0], &array[i]);
			print_array(array, print_size);
			heapify(array, i, 0, print_size);
		}
	}
}
