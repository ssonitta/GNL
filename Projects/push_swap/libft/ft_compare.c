/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:55:03 by kchaozu           #+#    #+#             */
/*   Updated: 2020/02/10 19:56:25 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_compare(int a, int b, int c)
{
	if (a > b && b > c)
		return (0);
	if (a > c && c > b)
		return (1);
	if (b > c && c > a)
		return (2);
	if (b > a && a > c)
		return (3);
	if (c > a && a > b)
		return (4);
	if (c > b && b > a)
		return (5);
	return (-1);
}
