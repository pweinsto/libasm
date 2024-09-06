#include "test.h"

void static compare(char *src)
{
	char	*ret_strdup;
	char	*ret_ft_strdup;
	char	*color_ret;
	char	*color_dest;

	ret_strdup = strdup(src);
	
	ret_ft_strdup = ft_strdup(src);

	color_ret = GREEN;
	color_dest = GREEN;

	if (strcmp(ret_strdup, ret_ft_strdup) != 0)
		color_dest = RED;
	
	printf(BOLD);
	printf("%-25s%-25s"RESET"\n", "src strdup", "src ft_strdup");
	printf("%-25s%-25s\n", src, src);
	printf("-------------------------------------------------------------\n");
	printf(BOLD);
	printf("%-25s%-20s"RESET"\n", "function", "return");
	printf("%-25s%s%-20p%-20s"RESET"\n", "strdup", GREEN, ret_strdup, ret_strdup);
	printf("%-25s%s%-20p%-20s"RESET"\n", "ft_strdup", color_ret, ret_ft_strdup, ret_ft_strdup);
	printf("\n\n");

	free(ret_strdup);
	free(ret_ft_strdup);
}

void strdup_test(void)
{
	printf("   __ _           _           _             \n"
       "  / _| |_     ___| |_ _ __ __| |_   _ _ __  \n"
       " | |_| __|   / __| __| '__/ _` | | | | '_ \\ \n"
       " |  _| |_    \\__ \\ |_| | | (_| | |_| | |_) |\n"
       " |_|  \\__|___|___/\\__|_|  \\__,_|\\__,_| .__/ \n"
       "        |_____|                      |_|    \n");

	char	*src = "source string";

	compare(src);
	compare(src);
}