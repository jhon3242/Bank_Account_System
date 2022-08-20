#include "main.h"

char    *str_to_upper(char *str)
{
	int     i;
	char    *result;

	i = 0;
	result = ft_strdup(str);
	while (str[i])
	{
		result[i] = ft_toupper(str[i]);
		i++;
	}
	return result;
}

void    exit_with_msg(const char * msg, int code)
{
	printf("%s\n", msg);
	exit(code);
}

// 배열 초기화 함수
void	initArr(char *arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}