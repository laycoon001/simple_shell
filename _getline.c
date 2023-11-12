#include "main.h"
/**
 * _getline - reads a line from standard input
 * @line: pointer to the buffer
 * @size: size of buffer
 * Return: number of characters
 */
ssize_t _getline(char **line, size_t *size)
{
	int c;
	size_t index = 0;
	*size = BUFFER_SIZE;
	char *temp;
	*line = (char *)malloc(*size);

	if (line == NULL || size == NULL)
		return (-1);

	while (read(STDIN_FILENO, &c, 1) == 1 && c != '\n')
	{
		if (index == *size - 1)
		{
			*size *= 2;
			temp = _realloc(*line, read, *size);

			if (temp == NULL)
			{
				free(*line);
				return (-1);
			}

			*line = temp;
		}

		(*line)[index++] = (char)c;

	}
	(*line)[index] = '\0';

	return ((ssize_t)index);
}
