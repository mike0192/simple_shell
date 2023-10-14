#include "main.h"

/**
  * main - Main entry point for our program
  * @argc: Argument count to the main
  * @argv: Pointer to array of argument values
  *
  * Return: O Always success
  */

int main(int argc, char *argv[])
{
	(void)argc, (void)argv;
	char *buf = NULL;
	size_t count = 0;
	ssize_t nread;

	while (1)
	{
		write(STDOUT_FILENO, "shelly$ ", 9);

		nread = getline(&buf, &count, stdin);

		if (nread == -1)
		{
			perror("Exiting Shell");
			exit(1);
		}
		printf("%s", buf);
	}
	free(buf);
	return (0);
}
