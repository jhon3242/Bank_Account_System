#include "main.h"

// 입금
void	deposit(int user_num)
{
	MYSQL_RES	*result;
	MYSQL_ROW	row;
	char		cmd[BUFF_SIZE];
	char		buff[BUFF_SIZE];
	char		*balance;

	system("clear");
	ft_printf("\n\n\t\t\tWELECOME TO DEPOSIT PAGE!\n\n");

	ft_printf("\n\n\t\t\tEnter amount to diposit (ex : 1000000)\n\n\t\t\t : ");
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

	ft_printf("\n\t\t\tDeposit success!\n");
}


void	withdraw(int user_num)
{
	MYSQL_RES	*result;
	MYSQL_ROW	row;
	char		cmd[BUFF_SIZE];
	char		buff[BUFF_SIZE];
	char		*balance;
	int			miss_count;

	system("clear");
	ft_printf("\n\n\t\t\tWELECOME TO WITHDRAW PAGE!\n\n");

	// 고객 정보 가져오기
	ft_strcat(cmd, "SELECT * from User WHERE user_num = ");
	ft_strcat(cmd, ft_itoa(user_num));
	result = before_cmd(cmd);
	row = mysql_fetch_row(result);

	// 비밀번호 확인
	miss_count = 0;
	while (1)
	{
		ft_printf("\n\n\t\t\tPlease enter your password : ");
		scanf("%s", buff);
		if (ft_strcmp(row[PASSWORD], buff))
		{
			system("clear");
			ft_printf("\n\t\t\tPassword doesn't match %d times.\n", 1 + miss_count++);
			if (miss_count >= 3)
			{
				ft_printf("\n\t\t\tmaximum try count exceed!\n\n");
				return ;
			}
		}
		else
			break;
	}

	ft_memset(buff, 0, BUFF_SIZE);
	ft_memset(cmd, 0, BUFF_SIZE);
	system("clear");
	ft_printf("\n\n\t\t\tEnter amount to withdraw (ex : 1000000)\n\n\t\t\t : ");
	scanf("%s", buff);
	
	// 고객 계좌 정보 가져오기
	ft_strcat(cmd, "SELECT * from Account WHERE user_num = ");
	ft_strcat(cmd, ft_itoa(user_num));
	result = before_cmd(cmd);
	row = mysql_fetch_row(result);

	// 가지고 있는 돈이 출금 금액보다 적은 경우
	if (ft_atoi(row[BALANCE]) < ft_atoi(buff))
	{
		ft_printf("\n\n\t\t\tYou don't have enough money!\n");
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
	free(balance);
	ft_printf("\n\n\t\t\tWithdraw success!\n");
}

// 이체
void	transmission(int user_num)
{
	system("clear");
	ft_printf("\n\n\t\t\tWelecome to trasmission page!\n");
}	