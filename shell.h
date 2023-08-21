#ifndef SHELL_H
#define SHELL_H

/*libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/*main.c*/
void int_handler(int sign);
void print_dollar(void);

/*command.c*/
unsigned int count_command(char *s);
char **array_strtok(char *str);

/*execute.c*/
void execute(char **commands, char *buffer, char **env,
		char **argv, int count);

/*strings.c*/
char *_strncpy(char *dest, char *src, int n);
char *_strncpyconst(char *dest, const char *src, int n);
unsigned int _strlenconst(const char *str);
unsigned int _strlen(char *str);
int _strcmp(char *s1, char *s2);

/*environ.c*/
unsigned int count_dir(char *path);
char **store_var(char *f_cmd, char **env);
char *_getenv(const char *name, char **env);
char *_strncpcommand(char *dest, char *src, char *command, int n, int c);
void print_environ(char **env);

/*frees.c*/
void free_all(char **ptr);
void free_commands(char *buffer, char **commands);
void free_else(char *buffer, char **commands);

/*error_messages.c*/
void error_message(char **av, char *f_cmd, int count);
int _puterror(char c);
void end_file(char *buffer);
void _fork(void);

/*getline.c*/
void free_buffer(char *buffer);
void _getline(char *buffer, char **commands);
void free_environ(char *buffer, char **commands, char **env);
/**find_path.c**/
void find_path(char **commands, char *buffer, char **env,
	       char **argv, int count);

#endif
