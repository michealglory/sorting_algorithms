#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers
 *              in ascending order using the Quick sort algorithm
 * @array: array
 * @size: array's size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_s(array, 0, size - 1, size);
}

/**
 * partition - partition
 * @array: array
 * @lo: lower
 * @hi: higher
 * @size: array's size
 * Return: i
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int iter_i = lo - 1, iter_j = lo;
	int pivot_point = array[hi], aux = 0;

	for (; iter_j < hi; iter_j++)
	{
		if (array[iter_j] < pivot_point)
		{
			iter_i++;
			if (array[iter_i] != array[iter_j])
			{
				aux = array[iter_i];
				array[iter_i] = array[iter_j];
				array[iter_j] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[iter_i + 1] != array[hi])
	{
		aux = array[iter_i + 1];
		array[iter_i + 1] = array[hi];
		array[hi] = aux;
		print_array(array, size);
	}
	return (iter_i + 1);
}

/**
 * quick_s - quick sort
 * @array: given array
 * @lo: lower
 * @hi:higher
 * @size: array's size
 * Return: void
 */
void quick_s(int *array, int lo, int hi, size_t size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		quick_s(array, lo, pivot - 1, size);
		quick_s(array, pivot + 1, hi, size);
	}
}