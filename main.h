#ifndef _MAIN_H_
#define _MAIN_H

#include <stdio.h>
#include <stdlib>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read & write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define Buf_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STROK 0

#define HIST_fILE	"simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * stuct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typdef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/** 
 * struct passinfo - contain pseudo-argument to pass into a function
 * allowing uniform prototype for function pointer struct
 * @arg: a string generated from getline containing arguments function
 * @argv: a string path for command
 * @path: a string path for the current command
 * @argc: the argument count
 * @line_count: the error count
 * @err_num the code for exit()s
 * @linecount_flag: if on count the line of input
 * @fname: the program file name
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL env
 * @history: the history node
 * @alias: the alias node
 * @env_changed on if environ was changed
 * @status: the return status of the last exec'd command function
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @cmd_buf: address of a pointer to cmd_buf, on if chaining
 * @reeadfd: the fd from which to read line input
 * @histcount: the history of number counts
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	list_t *env;
	char *fname;
	list_t *history;
	list_t *alias;
	char **environ
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int hiscount;
} info_t;

#define INFO_INT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL \
	0, 0, 0}

/**
 * struct buitin - contains a buitin string and related function
 * @type: the builtin command flag
 * @func: the function command
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/** toem_shloop.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* toem_parser.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int int);
char *find_path(info_t *, char *, char *);

/* toem_errors.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* loophsh.c */
int loophsh(char **);

/* toem_string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* toem_string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* toem_exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* toem_memory.c */
int bfree(void **);

/* toem_tokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* toem_realloc.c */
char *_memset(char *, char unsigned int);
void ffree(char **);
void *realloc(void *, unsigned int, unsigned int);

/* toem_atoi.c */
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* toem_buitin.c */
int _myexit(info_t *)
int _mycd(info_t *)
int _myhelp(info_t *);

/* toem_builtin1.c */
int _myhistory(info_t *);
int _myalias(info_t *);

/* toem_errors1.c */
int _erratoi(char *);
void print_error(info_t *, char *);
char *convert_number(long int, int, int);
void remove_comment(char *);
int print_d(int, int);

/*toem_getline.c */
ssize_t get_input(info_t *);
int _getline(info_t, char **, size_t *);
void sigintHandler(int);

/* toem_getinfo.c */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* toem_environ.c */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* toem_getenv.c */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *, char *);

/* toem_history.c */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int build_history_list(info_t *info);
int build_history_list

