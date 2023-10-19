#include "main.h"
/**
 * custom_getline - Reads a line from the standard input.
 *
 * Return: A pointer to the line read from the input, or NULL on failure or EOF.
 */
char *custom_getline(void)
{
static char buffer[BUFFER_SIZE];
static int buffer_index = 0;
static int num_chars = 0;

char *line = NULL;
int line_index = 0;
int c;

while (1)
{
if (buffer_index >= num_chars)
{
num_chars = read(STDIN_FILENO, buffer, BUFFER_SIZE);
buffer_index = 0;

if (num_chars <= 0)
{

break;
}
}

c = buffer[buffer_index++];

if (c == '\n' || c == '\r') 
{
if (line_index == 0)
{
continue;
}
break;
}
line = realloc(line, (line_index + 1) * sizeof(char));
line[line_index++] = c;
}

if (line_index > 0)
{

line = realloc(line, (line_index + 1) * sizeof(char));
line[line_index] = '\0';
}

return line;
}
