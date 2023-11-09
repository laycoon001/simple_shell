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

  

