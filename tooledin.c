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
	free(xrx), xrx = NULL;

}
/**
 * print_error - Prints an error message to the standard error stream.
 *
 * @name: The name or identifier associated with the error.
 * @cd: The error message or description.
 * @x: An integer representing some parameter.
 */
void print_error(char *name, char *cd, int x)
{
	char *idl, mssg[] = ": not found\n";

	idl = _itoa(x);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idl, _strlen(idl));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cd, _strlen(cd));
	write(STDERR_FILENO, mssg, _strlen(mssg));
	free(idl);
}
/**
 * reverse_string - Reverses a string in-place.
 *
 * @str: The string to be reversed.
 * @len: The length of the string.
 */
void reverse_string(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
/**
 * _itoa - Converts an integer to a string representation.
 *
 * @z: The integer to be converted.
 * Return: The string representation of the integer.
 */
char *_itoa(int z)
{
	char buffer[20];
	int i = 0;

	if (z == 0)
	buffer[i++] = '0';
	else
{
	while (z > 0)
	{
		buffer[i++] = (z % 10) + '0';
		z /= 10;
	}
}
buffer[i] = '\0';
reverse_string(buffer, i);
return (_strdup(buffer));
}

