#include "main.h"

/**
 * print_triangle - prints a triangle
 * @size: size of the triangle
 *
 * Return: void
 */
void print_triangle(int size)
{
	int i, j;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 1; i <= size; i++)
	{
		/* print spaces */
		for (j = i; j < size; j++)
			_putchar(' ');

		/* print #'s */
		for (j = 1; j <= i; j++)
			_putchar('#');

		_putchar('\n');
	}
}
