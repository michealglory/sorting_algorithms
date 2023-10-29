#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge_sort - Sorts an array using merge algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array to be sorted.
 * Return: Void.
 */
void merge_sort(int *array, size_t size)
{
	size_t iter_i = 0;
	int *base_ptr = NULL;

	if (array == NULL || size < 2)
		return;
	base_ptr = malloc(sizeof(int) * size);
	if (base_ptr == NULL)
		return;
	for (; iter_i < size; iter_i++)
		base_ptr[iter_i] = array[iter_i];
	merge_partition(0, size, array, base_ptr);
	free(base_ptr);
}

/**
 * merge - Sorts the subarrays.
 * @lo: Lower index.
 * @mi: Middle index.
 * @hi: Higher index.
 * @dest: Destination for data.
 * @src: Input data.
 * Return: Nothing
 */
void merge(size_t lo, size_t mi, size_t hi, int *dest, int *src)
{
	size_t iter_i = 0, iter_j = 0, iter_k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(src + lo, mi - lo);
	printf("[right]: ");
	print_array(src + mi, hi - mi);
	iter_i = lo;
	iter_j = mi;
	iter_k = lo;
		for (; iter_k < hi; iter_k++)
		{
			if (iter_i < mi && (iter_j >= hi || src[iter_i] <= src[iter_j]))
			{
				dest[iter_k] = src[iter_i];
				iter_i++;
			}
			else
			{
				dest[iter_k] = src[iter_j];
				iter_j++;
			}
		}
	printf("[Done]: ");
	print_array(dest + lo, hi - lo);
}

/**
 * merge_partition - Splits the array recursively.
 * @lo: Lower index.
 * @hi: Higher index.
 * @array: The array to sort.
 * @base: The copy of the array.
 * Return: Nothing.
 */
void merge_partition(size_t lo, size_t hi, int *array, int *base)
{
	size_t middle = 0;

	if (hi - lo < 2)
		return;
	middle = (lo + hi) / 2;
	merge_partition(lo, middle, array, base);
	merge_partition(middle, hi, array, base);
	merge(lo, middle, hi, array, base);
	for (middle = lo; middle < hi; middle++)
		base[middle] = array[middle];
}
