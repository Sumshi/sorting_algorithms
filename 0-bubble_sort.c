#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int swapped;/*indicates if any elements were swapped*/
	size_t i;/*Traverses the array, outer loop*/
	size_t j;/*iterates the inner loop compares elements*/
	int temp;/*to store copy of one element*/

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		swapped = 0;/*no elements were swapped at the start*/
		for (j = 0; j < (size - 1); j++)
		{
			if (array[j] > array[j + 1])/*< for descending order*/
			{
				/* Swap the elements */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;/*elements were swapped*/
				print_array(array, size);
			}
		}  
		if (!swapped)/*means it was already sorted*/
			break;
	}
}
