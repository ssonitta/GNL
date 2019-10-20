/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:19:14 by lronnet           #+#    #+#             */
/*   Updated: 2019/10/19 18:25:10 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_H
# define FT_GNL_H

# include "libft.h"

# define BUFF_SIZE 512

/*
** Структура дескриптора
*/
typedef struct	s_fd
{
	int			fd;
	t_node		*buff_list;
	int			eof_flag;
	size_t		last_str_len;
}				t_fd;

int				ft_gnl(const int fd, char **line);

#endif
