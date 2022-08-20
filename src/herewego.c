#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void    login();
void    newaccount();
void    manager_menu();
void    user_menu(const int);
void    deposit(const int);
void    withdraw(const int);
void    revise_userinfo(const int);

int main(void)
{
    int choice;
    here:
    system("clear");

    printf("\n\n\t\t\t🟩🤑🤑🤑🤑🤑🤑🤑🤑🤑🤑🤑🤑🤑🟩");
    printf("\n\n\t\t\tMINI BANKING MANAGEMENT SYSTEM ");
    printf("\n\n\t\t\t   [1] login\n\t\t\t   [2] create an new account\n\t\t\t   [3] exit");
    printf("\n\n\t\t\t   select your option : ");
    scanf("%d",&choice);

    if (choice == 1)
        login();
    else if (choice == 2)
        newaccount();
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


void    manager_menu()
{

}

void    user_menu(const int user_num)
{
    int choice;

    here:
    system("clear");
    printf("\n\n\t\t\t🟩🤑🤑🤑🤑🤑🤑🤑🤑🤑🤑🤑🤑🤑🟩");
    printf("\n\n\t\t\tMINI BANKING MANAGEMENT SYSTEM ");
    printf("\n\n\t\t\t   [1] deposit\n\t\t\t   [2] withdraw\n\t\t\t   [3] revise personal informationn\t\t\t   [4] exit");
    printf("\n\n\t\t\t   select your option : ");
    scanf("%d",&choice);

    if (choice == 1)
        deposit(user_num);
    else if (choice == 2)
        withdraw(user_num);
    else if (choice == 3)
        revise_userinfo(user_num);
    else if (choice == 4)
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
}

void    newaccount()
{

}

void    deposit(const int user_num)
{

}

void    withdraw(const int user_num)
{

}

void    revise_userinfo(const int user_num)
{

}

    // printf("\
    // ##      ## ######## ##        ######   #######  ##     ## ########\n\
    // ##  ##  ## ##       ##       ##    ## ##     ## ###   ### ##\n\
    // ##  ##  ## ##       ##       ##       ##     ## #### #### ##\n\
    // ##  ##  ## ######   ##       ##       ##     ## ## ### ## ######\n\
    // ##  ##  ## ##       ##       ##       ##     ## ##     ## ##\n\
    // ##  ##  ## ##       ##       ##    ## ##     ## ##     ## ##\n\
    //  ###  ###  ######## ########  ######   #######  ##     ## ########");

    cmd = ft_strjoin("SELECT * from User where ID = '", id);
	cmd2 = ft_strjoin(cmd, "'");
	free(cmd);
	result = before_cmd(cmd2);
	if (mysql_num_rows(result) == 0)
	{
		printf("No matched ID. Make account\n");// 띄어쓰기 나중에 수정
		return (-1);
	}