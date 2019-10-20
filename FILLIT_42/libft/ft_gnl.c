/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 15:19:15 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/29 15:37:43 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"

static t_node		*get_fd_list(t_node **list, const int fd)
{
	t_fd			*data;
	t_node			*proc;

	proc = *list;
	if (*list)
	{
		while (proc->prev)
			proc = proc->prev;
		while (proc)
		{
			if (((t_fd *)proc->data)->fd == fd)
				return (proc);
			proc = proc->next;
		}
	}
	if (!(data = (t_fd *)malloc(sizeof(t_fd))))
		return (NULL);
	data->fd = fd;
	data->eof_flag = 0;
	data->last_str_len = 0;
	data->buff_list = NULL;
	return (ft_ll_add_first(list, (void *)data));
}

static char			*get_strings(char *read_buff, t_node **list, size_t n)
{
	char			*n_pos;
	char			*read_buff_last_char;
	char			*new_str;

	read_buff_last_char = read_buff + n;
	while ((n_pos = ft_memchr(read_buff, '\n', n)) &&\
	n_pos < read_buff_last_char)
	{
		if (*read_buff == '\n')
			if (!(ft_ll_add_last(list, ft_strnew(0))))
				return (NULL);
		if (*read_buff != '\n')
		{
			if (!(ft_ll_add_last(list, ft_memcpy(malloc(n_pos - read_buff + 1),\
			read_buff, n_pos - read_buff))))
				return (NULL);
			*((char *)ft_ll_peek_last(*list) + (n_pos - read_buff)) = 0;
			read_buff = n_pos;
		}
		read_buff++;
	}
	if (!(new_str = ft_strnew(read_buff_last_char - read_buff + 1)))
		return (NULL);
	return (ft_ll_add_last(list, ft_memcpy(new_str, read_buff,\
	read_buff_last_char - read_buff + 1)) ? read_buff : NULL);
}

static int			read_from_file(const int fd, t_fd *buff,\
char **read_buff, ssize_t *cnt_bytes)
{
	char		*last_str_ptr;
	char		*start_read_pos;

	if (buff->buff_list)
	{
		ft_memcpy(*read_buff, ft_ll_peek_last(buff->buff_list),\
		buff->last_str_len);
		free(ft_ll_get_last(&(buff->buff_list)));
	}
	start_read_pos = *read_buff + buff->last_str_len;
	if ((*cnt_bytes = read(fd, start_read_pos, BUFF_SIZE)) <= 0)
		return (-1);
	if (*cnt_bytes < BUFF_SIZE)
		if (*(*read_buff + *cnt_bytes + buff->last_str_len -\
					(buff->eof_flag = 1)) == '\n')
			*(*read_buff + *cnt_bytes + buff->last_str_len - \
			buff->eof_flag) = 0;
	if (!(last_str_ptr = get_strings(*read_buff, &(buff->buff_list),\
	*cnt_bytes + buff->last_str_len - buff->eof_flag)))
		return (-1);
	buff->last_str_len = *cnt_bytes + buff->last_str_len - \
	buff->eof_flag - (last_str_ptr - *read_buff);
	return (0);
}

static int			error_output_resolver(t_node **fd_list,\
char *read_buff, ssize_t cnt_bytes)
{
	free(ft_ll_get(fd_list));
	free(read_buff);
	if (!cnt_bytes)
		return (0);
	return (-1);
}

int					ft_gnl(const int fd, char **line)
{
	static t_node	*fd_list;
	t_fd			*buff;
	ssize_t			cnt_bytes;
	char			*read_buff;

	if (fd < 0 || !line || !(fd_list = get_fd_list(&fd_list, fd)) ||\
	BUFF_SIZE < 1)
		return (error_output_resolver(NULL, NULL, 1));
	buff = (t_fd *)fd_list->data;
	while (1)
	{
		if (buff->buff_list && (buff->buff_list->next || buff->eof_flag))
		{
			*line = (char *)ft_ll_get_first(&(buff->buff_list));
			if (buff->eof_flag && !(buff->buff_list))
				free(ft_ll_get(&fd_list));
			return (1);
		}
		if (!(read_buff = ft_strnew(BUFF_SIZE + buff->last_str_len)))
			return (-1);
		if (read_from_file(fd, buff, &read_buff, &cnt_bytes) < 0)
			break ;
		free(read_buff);
	}
	return (error_output_resolver(&fd_list, read_buff, cnt_bytes));
}
