#include "main.h"
/**
 * _execute - Executes a command by forking a child process and using execve.
 * @command: An array of strings representing the command and its arguments.
 * @envp: An array of strings representing the environment variables.
 * @x: An integer representing some parameter.
 * Return: The exit status of the child process.
 */
int _execute(char **command, char **envp, int x)
{
	char *cmd;
	pid_t son;
	int status;

	cmd = _getpath(command[0]);
	if (!cmd)
	{
		print_error(envp[0], command[0], x);
		freearray2D(command);
		return (127);
	}

	son = fork();
	if (son == 0)
	{
		if (execve(cmd, command, envp) == -1)
		{
			free(cmd), cmd = NULL;
			freearray2D(command);
		}
	}
		else
		{
			waitpid(son, &status, 0);
			freearray2D(command);
			free(cmd), cmd = NULL;
		}
		return (WEXITSTATUS(status));
}
