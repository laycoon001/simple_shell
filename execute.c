#include "main.h"
<<<<<<< HEAD
/**
 * _execute - reads a line from stardard input
 * @pathlist: pointer to the
 * @fullpath: size of the buffer
 * @directpath:
 * retun: the number of characters
 */

char *findpath(char *fame)
{
	char *pathlist = getenv("PATH");
	char *pathlist_cpy = strdup(pathlist);
	char *directPath = strtok(pathlist_cpy, ";");
	char *fullpath = NULL;
=======

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
>>>>>>> f28848d74e9381828f716059f2bd80527622be7b

	if (access(filename, F_OK | X_OK) == 0)
		return (filename);
	if (filename == NULL || pathlist_cpy == NULL)
		return (NULL);
<<<<<<< HEAD
	while (direcpath != NULL)
	{
	length = strlen(filename) + strlen(direcpath) + 2;
	fullppath = realloc(fullpath, length);
	sprintf(fullpath, "%s/%s", direcpath, filename);

	if (access(fullpath, F_OK | X_OK) == 0)
	{
		free (pathlist_cpy);
		return (fullpath);
	}
	directpath = strtok(NULL, ":");
	}
	free (pathlist_cpy);
	free (fullpath);
=======
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
>>>>>>> f28848d74e9381828f716059f2bd80527622be7b
	return (NULL);
}
