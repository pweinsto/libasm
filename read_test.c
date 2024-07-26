#include "test.h"

void	compare(ssize_t fd, size_t buf_size, size_t count)
{
	ssize_t	ret_read;
	ssize_t	ret_ft_read;
	char	*buf_read;
	char	*buf_ft_read;
	//char	buf_read[buf_size];
	//char	buf_ft_read[buf_size];
	int		errno_read;
	int		errno_ft_read;
	char	*color_ret ;
	char	*color_errno;
	char	*color_buf;

	buf_read = calloc(buf_size, sizeof(char));
	if (buf_read <= 0)
		error();
	buf_ft_read = calloc(buf_size, sizeof(char));
	if (buf_ft_read <= 0)
		error();
	
	errno = 0;
	lseek(fd, SEEK_SET, 0);
	printf("test\n");
	ret_read = read(fd, buf_read, count);
	printf("test\n");
	errno_read = errno;

	errno = 0;
	lseek(fd, SEEK_SET, 0);
	ret_ft_read = ft_read(fd, buf_ft_read, count);
	printf("test\n");
	errno_ft_read = errno;

	color_ret = GREEN;
	color_errno = GREEN;
	color_buf = GREEN;
	if (ret_read != ret_ft_read)
		color_ret = RED;
	if (errno_read != errno_ft_read)
		color_errno = RED;
	if (strcmp(buf_read, buf_ft_read) != 0)
		color_buf = RED;
	
	printf(BOLD);
	printf("%-25s%-20s%-10s\n", "file descriptor", "buffer", "count");
	printf(RESET);
	printf("%-25s%-20lu%-10zu\n", "valid", buf_size, count);
	printf("-------------------------------------------------------------\n");
	printf(BOLD);
	printf("%-25s%-20s%-10s%-10s\n", "function", "return", "errno", "buffer");
	printf(RESET);
	printf("%-25s%s%-20zd%-10d%-10s\n", "read", GREEN,ret_read, errno_read, buf_read);
	printf(RESET);
	printf("%-25s%s%-20zd%s%-10d%s%-10s\n", "ft_read", color_ret, ret_ft_read, color_errno, errno_ft_read, color_buf, buf_ft_read);
	printf(RESET);
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

	// char	*buf_zero_read;
	// char	*buf_zero_ft_read;
	// char	*buf_one;
	// //char	*buf_len;
	// char	*buf_max;


	fd_read = open("read.txt", O_RDONLY);
	if (fd_read < 0)
		error();
	fd_write = open("read.txt", O_WRONLY);
	if (fd_write < 0)
		error();

	// buf_zero_read = calloc(0, sizeof(char));
	// if (buf_zero_read <= 0)
	// 	error();
	// buf_zero_ft_read = calloc(0, sizeof(char));
	// if (buf_zero_ft_read <= 0)
	// 	error();

	// buf_one = calloc(1, sizeof(char));
	// if (buf_one <= 0)
	// 	error();
	// buf_len = calloc(len, sizeof(char));
	// if (buf_len <= 0)
	// 	error();
		
	// buf_max = calloc(UINT32_MAX, sizeof(char));
	// if (buf_max <= 0)
	// 	error();
	
	compare(fd_read, 10, 110);
	
	
	
	return;
}