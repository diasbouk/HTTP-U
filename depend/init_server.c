#include "../include/http.h"
#include "../include/strings.h"

int init_socket(struct sockaddr_in *address) {
  int socket_fd;
  socklen_t address_len;

  socket_fd = socket(AF_INET, SOCK_STREAM, PROTOCOL);
  address_len = (socklen_t)sizeof(*address);
  if (socket_fd == -1)
    return (-1);

  /* Earasing the memory area for our adress struct */
  ft_bzero((char *)address, address_len);
  address->sin_family = AF_INET;
  address->sin_addr.s_addr = INADDR_ANY;
  address->sin_port = htons(PORT);

  /* Bind the socket to a port and an adress */
  if (bind(socket_fd, (struct sockaddr *)address, address_len))
    return (-1);

  /* Listen on the defined port ana wait for any
  connections from the client */
  if (listen(socket_fd, BACK_LOG))
    return (-1);
  return (socket_fd);
}
