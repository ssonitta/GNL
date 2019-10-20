/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures_list_forming.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:02:41 by lronnet           #+#    #+#             */
/*   Updated: 2019/10/19 18:16:13 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** В этом файле находятся функции предназнаяенные для формирования
** списка фигур.
*/

/*
** Инициализация полей структуры новой фигуры. Функция добавлена для
** целей номирования.
*/

void			init_new_figure(t_figure **new_figure, char **new_figure_data)
{
	t_figure	*n_f;

	n_f = *new_figure;
	n_f->x = -1;
	n_f->y = -1;
	n_f->width = -1;
	n_f->height = -1;
	set_figure_coord(n_f, new_figure_data);
}

/*
** Добавление новой фигуры в список фигур. Выделение памяти, формирорвание
** координаты фигуры на поле, инициализация полей структуры фигуры.
*/

int				add_figure_to_list(char **new_figure_data)
{
	static char	curr_symb_inc;
	t_figure	*new_figure;
	int			i;
	int			j;

	i = -1;
	if (!(new_figure = (t_figure *)malloc(sizeof(t_figure))) ||\
	!(new_figure->f_lines = (char **)malloc(sizeof(char *) * FIG_FLD_SIZE)))\
		return (1);
	new_figure->p_symb = 'A' + curr_symb_inc++;
	init_new_figure(&new_figure, new_figure_data);
	while (++i < FIG_FLD_SIZE)
	{
		if (!(new_figure->f_lines[i] = ft_strnew(FIG_FLD_SIZE + 1)))
			return (1);
		j = -1;
		while (++j < FIG_FLD_SIZE)
			if (new_figure_data[i][j] == '#')
				new_figure->f_lines[i][j] = new_figure->p_symb;
	}
	if (!(ft_ll_add_last(&g_figures, new_figure)))
		return (1);
	return (0);
}

/*
** Построчное чтение ввода с диска, валидация и формирование списка фигур.
** *new_figure[i] = 0 - признак конца массива строк образующих фигуру.
*/

t_node			*get_figures(int fd)
{
	char		*new_figure[FIG_FLD_SIZE + 1];
	int			i;
	int			err_flag;
	int			read_result;

	err_flag = 0;
	while (1)
	{
		i = -1;
		while (++i < FIG_FLD_SIZE + 1)
			if ((read_result = ft_gnl(fd, &new_figure[i])) <= 0)
				break ;
		if (!read_result)
			new_figure[FIG_FLD_SIZE] = ft_strnew(0);
		if (read_result < 0 || i < FIG_FLD_SIZE || validate(new_figure) ||\
		add_figure_to_list(new_figure))
			err_flag = 1;
		free_used_mem(new_figure, i, read_result);
		if (!read_result || err_flag)
			break ;
	}
	if (!err_flag)
		return (g_figures);
	return (NULL);
}

void			free_used_mem(char *new_figure[], int i, int read_result)
{
	while (i-- > 0)
		free(new_figure[i]);
	if (!read_result)
		free(new_figure[FIG_FLD_SIZE]);
}
