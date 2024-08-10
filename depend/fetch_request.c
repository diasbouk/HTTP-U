#include "../header/http.h"
#include "../header/strings.h"

int	check_methode(const char *str) {
	if (!_strcmp(str, "GET"))
		return (1);
	if (!_strcmp(str, "POST"))
		return (2);
	if (!_strcmp(str, "PUT"))
		return (3);
	return (0);
}

/**
	* fetch_request -  Checks type of methdoe in the request
	* @buffer: Whole request buffer
*/

void	fetch_request(char *buffer) {
	char *methode = _strtok(buffer, ' ');
	int	met_numb = check_methode(methode);
	if (!met_numb)
		_puts("Invalide methode!!\n");
	if(met_numb == 1)
		_puts("GET REQUEST RECIEVED\n");
	if(met_numb == 2)
		_puts("POST REQUEST RECIEVED\n");
	if(met_numb == 3)
		_puts("PUT REQUEST RECIEVED\n");
}


