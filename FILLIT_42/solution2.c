/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:49:36 by lronnet           #+#    #+#             */
/*   Updated: 2019/10/19 17:34:13 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Второй файл с функциями составляющими содержательную часть проекта.
** Разбито на 2 файла для целей нормирования.
*/

/*
** Компаратор для сортировки массива структур (ссылок на список фигур).
** См. char	**get_solution(void).
*/

int			comp_p_symb(ssize_t e1, ssize_t e2)
{
	if (((t_figure *)e1)->p_symb > ((t_figure *)e2)->p_symb)
		return (1);
	else if (((t_figure *)e1)->p_symb < ((t_figure *)e2)->p_symb)
		return (-1);
	return (0);
}

/*
** Создает массив ссылок на фигуры.
*/

size_t		*get_fig_links_arr(void)
{
	int		i;
	t_node	*l;

	l = g_figures;
	i = 0;
	if (!g_fig_links_arr)
		if (!(g_fig_links_arr =\
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
** Используется алгоритм Нарайаны.
*/

void		arr_next_transposition(void)
{
	int		i;
	int		j;
	int		k;

	i = g_fig_list_size - 2;
	j = g_fig_list_size - 1;
	while (i >= 0 && (((t_figure *)g_fig_links_arr[i])->p_symb >\
	((t_figure *)g_fig_links_arr[i + 1])->p_symb))
		i--;
	if (i == -1)
		return ;
	while ((j >= i + 1 && ((t_figure *)g_fig_links_arr[i])->p_symb >\
	((t_figure *)g_fig_links_arr[j])->p_symb))
		j--;
	ft_swap((ssize_t *)&g_fig_links_arr[i], (ssize_t *)&g_fig_links_arr[j]);
	k = i + 1;
	while (k <= (g_fig_list_size + i) / 2)
	{
		j = g_fig_list_size + i - k;
		ft_swap((ssize_t *)&g_fig_links_arr[k], (ssize_t *)&g_fig_links_arr[j]);
		k++;
	}
}
