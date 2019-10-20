# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lronnet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 18:55:02 by lronnet           #+#    #+#              #
#    Updated: 2019/09/27 19:28:04 by lronnet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c\
ft_bzero.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_islower.c\
ft_isprint.c\
ft_isupper.c\
ft_itoa.c\
ft_lstadd.c\
ft_lstdel.c\
ft_lstdelone.c\
ft_lstiter.c\
ft_lstmap.c\
ft_lstnew.c\
ft_memalloc.c\
ft_memccpy.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memdel.c\
ft_memmove.c\
ft_memset.c\
ft_putchar.c\
ft_putchar_fd.c\
ft_putendl.c\
ft_putendl_fd.c\
ft_putnbr.c\
ft_putnbr_fd.c\
ft_putstr.c\
ft_putstr_fd.c\
ft_strcat.c\
ft_strchr.c\
ft_strclr.c\
ft_strcmp.c\
ft_strcpy.c\
ft_strdel.c\
ft_strdup.c\
ft_strequ.c\
ft_striter.c\
ft_striteri.c\
ft_strjoin.c\
ft_strlcat.c\
ft_strlen.c\
ft_strmap.c\
ft_strmapi.c\
ft_strncat.c\
ft_strncmp.c\
ft_strncpy.c\
ft_strnequ.c\
ft_strnew.c\
ft_strnstr.c\
ft_strrchr.c\
ft_strsplit.c\
ft_strstr.c\
ft_strsub.c\
ft_strtrim.c\
ft_tolower.c\
ft_toupper.c\
ft_ll_add_first.c\
ft_ll_add_last.c\
ft_ll_add_n.c\
ft_ll_get.c\
ft_ll_get_first.c\
ft_ll_get_last.c\
ft_ll_get_n.c\
ft_ll_length.c\
ft_ll_new_node.c\
ft_ll_peek.c\
ft_ll_peek_first.c\
ft_ll_peek_last.c\
ft_ll_peek_n.c\
ft_ll_pop.c\
ft_ll_push.c\
ft_gnl.c\
ft_mathfact.c\
ft_arrinsnsorn.c\
ft_compasc.c\
ft_compdesc.c\
ft_swap.c\
ft_mathsqrt.c\
ft_mathpow.c

OBJ = ft_atoi.o\
ft_bzero.o\
ft_isalnum.o\
ft_isalpha.o\
ft_isascii.o\
ft_isdigit.o\
ft_islower.o\
ft_isprint.o\
ft_isupper.o\
ft_itoa.o\
ft_lstadd.o\
ft_lstdel.o\
ft_lstdelone.o\
ft_lstiter.o\
ft_lstmap.o\
ft_lstnew.o\
ft_memalloc.o\
ft_memccpy.o\
ft_memchr.o\
ft_memcmp.o\
ft_memcpy.o\
ft_memdel.o\
ft_memmove.o\
ft_memset.o\
ft_putchar.o\
ft_putchar_fd.o\
ft_putendl.o\
ft_putendl_fd.o\
ft_putnbr.o\
ft_putnbr_fd.o\
ft_putstr.o\
ft_putstr_fd.o\
ft_strcat.o\
ft_strchr.o\
ft_strclr.o\
ft_strcmp.o\
ft_strcpy.o\
ft_strdel.o\
ft_strdup.o\
ft_strequ.o\
ft_striter.o\
ft_striteri.o\
ft_strjoin.o\
ft_strlcat.o\
ft_strlen.o\
ft_strmap.o\
ft_strmapi.o\
ft_strncat.o\
ft_strncmp.o\
ft_strncpy.o\
ft_strnequ.o\
ft_strnew.o\
ft_strnstr.o\
ft_strrchr.o\
ft_strsplit.o\
ft_strstr.o\
ft_strsub.o\
ft_strtrim.o\
ft_tolower.o\
ft_toupper.o\
ft_ll_add_first.o\
ft_ll_add_last.o\
ft_ll_add_n.o\
ft_ll_get.o\
ft_ll_get_first.o\
ft_ll_get_last.o\
ft_ll_get_n.o\
ft_ll_length.o\
ft_ll_new_node.o\
ft_ll_peek.o\
ft_ll_peek_first.o\
ft_ll_peek_last.o\
ft_ll_peek_n.o\
ft_ll_pop.o\
ft_ll_push.o\
ft_gnl.o\
ft_mathfact.o\
ft_arrinsnsort.o\
ft_compasc.o\
ft_swap.o\
ft_mathsqrt.o\
ft_mathpow.o

NAME = libft.a

HEADERS = headers/

all: $(NAME)

$(NAME): ${OBJ}
	ar rc ${NAME} ${OBJ}
	ranlib ${NAME}

%.o: %.c libft.h ft_gnl.h
	gcc -Wall -Werror -Wextra -I. -c $<

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

