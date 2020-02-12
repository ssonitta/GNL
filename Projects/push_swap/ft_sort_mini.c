/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_mini.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:38:13 by kchaozu           #+#    #+#             */
/*   Updated: 2020/02/12 16:26:36 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_sort_a3(t_stacks *stack)
{
	int		res;
	int		size;

	if (!stack)
		return ;
	size = stack->size_a;
	res = ft_compare(stack->a[size - 1], stack->a[size - 2], \
	stack->a[size - 3]);
	if (res == 0 || res == 1 || res == 4)
		ft_sa(stack, 0);
	if (res == 0 || res == 1 || res == 2 || res == 3)
	{
		ft_pb(stack, 0);
		ft_sa(stack, 0);
		ft_pa(stack, 0);
	}
	if (res == 0 || res == 3)
		ft_sa(stack, 0);
}

void		ft_sort_b3(t_stacks *stack)
{
	int		res;
	int		size;

	if (!stack)
		return ;
	size = stack->size_b;
	res = ft_compare(stack->b[size - 1], stack->b[size - 2], \
	stack->b[size - 3]);
	if (res == 5 || res == 2 || res == 3)
		ft_sb(stack, 0);
	if (res == 5 || res == 2 || res == 4 || res == 1)
	{
		ft_pa(stack, 0);
		ft_sb(stack, 0);
		ft_pb(stack, 0);
	}
	if (res == 5 || res == 4)
		ft_sb(stack, 0);
}

void		ft_sort_a(t_stacks *stack)
{
	int		size;

	if (!stack)
		return ;
	size = stack->size_a;
	if (stack->a[size - 1] > stack->a[size - 2])
		ft_sa(stack, 0);
	return ;
}

void		ft_sort_b(t_stacks *stack)
{
	int		size;

	if (!stack)
		return ;
	size = stack->size_b;
	if (stack->b[size - 1] < stack->b[size - 2])
		ft_sb(stack, 0);
	return ;
}
