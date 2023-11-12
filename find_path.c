pid prompt () {i
	char prompt$[] = "";
	write(STDOUT_FILENO, prompt, sizeof(prompt) -1);
	void execute_command(char *args[] {
			int status = 0;
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
