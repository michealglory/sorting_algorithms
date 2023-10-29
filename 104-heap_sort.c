#include "sort.h"

/**
 * swap_root - Swap the root nodes.
 * @array: The heap to sort.
 * @root: The root of the heap.
 * @hi: The higher index.
 * @size: The size of the array.
 * Return: Nothing
 */
void swap_root(int *array, size_t root, size_t hi, size_t size)
{
	size_t low = 0, middle = 0, temp = 0;
	int aux = 0;

	while ((low = (2 * root + 1)) <= hi)
	{
		temp = root;
		middle = low + 1;
		if (array[temp] < array[low])
			temp = low;
		if (middle <= hi && array[temp] < array[middle])
			temp = middle;
		if (temp == root)
			return;
		aux = array[root];
		array[root] = array[temp];
		array[temp] = aux;
		print_array(array, size);
		root = temp;
	}
}

/**
 * heap_sort - Sorts an array using heap algorithm.
 * @array: An array to sorted.
 * @size: The size of the array to be sorted.
 * Return: Void.
 */
void heap_sort(int *array, size_t size)
{
	size_t high = 0, gap = 0;
	int temp = 0;

		if (array == NULL || size < 2)
			return;

		for (gap = (size - 2) / 2; 1; gap--)
		{
			swap_root(array, gap, size - 1, size);
			if (gap == 0)
				break;
		}

		high = size - 1;
		while (high > 0)
	{
		temp = array[high];
		array[high] = array[0];
		array[0] = temp;
		print_array(array, size);
		high--;
		swap_root(array, 0, high, size);
	}
}
