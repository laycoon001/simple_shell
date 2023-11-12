#include "main.h"
/**
 * _strcpy - copying of strings
 * @dest: destination
 * @src: source
 * Return: pointer to destinaion
 *
 */
char *_strcpy(char *dest, const char *src)
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
 * _strdup - duplication of strings
 * @str: the string to duplcate
 *
 * Return: a copy or string or NULL
 */
char *_strdup(const char *str)
{
	char *str_copy;

	if (str == NULL)
		return (NULL);

	str_copy = (char *)malloc((_strlen(str) + 1) * sizeof(char));

	if (str_copy == NULL)
		return (NULL);

	_strcpy(str_copy, str);

	return (str_copy);
}

/**
 * _strchr - first occurrence of a character in a string
 * @str: string to search
 * @c: the character to locate
 *
 * Return: a pointer
 */
char *_strchr(const char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
		{
			return (char *)str;
		}
		str++;
	}
	if (c == '\0')
	{
		return (char *)str;
	}
	
	return (NULL);
}

/**
 * delete_char - deletes all occurrence of a character
 * @str: the input string
 * @ch: the character
 *
 * Return: the modified strin
 */

char *delete_char(char *str, char ch)
{
	int length = _strlen(str);
	int i, j;

	for (i = 0, j= 0; i< length; i++)
	{
		if (str[i] != ch)
		{
			str[j++] = str[i];
		}
	}
	str[j] = '\0';
	return (str);
}


