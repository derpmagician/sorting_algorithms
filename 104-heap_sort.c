#include "sort.h"

/**
 * heap_sort - The main function to sort an array of given size
 * @array: pointer integer
 * @size: size_t
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	/*  Build a heap from the input data. */
	MaxHeap_t *maxHeap = createAndBuildHeap(array, size);

	/**
	 * Repeat following steps while heap size is greater than 1.
	 * The last element in max heap will be the minimum element
	 */
	while (maxHeap->size > 1)
	{
		/**
		 * The largest item in Heap is stored at the root. Replace it
		 * with the last item of the heap followed by reducing the
		 * size of heap by 1.
		 */
		swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size - 1]);
		--maxHeap->size;  /*  Reduce heap size */

		print_array(array, size);
		/*  Finally, heapify the root of tree. */
		maxHeapify(maxHeap, 0, array, size);
	}
}

/**
 * maxHeapify - Function to heapify a Max Heap.
 * @maxHeap: pointer of MaxHeap_t
 * @idx: integer
 * @array: pointer integer
 * @size: size_t
 * Return: void
 * The function assumes that everything under given root
 * (element at index idx) is already heapified
 */
void maxHeapify(MaxHeap_t *maxHeap, int idx, int *array, size_t size)
{
	int largest = idx;  /* Initialize largest as root */
	int left = (idx << 1) + 1;  /* left = 2*idx + 1 */
	int right = (idx + 1) << 1; /* right = 2*idx + 2 */
	/* See if left child of root exists and is greater than root*/
	if (left < maxHeap->size && maxHeap->array[left] > maxHeap->array[largest])
		largest = left;
	/* See if right child of root exists and is greater than the largest so far*/
	if (right < maxHeap->size && maxHeap->array[right] > maxHeap->array[largest])
		largest = right;

	/* Change root, if needed */
	if (largest != idx)
	{
		swap(&maxHeap->array[largest], &maxHeap->array[idx]);
		print_array(array, size);
		maxHeapify(maxHeap, largest, array, size);
	}
}

/**
 * createAndBuildHeap - Utility function to create a max heap of given capacity
 * @array: pointer integer
 * @size: integer
 * Return: maxHeap
 */
MaxHeap_t *createAndBuildHeap(int *array, int size)
{
	int i;
	MaxHeap_t *maxHeap = (MaxHeap_t *) malloc(sizeof(MaxHeap_t));

	maxHeap->size = size;   /* initialize size of heap */
	maxHeap->array = array; /* Assign address of first element of array */

	/**
	* Start from bottommost and rightmost internal mode and heapify all internal
	* modes in bottom up way
	*/
	for (i = (maxHeap->size - 2) / 2; i >= 0; --i)
		maxHeapify(maxHeap, i, array, size);
	return (maxHeap);
}

/**
 * swap - A utility function to swap to integers
 * @a: pointer integer
 * @b: pointer integer
 * Return: void
 */
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
