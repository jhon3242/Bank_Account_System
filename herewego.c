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

    printf("\n\n\t\t\tπ©π€π€π€π€π€π€π€π€π€π€π€π€π€π©");
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
        printf("\n\n\t\t\tπ©π€π€π€π€π€π€π€π€π€π€π€π€π€π©");
        printf("\n\n\t\t     Please enter the correct option number\n");
        printf("\n\t\t      You will be redirected in 3 seconds\n");
        sleep(3);
        goto here;
    }
    return (0);
}

void    login()
{
    char    id[20];
    char    pswd[20];
    int     user_num;
    
    system("clear");
    printf("\n\n\t\t\tπ©π€π€π€π€π€π€π€π€π€π€π€π€π€π©");
    printf("\n\n\t\t\tID : ");
    scanf("%s", id);
    printf("\n\t\t\tPASSWORD : ");
    scanf("%s", pswd);

    //μμ΄λλ λΉλ°λ²νΈ λ³΄λ΄κ³  
    //λ§μ½ μ§μμ΄λ μλμ΄λΌλ©΄ λ‘κ³ λ₯Ό λ³΄μ¬μ£Όκ³ 
    //μ§μμ΄λΌλ©΄ μ§μ λ©λ΄λ‘
        manager_menu();
    //μλμ΄λΌλ©΄ μλ λ²νΈλ₯Ό μ λ¬ν΄ μ£Όκ³  μλ λ©λ΄λ‘
        user_menu(user_num);
    //μλλ©΄ μ  λ€λ‘~~
}

void    manager_menu()
{

}

void    user_menu(const int user_num)
{
    int choice;

    here:
    system("clear");
    printf("\n\n\t\t\tπ©π€π€π€π€π€π€π€π€π€π€π€π€π€π©");
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
        printf("\n\n\t\t\tπ©π€π€π€π€π€π€π€π€π€π€π€π€π€π©");
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