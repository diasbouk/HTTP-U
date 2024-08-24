/*
 * This is the test file to check Requests format
 * This will help get to know to requests better
 * and generate ana appropriate response
 */

#include "../include/http.h"
#include "../include/strings.h"
#include <sys/socket.h>

int main(void) {
  int sockfd;
  int client_fd, i = 0;
  struct sockaddr_in address;
  char buffer[1014];
  char c;
  int file;
  socklen_t size = sizeof(address);
  sockfd = init_socket(&address);
  if (sockfd == -1) {
    perror("Didnt workout\n");
    return (0);
  }
  while (1) {
    client_fd = accept(sockfd, (struct sockaddr *)&address, &size);
    if (client_fd == -1) {
      perror("failed to connect\n");
      return (0);
    }
    ft_bzero(buffer, 1014);
    read(client_fd, buffer, 1014);
    file = open("request.txt", O_RDWR | O_CREAT | O_APPEND);
    write(file, buffer, strlen(buffer));
    write(client_fd, "Done!", 5);
    close(client_fd);
  }
    close(sockfd);
  return (0);
}
