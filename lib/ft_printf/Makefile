CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
HEADER = include/ft_printf.h
LIBDIR = ../libft/
SRCDIR = ./src

SRC = $(SRCDIR)/ft_printf.c\
		$(SRCDIR)/print_hex.c\
		$(SRCDIR)/print_pointer.c\
		$(SRCDIR)/print_unsigned_int.c\
		$(SRCDIR)/print_utils.c\

OBJ = $(SRC:.c=.o)
INC_LINK = -I./include


all : $(NAME)

$(NAME) : $(OBJ)
	# $(MAKE) -C $(LIBDIR) all
	cp $(LIBDIR)/libft.a ./$(NAME)
	ar rcs $(NAME) $^

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) $(INC_LINK) -c $< -o $@

clean :
	# $(MAKE) -C ./libft clean
	rm -f $(OBJ)

fclean : 
	# $(MAKE) -C ./libft fclean
	rm -f $(NAME) $(OBJ)

re : fclean all

.PHONY : all libft clean fclean re