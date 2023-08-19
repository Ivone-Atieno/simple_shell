#include "shell.h"
/**
 * free_all - frees all the memory
 * @ptr: pointer to free
 * Return: void
*/

void free_all(char **ptr)
{
	unsigned int i = 0;

	if (ptr == NULL)
		return;

	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}

	if (ptr[i] == NULL)
		free(ptr[i]);
	free(ptr);
}

/**
 * free_commands - frees commands and buffers
 * @buffer: buffer in getline
 * @commands: commands inputted
 * Return: void
*/

void free_commands(char *buffer, char **commands)
{
	free(buffer);
	free_all(commands);
}

/**
* free_else - Fress anything else
*@buffer: buffer created by getline
*@commands: array of commands
*Return: void
*/

void free_else(char *buffer, char **commands)
{
	if (commands == NULL)
		free_commands(buffer, commands);
	/*on exit status*/
	else if (_strcmp("exit", commands[0]))
		_getline(buffer, commands);
	else
		free_commands(buffer, commands);
}
