#include <stdio.h>

void	HelloWorld(void);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);

int	main(void)
{
	HelloWorld();
	ft_write(1, "Test!\n", 6);
	printf("return\n");

	return (0);
}