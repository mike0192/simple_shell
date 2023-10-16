#include "main.h"

int main(void)
{
	pid_t pid;
	pid_t ppid;

	pid = fork();

	if (pid == -1)
	{
		perror("Failed\n");
		return (1);
	}
	if(pid == 0)
	{
		sleep(40);
		printf("hey dad\n");
	}
	else
	{
		ppid = getpid();
		printf("hey son: %u\n", ppid);
	}

	return (0);
}
