/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <ataan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:46:06 by ataan             #+#    #+#             */
/*   Updated: 2025/02/07 15:14:08 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_limits(t_stack a, int *min, int *max);
void	algo_3(t_stack *a, int min, int max);
void	algo_5(t_stack *a, t_stack *b);
void	algo_3_desc(t_stack *b, int min, int max);

void	find_limits(t_stack a, int *min, int *max)
{
	*min = *(int *)a.top->content;
	*max = *(int *)a.top->content;
	while (a.top != NULL)
	{
		if (*(int *)a.top->content < *min)
			*min = *(int *)a.top->content;
		else if (*(int *)a.top->content > *max)
			*max = *(int *)a.top->content;
		a.top = a.top->next;
	}
}

/*sorts stak a of 3 elements in 3 moves*/
void	algo_3(t_stack *a, int min, int max)
{
	if (*(int *)a->top->content == min)
	{
		if ((*(int *)a->top->next->content == max))
		{
			rotate(a, "ra");
			swap(a, "sa");
			r_rotate(a, "rra");
		}
		return ;
	}
	else if (*(int *)a->top->content == max)
	{
		rotate(a, "ra");
		if (*(int *)a->top->content != min)
			swap(a, "sa");
		return ;
	}
	else
	{
		if (*(int *)a->top->next->content != max)
			swap(a, "sa");
		else
			r_rotate(a, "rra");
		return ;
	}
}

/*sorts stack b of 3 elements in descending order 3 moves or less*/
void	algo_3_desc(t_stack *b, int min, int max)
{
	if (*(int *)b->top->content == max)
	{
		if ((*(int *)b->top->next->content == min))
		{
			rotate(b, "rb");
			swap(b, "sb");
			r_rotate(b, "rrb");
		}
		return ;
	}
	else if (*(int *)b->top->content == min)
	{
		rotate(b, "rb");
		if (*(int *)b->top->content != max)
			swap(b, "sb");
		return ;
	}
	else
	{
		if (*(int *)b->top->next->content != min)
			swap(b, "sb");
		else
			r_rotate(b, "rrb");
		return ;
	}
}

void	algo_5(t_stack *a, t_stack *b)
{
	while (a->top)
	{
		if (*(int *)a->top->content == 0 || *(int *)a->top->content == 4)
			rotate(a, "ra");
		else
			push(a, b, 'b');
		if (ft_lstsize(b->top) == 3)
			break ;
	}
	if (*(int *)a->top->content < *(int *)a->top->next->content)
	{
		rotate(a, "ra");
	}
	algo_3_desc(b, 1, 3);
	push(a, b, 'a');
	push(a, b, 'a');
	push(a, b, 'a');
	r_rotate(a, "rra");
}
