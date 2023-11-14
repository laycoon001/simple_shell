#include "main.h"
<<<<<<< HEAD
pid prompt () {i
	char prompt$[] = "";
	write(STDOUT_FILENO, prompt, sizeof(prompt) -1);
	void execute_command(char *args[] {
			int status = 0;

			if (args[0] == NULL)
			{
				return;
			}
			if (strcmp(args[], "exit") == 0)
			{
				exit(0);
			}
			else if (stcrmp(args[0], "env") == 0)
			{
				char **env = environ;
				while (*env)
				{
					write(STDOUT_FILENO, *env, strlen(*env));
					write(STDOUT_FILENO, "\n", 1);
					env++;
				}
			}
			else
			}
				args[0]	= findpath(args[0]);
				if (args[0] == NULL)
					perror("./shell");
				else
				{
					if (fork() == 0)
					{
						execve(args[0], args, NULL);
						perror("./shell");
						exit (EXIT_FAILURE);
					}
					else
						wait(&status)
				}
			}
		}
=======

/**
 * prompt - display a prompt
 *
 */
void prompt(void)
{
	char prompt[] = "$ ";

	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}

/**
 * execute_command - handles commands
 * @args: argument
 */
void execute_command(char *args[])
{
	int status = 0;

	if (_strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		char **env = environ;

		while (*env)
		{
			write(STDOUT_FILENO, *env, _strlen(*env));
			write(STDOUT_FILENO, "\n", 1);
			env++;
		}
	}
	else if (_strcmp(args[0], "alias") == 0)
	{
		handle_alias(args);
	}
	else
	{
		args[0] = findPath(args[0]);
		if (args[0] == NULL)
			perror("./shell");
		else
		{
			if (fork() == 0)
			{
				execve(args[0], args, environ);
				perror("./shell");
				exit(EXIT_FAILURE);
			}
			else
				wait(&status);
		}
	}
}
>>>>>>> f28848d74e9381828f716059f2bd80527622be7b
