#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void counting_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Find the maximum element in the array */
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Create a count array of size 'max + 1' */
    int *count_array = malloc((max + 1) * sizeof(int));
    if (count_array == NULL)
        return;

    /* Initialize the count array elements to 0 */
    for (int i = 0; i <= max; i++)
    {
        count_array[i] = 0;
    }

    /* Count the occurrences of each element in the input array */
    for (size_t i = 0; i < size; i++)
    {
        count_array[array[i]]++;
    }

    printf("%d", count_array[0]);
    for (int i = 1; i <= max; i++)
    {
        printf(", %d", count_array[i]);
    }
    printf("\n");

    /* Calculate the cumulative sums in the count array */
    for (int i = 1; i <= max; i++)
    {
        count_array[i] += count_array[i - 1];
    }

    /* Create an output array */
    int *output_array = malloc(size * sizeof(int));
    if (output_array == NULL)
    {
        free(count_array);
        return;
    }

    /* Place the elements in their correct sorted positions */
    for (ssize_t i = size - 1; i >= 0; i--)
    {
        output_array[count_array[array[i]] - 1] = array[i];
        count_array[array[i]]--;
    }

    /* Copy the sorted elements back to the input array */
    for (size_t i = 0; i < size; i++)
    {
        array[i] = output_array[i];
    }

    free(count_array);
    free(output_array);
}
