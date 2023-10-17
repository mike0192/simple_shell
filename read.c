#include "main.h"

/**
 * read_line - Reads a line of input from the user.
 *
 * Return: A pointer to the dynamically allocated string containing the line.
 * Returns NULL if there was an error or if the end of input is reached.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "Shelly$ ", 8);

	n = getline(&line, &len, stdin);
	if (n == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);

}
