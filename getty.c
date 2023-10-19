#include "main.h"
/**
 * _getenv - Retrieves the value of an environment variable.
 *
 * @boom: The name of the environment variable.
 * Return: The value of the environment variable if found, or NULL otherwise.
 */
char *_getenv(char *boom)
{
	char *c, *ff, *ed, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		c = _strdup(environ[i]);
		ff = strtok(c, "=");
		if (_strcmp(ff, boom) == 0)
		{
			ed = strtok(NULL, "\n");
			env = _strdup(ed);
			free(c);
			return (env);
		}
		free(c), c = NULL;
	}
	return (NULL);
}
