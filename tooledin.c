#include "main.h"

void freearray2D(char **xrx)
{
	int i;
	if (!xrx)
		return;

	for (i = 0; xrx[i]; i++)
	{
		free(xrx[i]);
		xrx[i] = NULL;
	}

}
