#include "test.h"

void static compare(char *str)
{
	ssize_t	ret_strlen;
	ssize_t	ret_ft_strlen;
	char	*color_ret;

	ret_strlen = strlen(str);
	
	ret_ft_strlen = ft_strlen(str);

	color_ret = GREEN;

	if (ret_strlen != ret_ft_strlen)
		color_ret = RED;
	
	printf(BOLD);
	printf("%-25s"RESET"\n", "string");
	printf("%-25s\n", str);
	printf("-------------------------------------------------------------\n");
	printf(BOLD);
	printf("%-25s%-20s"RESET"\n", "function", "return");
	printf("%-25s%s%-20zd"RESET"\n", "strlen", GREEN, ret_strlen);
	printf("%-25s%s%-20zd"RESET"\n", "ft_strlen", color_ret, ret_ft_strlen);
	printf("\n\n");

}


void strlen_test(void)
{
	char	*heapString;
	char *stackString = "stack string";
	

	heapString = (char *)malloc(14 * sizeof(char));
	strcpy(heapString, "heap string");

	compare(stackString);
	compare(heapString);
	
}