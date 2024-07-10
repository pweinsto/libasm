#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

void	HelloWorld(void);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);

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


	return (0);
}