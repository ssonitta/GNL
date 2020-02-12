/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:08:28 by kchaozu           #+#    #+#             */
/*   Updated: 2020/02/10 22:47:47 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_free_pointer(char **res)
{
	int	i;

	i = 0;
	while ((res)[i])
	{
		free((res)[i]);
		i++;
	}
	free(res);
	res = NULL;
	return (0);
}

void		ft_free_stack(t_stacks *stacks)
{
	free(stacks->a);
	free(stacks->b);
	free(stacks);
}

t_stacks	*ft_clean_all(char **v, t_stacks *first)
{
	ft_free_pointer(v);
	ft_free_stack(first);
	return (NULL);
}
