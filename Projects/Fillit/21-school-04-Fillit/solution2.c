/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:49:36 by lronnet           #+#    #+#             */
/*   Updated: 2019/10/13 14:21:52 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Создает массив ссылок на фигуры.
*/

#include "fillit.h"
#include "libft/libft.h"

size_t		*get_fig_links_arr(void)
{
	int			i;
	t_node		*l;

	l = g_figures;
	i = 0;
	if (!g_fig_links_arr)
		if (!(g_fig_links_arr =
		(size_t *)malloc(sizeof(size_t) * g_fig_list_size)))
			return (NULL);
	while (l)
	{
		g_fig_links_arr[i++] = (size_t)l->data;
		l = l->next;
	}
	return (g_fig_links_arr);
}

/*
** Генерирует следующую переснановку массива ссылок на фигуры.
*/

void		arr_next_transposition(void)
{
	int		i;
	int		j;

	j = g_fig_list_size - 1;
	i = j - 1;
	while (i >= 0 && (g_fig_links_arr[i] > g_fig_links_arr[i + 1]))
		i--;
	i = i < 0 ? 0 : i;
	while ((g_fig_links_arr[j] < g_fig_links_arr[i]))
		j--;
	ft_swap((ssize_t *)&g_fig_links_arr[i],
	(ssize_t *)&g_fig_links_arr[j]);
	ft_arrinsnsort(&g_fig_links_arr[i + 1],
	g_fig_list_size - i - 1, &ft_compasc);
}
