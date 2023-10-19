#include "main.h"
/**
 * is_builtin - Checks if a command is a built-in command.
 *
 * @command: The command to check.
 * Return: 1 if the command is a built-in command, 0 otherwise.
 */
int is_builtin(char *command)
{
	char *builtin[] = {"exit", "env", "setenv", "cd", NULL};
	int i;

	for (i = 0; builtin[i]; i++)
	{
		if (_strcmp(command, builtin[i]) == 0)
			return (1);
	}
	return (0);
}
/**
 * handle_builtin - Handles built-in commands in the shell.
 *
 * @command: An array of strings representing the command and its arguments.
 * @argv: An array of strings representing the environment variables.
 * It is passed to provide access to the environment variables if needed.
 * @status: The exit status.
 * @x: An integer representing an additional parameter.
 * Its purpose and usage depend on the specific implementation.
 */

void handle_builtin(char **command, char **argv, int *status, int x)
{
	if (_strcmp(command[0], "exit") == 0)
		exit_shell(command, status, argv, x);
	else if (_strcmp(command[0], "env") == 0)
		print_env(command, status);
}
/**
 * exit_shell - Exits the shell with the specified status.
 *
 * @command: The command and arguments array.
 * @argv: The array of command-line arguments passed to the program.
 * @x: The line number or counter identifier.
 * @status: The exit status.
 */
void exit_shell(char **command, int *status, char **argv, int x)
{
int exit_value = (*status);
char *index, mssg[] = ": exit: Illegal number: ";

if (command[1])
{
if (is_positive_number(command[1]))
{
exit_value = atoi(command[1]);
}
else
{
index = _itoa(x);
write(STDERR_FILENO, argv[0], _strlen(argv[0]));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, index, _strlen(index));
write(STDERR_FILENO, command[1], _strlen(command[1]));
write(STDERR_FILENO, mssg, _strlen(mssg));
write(STDERR_FILENO, "\n", 1);
free(index);
freearray2D(command);
(*status) = 2;
return;
}
}
freearray2D(command);
exit(exit_value);
}

/**
 * print_env - Prints the environment variables.
 *
 * @command: The command and arguments array.
 * @status: The exit status.
 */

void print_env(char **command, int *status)
{
int i;

for (i = 0; environ[i]; i++)
{
write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
write(STDOUT_FILENO, "\n", 1);
}
freearray2D(command);
(*status) = 0;
}
