#include "./http.h"

int main(void) {

  /* Create the socket file descriptor here --> */
  int socket_fd;
  int client_socket;
  socklen_t address_len;
  struct sockaddr_in address;
  char buffer[BUFFER_SIZE];

  socket_fd = socket(AF_INET, SOCK_STREAM, PROTOCOL);
  address_len = (socklen_t)sizeof(address);
  if (socket_fd == -1)
    _failed("Socket couldn't be created \n");

  /* Earasing the memory area for our adress struct */
  bzero((char *)&address, address_len);
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  /* Bind the socket to a port and an adress */
  if (bind(socket_fd, (struct sockaddr *)&address, address_len))
    _failed("Couldn't bind the socket\n");

  /* Listen on the defined port ana wait for any
  connections from the client */
  if (listen(socket_fd, BACK_LOG))
    _failed("Can't listen on socket_fd\n");

  /* Accept connections if any */
  client_socket = accept(socket_fd, (struct sockaddr *)&address, &address_len);
  if (client_socket == -1)
    _failed(
        "Couldn't recieve any connection, failed to get the client fd !!\n");

  /* Read from and write to the clien */
  while (TRUE) {
    /* Taking request from client */
    bzero(buffer, BUFFER_SIZE);
    read(client_socket, buffer, BUFFER_SIZE);
    if (strcmp(buffer, "close") == 0)
      break;
		/* Handle request buffer to generate a response */
	fetch_request(buffer);
    _puts("Client: ");
    _puts(buffer);

    /* Responding with an answer */
    bzero(buffer, BUFFER_SIZE);
    if (read(STDIN_FILENO, buffer, BUFFER_SIZE) == -1)
      _failed("Couldn't read from stdin !!'\n");
    write(client_socket, buffer, _strlen(buffer));
  }
  _puts("Closed!\n");
  close(socket_fd);
  close(client_socket);
  return (0);
}
