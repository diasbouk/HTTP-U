#include "../include/http.h"
#include "../include/strings.h"

int main(void) {
	int servfd, clienfd;
	struct sockaddr_in address;
	socklen_t size;
	request_t *req;
	char request[BUFFER_SIZE];
	char *resp;

	servfd = init_socket(&address);
	if (servfd == -1) {
		ft_puts("Failed to create the server socket, try again\n");
		return (0);
	}

	while (TRUE) {
		clienfd = accept(servfd, (struct sockaddr *)&address, &size);
		if (clienfd == -1) {
			ft_puts("Failed to accept connections! Try again\n");
			return (0);
		}
		ft_bzero(request, BUFFER_SIZE);
		if (!read(clienfd, request, BUFFER_SIZE)) {
			ft_puts("Failed to read request\n");
			return (0);
		}
		req = strto_request(request);
		if (!req) {
			printf("Error parsing the request !\n");
			return (0);
		}
		resp = create_response(req);
		free(req);
		if (!resp) {
			printf("Failed to generate response !\n");
			return (0);
		}
		write(clienfd, resp, ft_strlen(resp));
		free(resp);
		resp = NULL;
		close(clienfd);
	}

	close(servfd);
	return (0);
}
