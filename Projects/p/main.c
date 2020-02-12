/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:10:43 by kchaozu           #+#    #+#             */
/*   Updated: 2020/02/11 22:18:58 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stacks	*new;

	if (argc <= 1)
		return (0);
	else if (argc == 2)
	{
		if (!(new = ft_first_arg(argv[1])))
		{
			ft_putendl("Error");
			return (0);
		}
	}
	else
	{
		if (!(new = ft_data(argv + 1, argc - 1)))
		{
			ft_error();
			return (0);
		}
	}
	ft_read(new, 1);
	ft_free_stack(new);
	return (0);
}
