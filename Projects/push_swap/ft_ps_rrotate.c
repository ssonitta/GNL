/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:20:03 by kchaozu           #+#    #+#             */
/*   Updated: 2020/02/10 22:15:58 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_rra(t_stacks *stack, int flag)
{
	int		size;
	int		el;
	int		n;

	if (!stack)
		return (0);
	if ((size = stack->size_a) > 1)
	{
		n = 0;
		while (n < size - 1)
		{
			el = stack->a[n];
			stack->a[n] = stack->a[n + 1];
			stack->a[n + 1] = el;
			n++;
		}
	}
	if (!flag)
		ft_putendl("rra");
	return (1);
}

int		ft_rrb(t_stacks *stack, int flag)
{
	int		size;
	int		el;
	int		n;

	if (!stack)
		return (0);
	if ((size = stack->size_b) > 1)
	{
		n = 0;
		while (n < size - 1)
		{
			el = stack->b[n];
			stack->b[n] = stack->b[n + 1];
			stack->b[n + 1] = el;
			n++;
		}
	}
	if (!flag)
		ft_putendl("rrb");
	return (1);
}
