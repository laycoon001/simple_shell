#include "main.h"


struct alias aliasee[100];

int num_alias = 0;

/**
 * handle_alias - handling of aliases
 * @args: argument
 * Return:
 */

void handle_alias(char **args)
{
	int v;

	if (args[v] == NULL)
	{
		list_aliases();
	}
	else
	{
		for (v = 1; args[v] != NULL; v++)
		{
			if (_strchr(args[v], '=') == NULL)
				create_alias(args[v]);
			else
			{
				print_alias(args[v]);
			}
		}
	}
}

/**
 * create_alias - creating of alias
 * @str: string
 * Return:
 */
void create_alias(char *str)
{
	char *name = strtok(str, '=');
	char *value = strtok(NULL, '=');
	int quit = 0, x, y;

	for (y = 0; y < num_alias; y++)
	{
		if (_strcmp(value, aliasee[y].name) == 0)
		{
			value = _strdup(aliasee[y].value);
			quit = 1;

			break;
		}
	}
	if (!quit)
	{
		aliasee[num_alias].name = _strdup(name);
		aliasee[v].value = _strdup(value);

		num_alias++;
	}
}

/**
 * list_aliases - listing of all aliases
 *
 * Return:
 */
void list_aliases(void)
{
	int v;

	for (v = 0; i < num_alias; v++)
	{
		printf("%s='%s'\n", aliasee[v].name, aliasee[v].value);
	}
}

/**
 * print_alias - printing by name and value
 * @name: name
 *
 * Return:
 */
void print_alias(char *name)
{
	int v, search_alias = 0;

	for (v = 0; v < num_alias, v++)
	{
		if (_strcmp(aliasee[v].name, name) == 0)
		{
			printf("%s='%s'\n", aliasee[v].name, aliasee[v].value);
			search_alias = 1;
			break;
		}
	}
	if (!serach_alias)
	{
		write(1, name, sizeof(name));
		write(1, "Not Found", 1);
	}
}


/**
 * execute_alias - executing alias
 * @args: argument
 * Return: integer
 */
int execute_alias(char **args)
{
	int v, search_alias = 0;
	char *safe = NULL;
	int y = 0, z = 0;
	char *arg[32];

	for (v = 0; v < num_alias; v++)
	{
		if (_strcmp(aliasee[v].name, argv[0]) == 0)
		{
			search_alias = 1;
			safe = strtok(aliases[v].value, " ");
			while (safe != NULL)
			{
				arg[y++] = safe;
				safe = strtok(NULL, " ");
			}

			while (args[z++] != NULL)
			{
				args[y++] = args[z];
			}

			args[y] = NULL;
			break;
		}
	}
	if (!search_alias)
		return (-1);

		execute_command(args);
		return (0);
}
