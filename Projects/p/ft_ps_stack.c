/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:23:46 by kchaozu           #+#    #+#             */
/*   Updated: 2020/02/10 23:08:44 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks		*ft_new_stack(int n)
{
	t_stacks *res;

	if (!(res = (t_stacks *)malloc(sizeof(t_stacks))))
		exit(-1);
	res->a = (int *)malloc(sizeof(int) * n);
	res->b = (int *)malloc(sizeof(int) * n);
	if (!res->a || !res->b)
		exit(-1);
	res->size_a = (int)n;
	res->size_b = 0;
	return (res);
}

static int		*ft_reverse(int *stack, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	if (!stack)
		return (NULL);
	while (i < n / 2)
	{
		j = stack[i];
		stack[i] = stack[n - i - 1];
		stack[n - i - 1] = j;
		i++;
	}
	return (stack);
}

t_stacks		*ft_data(char **stack, int n)
{
	t_stacks	*new;
	int			i;

	new = ft_new_stack(n);
	i = 0;
	while (i < n)
	{
		new->a[i] = ft_atoi(stack[i]);
		if (new->a[i] == 0 && stack[i][0] != '0')
		{
			ft_free_stack(new);
			return (NULL);
		}
		i++;
	}
	new->a = ft_reverse(new->a, new->size_a);
	if (!(ft_check_equal(new->a, new->size_a)))
	{
		ft_free_stack(new);
		return (NULL);
	}
	return (new);
}

t_stacks		*ft_first_arg(char *stack)
{
	t_stacks	*first;
	char		**v;
	int			i;

	if (!(v = ft_strsplit(stack, ' ')))
		return (NULL);
	else
	{
		i = 0;
		while (v[i])
			i++;
		first = ft_new_stack(i);
		i = -1;
		while (v[++i])
		{
			first->a[i] = ft_atoi(v[i]);
			if (first->a[i] == 0 && v[i][0] != '0')
				return (ft_clean_all(v, first));
		}
	}
	first->a = ft_reverse(first->a, first->size_a);
	if (!(ft_check_equal(first->a, first->size_a)))
		return (ft_clean_all(v, first));
	ft_free_pointer(v);
	return (first);
}
