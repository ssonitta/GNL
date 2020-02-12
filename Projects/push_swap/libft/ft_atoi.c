/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:56:42 by kchaozu           #+#    #+#             */
/*   Updated: 2020/02/10 23:06:49 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	n;
	int					flag;

	i = 0;
	n = 0;
	flag = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\f' || str[i] == '0')
		i++;
	if (str[i] == '-')
		flag = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		n = n * 10 + str[i++] - '0';
	if (n > 2147483647 && flag == 0)
		return (0);
	if (n > 2147483648 && flag == 1)
		return (0);
	return ((flag == 0) ? (int)n : (int)-n);
}
