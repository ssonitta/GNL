/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:36:31 by kchaozu           #+#    #+#             */
/*   Updated: 2020/02/12 17:09:06 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft_1/libft.h"
# include "libft_1/ft_gnl.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_stack
{
	int			*a;
	int			*b;
	int			size_a;
	int			size_b;
}				t_stacks;

t_stacks		*ft_clean_all(char **v, t_stacks *first);
t_stacks		*ft_data(char **stack, int n);
int				ft_error();
t_stacks		*ft_new_stack(int n);
int				ft_free_pointer(char **res);
int				ft_sa(t_stacks	*stack, int flag);
int				ft_sb(t_stacks	*stack, int flag);
int				ft_check_equal(int *stack, int n);
int				ft_select_cmd(char *s, t_stacks	*stack, int flag);
static int		*ft_reverse(int *stack, size_t n);
int				ft_pb(t_stacks *stack, int flag);
int				ft_pa(t_stacks *stack, int flag);
int				ft_ra(t_stacks *stack, int		flag);
int				ft_rb(t_stacks *stack, int flag);
int				ft_rra(t_stacks *stack, int		flag);
int				ft_rrb(t_stacks *stack, int flag);
int				ft_is_sorted(t_stacks *stack);
int				ft_expand_b(t_stacks *s);
void			ft_sort_a(t_stacks *stack);
void			ft_sort_b(t_stacks *stack);
int				ft_expand_a(t_stacks *stack);
int				ft_expand_b(t_stacks *s);
int				find_median(int *arr, int n);
void			ft_sort_a3(t_stacks *stack);
void			ft_sort_b3(t_stacks *stack);
void			ft_free_stack(t_stacks *stacks);
int				ft_read(t_stacks	*stack, int		flag);
t_stacks		*ft_first_arg(char *stack);
void			ft_sorta(t_stacks *stack, int high);
void			ft_sortb(t_stacks *stack, int high);
void			ft_sort_simple(t_stacks *stack);
void			ft_sort_start(t_stacks *stack);
void			ft_sort_mini3(t_stacks *stack);

#endif
