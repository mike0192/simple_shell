#include "main.h"
char *_getpath(char *commy)
{
	char *pathy, *cmd, *l;
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

	pathy = getenv("PATH");
	if (!pathy)
		return (NULL);

	l = strtok(pathy, ":");
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
				free(pathy);
				return (cmd);
			}
			free(cmd), cmd = NULL;

			l = strtok(NULL, ":");
		}
	}
	free(pathy);
	return (NULL);
}
