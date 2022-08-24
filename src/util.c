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

void	display_sql(MYSQL_RES* result)
{
	MYSQL_FIELD     *fields;
	MYSQL_ROW       row;
	unsigned int    count;

	if (result == 0)
	{
		// printf("Result is null.\n");
		return ;
	}

	fields = mysql_fetch_fields(result);
	count = mysql_num_fields(result);
	for(int i = 0; i < count; i++)
	{
		printf("[%s] ", fields[i].name);
	}
	printf("\n-------------------------------------\n");

	count = mysql_num_fields(result);
	while ((row = mysql_fetch_row(result)))
	{
		unsigned long *lengths;
		lengths = mysql_fetch_lengths(result);
		for(int i = 0; i < count; i++)
		{
			printf("[%.*s] ", (int) lengths[i],row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}
}