/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <ataan@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:20:41 by ataan             #+#    #+#             */
/*   Updated: 2025/02/04 10:20:41 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack);
void	clean_array(char **arr);
void	ft_close(char *err);
void	print_stack(t_stack *x);
int		is_sorted(t_stack *x);

/*
	prints a stack of decimals starting from the top.
	numbers are separated by a space.
	a new line is added at the end.
*/
void	print_stack(t_stack *x)
{
	t_list	*current;

	current = x->top;
	while (current)
	{
		ft_printf("%d ", *(int *)current->content);
		current = current->next;
	}
	ft_printf("\n");
}

/*
	checks if stack is sorted in ascending order
	return value: 1 for a sorted stack, 0 otherwise
	a stack of 0 to 1 elements is already sorted
*/
int	is_sorted(t_stack *x)
{
	t_list	*current;

	if (!x->top || !x->top->next)
		return (1);
	current = x->top;
	while (current->next != NULL)
	{
		if (*(int *)current->content > *(int *)current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

/*
	prints an err message and exits with EXIT_FAILURE
*/
void	ft_close(char *err)
{
	ft_printf("%s\n", err);
	exit(EXIT_FAILURE);
}

/*
	free the memory allocated to a double char array.
	free all elements.
	free the array pointer.
*/
void	clean_array(char **arr)
{
	int	i;

	i = 0;
	if (arr != NULL)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}

/*
	Function to free all memory in the stack
*/
void	free_stack(t_stack *stack)
{
	t_list	*current;
	t_list	*temp;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	while (current)
	{
		temp = current->next;
		free(current->content);
		free(current);
		current = temp;
	}
	stack->top = NULL;
}
