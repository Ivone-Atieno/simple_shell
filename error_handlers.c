#include "shell.h"

/**
 * _fork - handles fork
 * Return: void
*/

void _fork(void)
{
	perror("Error: ");
	exit(EXIT_FAILURE);
}

/**
* error_message - writes an error message
*@av: argument vector
*@f_cmd: first command to print if not found
*@count: number of times executed
*Return: void
*/

void error_message(char **av, char *f_cmd, int count)
{
	int num_length = 1, cp, mult = 1;

	write(STDERR_FILENO, av[0], _strlen(av[0]));
	write(STDERR_FILENO, ": ", 2);
	cp = count;

	while (cp >= 10)
	{
		cp /= 10;
		mult *= 10;
		num_length++;
	}

	while (num_length > 1)
	{
		if ((count / mult) < 10)
			_puterror((count / mult + '0'));
		else
			_puterror((count / mult) % 10 + '0');
		--num_length;
		mult /= 10;
	}

	_puterror(count % 10 + '0');
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, f_cmd, _strlen(f_cmd));
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
* _puterror - Prints a char
*@c: character to write
*Return: the integer to print
*/

int _puterror(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}

/**
* end_file - function to control the interrupt signal
*@buffer: buffer array created by new line
*Return: void
*/

void end_file(char *buffer)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(0);
}
