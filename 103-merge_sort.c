#include "sort.h"
/**
 * merge_sort - A function that sorts an array using merge algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 * Return: Nothing.
 */
void merge_sort(int *array, size_t size)
{
	size_t i = 0;/*for iterating the array*/
	int *copy = NULL;/*temporary copy of the original array*/

	if (array == NULL || size <= 1)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)/*memory allocation failed*/
		return;
	for (; i < size; i++)/*copies element from original arrray*/
		copy[i] = array[i];
	merge_partition(0, size, array, copy);/* O is left, size is right*/
	free(copy);
}

/**
 * merge - sorts the subarrays.
 * @low: Lower index.
 * @mid: Middle index.
 * @high: Higher index.
 * @dest: Destination for data.
 * @src: Input data.
 * Return: Nothing
 */
void merge(size_t low, size_t mid, size_t high, int *dest, int *src)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(src + low, mid - low);
	printf("[right]: ");
	print_array(src + mid, high - mid);
	i = low;
	j = mid;
	k = low;
	for (; k < high; k++)
	{
		if (i < mid && (j >= high || src[i] <= src[j]))
		{
			dest[k] = src[i];
			i++;
		}
		else
		{
			dest[k] = src[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(dest + low, high - low);
}

/**
 * merge_partition - A funtion that splits the array recursively.
 * @low: Lower index.
 * @high: Higher index.
 * @array: The array to sort.
 * @copy: The copy of the array.
 * Return: Nothing.
 */
void merge_partition(size_t low, size_t high, int *array, int *copy)
{
	size_t mid = 0;

	if (high - low < 2)
		return;
	mid = (low + high) / 2;
	merge_partition(low, mid, array, copy);
	merge_partition(mid, high, array, copy);
	merge(low, mid, high, array, copy);
	for (mid = low; mid < high; mid++)
		copy[mid] = array[mid];
}
