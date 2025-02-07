/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <ataan@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:20:32 by ataan             #+#    #+#             */
/*   Updated: 2025/02/05 18:15:18 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	int_check(char *snum);
void	check_av(char **av);
void	load_stack(t_stack *stack_x, char **av);
bool	has_duplicates(t_stack *stack);
void	check_args(int ac, char **av, t_stack *stack_x);

/*
    takes a string representing a number (snum) 
	and checks if it can fit in an integer variable
*/
void	int_check(char *snum)
{
	int				i;
	long long int	num;

	i = 0;
	num = 0;
	while (snum[i])
	{
		num = num * 10 + (snum[i] - '0');
		i++;
	}
	if (num >= INT_MAX)
		ft_close("number is greater than INT_MAX");
}

/*
    makes sure av contains only digits, spaces and - sign
    makes sure the numbers in av can fit in an integer
*/
void	check_av(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != ' ' && av[i][j] != '-')
				ft_close("its not a digit");
			j++;
		}
		int_check(av[i]);
		i++;
	}
}

/*
    loads the list of numbers from av into the stack
*/
void	load_stack(t_stack *stack_x, char **av)
{
	int	i;
	int	num;
	int	*num_ptr;

	i = 1;
	while (av[i])
	{
		num = ft_atoi(av[i]);
		num_ptr = malloc(sizeof(int));
		*num_ptr = num;
		ft_lstadd_back(&stack_x->top, ft_lstnew(num_ptr));
		i++;
	}
}

/*
    Function to check for duplicates in a stack
*/
bool	has_duplicates(t_stack *stack)
{
	t_list	*outer;
	t_list	*inner;

	if (!stack || !stack->top)
		return (false);
	outer = stack->top;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			if (*(int *)(outer->content) == *(int *)(inner->content))
				return (true);
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (false);
}

/*
    the following arg checks are performed:
    - if no numbers are provided, exit and retrun the prompt to user
    - check_av: 
        make sure only digits, spaces, and - sign are entered. 
        make sure the numbers will fit in an int.
    - load the numbers to the stack and verify it has no duplicates:
        if dupes are found, free the stack, print error, and exit
*/
void	check_args(int ac, char **av, t_stack *stack_x)
{
	if (ac == 1)
		exit(EXIT_FAILURE);
	check_av(av);
	load_stack(stack_x, av);
	if (has_duplicates(stack_x))
	{
		free_stack(stack_x);
		ft_close("dupes found.... exiting!");
	}
}
