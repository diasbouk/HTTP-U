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

void	ft_failed(char *msg);
void	ft_strcpy(char *dest, const char *src);
char	*ft_strcat(char *dest, const char *src);
void	ft_bzero(void *addr, unsigned int size);
char 	**ft_split(const char *str, char *charest);
char *ft_strdup(const char *str);
char *ft_super_strdup(char *str, char*charset);
int ft_strcmp(const char *s1, const char *s2);
void	ft_puts(const char *str);
unsigned int	ft_strlen(const char *str);
char *ft_strtok(const char *str, char c);
#endif
