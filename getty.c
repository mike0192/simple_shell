#include "main.h"
char *_getenv(char *boom, char **enviq)
{
	char *c, *ff, *ed, *mu;
	int i;

	for (i = 0; enviq[i]; i++)
	{
		c = _strdup(enviq[i]);
		ff = strtok(c, "=");
		if (_strcmp(ff, boom) == 0)
		{
			ed =strtok(NULL, "\n");
			mu = _strdup(ed);
			free(c);
			return (mu);
		}
		free(c), c = NULL;
	}
	return (NULL);
}
