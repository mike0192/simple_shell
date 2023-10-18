#include "main.h"
/**
 * is_builtin - Checks if a command is a built-in command.
 *
 * @command: The command to check.
 * Return: 1 if the command is a built-in command, 0 otherwise.
 */
int is_builtin(char *command)
{
	char *builtin[] = {
		"exit", "env", "setenv", "cd", NULL
	};
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
 * @command: The command and arguments array.
 * @argv: The arguments array.
 * @status: The exit status.
 * @x: Additional parameter (if needed).
 */
void handle_builtin (char **command, char **argv, int *status, int x)
{
	if (_strcmp(command[0], "exit") == 0)
		exit_shell(command, status, argv, x);
	else if (_strcmp(command[0], "env") == 0)
		print_env(command, status, envirom);
}
/**
 * exit_shell - Exits the shell with the specified status.
 *
 * @command: The command and arguments array.
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
		freearray2D(command);
		exit(exit_value);
}
/**
 * print_env - Prints the environment variables.
 *
 * @command: The command and arguments array.
 * @envirom: The array of environment variables.
 * @status: The exit status.
 */
void print_env(char **command, char **envirom, int *status)
{
	int i;
	(void) status;

	for (i = 0; envirom[i]; i++)
	{
		write(STDOUT_FILENO, envirom[i], _strlen(envirom[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freearray2D(command);
	(*status) = 0;
}
