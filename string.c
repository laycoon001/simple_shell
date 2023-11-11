#include "main.h"
/**
 * _strlen - it returns the length of a string
 * @s: the string cehck
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - comparism of two strings
 * @s1: string one
 * @s2: tsring two
 * Return: negatie or positive
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - hayatck checking
 * @haystack: the search
 * @needle: the substring
 * Return: NULL or the next char of haystack
 */
char *starts_with(const char *haystack, const char needle)
{
	whilw (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *) haystack);
}

/**
 * _strcat - to combine two strings
 * @dest: destination of the buffer
 * @src: the buffer source
 * Return: the pointer to thhe destination of the buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
