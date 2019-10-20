/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:12:38 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/17 16:54:50 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*scrolldig(char *nptr)
{
	while (ft_isdigit(*nptr) && *nptr)
		nptr++;
	return (nptr);
}

static size_t	calc(const char *nptr)
{
	size_t res;
	size_t dec;

	res = 0;
	dec = 1;
	nptr = scrolldig((char *)nptr);
	while (ft_isdigit(*--nptr) && *nptr)
	{
		res += (*nptr - 48) * dec;
		dec *= 10;
	}
	return (res);
}

int				ft_atoi(const char *nptr)
{
	int			neg;
	size_t		res;

	res = 0;
	neg = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || *nptr == '\r'\
	|| *nptr == '\v' || *nptr == '\f')
		nptr++;
	if (*nptr == '+')
		if (*(++nptr) == '-')
			return (res);
	if (*nptr == '-')
	{
		nptr++;
		neg = -1;
	}
	res = calc(nptr);
	if (res > 9223372036854775807 && neg > 0)
		return (-1);
	if (res > 9223372036854775807 && neg < 0)
		return (0);
	return (int)(neg * res);
}
