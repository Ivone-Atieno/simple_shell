#include "shell.h"
/**
*find_path -checks and execute the command inputted
*@commands: array of commands
*@buffer: buffer from getline
*@environ: enviroment variables
*@argv: argument vector
*@count: number of times runned the prompt
*/

void find_path(char **commands, char *buffer, char **environ,
	       char **argv, int count)
{
	struct stat fileStat2;
	int i = 0;
	char **directories;

	directories = store_var(commands[0], environ);
	while (directories[i])
	{
		if (stat(directories[i], &fileStat2) == 0)
			execve(directories[i], commands, NULL);
		i++;
	}

	/*if command not found print error*/
	error_message(argv, commands[0], count);

	free(buffer);
	free_all(commands);
	free_all(directories);
	exit(EXIT_SUCCESS);
}
