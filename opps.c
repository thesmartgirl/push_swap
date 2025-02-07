/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <ataan@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:15:33 by ataan             #+#    #+#             */
/*   Updated: 2025/02/05 18:15:36 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack_x, char *op);
void	push(t_stack *a, t_stack *b, char op);
void	rotate(t_stack *x, char *op);
void	r_rotate(t_stack *x, char *op);

void	swap(t_stack *stack_x, char *op)
{
	void	*temp;

	if (!stack_x->top || !stack_x->top->next)
		return ;
	ft_printf("%s\n", op);
	temp = stack_x->top->content;
	stack_x->top->content = stack_x->top->next->content;
	stack_x->top->next->content = temp;
}

void	push(t_stack *a, t_stack *b, char op)
{
	t_list	*temp;
	t_list	*temp;

	if (op == 'a')
	{
		if (b->top == NULL)
			return ;
		ft_printf("pa\n");
		ft_lstadd_front(&a->top, ft_lstnew(b->top->content));
		temp = b->top->next;
		free(b->top);
		b->top = temp;
	}
	if (op == 'b')
	{
		if (a->top == NULL)
			return ;
		ft_printf("pb\n");
		ft_lstadd_front(&b->top, ft_lstnew(a->top->content));
		temp = a->top->next;
		free(a->top);
		a->top = temp;
	}
}

void	rotate(t_stack *x, char *op)
{
	t_list	*last;

	if (x->top == NULL || x->top->next == NULL)
		return ;
	ft_printf("%s\n", op);
	last = x->top;
	while (last->next)
		last = last->next;
	last->next = x->top;
	x->top = x->top->next;
	last->next->next = NULL;
}

void	r_rotate(t_stack *x, char *op)
{
	t_list	*last;
	t_list	*tmp;

	if (x->top == NULL || x->top->next == NULL)
		return ;
	ft_printf("%s\n", op);
	last = x->top;
	while (last->next->next)
		last = last->next;
	tmp = last->next;
	tmp->next = x->top;
	last->next = NULL;
	x->top = tmp;
}
