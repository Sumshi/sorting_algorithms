#include "sort.h"
/**
 * quick_sort - function that sorts an array of integers, most effecient
 * uses divide and conquer concepts
 * @array: array
 * @size: array's size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_recursive(array, 0, size - 1, size);
}
/**
 * quick_swap - function that swaps elements at index
 * @a: element
 * @b: element
 * Return: void
 */
void quick_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * partition - elements less than or greater than pivot are arranged
 * @array: array to partition
 * @low: index of the lowest element in the sublist
 * @high: index of the highest element in the sublist
 * @size: array's size
 * Return: i
 */
int partition(int *array, int low, int high, size_t size)
{
	int i = low - 1;
	int j = low;
	int pivot = array[high];

	for (; j < high; j++)
	{
		if (array[j] < pivot)/*lower elements*/
		{
			i++;
			if (array[i] != array[j])
			{
				quick_swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])/*higher elements*/
	{
		quick_swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_recursive - recursively sorts the array
 * @array: given array
 * @low: lower side
 * @high:high side
 * @size: array's size
 * Return: void
 */
void quick_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)/*base case*/
	{
		pivot = partition(array, low, high, size);
		quick_recursive(array, low, pivot - 1, size);/*low index*/
		quick_recursive(array, pivot + 1, high, size);/*higher index*/
	}
}
