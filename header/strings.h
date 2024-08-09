#ifndef STRINGS_H
#define STRINGS_H

/* Inlcude header f any needed */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define TRUE 1
#define FALSE 0

void	_failed(char *msg);
int _strcmp(const char *s1, const char *s2);
void	_puts(const char *str);
unsigned int	_strlen(const char *str);
char	*_strtok(const char *str, char c);
#endif
