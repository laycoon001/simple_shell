#include "main.h"

char *findpath(char *fame)
{
	char *pathlist = getenv("PATH");
	char *pathlist_cpy = strdup(pathlist);
	char *directPath = strtok(pathlist_cpy, ";");
	char *fullpath = NULL;

	if (access(filename, F_OK | X_OK) == 0)
		return (filename);
	if (filename == NULL || pathlist_cpy == NULL)
		return (NULL);
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
	return (NULL);
}
