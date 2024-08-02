#include <errno.h>
#include <stdio.h>
void	read_test();
void 	write_test();
void	strlen_test();

ssize_t	ft_read(int, void *, size_t);

/*void	HelloWorld(void);
ssize_t	ft_write(int fd, const void *buf, size_t nbyte);
ssize_t	ft_read(int, void *, size_t);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char * dst, const char * src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);*/


int	main(void)
{
	//read_test();
	//write_test();
	strlen_test();
	
	/*char	buf[64];
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

	char	*src = "Hello World";
	char	dst[20];

	printf("strcpy: %s\n", strcpy(dst, src));
	memset(dst, 1, 20);
	printf("strcpy: %s\n", ft_strcpy(dst, src));

	printf("strcmp: %d\n", strcmp("Hello", "Hello"));
	printf("ft_strcmp: %d\n", ft_strcmp("Hello", "Hello"));

	printf("strdup: %s\n", strdup("Hello World"));

	printf("ft_strdup: %s\n", ft_strdup("Hello World"));

	void *ptr = calloc(0, sizeof(char));
	printf("ptr: %p\n", ptr);

	free(ptr);*/

	return (0);
}