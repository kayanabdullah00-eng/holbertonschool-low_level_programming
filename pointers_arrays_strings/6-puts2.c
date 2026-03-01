#include "main.h"
#include <stdio.h>

/**
 * puts2 - prints every other character of a string
 * @str: pointer to the string
 *
 * Return: void
 */
void puts2(char *str)
{
	int i;
	int len;

	if (!str) /* تحقق من عدم وجود NULL */
		return;

	/* نحسب طول السلسلة */
	len = _strlen(str);

	/* نطبع كل حرف ثاني */
	for (i = 0; i < len; i += 2)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
