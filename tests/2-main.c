
#include "../include/http.h"
#include "../include/strings.h"

int main(void) {
  int servfd, clienfd;
  struct sockaddr_in address;
  socklen_t size;

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
    char request[BUFFER_SIZE];
    ft_bzero(request, BUFFER_SIZE);
    if (!read(clienfd, request, BUFFER_SIZE)) {
      ft_puts("Failed to read request\n");
      return (0);
    }
    char **res_list = ft_split(request, " ");
    char *response = create_response(res_list[1]);
    write(clienfd, response, ft_strlen(response));
    close(clienfd);
  }
  close(servfd);
  return (0);
}
