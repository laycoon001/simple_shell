#include "main.h"
/**
 * _strcpy - copying of strings
 * @dest: destination
 * @src: source
 * Return: pointer to destinaion
 *
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - duplication
 *
