#include "sort.h"

/**
 * quick_sort - function that sorts an array
 * of integers in ascending order using the
 * quick sort algorithm
 *
 * @array: input arrray
 * @size: size of the array
 * Return: no return
 */
void quick_sort(int *array, size_t size)
{
	_qsort(array, 0, size - 1, size);
}
/**
 * _qsort - auxiliar function for the
 * quick_sort function
 * @a: input arrray
 * @low: index for the first element
 * @high: index for the last element
 * @size: size of the array
 * Return: no return
 */
void _qsort(int *a, int low, int high, int size)
{
	int x, y, z;
	int tmp;

	if (low < high)
	{
		x = high;
		y = low;
		for (z = low; z < high; z++)
		{
			if (a[z] < a[x])
			{
				if (z != y)
				{
					tmp = a[z];
					a[z] = a[y];
					a[y] = tmp;
					print_array(a, size);
				}
				y++;
			}
		}
		if (y != x && a[y] != a[x])
		{
			tmp = a[y];
			a[y] = a[x];
			a[x] = tmp;
			print_array(a, size);
		}
		_qsort(a, low, y - 1, size);
		_qsort(a, y + 1, high, size);
	}
}
