#include "shell_function.h"

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
