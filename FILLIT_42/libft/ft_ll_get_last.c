/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_get_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 10:18:55 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/28 20:32:08 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_ll_get_last(t_node **list)
{
	t_node	*proc;
	void	*data;

	if (!(proc = *list))
		return (NULL);
	while (proc->next)
		proc = proc->next;
	data = (void *)proc->data;
	*list = proc->prev;
	free(proc);
	if (*list)
		(*list)->next = NULL;
	return (data);
}
