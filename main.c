#include "shell_function.h"

<<<<<<< HEAD
#define MAX_ARGS 10

int main() {
	char *command = NULL;
	char *args[MAX_ARGS];
	ssize_t red;
	size_t len;
	char *token;
	int i;

	while (1) 
{
		prompt();
		read = getline(&command, &len, stdin);
		if (read == -1)
		{
		break;
		}
		if (read > 0 && command[read -1] == '\n') {
			command[read -1] = '\0';
		}
		i = 0;
		token = strtok(command, " ");
		while (token != NULL) {
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] NULL;
		execute_command(args);

		free(command);
		return 0;
}
=======
/**
 * main - file entry point description
 * @ac: argument count
 * @av: argument vector
 * Return: 1 on errno, 0 on success
 */
int main()
{
>>>>>>> 8649151867274507879a4ac14ea3ad282bcaa4e4
