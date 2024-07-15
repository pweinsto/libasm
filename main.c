#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

void	HelloWorld(void);
ssize_t	ft_write(int fd, const void *buf, size_t nbyte);
ssize_t	ft_read(int, void *, size_t);
size_t	ft_strlen(const char *s);


int	main(void)
{
	char	buf[64];
	int fd = open("read.txt", O_RDONLY);

	HelloWorld();
	printf("return write: %zd\n", ft_write(-1, "Test!\n", 6));
	printf("return read: %zd\n", ft_read(fd, buf, 32));
	printf("%s\n", buf);

	errno = 0;
	write(-1, "write test\n", 11);
	printf("errno: %d\n", errno);
	errno = 0;
	ft_write(-1, "ft_write test\n", 14);
	printf("errno: %d\n", errno);
	errno = 0;
	ft_read(-1, buf, 32);
	printf("errno: %d\n", errno);

	printf("strlen: %lu\n", strlen("Hello World!"));
	printf("ft_strlen: %lu\n", ft_strlen("Hello World!"));


	return (0);
}