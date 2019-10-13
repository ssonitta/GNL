# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 14:13:39 by kchaozu           #+#    #+#              #
#    Updated: 2019/10/13 14:16:14 by kchaozu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =  field_opers.c \
	 figures_list_forming.c \
	  solution.c \
	  solution2.c \
	  validators.c \
	  main.c 

OBJS = $(SRC:.c=.o)

INCLUDES = fillit.h

LIB = libft/libft.a

all : $(NAME)

$(OBJS): %.o: %.c
	@gcc -Wall -Werror -Wextra -c $< -I. -o $@

$(LIB):
	@make -C libft

$(NAME): $(LIB) $(OBJS)
	@gcc -Werror -Wall -Wextra $(OBJS) -o $(NAME) $(LIB)

clean:
		@rm -f $(OBJS)
		@make -C libft clean

fclean: clean
		@rm -f $(NAME)
		@make -C libft fclean

re : fclean all
