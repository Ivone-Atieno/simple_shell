#include "shell.h"

/**
* free_buffer - Free the buffer created
*@buffer: buffer from getline
*Return: void
*/

void free_buffer(char *buffer)
{
	free(buffer);
	exit(EXIT_SUCCESS);
}

/**
* _getline - Free the buffer and commands from getline
*@buffer: buffer from getline
*@commands: command inputted
*Return: void
*/

void _getline(char *buffer, char **commands)
{
	free(buffer);
	free_all(commands);
	exit(EXIT_SUCCESS);
}

/**
* free_environ - frees the buffer and commands created in getline
*@buffer: buffer from getline
*@commands: array store commands
*@environ: enviroment variables
*Return: void
*/

void free_environ(char *buffer, char **commands, char **environ)
{
	free(buffer);
	free_all(commands);
	print_environ(environ);
	exit(EXIT_SUCCESS);
}
