#ifndef TEST_H
#define TEST_H


#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[0;31m"
#define GREEN "\033[0;42m"

ssize_t	ft_write(int fd, const void *buf, size_t nbyte);
ssize_t	ft_read(int, void *, size_t);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char * dst, const char * src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);


void	error(void);

#endif