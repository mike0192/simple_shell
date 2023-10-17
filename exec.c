#include "main.h"
int _execute(char **command, char **envp)
{
	pid_t son;
	int status;

	son = fork();
	if (son == 0)
	{
		if (son == 0)
		{
			if (execve(command[0], command, envp) == -1)
			{
				perror(envp[0]);
				freearray2D(command);
				exit(0);
			}
		}
		else
		{
			waitpid(son, &status, 0);
			freearray2D(command);
		}
		return(WEXITSTATUS(status));
	}
	return (0);
}
