/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:12:41 by kchaozu           #+#    #+#             */
/*   Updated: 2020/02/10 22:15:54 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_pb(t_stacks *stack, int flag)
{
	int		el;

	if (!stack)
		return (0);
	if (stack->size_a > 0)
	{
		el = stack->a[stack->size_a - 1];
		(stack->size_b)++;
		stack->b[stack->size_b - 1] = el;
		(stack->size_a)--;
	}
	if (flag == 0)
		ft_putendl("pb");
	return (1);
}

int		ft_pa(t_stacks *stack, int flag)
{
	int		el;

	if (!stack)
		return (0);
	if (stack->size_b > 0)
	{
		el = stack->b[stack->size_b - 1];
		(stack->size_a)++;
		stack->a[stack->size_a - 1] = el;
		(stack->size_b)--;
	}
	if (!flag)
		ft_putendl("pa");
	return (1);
}
