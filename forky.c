#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;

	printf("before forky i was one\n");

	fork();

	if (pid == -1)
	{
		perror("Failed\n);
		return (1);
	}

	printf("after forky i become two\n");

	return (0);
