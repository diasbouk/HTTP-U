#include "../include/http.h"
#include "../include/strings.h"

void	ft_free(char **arr) {
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i]) {
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	*ft_memcpy(void *dest, void *src, unsigned int size)
{
        unsigned long   i;
        unsigned char   *dst;
        unsigned char   *sc;

        if (!src || !dest)
                return (0);
        i = 0;
        dst = (unsigned char *)dest;
        sc = (unsigned char *)src;
        while (i < size)
        {
                dst[i] = sc[i];
                i++;
        }
        return (dest);
}

unsigned int	ft_min(unsigned int a, unsigned int b) {
	if (a < b)
		return (a);
	return (b);
}

void	*ft_realloc(void *old,unsigned int old_size, unsigned int new_size) {

	void	*new;

	if (!old)
		return (NULL);
	if (new_size == 0) {
		free(old);
		return (NULL);
	}
	new = malloc(new_size);
	if (!new)
		return (NULL);
	ft_bzero(new, new_size);
	ft_memcpy(new, old, ft_min(new_size, old_size));
	free(old);
	return (new);
}
