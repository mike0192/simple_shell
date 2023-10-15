#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
pid_t wait(int *wstatus);
pid_t fork(void);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
int execve(const char *pathname, char *const argv[], char *const envp[]);
char *strtok(char *str, const char *delim);
#endif /* MAIN_H */
