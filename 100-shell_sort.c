#include "sort.h"

/**
 * shell_sort - function that sorts an array
 * of integers in ascending order using the
 * Shell sort algorithm
 *
 * @array: input arrray
 * @size: size of the array
 * Return: no return
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 1;

	while (n < size)
		n = (n * 3) + 1;

	while ((n = (n - 1) / 3) > 0)
		_ssort(array, size, n);
}

/**
 * _ssort - auxiliar function for
 * shell_sort function
 * @a: input arrray
 * @size: size of the array
 * @n: intervale
 * Return: no return
 */

void _ssort(int *a, int size, int n)
{
	int tmp, x, y;

	for (x = 0; (x + n) < size; x++)
	{
		for (y = x + n; (y - n) >= 0; y = y - n)
		{
			if (a[y] < a[y - n])
			{
				tmp = a[y];
				a[y] = a[y - n];
				a[y - n] = tmp;
			}
		}
	}
	print_array(a, size);
}
