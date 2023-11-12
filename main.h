#ifndef SHELL_FUNCTIONS_H
#define SHELL_FUNCTIONS_H

#define BUFFER_SIZE 128

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <limits.h>

extern char **env;

void prompt();
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *findPath(char *filename);
void execute_command(char *args[]);
ssize_t _getline(char **line, size_t *size);

#endif
