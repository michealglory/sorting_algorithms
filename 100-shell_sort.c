#include "sort.h"

/**
  * shell_sort - Sorts an array usin shell algorithm.
  * @array: The array to sort.
  * @size: The length of the array.
  * Return: Nothing.
  */
void shell_sort(int *array, size_t size)
{
	unsigned int iter_i = 0, iter_j = 0, space = 0;
	int aux = 0;

	if (array == NULL || size < 2)
		return;

	while (space < size / 3)
		space = space * 3 + 1;

	for (; space > 0; space = (space - 1) / 3)
	{
		for (iter_i = space; iter_i < size; iter_i++)
		{
			aux = array[iter_i];
			for (iter_j = iter_i; iter_j >= space 
				&& array[iter_j - space] > aux;
					iter_j -= space)
			{
				if (array[iter_j] != array[iter_j - space])
					array[iter_j] = array[iter_j - space];
			}
			if (array[iter_j] != aux)
				array[iter_j] = aux;

		}
		print_array(array, size);
	}
}
