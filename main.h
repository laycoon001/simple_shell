#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 128

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <limits.h>

struct alias
{
	char *name;
	char *value;
};

extern char **environ;

/********/
int _atoi(char *str);
char *_strdup(const char *str);
size_t _strlen(const char *str);
int _strcmp(const char *str1, const char *str2);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
char *_strchr(const char *str, char c);
char *delete_char(char *str, char ch);
/****/

void prompt(void);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *findPath(char *filename);
void execute_command(char *args[]);
ssize_t _getline(char **line, size_t *size);


/**handle_alias**/
void handle_alias(char **args);
void create_alias(char *str);
void list_aliases(void);
void print_alias(char *name);
int execute_alias(char **args);

#endif
