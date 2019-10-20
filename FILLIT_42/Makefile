# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lronnet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/19 18:45:58 by lronnet           #+#    #+#              #
#    Updated: 2019/10/19 18:59:05 by lronnet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = field_opers.c\
figures_list_forming.c\
figures_list_forming2.c\
solution.c\
solution2.c\
validators.c\
main.c 

OBJS = field_opers.o\
figures_list_forming.o\
figures_list_forming2.o\
solution.o\
solution2.o\
validators.o\
main.o 

LIB = libft/libft.a

all : $(NAME)

%.o: %.c fillit.h
	gcc -Wall -Werror -Wextra -I. -c $<

$(LIB):
	make -C libft

$(NAME): $(LIB) $(OBJS)
	gcc -Werror -Wall -Wextra $(OBJS) -o $(NAME) $(LIB)

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re : fclean all
