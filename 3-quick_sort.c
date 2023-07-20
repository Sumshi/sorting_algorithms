#include "sort.h"
/**
 * quick_sort - Sorts an array of integers in ascending order
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
/*0 is the  first element, size -1 is the last element*/
	quick_sort_recursive(array, 0, size - 1);
}

/**
 * quick_sort_recursive - Recursive function to perform Quick sort
 * @array: Array to sorted
 * @low: Starting index of the partition(left)
 * @high: Ending index of the partition(right)
 */
void quick_sort_recursive(int *array, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high);
		quick_sort_recursive(array, low, pivot - 1);/*left */
		quick_sort_recursive(array, pivot + 1, high);/*right*/
	}
}

/**
 * partition - Performs Lomuto partition and rearranges the array
 * @array: Array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * Return: Index of the pivot after partitioning
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, high + 1);
			}
		}
	}

	if (i + 1 != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, high + 1);
	}

	return (i + 1);
}
