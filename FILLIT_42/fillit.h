/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:06:22 by lronnet           #+#    #+#             */
/*   Updated: 2019/10/19 18:20:24 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include "libft/ft_gnl.h"
# include "libft/libft.h"

# define FIG_FLD_SIZE 4

/*
** Стуктура для описания фигуры.
*/
typedef struct	s_figure
{
	char		p_symb;
	char		**f_lines;
	int			x;
	int			y;
	int			width;
	int			height;
}				t_figure;

/*
** === ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ ===
*/

/*
** Поле для расстановки фигур.
*/
char			**g_field;

/*
** Список валидированных фигур (структур, см. выше).
*/
t_node			*g_figures;

/*
** Количество фигур для расстановки.
*/
int				g_fig_list_size;

/*
** Текущий размер стороны поля для расстановки фигур.
*/
int				g_field_size;

/*
** Масссив ссылок на фигуры (находящиеся в списке g_figures). Это сделано
** для оптимизации скорости перебора.
*/
size_t			*g_fig_links_arr;

/*
** Счётчик числа фигур размещегнных на поле.
*/
int				g_fig_on_field_cnt;

/*
** === ФУНКЦИИ ===
*/

/*
** validators.c
*/
int				chars_n_field_v(char *str[]);
int				gap_horiz_v(char *str[]);
int				gap_vert_v(char *str[]);
int				gap_diag_v(char *str[]);
int				validate(char *potencial_figure[]);

/*
** figures_list_forming.c
*/
void			init_new_figure(t_figure **new_figure, char **new_figure_data);
int				add_figure_to_list(char **new_figure_data);
t_node			*get_figures(int fd);
void			free_used_mem(char *new_figure[], int i, int read_result);

/*
** figures_list_forming2.c
*/
void			set_figure_coord(t_figure *f_d, char **new_figure_data);
void			set_figure_y_coord(t_figure *f_d, char **new_figure_data);

/*
** field_opers.c
*/
char			**get_empty_field(void);
void			delete_field(void);
void			delete_figure(int x, int y, t_figure *figure);
int				fit_on_figure(int x, int y, int curr_fig);
void			place_figure(int x, int y, t_figure *figure);

/*
** solution.c
*/
void			init_vars(int *x, int *y, int *curr_fig, int *fig_on_field_cnt);
int				step_solution_tree(int x, int y,\
				int fig_on_field_cnt, int curr_fig);
char			**try_better_field(int transp_cnt);
char			**get_solution(void);

/*
** solution2.c
*/
size_t			*get_fig_links_arr(void);
void			arr_next_transposition(void);
int				comp_p_symb(ssize_t e1, ssize_t e2);

#endif
