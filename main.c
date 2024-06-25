#include <stdio.h>
#include <fcntl.h>

void	HelloWorld(void);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);

int	main(void)
{
	char	buf[64];
	int fd = open("read.txt", O_RDONLY);

	HelloWorld();
	printf("return write: %zd\n", ft_write(1, "Test!\n", 6));
	printf("return read: %zd\n", ft_read(fd, buf, 32));
	printf("%s\n", buf);
	return (0);
}