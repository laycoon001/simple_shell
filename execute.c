#include "main.h"

/**
 * findPath - finding paths
 * @filename: specific env
 *
 * Return: Null
 */

char *findPath(char *filename)
{
	char *pathlist = getenv("PATH");
	char *pathlist_cpy = _strdup(pathlist);
	char *direcPath = strtok(pathlist_cpy, ":");
	char *fullPath = NULL;
	int length = 0;


	if (access(filename, F_OK | X_OK) == 0)
		return (filename);
	if (filename == NULL || pathlist_cpy == NULL)
		return (NULL);

	while (direcPath != NULL)
	{
		length = _strlen(filename) + _strlen(direcPath) + 2;
		fullPath = _realloc(fullPath, sizeof(fullPath), length);
		snprintf(fullPath, length, "%s/%s", direcPath, filename);

		if (access(fullPath, F_OK | X_OK) == 0)
		{
			free(pathlist_cpy);
			return (fullPath);
		}
		direcPath = strtok(NULL, ":");
	}
	free(pathlist_cpy);
	return (NULL);
}
