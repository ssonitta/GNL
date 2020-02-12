/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 23:27:53 by kchaozu           #+#    #+#             */
/*   Updated: 2020/02/10 22:14:47 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_check_equal(int *stack, int n)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (i < n)
	{
		while (j < n)
		{
			if (stack[i] == stack[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			ft_is_sorted(t_stacks *stack)
{
	int		i;
	int		size;

	if (!stack || stack->size_b)
		return (0);
	i = 0;
	size = stack->size_a;
	while (i < size - 1)
	{
		if (stack->a[i] < stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
