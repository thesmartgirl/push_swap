/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <ataan@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:46:06 by ataan             #+#    #+#             */
/*   Updated: 2025/02/05 18:14:30 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_limits(t_stack a, int *min, int *max);
void	algo_3(t_stack *a, int min, int max);
void	algo_5(t_stack *a, t_stack *b);
void	insertion_sort(t_stack *a, t_stack *b, int min, int max);

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

/*sorts 3 elements in 3 moves*/
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

void	insertion_sort(t_stack *a, t_stack *b, int min, int max)
{
	int	i;

	i = 0;
	while (b->top != NULL)
	{
		if (*(int *)b->top->content < *(int *)a->top->content)
			push(a, b, 'a');
		else
		{
			if (*(int *)b->top->content > max)
			{
				push(a, b, 'a');
				rotate(a, "ra");
			}
			else if (*(int *)b->top->content < min)
				push(a, b, 'a');
			else
			{
				rotate(a, "ra");
				i++;
			}
		}
	}
	while (i-- > 0)
		r_rotate(a, "rra");
}

void	algo_5(t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	while (ft_lstsize(a->top) > 3)
		push(a, b, 'b');
	if (*(int *)b->top->content > *(int *)b->top->next->content)
		swap(b, "sb");
	find_limits(*a, &min, &max);
	algo_3(a, 0, 2);
	insertion_sort(a, b, min, max);
}
