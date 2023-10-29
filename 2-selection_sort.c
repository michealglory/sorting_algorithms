#include "sort.h"

/**
 * selection_sort - Sorts an array using election sort algorithm.
 * @array: An array to sort.
 * @size: The size of the array.
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
	int temp = 0;
	size_t iter_i = 0, iter_j = 0, item_pos = 0;

	if (array == NULL || size == 0)
		return;

	for (; iter_i < size - 1; iter_i++)
	{
		item_pos = iter_i;
		for (iter_j = iter_i + 1; iter_j < size; iter_j++)
		{
			if (array[iter_j] < array[item_pos])
				item_pos = iter_j;
		}
		if (item_pos != iter_i)
		{
			temp = array[iter_i];
			array[iter_i] = array[item_pos];
			array[item_pos] = temp;
			print_array(array, size);
		}
	}
}
