#include "main.h"
/**
 * _getpath - Retrieves the full path of a command by searching the directories
 * specified in the "PATH" environment variable.
 *
 * @commy: The command name.
 * Return: The full path of the command if found, or NULL otherwise.
 */
char *_getpath(char *commy)
{
	char *path_env, *cmd, *l;
	int i;
	struct stat st;

	for (i = 0; commy[i]; i++)
	{
		if (commy[i] == '/')
		{
			if (stat(commy, &st) == 0)
				return (_strdup(commy));
			return (NULL);
		}
	}

	path_env = getenv("PATH");
	if (!path_env)
		return (NULL);

	l = strtok(path_env, ":");
	while (l)
	{
		cmd = malloc(_strlen(l) + _strlen(commy) + 2);
		if (cmd)
		{
			_strcpy(cmd, l);
			_strcat(cmd, "/");
			_strcat(cmd, commy);
			if (stat(cmd, &st) == 0)
			{
				free(path_env);
				return (cmd);
			}
			free(cmd), cmd = NULL;

			l = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
