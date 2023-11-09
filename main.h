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




