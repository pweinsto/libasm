#include "../inc/test.h"

void static compare(char *str1, char *str2)
{
	ssize_t	ret_strcmp;
	ssize_t	ret_ft_strcmp;
	char	*color_ret;

	ret_strcmp = strcmp(str1, str2);
	
	ret_ft_strcmp = ft_strcmp(str1, str2);

	color_ret = GREEN;

	if (ret_strcmp != ret_ft_strcmp)
		color_ret = RED;
	
	printf(BOLD);
	printf("%-25s%-25s"RESET"\n", "string1", "string2");
	printf("%-25s%-25s\n", str1, str2);
	printf("-------------------------------------------------------------\n");
	printf(BOLD);
	printf("%-25s%-20s"RESET"\n", "function", "return");
	printf("%-25s%s%-20zd"RESET"\n", "strcmp", GREEN, ret_strcmp);
	printf("%-25s%s%-20zd"RESET"\n", "ft_strcmp", color_ret, ret_ft_strcmp);
	printf("\n\n");

}

void strcmp_test(void)
{
	printf("   __ _           _                            \n"
       "  / _| |_     ___| |_ _ __ ___ _ __ ___  _ __  \n"
       " | |_| __|   / __| __| '__/ __| '_ ` _ \\| '_ \\ \n"
       " |  _| |_    \\__ \\ |_| | | (__| | | | | | |_) |\n"
       " |_|  \\__|___|___/\\__|_|  \\___|_| |_| |_| .__/ \n"
       "        |_____|                         |_|    \n");

	compare("", "");
	compare("", "42");
	compare("42", "");
	compare("42", "42");
}