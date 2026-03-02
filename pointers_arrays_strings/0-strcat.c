#include "main.h"

/**
 * _strcat - concatenates the string pointed to by src
 *           to the end of the string pointed to by dest
 * @dest: destination string
 * @src: source string to append
 *
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;

    /* Find the end of dest */
    while (dest[i] != '\0')
        i++;

    /* Copy src to dest starting at the end of dest */
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    /* Add terminating null byte */
    dest[i] = '\0';

    return dest;
}
