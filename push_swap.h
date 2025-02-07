/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <ataan@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:18:05 by ataan             #+#    #+#             */
/*   Updated: 2025/02/05 17:59:21 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	t_list	*top;
}			t_stack;

void		free_stack(t_stack *stack);
void		clean_array(char **arr);
void		ft_close(char *err);
void		print_stack(t_stack *x);
int			is_sorted(t_stack *x);

void		int_check(char *snum);
void		check_av(char **av);
void		load_stack(t_stack *stack_x, char **av);
bool		has_duplicates(t_stack *stack);
void		check_args(int ac, char **av, t_stack *stack_x);

void		find_limits(t_stack a, int *min, int *max);
void		normalize_stack_range(t_stack *x);
void		algo_3(t_stack *a, int min, int max);
void		algo_5(t_stack *a, t_stack *b);
void		algo(t_stack *a, t_stack *b);

void		swap(t_stack *stack_x, char *op);
void		push(t_stack *a, t_stack *b, char op);
void		rotate(t_stack *x, char *op);
void		r_rotate(t_stack *x, char *op);

#endif
