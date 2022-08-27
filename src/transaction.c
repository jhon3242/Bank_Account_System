#include "main.h"
MYSQL_RES	*result;
MYSQL_ROW	row;

//거래내역
void	transfer(int user_num)
{
	MYSQL_ROW	from_row;
	MYSQL_ROW	to_row;
	char		send_acc[BUFF_SIZE];
	char		cmd[BUFF_SIZE];
	int			send_money;

	//사용자 정보 가져오기
	ft_memset(cmd, 0, 1024);
	ft_strcat(cmd, "SELECT * from Account WHERE user_num = ");
	ft_strcat(cmd, ft_itoa(user_num));
	result = before_cmd(cmd);
	from_row = mysql_fetch_row(result);

	here:
	//기본화면
	system("clear");
	ft_printf("\n\n\t\t\t🟩🤑🤑TRANSACTION PAGE🤑🤑🟩\n");
	print_userinfo(user_num);

	//계좌입력 및 확인
	ft_printf("\n\n\t\tEnter the bank account you want to transfer: ");
	scanf("%s", send_acc);

	ft_memset(cmd, 0, 1024);
	ft_strcat(cmd, "SELECT * from Account WHERE account_num = ");
	ft_strcat(cmd, send_acc);
	result = before_cmd(cmd);
	to_row = mysql_fetch_row(result);
	if (to_row == 0)
	{
		system("clear");
		ft_printf("\n\n\n\n\t\t\tNo matched account number. Try again");
		sleep(2);
		goto here;
	}

	//인제 화면 클리어하고 돈 보내기
	here2:
	system("clear");
	ft_printf("\n\n\t\t\t🟩🤑🤑TRANSACTION PAGE🤑🤑🟩\n");
	print_userinfo(user_num);

	ft_printf("\n\n\t\tEnter the amount you want to transfer: ");
	scanf("%d", &send_money);
	
	//돈 안 넘치는 지 확인하기
	if (send_money > ft_atoi(from_row[1]))
	{
		system("clear");
		ft_printf("\n\n\n\n\t\t\tAbove the balance you have. Enter again\n");
		ft_printf("\033[0;32mCurrent balance\033[0m : %s", from_row[1]);
		sleep(2);
		goto here2;
	}

	//인제 진짜로 보내기(확인 다 끝남)
	system("clear");
	ft_printf("\n\n\t\t\t🟩🤑🤑TRANSACTION PAGE🤑🤑🟩\n");
	
	// 고객 정보 가져오기
	ft_memset(cmd, 0, 1024);
	ft_strcat(cmd, "SELECT * from User WHERE user_num = ");
	ft_strcat(cmd, ft_itoa(user_num));
	result = before_cmd(cmd);
	row = mysql_fetch_row(result);

	ft_printf("\n\n\t\t\t🟩FROM \033[0;34m%s\033[0m TO ", row[3]);
	
	ft_memset(cmd, 0, 1024);
	ft_strcat(cmd, "SELECT * from User WHERE user_num = ");
	ft_strcat(cmd, to_row[4]);
	result = before_cmd(cmd);
	row = mysql_fetch_row(result);

	ft_printf("\033[0;34m%s\033[0m\n", row[3]);
	ft_printf("\n\n\t\t\t🟩SENDING %d\n", send_money);
	ft_printf("\n\n\t\t\t🟩REMAIN BALANCE : %d\n", ft_atoi(from_row[1]) - send_money);
	sleep(3);

	//정리
	ft_memset(cmd, 0, 1024);
	ft_strcat(cmd, "UPDATE Account set balance = ");
	ft_strcat(cmd, ft_itoa(ft_atoi(from_row[1]) - send_money));
	ft_strcat(cmd, " where user_num = ");
	ft_strcat(cmd, ft_itoa(user_num));
	before_cmd(cmd);

	ft_memset(cmd, 0, 1024);
	ft_strcat(cmd, "UPDATE Account set balance = ");
	ft_strcat(cmd, ft_itoa(ft_atoi(to_row[1]) + send_money));
	ft_strcat(cmd, " where user_num = ");
	ft_strcat(cmd, to_row[4]);
	before_cmd(cmd);
}

// 입금
void	deposit(int user_num)
{
	char		cmd[BUFF_SIZE];
	char		buff[BUFF_SIZE];
	char		*balance;

	system("clear");
	ft_printf("\n\n\t\t\t🟩🤑🤑🤑DEPOSIT PAGE🤑🤑🤑🟩\n");
	print_userinfo(user_num);

	ft_printf("\n\n\t\tEnter amount to diposit (ex : 1000000) : ");
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

	ft_printf("\n\t\tDeposit success! \033[0;32mCurrent balance\033[0m : %s\n", balance);
	sleep(2);
}


void	withdraw(int user_num)
{
	char		cmd[BUFF_SIZE];
	char		buff[BUFF_SIZE];
	char		*balance;
	int			miss_count;

	// 고객 정보 가져오기
	ft_strcat(cmd, "SELECT * from User WHERE user_num = ");
	ft_strcat(cmd, ft_itoa(user_num));
	result = before_cmd(cmd);
	row = mysql_fetch_row(result);

	// 비밀번호 확인
	miss_count = 0;
	while (1)
	{
		system("clear");
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

	system("clear");
	ft_printf("\n\n\t\t\t🟩🤑🤑🤑WITHDRAW PAGE🤑🤑🤑🟩\n");
	print_userinfo(user_num);


	ft_memset(buff, 0, BUFF_SIZE);
	ft_memset(cmd, 0, BUFF_SIZE);
	ft_printf("\n\n\t\tEnter amount to withdraw (ex : 1000000) : ");
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

	ft_printf("\n\t\tWithdraw success! \033[0;32mCurrent balance\033[0m : %s\n", balance);
	sleep(2);
}