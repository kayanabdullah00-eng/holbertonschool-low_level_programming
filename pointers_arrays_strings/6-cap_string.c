#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: input string
 *
 * Return: pointer to the resulting string
 */
char *cap_string(char *str)
{
	int i = 0;
	int sep;

	char separators[] = " \t\n,;.!?\"(){}";

	/* Capitalize the first character if needed */
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 'a' - 'A';

	while (str[i] != '\0')
	{
		sep = 0;
		for (int j = 0; separators[j] != '\0'; j++)
		{
			if (str[i] == separators[j])
			{
				sep = 1;
				break;
			}
		}

		if (sep && str[i + 1] >= 'a' && str[i + 1] <= 'z')
			str[i + 1] -= 'a' - 'A';

		i++;
	}

	return (str);
}
