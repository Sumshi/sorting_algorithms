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

	for (i = 1; i < size; i++)
	{
		if (array[i] > max;
			max = array[i];
	}
	return (max);
}
/**
 * counting_sort - Sorts an array of integers using counting sort
 * @array: The input array
 * @size: Size of the array
 * @digit: The current digit place value
 */
void counting_sort(int *array, size_t size, int digit)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;
	int i;

	if (!output)
	{
        	exit(EXIT_FAILURE);
    	}
	for (i = 0; i < size; i++)
        	count[(array[i] / digit) % 10]++;

	for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / digit) % 10] - 1] = array[i];
        	count[(array[i] / digit) % 10]--;
	}
	for (i = 0; i < size; i++)
        	array[i] = output[i];
    free(output);
}
/**
 * radix_sort - Sorts an array of integers using LSD sort algorithm
 * @array: The input array
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	int digit;

	for (digit = 1; max / digit > 0; digit *= 10)
	{
        	counting_sort(array, size, digit);
        	print_array(array, size);
	}
}
