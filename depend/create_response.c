#include "../include/http.h"
#include "../include/strings.h"


char	*get_fname(char *route) {
	char *fname;
	char	*data = "data";
	int size;
	if (!route)
		return (NULL);
	if (route[0] == '/' && !route[1]) {
		fname = (char *)malloc(sizeof(char) * 16);
		ft_bzero(fname, 16);
		ft_strcpy(fname, "data/index.html");
		fname[15] = '\0';
		return (fname);
	}

	size = ft_strlen(route) + ft_strlen(data) + 1;
	fname = (char *)malloc(sizeof(char) * size);
	if (!fname)
		return (NULL);
	ft_bzero(fname, size);
	ft_strcpy(fname, data);
	ft_strcat(fname, route);
	fname[size - 1] = '\0';

	return (fname);
}

char *create_response(request_t *req) {
	char *response, *content_type, *content, *header, *fname;
	int size;

	fname = get_fname(req->route);
	content = file_read(fname);
	free(fname);
	if (!content) {
		header = HEADER_404;
		content_type =TYPE_TEXT;
		content = file_read("data/not-found.html");
	}
	else {
		header = HEADER_200;
	content_type =TYPE_HTML;
	}
	size = ft_strlen(header) + ft_strlen(content_type) + ft_strlen(content);
	response = malloc(sizeof(char) * (size + 1));
	if (!response)
		return (NULL);
	ft_bzero(response, size);
	strcpy(response, header);
	strcat(response, content_type);
	strcat(response, content);
	free(content);
	return (response);
}
