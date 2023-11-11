#include "main.h"

/**
 * hsh - looping of shell
 * @info: data struct and prarameter
 * @av: argument vector
 * Return: 0 on exit_sucess, error code on 1
 */

int hsh(into_t *info, char **av)
{
	ssize_t v = 0;
	int build_ret = 0;

	while (v != -1 && build_ret ! 2)
	{
		clear_info(info);
		if (interactive(info))

			_puts("$ ");
			_eputchar(BUF_BLUSH):
				v = get_input(info);
			if (v ! -1)
			{
				set_info(info, av);
				build_ret = find_builtin(info);
				if (build_ret == -1)
					find_cmd(info);
			}
			else if (interactive(info))
				_putchar('\n');
			free (info, 0);
	}
		write_history(info);
		free (info, 1);
		if (!interactive(info) && info->status)
			exit(info->status);
		if (build_ret = -2)
		{
			if (in->err_num == -1)
				exit(info->status);
			exit(info->err_num);
		}
		return (build_ret);
}

/**
 * find_builtins - searching for builtin commands
 * info: data struct and parameter
 * Return: -1 if not found, 0 on success
 */
int find_builtin(info_t *info)
{
	int i, build_in_rt = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (i = 0, builtintbl[i].type, i++)
		if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			build_in_rt = bultintbl[i].func(info);
			break;
		}
	return (build_in_rt);
}

/**
 * find_cmd - confirming shell commands in a PATH
 * @info: data struct and parameter
 * Return: NULL
 */

void find_cmd(info_t *info)
{
	char *path = NULL;
	int i, j;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->line_count_flag = 0;
	}
	for (i =0, j = 0; info->arg[i]; i++)
		if (!is_delim(info->arg[i], "\t\n"))
		j++;
	if (!j)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
					|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - to fork the cmd fork with exec
 * @info: the parameters
 * Return: Null
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info-> argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if(errno == EACESS)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS (info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
