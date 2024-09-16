#include "../inc/test.h"

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
	printf("   __ _           _                        \n"
       "  / _| |_     ___| |_ _ __ ___ _ __  _   _ \n"
       " | |_| __|   / __| __| '__/ __| '_ \\| | | |\n"
       " |  _| |_    \\__ \\ |_| | | (__| |_) | |_| |\n"
       " |_|  \\__|___|___/\\__|_|  \\___| .__/ \\__, |\n"
       "        |_____|               |_|    |___/ \n");

	char	*src = "source string";

	char	stack_dest_strcpy[strlen(src) + 1];
	char	stack_dest_ft_strcpy[strlen(src) + 1];

	char	*heap_dest_strcpy = calloc(strlen(src) + 1, sizeof(char));
	char	*heap_dest_ft_strcpy = calloc(strlen(src) + 1, sizeof(char));

	char	empty_dest_strcpy[strlen(EMPTYSTRING) + 1];
	char	empty_dest_ft_strcpy[strlen(EMPTYSTRING) + 1];
	
	char	long_dest_strcpy[strlen(LONGSTRING) + 1];
	char	long_dest_ft_strcpy[strlen(LONGSTRING) + 1];

	compare(stack_dest_strcpy, stack_dest_ft_strcpy, src);
	compare(heap_dest_strcpy, heap_dest_ft_strcpy, src);
	compare(empty_dest_strcpy, empty_dest_ft_strcpy, EMPTYSTRING);
	compare(long_dest_strcpy, long_dest_ft_strcpy, LONGSTRING);

	free(heap_dest_strcpy);
	free(heap_dest_ft_strcpy);
}