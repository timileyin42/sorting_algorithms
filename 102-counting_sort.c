#include "sort.h"

/**
 * counting_sort -Sorts an arrayof integers
 * in ascending order using the
 * Counting sort algorithm
 * @array: array
 * @size: size
 * Return: no return
 */
void counting_sort(int *array, size_t size)
{
	int x, y;
	int *buff, *a;

	if (size < 2)
		return;

	for (x = y = 0; y < (int)size; y++)
		if (array[y] > x)
			x = array[y];

	buff = malloc(sizeof(int) * (x + 1));
	if (!buff)
		return;

	for (y = 0; y <= x; y++)
		buff[y] = 0;
	for (y = 0; y < (int)size; y++)
		buff[array[y]] += 1;
	for (y = 1; y <= x; y++)
		buff[y] += buff[y - 1];

	print_array(buff, (x + 1));
	a = malloc(sizeof(int) * (size + 1));

	if (!a)
	{
		free(buff);
		return;
	}
	for (y = 0; y < (int)size; y++)
	{
		a[buff[array[y]] - 1] = array[y];
		buff[array[y]] -= 1;
	}
	for (y = 0; y < (int)size; y++)
		array[y] = a[y];
	free(buff);
	free(a);
}
