#ifndef HTTP_H
#define HTTP_H
#include <arpa/inet.h>
#include <fcntl.h>
#include <limits.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

#define BACK_LOG 4
#define PROTOCOL 0
#define BUFFER_SIZE 1024
#define TRUE 1
#define FALSE 0
#define PORT 8089
#define SEG 0
#define HEADER_404 "HTTP/1.1 404 NOT FOUND\r\n"
#define HEADER_200 "HTTP/1.1 200 OK\r\n"
#define TYPE_HTML "Content-Type: text/html\r\n\r\n"
#define TYPE_TEXT "Content-Type: text/html\r\n\r\n"


enum method { GET, POST, PUT, ERROR };

/** request_t - Request structure sent by client
 * @methode: Methode used by client
 * @file_name: File requested by the client
 */

typedef struct request_t {
	enum method method;
	char *route;
	int version;
} request_t;

/**
 * response_t - struct for HTTP response from the server
 * @status_code: Code returned from server to request
 * @content_length: length of HTML file returned to client
 * @body: Content of HTML file
 */
typedef struct response_t {
	int status_code;
	unsigned int content_length;
	char body[BUFFER_SIZE];
} response_t;

/* Prints erorrs and exits with EXIT_FAILURE */
void fetch_request(char *buff);
void handle_signal(int seg);
void	*ft_realloc(void *old,unsigned int old_size, unsigned int new_size);
void	d_free(char **arr);
request_t *strto_request(const char *request);
int init_socket(struct sockaddr_in *address);
char	*get_fname(char *route);
int file_write(char *fname, const char *str);
char *create_response(request_t *req);
char *file_read(const char *fname);
void	ft_free(char **arr);


#endif
