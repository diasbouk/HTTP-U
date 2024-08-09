#include "../header/strings.h"

/**
 * _puts -  Prints a string to stdout
 * @str: string to write
 */

void _puts(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

/**
 * _strlen -  Counts lenght of a string
 * @str: string to get length
 * Return: length of the string (INT)
 */
unsigned int _strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * _failed - Prints the error mesg to stdout
 * and quits with an exit failure value
 * @mgs: Msg to write out
 */
void _failed(char *msg)
{
	write(1, msg, _strlen(msg));
	exit(EXIT_FAILURE);
}

/**
 * _strcmp -  compares  two strings
 * @s1: string 1
 * @s2g: string 1
 * Return: 0 if they equal or a int
 */

int _strcmp(const char *s1, const char *s2)
{
	int index;

	index = 0;
	while (s1[index] || s2[index])
	{
		if (s1[index] != s2[index])
			return (s1[index] - s2[index]);
		index++;
	}
	return (s1[index] - s2[index]);
}

/**
 * _strtok - Tokenize till a char
 * @str: string to check
 * @c: char to find
 * Return: new token or (void *)0
 */

char *_strtok(const char *str, char c)
{
	int index;
	char *token = malloc(sizeof(char) * strlen(str));

	if (!token)
		return (NULL);
	index = 0;
	while (str[index])
	{
		token[index] = str[index];
		if (str[index] == c)
		{
			token[index] = 0;
			return (token);
		}
		index++;
	}
	return (token);
}
