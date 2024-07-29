#include "test.h"

void	static compare(ssize_t fd, size_t buf_size, size_t count)
{
	ssize_t	ret_read;
	ssize_t	ret_ft_read;
	char	*buf_read;
	char	*buf_ft_read;
	int		errno_read;
	int		errno_ft_read;
	char	*color_ret ;
	char	*color_errno;
	char	*color_buf;

	buf_read = 0;
	buf_ft_read = 0;
	buf_read = calloc(buf_size, sizeof(char));
	if (buf_read <= 0)
		error();
	buf_ft_read = calloc(buf_size, sizeof(char));
	if (buf_ft_read <= 0)
		error();
	
	errno = 0;
	lseek(fd, SEEK_SET, 0);
	ret_read = read(fd, buf_read, count);
	errno_read = errno;

	errno = 0;
	lseek(fd, SEEK_SET, 0);
	ret_ft_read = ft_read(fd, buf_ft_read, count);
	errno_ft_read = errno;

	color_ret = GREEN;
	color_errno = GREEN;
	color_buf = GREEN;
	if (ret_read != ret_ft_read)
		color_ret = RED;
	if (errno_read != errno_ft_read)
		color_errno = RED;
	if (memcmp(buf_read, buf_ft_read, buf_size) != 0)
		color_buf = RED;
	
	printf(BOLD);
	printf("%-25s%-20s%-10s"RESET"\n", "file descriptor", "buffer", "count");
	printf("%-25zd%-20lu%-10zu\n", fd, buf_size, count);
	printf("-------------------------------------------------------------\n");
	printf(BOLD);
	printf("%-25s%-20s%-10s%-10s"RESET"\n", "function", "return", "errno", "buffer");
	printf("%-25s%s%-20zd%-10d%-10.*s"RESET"\n", "read", GREEN,ret_read, errno_read, (int)buf_size, buf_read);
	printf("%-25s%s%-20zd%s%-10d%s%-10.*s"RESET"\n", "ft_read", color_ret, ret_ft_read, color_errno, errno_ft_read, color_buf, (int)buf_size, buf_ft_read);
	printf("\n\n");

	bzero(buf_read, buf_size);
	bzero(buf_ft_read, buf_size);
	free(buf_read);
	free(buf_ft_read);
}


void read_test(void)
{
	ssize_t	fd_read;
	ssize_t	fd_write;
	ssize_t	fd_empty;


	fd_read = open("read.txt", O_RDONLY);
	if (fd_read < 0)
		error();
	fd_write = open("read.txt", O_WRONLY);
	if (fd_write < 0)
		error();
	fd_empty = open("read.txt", O_RDONLY);
	if (fd_read < 0)
		error();
	
	compare(fd_read, 42, 42);
	compare(fd_read, 0, 0);
	compare(fd_read, 0, 1);
	compare(fd_read, 1, 0);
	compare(fd_read, 20, UINT32_MAX);
	compare(fd_write, 42, 42);
	compare(-1, 42, 42);
	compare(fd_empty, 42, 42);

	close(fd_read);
	close(fd_write);
	close(fd_empty);

	return;
}