/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mathsqrt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:10:52 by kchaozu           #+#    #+#             */
/*   Updated: 2019/10/13 15:10:54 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_mathsqrt(int n)
{
	int i;

	i = 1;
	if (n < 0)
		return (-1);
	if (!n)
		return (0);
	while (i * i < n)
		i++;
	if (!(n % i))
		return (i);
	else
		return (n / i);
}
