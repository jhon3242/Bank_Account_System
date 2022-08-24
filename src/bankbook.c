#include "main.h"

static char	*make_random_account_num(void)
{
	char	*num;

	num = calloc(9, sizeof(char));
	for (size_t i = 0; i < 8; i++)
	{
		num[i] = '0' + rand() % 9;
	}
	return (num);
}

static int	same_account_num_ck(char *num)
{
	char		cmd[BUFF_SIZE];
	MYSQL_RES	*result;

	ft_strcat(cmd, "SELECT * from Account WHERE account_num = ");
	ft_strcat(cmd, num);
	result = before_cmd(cmd);
	if (mysql_num_rows(result) > 0)
		return (1);
	else
		return (0);
}

// 통장 계설 함수
void	create_bankbook(int user_num)
{
	char	cmd[BUFF_SIZE];
	char	*account_num;

	ft_printf("Do you want create bankbook?? (y/n)");
	scanf("%s", cmd);
	if (strcmp(cmd, "y") != 0)
		return ;
	ft_memset(cmd, 0, BUFF_SIZE);

	// 통장 번호 생성
	while (1)
	{
		account_num = make_random_account_num();
		if (same_account_num_ck(account_num) == 0) // 동일한 통장 번호가 없으면 break 로 반복문을 빠져나감
			break;
		free(account_num);
	}

	// sql 쿼리문 작성
	ft_strcat(cmd, "INSERT INTO Account (account_num, user_num) VALUE (");
	ft_strcat(cmd, account_num);
	free(account_num);
	ft_strcat(cmd, ", ");
	ft_strcat(cmd, ft_itoa(user_num));
	ft_strcat(cmd, ")");
	before_cmd(cmd);
	ft_printf("You create new bankbook!\n");
}

// 통장이 있는지 확인하는 함수
int has_bankbook(int user_num)
{
	char	cmd[BUFF_SIZE];
	MYSQL_RES	*result;

	ft_memset(cmd, 0, BUFF_SIZE);
	ft_strcat(cmd, "SELECT * from Account WHERE user_num = ");
	ft_strcat(cmd, ft_itoa(user_num));
	before_cmd(cmd);
	result = before_cmd(cmd);
	if (mysql_num_rows(result) > 0)
		return (1);
	else
		return (0);
}