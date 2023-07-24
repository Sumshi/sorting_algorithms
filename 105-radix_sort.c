#include "sort.h"
/**
 * get_max - Returns the maximum value in an array
 * @array: The input array
 * @size: Size of the array
 * Return: The maximum value
 */
int get_max(int *array, size_t size)
{
	int i;
	int  max = array[0];/*to store the maximum value*/

	for (i = 1; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}
/**
 * count_sort - Sorts an array of integers using counting sort
 * @array: The input array
 * @size: Size of the array
 * @digit: The current digit place value
 */
void count_sort(int *array, size_t size, int digit)
{
	int *output = NULL;
	int i;
	int count[10] = {0};/*is used for counting occurrences of digits*/

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	for (i = 0; i < (int)size; i++)
		count[(array[i] / digit) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = (int)size - 1; i >= 0; i--)
	{
		output[count[(array[i] / digit) % 10] - 1] = array[i];
		count[(array[i] / digit) % 10]--;
	}
	for (i = 0; i < (int)size; i++)
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
	int digit, max;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);
	for (digit = 1; max / digit > 0; digit *= 10)
	{
		count_sort(array, size, digit);
		print_array(array, size);
	}
}
