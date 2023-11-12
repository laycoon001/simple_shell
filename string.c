#include "main.h"

/**
 * _atoi - converts a character string to an integer
 * @str: the string argument
 *
 * Return: the converted integer value
 */
int _atoi(char *str)
{
	int result = 0;
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - '0');
		else
			return (0);
		i++;
	}
	return (result);
}

/**
 * _strlen - calculates the length of a string
 * @str: pointer to the string
 * Return: length of the string
 */
size_t _strlen(const char *str)
{
	size_t len;

	if (str == NULL)
		return (0);
	len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _strcmp - compares two strings
 * @str1: string one
 * @str2: string two
 *
 * Return: 0 or 1
 */
int _strcmp(const char *str1, const char *str2)
{
	int len;

	for (len = 0; str1[len] == str2[len] && str1[len] != '\0'; len++)
		;
	if (str[len] > str[len])
		return (1);
	else if (str[len] < str2[len])
		return (-1);
	return (0);
}

/**
 * _strncmp - comapres two strings up to a specified
 * number of bytes
 * @str1: the first string
 * @str2: the secod string
 * @n: maximum number of bytes
 * Return: 0 if the strings are equal to number of n bytes
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	if (n == 0)
		return (0);

	while (*str1 != '\0' && *str2 != '\0' && n > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);

		str1++;
		str2++;
		n--;
	}
	if (n == 0)
		return (0);

	return (*str1 - *str2);
}

/**
 * _strcat - concatenation of two strings
 * @dest: the first string the second will be added
 * @src: the string to add
 *
 * Return: the concatenated str
 */
char *_strcat(char *dest, const char *src)
{
	int dest_len = 0;
	int i;

	while (dest[dest_len] != '\0')
		dest_len++;

	for (i = 0; src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];

	dest[dest_len + i] = '\0';

	return (dest);
}
