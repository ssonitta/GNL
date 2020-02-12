/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:44:32 by kchaozu           #+#    #+#             */
/*   Updated: 2020/02/12 16:27:59 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_rr(t_stacks *stack, char c, int rr)
{
	if (c == 'a')
	{
		while (rr > 0)
		{
			ft_rra(stack, 0);
			rr--;
		}
	}
	else if (c == 'b')
	{
		while (rr > 0)
		{
			ft_rrb(stack, 0);
			rr--;
		}
	}
	else
		return ;
}

int		ft_expand_a(t_stacks *stack)
{
	int	size;
	int middle;
	int	ret;
	int rot;

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
		{
			ft_ra(stack, 0);
			rot++;
		}
		size--;
	}
	ft_do_rr(stack, 'a', rot);
	return (ret);
}

int		ft_expand_b(t_stacks *stack)
{
	int	size;
	int middle;
	int	ret;
	int rot;

	size = stack->size_b;
	middle = ft_find_median(stack->b, stack->size_b);
	ret = 0;
	rot = 0;
	while (size > 0)
	{
		if (stack->b[stack->size_b - 1] >= middle)
		{
			ft_pa(stack, 0);
			ret++;
		}
		else if (stack->b[stack->size_b - 1] < middle)
		{
			ft_rb(stack, 0);
			rot++;
		}
		size--;
	}
	ft_do_rr(stack, 'b', rot);
	return (ret);
}

void	ft_sorta(t_stacks *stack, int high)
{
	int	res;
	int	*s;
	int	len;

	if (high == 3)
		ft_sort_a3(stack);
	else if (high == 2)
		ft_sort_a(stack);
	else if (high > 3)
	{
		res = ft_expand_a(stack);
		ft_sorta(stack, stack->size_a);
		s = stack->b;
		len = stack->size_b;
		stack->b = s + (len - res);
		stack->size_b = res;
		ft_sortb(stack, res);
		stack->b = s;
		stack->size_b = len;
		while (res > 0)
		{
			ft_pa(stack, 0);
			res--;
		}
	}
}

void	ft_sortb(t_stacks *stack, int high)
{
	int	res;
	int	*s;
	int	len;

	if (high == 3)
		ft_sort_b3(stack);
	else if (high == 2)
		ft_sort_b(stack);
	else if (high > 3)
	{
		res = ft_expand_b(stack);
		ft_sortb(stack, stack->size_b);
		s = stack->a;
		len = stack->size_a;
		stack->a = s + (len - res);
		stack->size_a = res;
		ft_sorta(stack, res);
		stack->a = s;
		stack->size_a = len;
		while (res > 0)
		{
			ft_pb(stack, 0);
			res--;
		}
	}
}
