#include "test.h"

void static compare(char *dest_strcpy, char *dest_ft_strcpy, char *src)
{
	char	*ret_strcpy;
	char	*ret_ft_strcpy;
	char	*color_ret;
	char	*color_dest;

	ret_strcpy = strcpy(dest_strcpy, src);
	
	ret_ft_strcpy = ft_strcpy(dest_ft_strcpy, src);

	color_ret = GREEN;
	color_dest = GREEN;

	if (ret_ft_strcpy != dest_ft_strcpy)
		color_ret = RED;
	if (strcmp(dest_strcpy, dest_ft_strcpy) != 0)
		color_dest = RED;
	
	printf(BOLD);
	printf("%-25s%-25s"RESET"\n", "dest strcpy", "dest ft_strcpy");
	printf("%-25p%-25p\n", dest_strcpy, dest_ft_strcpy);
	printf("-------------------------------------------------------------\n");
	printf(BOLD);
	printf("%-25s%-20s"RESET"\n", "function", "return");
	printf("%-25s%s%-20p%-20s"RESET"\n", "strcpy", GREEN, ret_strcpy, dest_strcpy);
	printf("%-25s%s%-20p%-20s"RESET"\n", "ft_strcpy", color_ret, ret_ft_strcpy, dest_ft_strcpy);
	printf("\n\n");

}

void strcpy_test(void)
{
	char	*src = "source string";

	char	stack_dest_strcpy[strlen(src) + 1];
	char	stack_dest_ft_strcpy[strlen(src) + 1];

	char	*heap_dest_strcpy = calloc(strlen(src) + 1, sizeof(char));
	char	*heap_dest_ft_strcpy = calloc(strlen(src) + 1, sizeof(char));

	compare(stack_dest_strcpy, stack_dest_ft_strcpy, src);
	compare(heap_dest_strcpy, heap_dest_ft_strcpy, src);

	free(heap_dest_strcpy);
	free(heap_dest_ft_strcpy);
}