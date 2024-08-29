#include "../include/http.h"
#include "../include/strings.h"

int main(void)
{

	struct sockaddr_in address;
	socklen_t size = sizeof(address);
	int sockfd, clienfd;
	request_t *req;
	char *buffer, *response;

	sockfd = init_socket(&address);
	if (sockfd == -1)
	{
		ft_puts("Sokcet messed up!\n");
		return (0);
	}

	while (1)
	{
		clienfd = accept(sockfd, (struct sockaddr *)&address, &size);
		if (clienfd == -1)
			ft_failed("failed to accept !\n");

		buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		ft_bzero(buffer, BUFFER_SIZE);

		if (read(clienfd, buffer, BUFFER_SIZE) < 1)
			ft_failed("Error reading\n");

		buffer = ft_realloc(buffer, ft_strlen(buffer), BUFFER_SIZE);
		req = strto_request(buffer);
		response = create_response(req);
		printf("\n\n --- %s --- \n\n", response);
		write(clienfd, response, ft_strlen(response));
		free(req->route);
		free(req);
		free(buffer);
		free(response);
		close(clienfd);
	}
	close(sockfd);
	return (0);
}
