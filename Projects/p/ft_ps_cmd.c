/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:09:46 by kchaozu           #+#    #+#             */
/*   Updated: 2020/02/10 22:20:39 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_error(void)
{
	ft_putendl("Error");
	return (0);
}

int		ft_select_cmd(char *s, t_stacks *stack, int flag)
{
	if (!ft_strcmp(s, "sa"))
		return (ft_sa(stack, flag));
	else if (!ft_strcmp(s, "sb"))
		return (ft_sb(stack, flag));
	else if (!ft_strcmp(s, "ss"))
		return (ft_sa(stack, flag) + ft_sb(stack, flag));
	else if (!ft_strcmp(s, "pa"))
		return (ft_pa(stack, flag));
	else if (!ft_strcmp(s, "pb"))
		return (ft_pb(stack, flag));
	else if (!ft_strcmp(s, "ra"))
		return (ft_ra(stack, flag));
	else if (!ft_strcmp(s, "rb"))
		return (ft_rb(stack, flag));
	else if (!ft_strcmp(s, "rr"))
		return (ft_ra(stack, flag) + ft_rb(stack, flag));
	else if (!ft_strcmp(s, "rra"))
		return (ft_rra(stack, flag));
	else if (!ft_strcmp(s, "rrb"))
		return (ft_rrb(stack, flag));
	else if (!ft_strcmp(s, "rrr"))
		return (ft_rra(stack, flag) + ft_rrb(stack, flag));
	else
		return (0);
	return (1);
}

int		ft_read(t_stacks *stack, int flag)
{
	char *s;

	while (ft_gnl(0, &s) > 0)
	{
		if (ft_select_cmd(s, stack, flag) == 0)
		{
			ft_error();
			free(s);
			return (-1);
		}
		free(s);
	}
	if (!ft_is_sorted(stack))
		ft_putendl("KO");
	else
		ft_putendl("OK");
	return (1);
}
