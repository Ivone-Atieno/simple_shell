#include "shell.h"

/**
* execute - verifies and execute every command
*@commands: command inputted
*@buffer: command in getline
*@environ: enviroment variable
*@argv: argument counter
*@count: execution times
*Return: void
*/

void execute(char **commands, char *buffer, char **environ,
	     char **argv, int count)
{
	struct stat fileStat;

	/*check if command is NULL or empty spaces*/
	if (commands == NULL)
		free_buffer(buffer);
	/*check command to exit from shell*/
	else if (_strcmp("exit", commands[0]))
		_getline(buffer, commands);
	/* check if the command to print environment variables */
	else if (_strcmp("environ", commands[0]))
		free_environ(buffer, commands, environ);
	/*check if the command is a full path**/
	else if (stat(commands[0], &fileStat) == 0)
		execve(commands[0], commands, NULL);
	/*check all $PATH directories for executable commands*/
	else
		find_path(commands, buffer, environ, argv, count);
}
