/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:22:32 by kchaozu           #+#    #+#             */
/*   Updated: 2020/02/10 22:17:09 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"

static int		add_line(char **str, char **line)
{
	int		len;
	char	*c;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++;
	if ((*str)[len] == '\n')
	{
		*line = ft_strsub(*str, 0, len);
		c = ft_strdup(&((*str)[len + 1]));
		free(*str);
		*str = c;
		if ((*str)[0] == '\0')
			ft_strdel(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (1);
}

int				ft_gnl(const int fd, char **line)
{
	char		*c;
	static char	*str[FD_SIZE];
	char		buff[BUFF_SIZE + 1];
	int			res;

	if (fd < 0 || fd >= FD_SIZE || line == NULL ||
		BUFF_SIZE <= 0 || read(fd, buff, 0) < 0)
		return (-1);
	while ((res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buff);
		else
		{
			c = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = c;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (res == 0 && str[fd] == NULL)
		return (0);
	return ((res >= 0) ? add_line(&str[fd], line) : -1);
}
