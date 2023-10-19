#include "main.h"
/**
 * is_positive_number - Checks if the given string represents a + number.
 *
 * @str: The string to check.
 * Return: 1 if the string represents a positive number, 0 otherwise.
 **/
int is_positive_number(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
/**
 * _atoi - Converts the given string to an integer value.
 *
 * @str: The string to convert.
 * Return: The integer value of the string.
 */
int _atoi(char *str)
{
	int i, num = 0;

	for (i = 0; str[i]; i++)
	{
		num *= 10;
		num += (str[i] - '0');
	}
	return (num);
}
