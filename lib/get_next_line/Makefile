# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/26 00:55:09 by wonjchoi          #+#    #+#              #
#    Updated: 2022/06/26 00:55:53 by wonjchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libgnl.a

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

INCLUDE	= -I./include

SRC_DIR	= ./src
SRC = \
	$(SRC_DIR)/get_next_line.c\
	$(SRC_DIR)/get_next_line_utils.c\

OBJ	= $(SRC:.c=.o)

$(NAME): $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^
	@ar crsu $(NAME) $@

all: $(NAME)
		
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
