/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures_list_forming2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:27:14 by lronnet           #+#    #+#             */
/*   Updated: 2019/10/19 17:04:57 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 ** В этом файле находятся функции так же предназнаяенные для формирования
** списка фигур. Выделено для целей нормирования.
*/

/*
** Функция задаёт координату по оси Y фигуры на поле. Функция разъединена
** с функцией set_figure_coord для целей нормирования.
*/

void		set_figure_y_coord(t_figure *f_d, char **new_figure_data)
{
	char	*x;
	int		y;
	int		i;

	y = FIG_FLD_SIZE - 1;
	i = y;
	while (i >= 0)
	{
		if ((x = ft_strrchr(new_figure_data[i], '#')))
		{
			if (f_d->width < 0)
				f_d->height = y - f_d->y;
			if (f_d->width < (x - new_figure_data[i] - f_d->x))
				f_d->width = x - new_figure_data[i] - f_d->x;
		}
		if (f_d->height < 0)
			y--;
		i--;
	}
}

/*
** Функция задаёт координату по оси X фигуры на поле.
*/

void		set_figure_coord(t_figure *f_d, char **new_figure_data)
{
	char	*x;
	int		y;
	int		i;

	i = 0;
	y = 0;
	while (i < FIG_FLD_SIZE)
	{
		if ((x = ft_strchr(new_figure_data[i], '#')))
		{
			if (f_d->x < 0)
				f_d->y = y;
			if (f_d->x < 0 || f_d->x > (x - new_figure_data[i]))
				f_d->x = x - new_figure_data[i];
		}
		if (f_d->x < 0)
			y++;
		i++;
	}
	set_figure_y_coord(f_d, new_figure_data);
	f_d->width++;
	f_d->height++;
}
