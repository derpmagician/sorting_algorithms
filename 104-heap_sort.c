#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
void heap_sort(int *array, size_t size)
{

}
/**
 * maxHeapify - Entry point
 *
 * Return: Always 0
 * The function assumes that everything undex given root (element 
 * at index (idx) us already heapified)
 */

void maxHeapify(listint_t *maxHeap; int index)
{
	int largest = index; /* Inicialize largest as root*/
	int left = (index << 1) + 1; /* left = 2 * index + 1 */
	int right = (index + 1) << 1; /* right = 2 * index +2 */

	/*see if left child of root exists and is greater than root */
	if (left < maxHeap->n && maxHeap->next[left] > maxHeap->next[largest])
		largest = left;
	/* See if right child of root exists and is greater than the largest so far */
	if (right < maxHeap->n && maxHeap->next[right] > maxHeap->next[largest])
		largest = right;

	/* Change root, if needed */
	if (largest != index)
	{
		swap(&maxHeap->next[largest], &maxHeap->next[index]);
		maxHeapify(maxHeap, largest);
	}
}
