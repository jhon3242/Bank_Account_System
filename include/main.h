
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

typedef struct s_table
{
    char    *colnums;
    char    **rows;
    int     count;
}               t_table;

/* util.c
================================================== */
char    *str_to_upper(char *str);
void    exit_with_msg(const char * msg, int code);
void    initArr(char *arr, int size);

/* main.c
================================================== */
MYSQL_RES*    sql_select(char *cmd);
void    display_sql(MYSQL_RES* result);
void    sql_query(char *cmd);
MYSQL_RES*    before_cmd(char *cmd);

#endif