#include "main.h"

MYSQL* conn;
MYSQL connection;
MYSQL_RES* result;
MYSQL_ROW row;

// SQL 명령어를 종류에 따라서 맞게 
MYSQL_RES*    before_cmd(char *cmd)
{
	mysql_query(conn, cmd);
	result = mysql_store_result(conn);
	return result;
}

// 로그인
int	login()
{
	// 초기화
	int			user_num;
	char		id[20];
	char		pswd[20];
	char		*cmd;
	char		*cmd2;
	MYSQL_ROW	tmprow;
	
	//재로그인할 시
	here:

	//화면 및 아이디 비밀번호 입력
    system("clear");
    printf("\n\n\t\t\t🟩🤑🤑🤑🤑🤑🤑🤑🤑🤑🤑🤑🤑🤑🟩");
    printf("\n\n\t\t\tID : ");
    scanf("%s", id);
    printf("\n\t\t\tPASSWORD : ");
    scanf("%s", pswd);

	// 해당 id가 있는지 검색하고 없으면 종료
	cmd = ft_strjoin("SELECT * from User where ID = '", id);
	cmd2 = ft_strjoin(cmd, "'");
	free(cmd);

	result = before_cmd(cmd2);
	if (mysql_num_rows(result) == 0)
	{
		printf("\n\n\t\t\tNo matched ID. Make account\n");
		sleep(2);
		goto here;
	}
	// pasword 가 일치한지 확인
	tmprow = mysql_fetch_row(result);
	if (strcmp(tmprow[2], pswd) != 0)
	{
		printf("\n\n\t\t\tPassword is not matched. Please enter right password\n");
		sleep(2);
		goto here;
	}
	
	//사용자와 관리자를 구분해서 보내버리기
	user_num = ft_atoi(tmprow[0]);
	if (ft_atoi(tmprow[MANAGER]) == 1)
		manager_page();
	else
	{
		if (has_bankbook(user_num)) // 통장이 있는지 확인
			user_page(user_num);
		else
			create_bankbook(user_num);
	}
	return (0);
}

void manager_page() // TODO 매니저 페이지 구현 필요
{
	system("clear");
	ft_printf("\n\n\t\t\tWelecome to manager page\n");
}

void user_page(int user_num)
{
	int	choice;

	system("clear");
	here :
	ft_printf("\n\n\t\t\tWELECOME TO USER PAGE\n");
	
	ft_printf("\n\t\t\t [1] deposit");
	ft_printf("\n\t\t\t [2] withdraw");
	ft_printf("\n\t\t\t [3] transaction");
	ft_printf("\n\n\t\t\tSelect menu number : ");
	scanf("%d", &choice);

	if (choice == 1)
		deposit(user_num);
	else if (choice == 2)
		withdraw(user_num);
	else{
		system("clear");
		ft_printf("\n\n\t\t\tNo match num. please enter number (ex : 1)");
		goto here;
	}
}


// 회원가입
void create_account()
{
	char		buff[20];
	char		*cmd;
	char		*cmd2;
	char		*id;
	char		*passwd;
	char		*tmp;
	MYSQL_ROW   tmprow;

	
	here:
	system("clear");
	// id 입력 받기
	ft_printf("\n\n\t\t\t Create new account.");
	printf("\n\n\t\t\tID : ");
	scanf("%s", buff);

	// 해당 id가 있는지 검색하고 없으면 종료
	cmd = ft_strjoin("SELECT * from User where ID = '", buff);
	cmd2 = ft_strjoin(cmd, "'");
	free(cmd);
	result = before_cmd(cmd2);
	if (mysql_num_rows(result) != 0)
	{
		printf("\n\n\t\t\tID you entered already exist. Try another\n");
		sleep(2);
		goto here;
	}
	
	// 쿼리 명령어 작성
	cmd = ft_strjoin(cmd, "insert into User (id, password, name, age, email) values ('");
	cmd2 = ft_strjoin(cmd, buff);
	free(cmd);
	cmd = ft_strjoin(cmd2, "', ");

	// password 입력 받기
	printf("\n\t\t\tPASSWORD : ");
	scanf("%s", buff);
	cmd2 = ft_strjoin(cmd, "'");
	free(cmd);
	cmd = ft_strjoin(cmd2, buff);
	free(cmd2);
	cmd2 = ft_strjoin(cmd, "', ");
	free(cmd);
	cmd = cmd2;
	
	// name 입력 받기
	printf("\n\t\t\tNAME : ");
	scanf("%s", buff);
	cmd2 = ft_strjoin(cmd, "'");
	free(cmd);
	cmd = ft_strjoin(cmd2, buff);
	free(cmd2);
	cmd2 = ft_strjoin(cmd, "', ");
	free(cmd);
	cmd = cmd2;

	// age 입력 받기
	printf("\n\t\t\tage : ");
	scanf("%s", buff);
	cmd2 = ft_strjoin(cmd, buff);
	free(cmd);
	cmd = ft_strjoin(cmd2, ", ");
	free(cmd2);

	// email 입력 받기
	printf("\n\t\t\tEMAIL : ");
	scanf("%s", buff);
	cmd2 = ft_strjoin(cmd, "'");
	free(cmd);
	cmd = ft_strjoin(cmd2, buff);
	free(cmd2);
	cmd2 = ft_strjoin(cmd, "')");
	free(cmd);
	cmd = cmd2;

	
	before_cmd(cmd);
	printf("\n\n\t\t\tCreate account successfuly\n");
	// TODO 다시 메뉴로 가는게 좋을 듯
}



void init()
{
	char 		DB_HOST[] = "localhost";
	char 		DB_USER[] = "root";
	char 		DB_PASS[] = "jehmno316";
	char 		DB_NAME[] = "bank";

	mysql_init(&connection);
	conn = mysql_real_connect(&connection, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char *)NULL, 0);
}


int main(int argc, char** argv){
	int choice;

	here:
	system("clear");

	printf("\n\n\t\t\t🟩🤑🤑🤑🤑🤑🤑🤑🤑🤑🤑🤑🤑🤑🟩");
	printf("\n\n\t\t\tMINI BANKING MANAGEMENT SYSTEM ");
	printf("\n\n\t\t\t   [1] login\n\t\t\t   [2] create an new account\n\t\t\t   [3] exit");
	printf("\n\n\t\t\t   select your option : ");
	scanf("%d",&choice);

	init();
	if (choice == 1)
	{
		if (login() == -1)
			goto here;
	}
	else if (choice == 2)
		create_account();
	else if (choice == 3)
		exit(0);
	else
	{
		system("clear");
		printf("\n\n\t\t\t🟩🤑🤑🤑🤑🤑🤑🤑🤑🤑🤑🤑🤑🤑🟩");
		printf("\n\n\t\t     Please enter the correct option number\n");
		printf("\n\t\t      You will be redirected in 3 seconds\n");
		sleep(3);
		goto here;
	}
	return (0);
}
