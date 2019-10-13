/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:48:36 by lronnet           #+#    #+#             */
/*   Updated: 2019/10/13 14:00:57 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Инициализация переменных. Функция создана для целей нормирования.
*/

#include "fillit.h"
#include "libft/libft.h"

static void		init_vars(int *x, int *y, int *curr_fig, int *fig_on_field_cnt)
{
	*x = 0;
	*y = 0;
	*curr_fig = 0;
	*fig_on_field_cnt = 0;
}

/*
** Изменяет координаты вставки неподошедшей фигуры.
*/

static int		try_another_position(int *x, int *y, int *curr_fig, int *fig_on_field_cnt)
{
	*curr_fig = *fig_on_field_cnt;
	if (*x < g_field_size - ((t_figure *)g_fig_links_arr[*curr_fig])->width)
	{
		(*x)++;
	}
	else
	{
		(*y)++;
		*x = g_shift_marker;
	}
	if (*y >= g_field_size)
	{
		if (!g_shift_marker)
			g_shift_marker++;
		else
			return (0);
		init_vars(x, y, curr_fig, fig_on_field_cnt);
		clear_field();
	}
	return (1);
}

/*
** Размещение фигуры на поле.
*/

static int		place_this_figure(int *x, int y, int *curr_fig, int *fig_on_field_cnt)
{
	place_figure(*x, y, (t_figure *)g_fig_links_arr[*curr_fig]);
	*x += ((t_figure *)g_fig_links_arr[*curr_fig])->width - 1;
	(*fig_on_field_cnt)++;
	(*curr_fig)++;
	if (*fig_on_field_cnt == g_fig_list_size)
		return (0);
	return (1);
}

/*
** Размещает фигуры на поле. Если ниодна из перестановок фигур не подошла
** размер поля увеличивается.
*/

static char		**try_better_field(int transp_cnt)
{
	int x;
	int y;
	int curr_fig;
	int	fig_on_field_cnt;

	while (transp_cnt-- > 0)
	{
		init_vars(&x, &y, &curr_fig, &fig_on_field_cnt);
		g_shift_marker = 0;
		while (1)
		{
			if (!(fit_on_figure(x, y, (t_figure *)g_fig_links_arr[curr_fig])))
			{
				if (!place_this_figure(&x, y, &curr_fig, &fig_on_field_cnt))
					return (g_field);
			}
			else if (!try_another_position(&x, &y, &curr_fig, &fig_on_field_cnt))
				break ;
		}
		arr_next_transposition();
		clear_field();
	}
	return (NULL);
}

/*
** Генерация решения.
*/

char			**get_solution(void)
{
	int transp_cnt;

	g_field_size = (int)ft_mathsqrt(4 * g_fig_list_size) - 2;
	transp_cnt = ft_mathfact(g_fig_list_size);
	while (1)
	{
		delete_field();
		g_field_size++;
		get_empty_field();
		if (!(get_fig_links_arr()))
			return (NULL);
		ft_arrinsnsort(g_fig_links_arr, g_fig_list_size, &ft_compasc);
		if (try_better_field(transp_cnt))
			return (g_field);
	}
}
