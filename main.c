#include "shell.h"
/**
* main - main function
*@argc: argument count
*@argv: argument vector
*@env: enviroment variables
*Return: 0 on success else 1
*/

int main(int argc, char **argv, char **env)
{
char *buffer, **commands;
int status, count;
pid_t pid;
size_t len;
ssize_t chars;
(void)argc;
buffer = NULL, len = 0, count = 0;
/*write promt only if it's from standard input*/
print_dollar();
/*infinite loop*/
while ((chars = getline(&buffer, &len, stdin)))
{
signal(SIGINT, int_handler);
/*check the end of file*/
if (chars == EOF)
end_file(buffer);
count++;
/*collect commands from the prompt and store in double pointer*/
commands = array_strtok(buffer);
/*create new process*/
pid = fork();
if (pid == -1)
_fork();
if (pid == 0)
execute(commands, buffer, env, argv, count);
/*free all*/
else
{
wait(&status);
free_else(buffer, commands);
}
len = 0, buffer = NULL; /*reset for getline*/
print_dollar();
}
if (chars == -1)
return (EXIT_FAILURE);
return (EXIT_SUCCESS);
}
/**
* int_handler - handles signals
*@sign: signal to handle
*Return: Nothing (void)
*/

void int_handler(int sign)
{
(void)sign;
write(STDOUT_FILENO, "\n$ ", 3);
}

/**
* print_dollar - Function to print the dollar sign
*Return: void
*/

void print_dollar(void)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", 2);
}
