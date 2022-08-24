
#ifndef MAIN_H

# define MAIN_H

#include "../lib/libft/include/libft.h"
#include "../lib/ft_printf/include/ft_printf.h"
#include <mysql.h>
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
# define EXIT_ERROR 1
# define EXIT_SUCCESS 0
# define MANAGER 6
# define BALANCE 1
# define BUFF_SIZE 1024

typedef struct	s_table
{
	char	*colnums;
	char	**rows;
	int		count;
}				t_table;

/* deposit.c
================================================== */
void	deposit(int user_num);
void	withdraw(int user_num);

/* bankbook.c
================================================== */
void		create_bankbook(int user_num);
int			has_bankbook(int user_num);

/* util.c
================================================== */
char		*str_to_upper(char *str);
void		exit_with_msg(const char * msg, int code);
void		initArr(char *arr, int size);
void		display_sql(MYSQL_RES* result);

/* main.c
================================================== */
MYSQL_RES*	before_cmd(char *cmd);
int			login();
void		manager_page();
void		user_page(int user_num);

void		create_account();
void		init();

#endif