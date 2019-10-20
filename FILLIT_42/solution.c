/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:48:36 by lronnet           #+#    #+#             */
/*   Updated: 2019/10/19 18:19:10 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** В этом файле находится содержательная часть проекта -
** функции предназначенные для поиска решения задачи.
*/

/*
** Инициализация переменных. Функция создана для целей нормирования.
*/

void	init_vars(int *x, int *y, int *curr_fig, int *fig_on_field_cnt)
{
	*x = 0;
	*y = 0;
	*curr_fig = 0;
	*fig_on_field_cnt = 0;
}

/*
** Рекурсивная функция получения решения.
** Алгоритм: Каждая фигура новой перестановки последовательно проверяется
** на возможность вставки. Если вставка по текущим координатам невозможна,
** делается попытка новой вставки со сдвигом вправо или вниз (последовательно
** на одну позицию). Если фигуру вставить не удаётся, происходит возврат по
** стеку вызовов с перемещением предыдущей фигуры вышеописанным способом.
** Если решение таким образом не найдено, генерируется следующая перестановка.
*/

int		step_solution_tree(int x, int y, int fig_on_field_cnt, int curr_fig)
{
	if (fig_on_field_cnt == g_fig_list_size)
		return (0);
	while (x * y < (int)ft_mathpow((g_field_size - 1), 2))
	{
		if (!fit_on_figure(x, y, curr_fig))
		{
			place_figure(x, y, (t_figure *)g_fig_links_arr[curr_fig]);
			if (!step_solution_tree(x + 1, y,\
			fig_on_field_cnt + 1, curr_fig + 1))
				return (0);
			delete_figure(x, y, (t_figure *)g_fig_links_arr[curr_fig]);
		}
		if (++x >= g_field_size)
		{
			x = 0;
			y++;
		}
	}
	return (1);
}

/*
** Размещает фигуры на поле. Если ниодна из перестановок фигур не подошла
** размер поля увеличивается.
*/

char	**try_better_field(int transp_cnt)
{
	int	x;
	int y;
	int curr_fig;
	int	fig_on_field_cnt;

	while (transp_cnt-- > 0)
	{
		init_vars(&x, &y, &curr_fig, &fig_on_field_cnt);
		if (!step_solution_tree(x, y, fig_on_field_cnt, curr_fig))
			return (g_field);
		arr_next_transposition();
	}
	return (NULL);
}

/*
** Генерация решения.
*/

char	**get_solution(void)
{
	int transp_cnt;

	g_field_size = (int)ft_mathsqrt(4 * g_fig_list_size) - 1;
	transp_cnt = ft_mathfact(g_fig_list_size);
	if (!(get_fig_links_arr()))
		return (NULL);
	while (1)
	{
		delete_field();
		g_field_size++;
		get_empty_field();
		ft_arrinsnsort(g_fig_links_arr, g_fig_list_size, &comp_p_symb);
		if (try_better_field(transp_cnt))
			return (g_field);
	}
}
