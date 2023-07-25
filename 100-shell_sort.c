#include "sort.h"
/**
 * shell_sort - Sorts an array of integers in ascending order
 * it is a variation of insertion sort, it uses gaps
 * gap determines how far apart elements are
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i;/*outer loop*/
	size_t j;/*for inner loop*/
	int temp;

	if (array == NULL || size < 2)
		return;

	/*use knuth sequence to get the gap*/
	while (gap < size)
		gap = gap * 3 + 1;
	gap = (gap - 1) / 3;

	while (gap > 0)
	{
		for (i = 0; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
