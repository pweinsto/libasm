#include <errno.h>
#include <stdio.h>

void	read_test();
void	write_test();
void	strlen_test();
void	strcmp_test();
void	strcpy_test();
void	strdup_test();

int	main(void)
{
	read_test();
	write_test();
	strlen_test();
	strcmp_test();
	strcpy_test();
	strdup_test();

	return (0);
}