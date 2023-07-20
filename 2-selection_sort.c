#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using Selection sort algorithm
 * @array: Pointer to the first element of the array
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i;/*iterates outer loop which contains array element*/
	size_t j;/*iterates inner loop, compares elements*/
	int temp;/*stores a copy of one element*/
	size_t min_idx;/*smallest element in the array*/

	if (array == NULL || size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;/*points to first index*/

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])/* use > to sort max to min*/
				min_idx = j;
		}
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
		}
	}
}
