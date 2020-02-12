/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:16:20 by kchaozu           #+#    #+#             */
/*   Updated: 2020/02/10 22:15:56 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_ra(t_stacks *stack, int flag)
{
	int		size;
	int		el;
	int		n;

	if (!stack)
		return (0);
	if ((size = stack->size_a) > 1)
	{
		n = 0;
		while (n < size)
		{
			el = stack->a[size - 1];
			stack->a[size - 1] = stack->a[n];
			stack->a[n] = el;
			n++;
		}
	}
	if (!flag)
		ft_putendl("ra");
	return (1);
}

int		ft_rb(t_stacks *stack, int flag)
{
	int		size;
	int		el;
	int		n;

	if (!stack)
		return (0);
	if ((size = stack->size_b) > 1)
	{
		n = 0;
		while (n < size)
		{
			el = stack->b[size - 1];
			stack->b[size - 1] = stack->b[n];
			stack->b[n] = el;
			n++;
		}
	}
	if (!flag)
		ft_putendl("rb");
	return (1);
}
