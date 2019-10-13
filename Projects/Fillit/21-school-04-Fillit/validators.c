/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:39:20 by kchaozu           #+#    #+#             */
/*   Updated: 2019/10/13 13:46:23 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

/*
** В этом файле находятся функции проверки корректности поданного поля
** потенциально опусывающего фигуру
*/

/*
** Проверка размера поля фигуры, символа фигуры и корректного разделителя между
** полями фигур.
*/

static int	chars_n_field_v(char *str[])
{
	int i;
	int j;

	i = 0;
	while (i < FIG_FLD_SIZE)
	{
		j = 0;
		while (j < FIG_FLD_SIZE)
		{
			if (str[i][j] != '.' && str[i][j] != '#')
				return (1);
			j++;
		}
		if (str[i++][j])
			return (1);
	}
	if (ft_strlen(str[i]) != 1 && *str[i])
		return (1);
	return (0);
}

/*
** Проверка наличия пустого символа между
** парой символов фигуры. Направление проверки по горизонтали.
** Например .##. - допустимо, а .#.# - нет.
*/

static int	gap_horiz_v(char *str[])
{
	int hor;
	int vert;
	int i;
	int j;

	i = 0;
	while (i < FIG_FLD_SIZE)
	{
		hor = 0;
		vert = 0;
		j = 0;
		while (j < FIG_FLD_SIZE)
		{
			if (str[i][j++] == '#')
			{
				hor++;
				if (vert > 0)
					return (1);
			}
			else if (hor > 0)
				vert++;
		}
		i++;
	}
	return (0);
}

/*
** Проверка наличия пустого символа между
** парой символов фигуры. Направление проверки по вертикали.
** Например:
** .
** #
** #
** . - допустимо, а
**
** .
** #
** .
** # - нет.
*/

static int	gap_vert_v(char *str[])
{
	int hor;
	int vert;
	int i;
	int j;

	i = 0;
	while (i < FIG_FLD_SIZE)
	{
		hor = 0;
		vert = 0;
		j = 0;
		while (j < FIG_FLD_SIZE)
		{
			if (str[j++][i] == '#')
			{
				vert++;
				if (hor > 0)
					return (1);
			}
			else if (vert > 0)
				hor++;
		}
		i++;
	}
	return (0);
}

/*
** Проверка наличия пустого символа между
** парой символов фигуры. Направление проверки по диагонали.
** При наличии 1 диагонального расположения
** (пример диагонального расположения):
** .#
** #. - проверка считается не пройденой.
*/

static int	gap_diag_v(char *str[])
{
	int i;
	int j;
	int cnt;

	i = 0;
	cnt = 0;
	while (i < FIG_FLD_SIZE - 1)
	{
		j = 0;
		while (j < FIG_FLD_SIZE - 1)
		{
			if ((str[i][j] == '#' && str[i + 1][j + 1] == '#' &&\
			str[i][j + 1] == '.' && str[i + 1][j] == '.') ||\
			(str[i][j + 1] == '#' && str[i + 1][j] == '#' &&\
			str[i][j] == '.' && str[i + 1][j + 1] == '.'))
				cnt++;
			if (cnt == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int			validate(char *potencial_figure[])
{
	if (chars_n_field_v(potencial_figure) ||\
	gap_horiz_v(potencial_figure) ||\
	gap_vert_v(potencial_figure) ||\
	gap_diag_v(potencial_figure))
		return (1);
	return (0);
}
