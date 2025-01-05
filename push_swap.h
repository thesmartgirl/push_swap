/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <ataan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:18:05 by ataan             #+#    #+#             */
/*   Updated: 2025/01/05 20:17:59 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <limits.h>
#include <stdio.h>
#include "./libft/libft.h"

typedef struct s_node
{
	int			*content;
	struct s_node	*next;
}	t_node;

// typedef struct s_node
// {
//     int data;
//     struct s_node *next;
// } t_node;

typedef struct s_stack
{
    t_list *top;
	t_list *last;
} t_stack;

void ft_swap_stack (t_stack *stack_x, char *op);
void del(void *content);
void push(t_stack *a, t_stack *b, char op);
void rotate(t_stack *x, char *op);

#endif
