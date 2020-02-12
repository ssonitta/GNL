/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:51:39 by kchaozu           #+#    #+#             */
/*   Updated: 2020/02/11 22:22:23 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stacks	*stack;

	if (argc <= 1)
		return (0);
	else if (argc == 2)
	{
		if (!(stack = ft_first_arg(argv[1])))
		{
			ft_putendl("Error");
			return (0);
		}
	}
	else
	{
		if (!(stack = ft_data(argv + 1, argc - 1)))
		{
			ft_putendl("Error");
			return (0);
		}
	}
	if (!ft_is_sorted(stack))
		ft_sort_start(stack);
	ft_free_stack(stack);
	return (0);
}
