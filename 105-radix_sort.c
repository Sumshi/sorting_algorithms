#include "sort.h"
/**
 * get_max - Returns the maximum value in an array
 * @array: The input array
 * @size: Size of the array
 * Return: The maximum value
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max;
			max = array[i];
	}
	return (max);
}
