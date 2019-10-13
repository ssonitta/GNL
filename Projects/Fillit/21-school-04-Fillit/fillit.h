/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:03:29 by kchaozu           #+#    #+#             */
/*   Updated: 2019/10/13 13:09:28 by kchaozu          ###   ########.fr       */
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

typedef struct			s_figure
{
	char				p_symb;
	char				**f_lines;
	int					x;
	int					y;
	int					width;
	int					height;
}						t_figure;

/*
** === ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ ===
*/

/*
** Поле для расстановки фигур.
*/
char **g_field;

/*
** Список валидированных фигур (структур, см. выше).
*/
t_node *g_figures;

/*
** Количество фигур для расстановки.
*/
int g_fig_list_size;

/*
** Текущий размер стороны поля для расстановки фигур.
*/
int g_field_size;

/*
** Масссив ссылок на фигуры (находящиеся в списке g_figures). Это сделано
** для оптимизации скорости перебора.
*/
size_t *g_fig_links_arr;

/*
** Счётчик числа фигур размещегнных на поле.
*/
int g_fig_on_field_cnt;

/*
** Маркер сдвига фигуры по оси X. Каждая перестановка (g_fig_links_arr)
** проверяется с начальными координатами по X  - 0 или 1.
*/
int g_shift_marker;

/*
** === ФУНКЦИИ ===
*/

/*
** validators.c
*/
int				validate(char *potencial_figure[]);

/*
** figures_list_forming.c
*/
t_node			*get_figures(char *filename);

/*
** field_opers.c
*/
char			**get_empty_field(void);
char			**clear_field(void);
void			delete_field(void);
int				fit_on_figure(int x, int y, t_figure *figure);
void			place_figure(int x, int y, t_figure *figure);

/*
** solution.c
*/
char			**get_solution(void);

/*
** solution2.c
*/
size_t			*get_fig_links_arr(void);
void			arr_next_transposition(void);
#endif
