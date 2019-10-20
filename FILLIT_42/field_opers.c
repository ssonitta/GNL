/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_opers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:36:52 by lronnet           #+#    #+#             */
/*   Updated: 2019/10/19 15:47:29 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** В этом файле находятся функции операций с полем и фигурами.
*/

/*
** Выделяет память и возвращат ссылку на поле требуемой величины.
** ДЛЯ ЦЕЛЕЙ ОПТИМИЗАЦИИ ПУСТЫЕ СЕКТОРЫ ПОЛЯ НЕ ЗАПОЛНЯЮТСЯ СИМВОЛАМИ '.',
** А ОСТАЮТСЯ ПУСТЫМИ (0). ТОЧКИ ДОСТАВЛЯюТСЯ В ГОТОВЫЙ ОТВЕТ ПРИ ПЕЧАТИ
** (см. print_field в main.c).
*/

char			**get_empty_field(void)
{
	int			i;

	i = g_field_size;
	if (!(g_field = (char **)malloc(sizeof(char *) * g_field_size)))
		return (NULL);
	while (--i >= 0)
		if (!(g_field[i] = ft_strnew(g_field_size)))
			return (NULL);
	return (g_field);
}

/*
** Удаление поля с высвобождением памяти.
*/

void			delete_field(void)
{
	int			i;

	if (!g_field)
		return ;
	i = g_field_size;
	while (i-- > 0)
		free(g_field[i]);
	free(g_field);
}

/*
** Удаление фигуры с поля.
*/

void			delete_figure(int x, int y, t_figure *figure)
{
	int			i;
	int			j;

	i = -1;
	while (++i < figure->height)
	{
		j = -1;
		while (++j < figure->width)
			if (g_field[y + i][x + j] == figure->p_symb)
				g_field[y + i][x + j] = 0;
	}
}

/*
** "Примерка" фигуры к очережной позиции на поле. Отсчёт ведётся от
** левого верхнего угла фигуры.
*/

int				fit_on_figure(int x, int y, int curr_fig)
{
	int			i;
	int			j;
	t_figure	*figure;

	figure = (t_figure *)g_fig_links_arr[curr_fig];
	if (!figure || (x + figure->width) > g_field_size ||\
	(y + figure->height) > g_field_size)
		return (-1);
	if (y > 0 && !fit_on_figure(x, y - 1, curr_fig))
		return (1);
	i = -1;
	while (++i < figure->height)
	{
		j = -1;
		while (++j < figure->width)
			if (figure->f_lines[figure->y + i][figure->x + j] &\
			g_field[y + i][x + j])
				return (1);
	}
	if (figure->width == 4)
		while (++curr_fig < g_fig_list_size)
			if (((t_figure *)g_fig_links_arr[curr_fig])->p_symb <\
			figure->p_symb)
				return (1);
	return (0);
}

/*
** Расположение фигуры на поле.
*/

void			place_figure(int x, int y, t_figure *figure)
{
	int			i;
	int			j;

	i = -1;
	while (++i < figure->height)
	{
		j = -1;
		while (++j < figure->width)
			if (figure->f_lines[figure->y + i][figure->x + j])
				g_field[y + i][x + j] = figure->p_symb;
	}
}
