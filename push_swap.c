/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <ataan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:27:28 by ataan             #+#    #+#             */
/*   Updated: 2025/02/07 15:25:17 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	loops through a stack of positive integers to find its maximum,
	then finds out how many bits are needed to represent it in binary form
	- works only with positive numbers...
	- doesn't matter because we normalize data
*/
static int	get_max_bits(t_stack *x)
{
	t_list	*current;
	int		max;
	int		bits;

	current = x->top;
	max = *(int *)current->content;
	bits = 0;
	while (current)
	{
		if (*(int *)current->content > max)
			max = *(int *)current->content;
		current = current->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

/*
	finds the next minimum value of the stack.
	i.e the next number is ascending order.
*/
static t_list	*get_next_min(t_stack *x)
{
	t_list	*current;
	t_list	*min;

	min = NULL;
	current = x->top;
	while (current)
	{
		if (current->index == -1)
		{
			if (min == NULL)
				min = current;
			else if (*(int *)current->content < *(int *)min->content)
				min = current;
		}
		current = current->next;
	}
	return (min);
}

/*

*/
void	normalize_stack_range(t_stack *x)
{
	t_list	*current;
	int		index;

	current = x->top;
	while (current)
	{
		current->index = -1;
		current = current->next;
	}
	index = 0;
	current = get_next_min(x);
	while (current)
	{
		current->index = index;
		*(int *)current->content = index++;
		current = get_next_min(x);
	}
}

void	algo(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	normalize_stack_range(a);
	i = 0;
	size = ft_lstsize(a->top);
	max_bits = get_max_bits(a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((*(int *)a->top->content >> i) & 1) == 1)
				rotate(a, "ra");
			else
				push(a, b, 'b');
		}
		while (ft_lstsize(b->top) != 0)
			push(a, b, 'a');
		if (is_sorted(a))
			break ;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	int		size;
	int		min;
	int		max;

	a.top = NULL;
	b.top = NULL;
	check_args(ac, av, &a);
	normalize_stack_range(&a);
	size = ft_lstsize(a.top);
	if (!is_sorted(&a))
	{
		if (size == 3)
		{
			find_limits(a, &min, &max);
			algo_3(&a, min, max);
		}
		else if (size == 5)
			algo_5(&a, &b);
		else
			algo(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
}
