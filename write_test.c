#include "test.h"

void static compare(ssize_t fd_write, int fd_ft_write, const void *buf, size_t nbyte)
{
	ssize_t	ret_write;
	ssize_t	ret_ft_write;
	int		errno_write;
	int		errno_ft_write;
	char	*color_ret;
	char	*color_errno;
	char	*color_buf;
	
	errno = 0;
	ret_write = write(fd_write, buf, nbyte);
	errno_write = errno;

	errno = 0;
	ret_ft_write = ft_write(fd_ft_write, buf, nbyte);
	errno_ft_write = errno;

	color_ret = GREEN;
	color_errno = GREEN;
	color_buf = GREEN;

	if (ret_write != ret_ft_write)
		color_ret = RED;
	if (errno_write != errno_ft_write)
		color_ret = RED;
	
	printf(BOLD);
	printf("%-25s%-20.10s%-10s"RESET"\n", "file descriptor", "buffer", "count");
	printf("%-25zd%-20.10s%-10zu\n", fd_write, buf, nbyte);
	printf("-------------------------------------------------------------\n");
	printf(BOLD);
	printf("%-25s%-20s%-10s%-10s"RESET"\n", "function", "return", "errno", "buffer");
	printf("%-25s%s%-20zd%-10d%-10.*s"RESET"\n", "write", GREEN, ret_write, errno_write, 1, buf);
	printf("%-25s%s%-20zd%s%-10d%s%-10.*s"RESET"\n", "ft_write", color_ret, ret_ft_write, color_errno, errno_ft_write, color_buf, 1, buf);
	printf("\n\n");

}


void write_test(void)
{
	char *buf = "Hello world\n";
	
	
	compare(1, 1, buf, 1);
	compare(1, 1, buf, 0);
	compare(1, 1, buf, 42);

	compare(1, 1, NULL, 13);

	compare(4, 4, buf, 13);
}