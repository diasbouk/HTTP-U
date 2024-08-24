#include "../include/http.h"
#include "../include/strings.h"

char *create_response(char *route) {
	char *response, *status, *content, *header, fname[30] = {0};
	int size;

	if (!strcmp(route, "/"))
		strcpy(fname, "data/index.html");
	else {
		strcpy(fname, "data");
		strcat(fname, route);
	}
	content = file_read(fname);
	if (!content) {
		status = "404";
		content = "Not found !! :(";
	}
	header = "HTTP/1.1 200 OK\r\n";
	status = "Content-Type: text/html\r\n\r\n";
	size = ft_strlen(header) + ft_strlen(status) + ft_strlen(content);
	response = malloc(sizeof(char) * (size + 1));
	if (!response)
		return (NULL);
	ft_bzero(response, size);
	strcpy(response, header);
	strcat(response, status);
	strcat(response, content);
	return (response);
}
