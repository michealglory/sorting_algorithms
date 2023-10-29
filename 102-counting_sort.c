#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * counting_sort - sorts an array using counting algorithm.
  * @array: The array to sort.
  * @size: The length of the array.
  * Return: Nothing.
  */
void counting_sort(int *array, size_t size)
{
	unsigned int iter_i = 1;
	int *count = NULL, iter_k = 0, iter_j = 0;

	if (array == NULL || size < 2)
		return;

	iter_k = array[0];
	for (; iter_i < size; iter_i++)
	{
		if (array[iter_i] > iter_k)
			iter_k = array[iter_i];
	}

	count = malloc(sizeof(int) * (iter_k + 1));
	if (count == NULL)
		return;

	for (iter_j = 0; iter_j <= iter_k; iter_j++)
		count[iter_j] = 0;
	for (iter_i = 0; iter_i < size; iter_i++)
		count[array[iter_i]] += 1;
	for (iter_j = 0; iter_j < iter_k; iter_j++)
	{
		count[iter_j + 1] += count[iter_j];
		printf("%d, ", count[iter_j]);
	}
	count[iter_j + 1] += count[iter_j];
	printf("%d\n", count[iter_j + 1]);
	for (iter_i = 0; iter_i < size; iter_i++)
	{
		iter_j = count[array[iter_i]] - 1;
		if (array[iter_i] != array[iter_j])
		{
			iter_k = array[iter_i];
			array[iter_i] = array[iter_j];
			array[iter_j] = iter_k;
		}
	}
	free(count);
}
