#include "shell.h"

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

