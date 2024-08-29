#include "../include/http.h"
 #include "../include/strings.h" 

static enum method	get_method(const char *str) {
	if (!strcmp(str, "GET"))
		return (GET);
	if (!strcmp(str, "POST"))
		return (POST);
	if (!strcmp(str, "PUT"))
		return (PUT);
	return (ERROR);
}

request_t *strto_request(const char *request) {
	request_t *req;
	char **list;

	if (!request)
		return (NULL);
	list = ft_split(request, " \n\r");
	if (!list)
		return (NULL);
	req = (request_t *)malloc(sizeof(request_t));
	if (!req) {
		ft_free(list);
		return (NULL);
	}

	req->method = get_method(list[0]);
	req->route = ft_strdup(list[1]);
	req->version = list[2][5] -48;
	ft_free(list);

	return (req);
}
