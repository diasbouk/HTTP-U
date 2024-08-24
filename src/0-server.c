#include "../include/http.h"
#include "../include/strings.h"

int main(void) {

	/* Create the socket file descriptor here --> */
	int socket_fd;
	int client_socket;
	socklen_t size;
	struct sockaddr_in address;
	char response[BUFFER_SIZE];
	char request[BUFFER_SIZE];

	/* Initializing the socket file descriptor */
	socket_fd = init_socket(&address);
	if (socket_fd == -1)
		ft_failed("Failed to initialize the socket\n");
	while (1) {
		client_socket = accept(socket_fd, (struct sockaddr *)&address, &size);
		if (client_socket == -1) {
			ft_puts("Failed to accept connections! Try again\n");
			return (0);
		}
		char request[BUFFER_SIZE];
		ft_bzero(request, BUFFER_SIZE);
		if (!read(client_socket, request, BUFFER_SIZE)) {
			ft_puts("Failed to read request\n");
			return (0);
		}
		char **res_list = ft_split(request, " ");
		char *response = create_response(res_list[1]);
		write(client_socket, response, ft_strlen(response));
		close(client_socket);
	}
	close(socket_fd);
	return (0);
}
