/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:22:49 by kchaozu           #+#    #+#             */
/*   Updated: 2019/07/15 20:25:54 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# define FD_SIZE 1000

# include <fcntl.h>
# include "libft/libft.h"

int		get_next_line(const int fd, char **line);

#endif
