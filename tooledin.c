#include "main.h"

/**
 * freearray2D - Frees the memory allocated for a 2D array of strings.
 * @xrx: The array to be freed.
 *
 * This function frees the memory allocated for each string in the array and
 * sets the corresponding pointers to NULL. The array itself is not freed.
 */
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
