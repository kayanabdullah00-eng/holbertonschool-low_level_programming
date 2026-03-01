#include "main.h"

/**
 * print_numbers - prints the numbers, from 0 to 9
 *
 * Return: void
 */
void print_numbers(void)
{
	char n[11] = "0123456789\n";
	int i;

	for (i = 0; n[i] != '\0'; i++)
		_putchar(n[i]);
}
