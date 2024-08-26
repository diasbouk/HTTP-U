#include "../include/http.h"

/**
	 * is_delim - Checks if a character is included in a charset
	 * @c: char to check
	 * @charset: set of delimiters
	 * @Return: 1 if it's included, 0 otherwise
*/

int is_delim(char c, char *charset) {
	int	i;

	i = 0;
	while (charset[i]) {
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_super_strlen(const char *str, char *charset) {
	int i;

	i = 0;
	while (!is_delim(str[i], charset))
		i++;
	return (i);
}

char *ft_super_strdup(const char *str, char*charset) {
	int	i;
	char *dup;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (ft_super_strlen(str, charset) + 1));
	if (!dup)
		return (NULL);
	while (!is_delim(str[i], charset)) {
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
    
/**
	 * ft_split - to split command argumnets
	 * @command: command enterde by user
	 * Return: An array of strings containing args .
*/

char **ft_split(const char *str, char *charset) {
	int i;
	int count;
	char **tab;

	i = 0;
	count = 0;
	if (!str)
		return (NULL);
	while (str[i]) {
		if (!is_delim(str[i], charset)) {
			count++;
			while (!is_delim(str[i], charset))
				i++;
		}
		i++;
	}
	tab = (char **)malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	i = 0;
	count = 0;
	while (str[i]) {
		while (is_delim(str[i], charset))
			i++;
		if (!is_delim(str[i], charset)) {
			tab[count++] = ft_super_strdup(str + i, charset);
			while (!is_delim(str[i], charset))
				i++;
		}
		i++;
	}
	tab[count] = NULL;
	return (tab);
}
