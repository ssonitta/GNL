/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 12:16:35 by lronnet           #+#    #+#             */
/*   Updated: 2019/10/19 19:03:29 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Печать поля, см. так же комментарий к ф-ци get_empty_field,
** field_opers.c
*/

void			print_field(void)
{
	int			i;
	int			j;
	char		ch;

	ch = '\n';
	i = -1;
	if (!g_field)
		return ;
	while (++i < g_field_size)
	{
		j = -1;
		while (++j < g_field_size)
			if (!g_field[i][j])
				g_field[i][j] = '.';
	}
	i = 0;
	while (i < g_field_size)
	{
		ft_putstr(g_field[i++]);
		ft_putchar(ch);
	}
}

void			free_mem(void)
{
	t_node		*next;
	t_figure	*data;
	int			i;

	while (g_figures)
	{
		next = g_figures->next;
		data = (t_figure *)ft_ll_get_first(&g_figures);
		i = -1;
		while (++i < FIG_FLD_SIZE)
			free(data->f_lines[i]);
		free(data->f_lines);
		free(data);
		g_figures = next;
	}
	i = -1;
	while (g_field && ++i < g_field_size)
		free(g_field[i]);
	free(g_field);
	free(g_fig_links_arr);
}

int				main(int argc, char **argv)
{
	int			my_err_code;
	int			fd;

	my_err_code = 1;
	g_figures = NULL;
	g_field = NULL;
	g_fig_links_arr = NULL;
	if (argc == 2 && (fd = open(argv[1], O_RDONLY)) >= 0 &&\
	get_figures(fd))
	{
		g_fig_list_size = ft_ll_length(g_figures);
		if (get_solution())
		{
			my_err_code = 0;
			print_field();
		}
		close(fd);
	}
	if (my_err_code)
		ft_putstr("error\n");
	free_mem();
	return (my_err_code);
}
