NAME = bank

CC = gcc
SQL_FLAG = `mysql_config --cflags`
SQL_LIB = `mysql_config --libs`

LIB_DIR = lib/libft/
FPT_DIR = lib/ft_printf/
SRC_DIR = src

INCLUDE = -I./include

SRC = $(SRC_DIR)/main.c\
		$(SRC_DIR)/util.c\


OBJ = $(SRC:.c=.o)





all : $(NAME)


$(NAME) : $(OBJ)
	$(MAKE) -C $(LIB_DIR)
	$(MAKE) -C $(FPT_DIR)
	$(CC) -o $@ $^ -L $(LIB_DIR) -lft -L $(FPT_DIR) -lftprintf $(SQL_LIB)

%.o : %.c
	$(CC) $(SQL_FLAG) $(INCLUDE) -c $< -o $@

clean :
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(FPT_DIR) clean
	rm -f $(OBJ) $(B_OBJ)

fclean : clean
	$(MAKE) -C $(LIB_DIR) fclean
	$(MAKE) -C $(FPT_DIR) fclean
	rm -f $(NAME) $(B_NAME)

re : fclean all

.PHONY : all clean fclean re bonus