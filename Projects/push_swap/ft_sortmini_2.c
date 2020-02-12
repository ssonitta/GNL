/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortmini_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 22:15:18 by kchaozu           #+#    #+#             */
/*   Updated: 2020/02/11 22:28:01 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_sort_mini3(t_stacks *stack)
{
	int		res;
	int		size;

	if (!stack)
		return ;
	size = stack->size_a;
	res = ft_compare(stack->a[size - 1], stack->a[size - 2], \
	stack->a[size - 3]);
	if (res == 0)
	{
		ft_sa(stack, 0);
		ft_rra(stack, 0);
	}
	if (res == 1)
		ft_ra(stack, 0);
	if (res == 2)
	{
		ft_rra(stack, 0);
		ft_sa(stack, 0);
	}
	if (res == 3)
		ft_rra(stack, 0);
	if (res == 4)
		ft_sa(stack, 0);
}

void		ft_sort_simple(t_stacks *stack)
{
	int	size;
	int middle;
	int	ret;
	int rot;
	int res;

	size = stack->size_a;
	middle = ft_find_median(stack->a, stack->size_a);
	ret = 0;
	rot = 0;
	while (size > 0)
	{
		if (stack->a[stack->size_a - 1] < middle)
		{
			ft_pb(stack, 0);
			ret++;
		}
		else if (stack->a[stack->size_a - 1] >= middle)
			ft_ra(stack, 0);
		size--;
	}
	ft_sort_mini3(stack);
	ft_sort_b(stack);
	while (--ret >= 0)
		ft_pa(stack, 0);
}

void		ft_sort_start(t_stacks *stack)
{
	if (stack->size_a == 3)
		ft_sort_mini3(stack);
	else if (stack->size_a == 2)
		ft_sort_a(stack);
	else if (stack->size_a == 5)
		ft_sort_simple(stack);
	else
		ft_sorta(stack, stack->size_a);
}
