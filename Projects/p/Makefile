# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 19:51:30 by kchaozu           #+#    #+#              #
#    Updated: 2020/02/12 17:09:11 by kchaozu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SURNAME = checker

SRC =\
ft_ps_cmd.c\
ft_sort.c\
ft_sort_mini.c\
ft_ps_checker.c\
ft_ps_clean.c\
ft_ps_push.c\
ft_ps_rotate.c\
ft_ps_rrotate.c\
ft_ps_swap.c\
ft_ps_stack.c\
ft_sortmini_2.c

MAIN_PS = push_swap.c
MAIN_CHECK = main.c
HEAD = push_swap.h

OBJ = ${SRC:%.c=%.o}
OBJ_1 = ${MAIN_PS:%.c=%.o}
OBJ_2 = ${MAIN_CHECK:%.c=%.o}

LIB = libft_1/libft.a

all : ${NAME} ${SURNAME}

$(LIB):
	make -C libft_1

$(NAME): ${LIB} $(OBJ) $(OBJ_1) $(OBJ_2)
	gcc -g ${LIB} -Wall -Werror -Wextra $(OBJ) $(OBJ_1) -o $(NAME)

	gcc -g ${LIB} -Wall -Werror -Wextra $(OBJ) $(OBJ_2) -o $(SURNAME)

clean:
	rm -f $(OBJ) $(OBJ_1) $(OBJ_2)
	make clean -C libft_1/

fclean: clean
	rm -f $(NAME) $(SURNAME)
	make fclean -C libft_1/

re: fclean all
