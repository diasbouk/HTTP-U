#include "../include/http.h"
#include "../include/strings.h"
int	file_write(char *fname, const char *str) {
	int	file;

	if (!fname || !str)
		return (-1);
	file = open(fname, O_RDWR | O_APPEND | O_CREAT);
	if (file == -1)
		return (-1);
	write(file, str, ft_strlen(str));
	close(file);
	return (0);
}

char	*file_read(const char *fname) {

	char	*buff;
	char	c;
	int		i;
	int		file;

	if (!fname)
		return (NULL);
	i = 0;
	file = open(fname, O_RDONLY);
	if (file == -1)
		return (NULL);
	while (read(file, &c, 1))
			i++;
	close(file);
	file = open(fname, O_RDONLY);
	if (file == -1)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (i + 1));
	if (!buff)
		return (NULL);
	i = 0;
	while (read( file, &c, 1)) {
		buff[i++] = c;
	}
	buff[i] = '\0';
	return (buff);
}
