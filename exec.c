#include "main.h"
/**
 * _execute - Executes a command by forking a child process and using execve.
 * @command: An array of strings representing the command and its arguments.
 * @envp: An array of strings representing the environment variables.
 *
 * Return: The exit status of the child process.
 */
int _execute(char **command, char **envp)
{
	pid_t son;
	int status;

	son = fork();
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
		return (WEXITSTATUS(status));
	
}
