#include "../include/strings.h"
#include "../include/http.h"


request_t *strto_req(char *str) {
	if (!str)
		return (NULL);
	char **list = ft_split(str, "\n\v :");
	request_t *req = (request_t *)malloc(sizeof(request_t));
	if (!req)
		return (NULL);
	if (!list) {
		printf("Couldn't split !\n"); 
		return (NULL);
	}
	req->methode = ft_strdup(list[0]);
	req->file_name =ft_strdup(list[1]);
	return (req);
}

int main(void) {
	int i = 0;
	char *str = file_read("./request.txt");
	if (!str) {
		printf("Can't read\n");
		return(0);
	}
	request_t *req =  strto_req(str);
	printf("%s -- %s\n", req->methode, req->file_name);
	printf("%s\n", str);
	free(str);
	return (0);
}
