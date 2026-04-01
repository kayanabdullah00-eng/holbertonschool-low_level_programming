#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes from s2 to concatenate
 *
 * Return: pointer to the new string, or NULL if fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	unsigned int len1 = 0, len2 = 0, i, j;

	/* 1. If NULL is passed, treat it as an empty string */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* 2. Calculate lengths of s1 and s2 */
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;

	/* 3. If n >= len2, use the entire string s2 */
	if (n >= len2)
		n = len2;

	/* 4. Malloc space for s1 + n bytes + null terminator */
	concat = malloc(sizeof(char) * (len1 + n + 1));
	if (concat == NULL)
		return (NULL);

	/* 5. Copy s1 into concat */
	for (i = 0; i < len1; i++)
		concat[i] = s1[i];

	/* 6. Copy n bytes of s2 into concat */
	for (j = 0; j < n; j++, i++)
		concat[i] = s2[j];

	/* 7. Add the null terminator */
	concat[i] = '\0';

	return (concat);
}
