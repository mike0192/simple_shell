#include "main.h"
/**
 * main - Simple Shell main function
 * @ac: Count of arguments
 * @argv: Array of aguments
 * Return: 0 Always (success)
 */
int main(int ac, char **argv)
{
	char *line = NULL, **command = NULL;
	int status = 0, x = 0;
	(void) ac;

	while (1)
	{
		line = custom_getline();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		x++;

		command = tokenizer(line);
		if (!command)
			continue;
		if (is_builtin(command[0]))
			handle_builtin(command, argv, &status, x);
		else

		status = _execute(command, argv, x);
		freearray2D(command);
		free(line);

	}
	return (0);

}
