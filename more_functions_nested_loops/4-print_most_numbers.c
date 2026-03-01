#include "main.h"

/**
 * print_most_numbers - prints numbers from 0 to 9 except 2 and 4
 *
 * Return: void
 */
void print_most_numbers(void)
{
	char n[] = "01356789\n";
	int i;

	for (i = 0; n[i] != '\0'; i++)
		_putchar(n[i]);
}
