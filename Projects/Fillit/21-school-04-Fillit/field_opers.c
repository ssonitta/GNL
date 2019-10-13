/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_opers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 12:54:16 by kchaozu           #+#    #+#             */
/*   Updated: 2019/10/13 13:58:35 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Выделяет память и возвращат ссылку на поле требуемой величины.
** ДЛЯ ЦЕЛЕЙ ОПТИМИЗАЦИИ ПУСТЫЕ СЕКТОРЫ ПОЛЯ НЕ ЗАПОЛНЯЮТСЯ СИМВОЛАМИ '.',
** А ОСТАЮТСЯ ПУСТЫМИ (0). ТОЧКИ ДОСТАВЛЯюТСЯ В ГОТОВЫЙ ОТВЕТ ПРИ ПЕЧАТИ
** (см. print_field в main.c).
*/

#include "fillit.h"
#include "libft/libft.h"

char	**get_empty_field(void)
{
	int i;

	i = g_field_size;
	if (!(g_field = (char **)malloc(sizeof(char *) * g_field_size)))
		return (NULL);
	while (--i >= 0)
	{
		if (!(g_field[i] = ft_strnew(g_field_size)))
			return (NULL);
	}
	return (g_field);
}

/*
** Очистка поля.
*/

char	**clear_field(void)
{
	int i;
	int j;

	i = g_field_size;
	if (!g_field)
		return (NULL);
	while (--i >= 0)
	{
		j = 0;
		while (j < g_field_size)
			g_field[i][j++] = 0;
	}
	return (g_field);
}

/*
** Удаление поля с высвобождением памяти.
*/

void	delete_field(void)
{
	int i;

	if (!g_field)
		return ;
	i = g_field_size;
	while (i-- > 0)
		free(g_field[i]);
	free(g_field);
}

/*
** "Примерка" фигуры к очережной позиции на поле. Отсчёт ведётся от
** левого верхнего угла фигуры.
*/

int		fit_on_figure(int x, int y, t_figure *figure)
{
	int i;
	int j;

	i = 0;
	if (!figure || (x + figure->width) > g_field_size ||
		(y + figure->height) > g_field_size)
		return (-1);
	while (i < figure->height)
	{
		j = 0;
		while (j < figure->width)
		{
			if (figure->f_lines[figure->y + i][figure->x + j] &\
			g_field[y + i][x + j])
			{
				return (g_field[y + i][x + j]);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*
** Расположение фигуры на поле.
*/

void	place_figure(int x, int y, t_figure *figure)
{
	int i;
	int j;

	i = 0;
	while (i < figure->height)
	{
		j = 0;
		while (j < figure->width)
		{
			if (figure->f_lines[figure->y + i][figure->x + j])
				g_field[y + i][x + j] = figure->p_symb;
			j++;
		}
		i++;
	}
}
