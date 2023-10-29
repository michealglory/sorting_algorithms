#include "sort.h"

/**
  * bubble_sort - sorts an array using the bubble sort algorithm.
  * @array: The array to sort.
  * @size: THe length of the aaray.
  * Return: Nothing.
  */
void bubble_sort(int *array, size_t size)
{
	size_t iter_i = 0, iter_j = 0;
	int temp = 0;

	if (array == NULL || size == 0)
		return;
	for (; iter_i < size - 1; iter_i++)
	{
		for (iter_j = 0; iter_j < size - iter_i - 1; iter_j++)
		{
			if (array[iter_j] > array[iter_j + 1])
			{
				temp = array[iter_j + 1];
				array[iter_j + 1] = array[iter_j];
				array[iter_j] = temp;
				print_array(array, size);
			}
		}
	}
}
