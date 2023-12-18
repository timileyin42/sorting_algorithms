#include "sort.h"

/**
 * selection_sort - sorts an array of integers in
 * ascending order using the Selection sort
 * algorithm
 *
 * @array: input array of integers
 * @size: size of the array
 * Return: no return
 */
void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t x, y, z;

	for (x = 0; x < size; x++)
	{
		z = x;
		for (y = x + 1; y < size; y++)
		{
			if (array[z] > array[y])
				z = y;
		}

		if (x != z)
		{
			tmp = array[x];
			array[x] = array[z];
			array[z] = tmp;
			print_array(array, size);
		}
	}
}
