/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <ataan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:18:05 by ataan             #+#    #+#             */
/*   Updated: 2025/01/04 20:03:53 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <limits.h>
#include "./libft/libft.h"

typedef struct s_node
{
	void			*content;
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
} t_stack;

#endif
