#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define DELIM " \t\n"
extern char **envirom;
char *read_line(void);
char **tokenizer(char *line);
void freearray2D(char **xrx);
char *_getenv(char *boom, char **enviq);
char *_getpath(char *commy);
void print_error(char *name, char *cd, int x);

int is_builtin(char *command);
void handle_builtin(char **command, char **argv, int *status, int x);
void exit_shell(char **command, int *status, char **argv, int x);
void print_env(char **command, int *status);

char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _execute(char **command, char **argv, int x);
char *_itoa(int z);
void reverse_string(char *str, int len);
int _atoi(char *str);
int is_positive_number(char *str);
#endif /* MAIN_H */
