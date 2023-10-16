#include "main.h"
/**
 * main - Simple Shell main function
 * @ac: Count of arguments
 * @av: Arguments
 * Return: 0 Always (success)
 */
int main(int ac, char **argv)
{
	char *line = NULL;
	/*char **command = NULL;*/
	int status = 0;
	(void) ac;
	(void) argv;

	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
			write(STDOUT_FIILENO, "\n", 1);
			return (status);
		}

		command = tokenizer(line);

		/*status = _execute(command, argv)*/

	}

}
