#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

void	error(void)
{
	fprintf(stderr, "%s\n", strerror(errno));
	exit(EXIT_FAILURE);
}