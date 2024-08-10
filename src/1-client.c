#include "http.h"

int main(void) {
  int server_socket;
	char buffer[BUFFER_SIZE];
  struct sockaddr_in server_address;
  socklen_t server_len;
	/* struct hostent *server; */
  server_socket = socket(AF_INET, SOCK_STREAM, PROTOCOL);
  server_len = sizeof(server_address);
  if (server_socket == -1)
    _failed("Couldn't create the socket\n");
  bzero((char *)&server_address, server_len);
	/* server = gethostbyname("127.0.0.1"); */
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_address.sin_port = htons(PORT);
	if (connect(server_socket, (struct sockaddr *)&server_address, server_len) == -1)
		_failed("Couldn't connect to the server !\n");

	while (TRUE) {
		read(STDIN_FILENO, buffer,BUFFER_SIZE);
		if (!strcmp(buffer, "close\n"))
			break;
		write(server_socket, buffer, _strlen(buffer));
		bzero(buffer, BUFFER_SIZE);
		read(server_socket, buffer, BUFFER_SIZE);
		_puts("Server:  ");
		_puts(buffer);
	}
	write(server_socket, "close", 5);
	close(server_socket);
	_puts("Closed\n");
}
