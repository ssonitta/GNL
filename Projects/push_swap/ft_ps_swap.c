/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:36:21 by kchaozu           #+#    #+#             */
/*   Updated: 2020/02/10 22:15:23 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_sa(t_stacks *stack, int flag)
{
	int		i;
	int		size;

	size = stack->size_a;
	if (!stack)
		return (0);
	if (stack->size_a >= 2)
	{
		i = stack->a[size - 1];
		stack->a[size - 1] = stack->a[size - 2];
		stack->a[size - 2] = i;
	}
	if (!flag)
		ft_putendl("sa");
	return (1);
}

int		ft_sb(t_stacks *stack, int flag)
{
	int		i;
	int		size;

	size = stack->size_b;
	if (!stack)
		return (0);
	if (stack->size_b >= 2)
	{
		i = stack->b[size - 1];
		stack->b[size - 1] = stack->b[size - 2];
		stack->b[size - 2] = i;
	}
	if (!flag)
		ft_putendl("sb");
	return (1);
}
