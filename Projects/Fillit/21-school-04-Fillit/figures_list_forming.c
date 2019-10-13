/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures_list_forming.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:02:41 by lronnet           #+#    #+#             */
/*   Updated: 2019/10/13 13:55:12 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static void	set_figure_y_coord(t_figure *f_d, char **new_figure_data)
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

static void	set_figure_coord(t_figure *f_d, char **new_figure_data)
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

static void	init_new_figure(t_figure **new_figure, char **new_figure_data)
{
	t_figure *n_f;

	n_f = *new_figure;
	n_f->x = -1;
	n_f->y = -1;
	n_f->width = -1;
	n_f->height = -1;
	set_figure_coord(n_f, new_figure_data);
}

static int	add_figure_to_list(char **new_figure_data)
{
	static char		curr_symb_inc;
	t_figure		*new_figure;
	int				i;
	int				j;

	i = 0;
	if (!(new_figure = (t_figure *)malloc(sizeof(t_figure))) ||\
	!(new_figure->f_lines = (char **)malloc(sizeof(char *) * FIG_FLD_SIZE)))\
		return (1);
	new_figure->p_symb = 'A' + curr_symb_inc++;
	while (i < FIG_FLD_SIZE)
	{
		if (!(new_figure->f_lines[i] = ft_strnew(FIG_FLD_SIZE + 1)))
			return (1);
		j = -1;
		while (++j < FIG_FLD_SIZE)
			if (new_figure_data[i][j] == '#')
				new_figure->f_lines[i][j] = new_figure->p_symb;
		i++;
	}
	init_new_figure(&new_figure, new_figure_data);
	if (!(ft_ll_add_first(&g_figures, new_figure)))
		return (1);
	return (0);
}

/*
** *new_figure[i] = 0 - признак конца массива строк образующих фигуру.
*/

t_node		*get_figures(char *filename)
{
	int		fd;
	char	*new_figure[FIG_FLD_SIZE + 1];
	int		i;
	int		err_flag;
	int		read_result;

	err_flag = 0;
	read_result = 0;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL);
	while (1)
	{
		i = -1;
		while (++i < FIG_FLD_SIZE + 1)
			if ((read_result = ft_gnl(fd, &new_figure[i])) < 0)
				break ;
		if (!read_result)
			new_figure[FIG_FLD_SIZE] = ft_strnew(0);
		if (read_result < 0 || validate(new_figure) ||\
		add_figure_to_list(new_figure))
			err_flag = 1;
		i = -1;
		while (++i < FIG_FLD_SIZE + 1)
			free(new_figure[i]);
		if (!read_result || err_flag)
			break ;
	}
	close(fd);
	if (!err_flag)
		return (g_figures);
	return (NULL);
}
