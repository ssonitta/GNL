/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrinsnsort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:20:44 by lronnet           #+#    #+#             */
/*   Updated: 2019/10/19 18:23:41 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_arrinsnsort(size_t *arr, size_t n, int (*f)(ssize_t, ssize_t))
{
	size_t	i;
	size_t	j;
	ssize_t	curr;

	i = 1;
	while (i < n)
	{
		curr = *(arr + i);
		j = i;
		while (j > 0 && f(*(arr + j - 1), curr) > 0)
		{
			*(arr + j) = *(arr + j - 1);
			j--;
		}
		*(arr + j) = curr;
		i++;
	}
}
