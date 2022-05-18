#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MAXARGS 10
#define DELIM " \t\n\r\a"
#define EXEC 1

extern char **environ;

typedef struct cmd_t
{
	int mode;
	int ready;
	char **args;
} cmd_t;

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void open_console(void);
void runcmd(char* dir, char **input, cmd_t *cmd);
void init_cmd(cmd_t *cmd);
void prompt(int status);
void t_error(char *s);
int _fork(void);
char **get_toks(char *args, char *delimiter);
void setcmd(char *buf, cmd_t *cmd);

/* builtins */
typedef struct builtins
{
	char *name;
	int (*f)(void);
} built_t;

int parse_builtins(char **input);

#endif /* SHELL_H */
