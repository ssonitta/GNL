/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:22:49 by kchaozu           #+#    #+#             */
/*   Updated: 2020/02/10 22:17:07 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_H
# define FT_GNL_H
# define BUFF_SIZE 32
# define FD_SIZE 1000

# include <fcntl.h>
# include "libft.h"

int		ft_gnl(const int fd, char **line);

#endif
