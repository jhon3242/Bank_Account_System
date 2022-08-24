#include "main.h"

// char	*get_account_num(int user_num)
// {
// 	char	cmd[BUFF_SIZE];
// }

// char	*get_balance(int account_num)
// {
// 	char		cmd[BUFF_SIZE];
// 	MYSQL_RES	*result;

// 	ft_strcat(cmd, "SELECT balance from Account WHERE account_num = ")
// 	ft_strcat(cmd, account_num);
// 	result = before_cmd(cmd);
// 	display_cmd(result);
// }


// 입금
void	deposit(int user_num)
{
	MYSQL_RES	*result;
	MYSQL_ROW	row;
	char		cmd[BUFF_SIZE];
	char		buff[BUFF_SIZE];
	char		*balance;

	ft_printf("Welecome to deposit page!\n\n"); // TODO 추가적인 화면 구성 필요

	ft_printf("Enter amount to diposit (ex : 1000000) : ");
	scanf("%s", buff);
	
	ft_strcat(cmd, "SELECT * from Account WHERE user_num = ");
	ft_strcat(cmd, ft_itoa(user_num));
	result = before_cmd(cmd);
	row = mysql_fetch_row(result);
	balance = ft_itoa(ft_atoi(row[BALANCE]) + ft_atoi(buff));

	// 계좌 금액 정보 수정
	ft_memset(cmd, 0, BUFF_SIZE);
	ft_strcat(cmd, "UPDATE Account SET update_date = NOW(), balance = ");
	ft_strcat(cmd, balance);
	before_cmd(cmd);

	// 거래 테이블에 레코드 추가
	ft_memset(cmd, 0, BUFF_SIZE);
	ft_strcat(cmd, "INSERT INTO Transaction (type, amount, balance, client, account_num) VALUES ('deposit', ");
	ft_strcat(cmd, buff);
	ft_strcat(cmd, ", ");
	ft_strcat(cmd, balance);
	ft_strcat(cmd, ", ");
	ft_strcat(cmd, row[0]);
	ft_strcat(cmd, ", ");
	ft_strcat(cmd, row[0]);
	ft_strcat(cmd, ")");
	before_cmd(cmd);

	ft_printf("Deposit success!\n");
}

void	withdraw(int user_num)
{
	MYSQL_RES	*result;
	MYSQL_ROW	row;
	char		cmd[BUFF_SIZE];
	char		buff[BUFF_SIZE];
	char		*balance;
	int			miss_count;

	ft_printf("Welecome to withdraw page!\n\n"); // TODO 추가적인 화면 구성 필요

	// 고객 정보 가져오기
	ft_strcat(cmd, "SELECT * from User WHERE user_num = ");
	ft_strcat(cmd, ft_itoa(user_num));
	result = before_cmd(cmd);
	row = mysql_fetch_row(result);

	// 비밀번호 확인
	miss_count = 0;
	while (1)
	{
		ft_printf("Please enter your password : ");
		scanf("%s", buff);
		if (ft_strcmp(row[PASSWORD], buff))
		{
			ft_printf("Password doesn't match %d times.\n", 1 + miss_count++);
			if (miss_count >= 3)
			{
				ft_printf("maximum try count exceed!\n\n");
				return ;
			}
		}
		else
			break;
	}

	ft_memset(buff, 0, BUFF_SIZE);
	ft_memset(cmd, 0, BUFF_SIZE);
	ft_printf("Enter amount to withdraw (ex : 1000000) : ");
	scanf("%s", buff);
	
	// 고객 계좌 정보 가져오기
	ft_strcat(cmd, "SELECT * from Account WHERE user_num = ");
	ft_strcat(cmd, ft_itoa(user_num));
	result = before_cmd(cmd);
	row = mysql_fetch_row(result);

	// 가지고 있는 돈이 출금 금액보다 적은 경우
	if (ft_atoi(row[BALANCE]) < ft_atoi(buff))
	{
		ft_printf("You don't have enough money!\n");
		return ;
	}

	
	balance = ft_itoa(ft_atoi(row[BALANCE]) - ft_atoi(buff));

	// 계좌 금액 정보 수정
	ft_memset(cmd, 0, BUFF_SIZE);
	ft_strcat(cmd, "UPDATE Account SET update_date = NOW(), balance = ");
	ft_strcat(cmd, balance);
	before_cmd(cmd);

	// 거래 테이블에 레코드 추가
	ft_memset(cmd, 0, BUFF_SIZE);
	ft_strcat(cmd, "INSERT INTO Transaction (type, amount, balance, client, account_num) VALUES ('withdraw', ");
	ft_strcat(cmd, buff);
	ft_strcat(cmd, ", ");
	ft_strcat(cmd, balance);
	ft_strcat(cmd, ", ");
	ft_strcat(cmd, row[0]);
	ft_strcat(cmd, ", ");
	ft_strcat(cmd, row[0]);
	ft_strcat(cmd, ")");
	before_cmd(cmd);

	ft_printf("Withdraw success!\n");
}

// 이체
void	transmission_page()
{

	ft_printf("What type of imformation about dispoit address will you give me?\n");
	ft_printf("1. user_num\n");
	ft_printf("2. account_num\n");
}