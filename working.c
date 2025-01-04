/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   working.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <ataan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:27:28 by ataan             #+#    #+#             */
/*   Updated: 2025/01/04 21:02:40 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void ft_swap_stack (t_stack *stack_x, char *op)
{
    if (!stack_x->top || !stack_x->top->next)
        return;
    printf("%s\n", op);
    void *temp;
    temp = stack_x->top->content;
    stack_x->top->content = stack_x->top->next->content;
    stack_x->top->next->content = temp;

}

void print_stack(t_stack *stack_x)
{
    t_list *current = stack_x->top;
    while (current) {
        printf("%d\n", *(int*)current->content);
        current = current->next;
    }
    // printf("\n");
}

// void ft_init_stack(t_stack *stack_x /* ac av*/)
// {
//     int size = ac - 1;
//     while (size)
//     {
//         ft_lstadd_back(stack_x, ft_lstnew(av[size]));
//         size--;
//     }
// }

void ft_close(char *err)
{
    printf("%s\n",err);
    exit(EXIT_FAILURE);
}

void check_size(char *snum)
{
    int i = 0;
    long long int num = 0;
    while(snum[i])
    {
        num = num * 10 + (snum[i] - '0');
        i++;
    }
    if(num >= INT_MAX)
        ft_close("int is larger than max");
}

void check_av(char **av)
{
    int i;
    int j;
    i = 1;
    while (av[i])
    {
        j = 0;
        while(av[i][j])
        {
            if (!ft_isdigit(av[i][j]) && av[i][j] != ' ' && av[i][j] != '-')
                ft_close("its not a digit");
            j++;
        }
        check_size(av[i]);
        // printf("%s\n", av[i]);
        i++;
    }
}

void	ft_cleanup(char **nums)
{
	int	i;

	i = 0;
	if (nums != NULL)
	{
		while (nums[i])
			free(nums[i++]);
		free(nums);
    }
}

void ft_stack(t_stack *stack_x, int ac, char **av)
{
    char **nums;
    int i = 1;
    ft_printf("%d\n", ac);
    if (ac == 2)
    {
        nums = ft_split(av[1], ' ');
        while (nums[i])
        {
            ft_lstadd_front(stack_x->top->content, ft_lstnew(&nums[i]));
            i++;
        }
        ft_cleanup(nums);
    }
    else
    {
        while(av[i])
        {
            int k = ft_atoi(av[i]);
            int *k_ptr = malloc(sizeof(int));
             *k_ptr = k;
            // ft_printf("k = %d\n", k);
            // stack_x->top = ft_lstnew(&k);
            // printf("test : %d\n", *(int *)stack_x->top->content);
            // t_list *tmp = ft_lstnew(&k);
            // ft_printf("tmp = %d\n", *(int *)tmp->content);
            ft_lstadd_front(&stack_x->top, ft_lstnew(k_ptr));
            i++;
        }
    }
}

void check_args(int ac, char **av, t_stack *stack_x)
{
    if (ac == 1)
        exit(EXIT_FAILURE);
    check_av(av);
    ft_stack(stack_x, ac, av);
    
    // if (ac == 2)
    //     ft_init_stack(stack_x, 's');
    // if (ac > 2)
    //     ft_init_stack(stack_x, 'm');
}

int main(int ac, char **av)
{
    t_stack a;
    check_args(ac, av, &a);
    print_stack(&a);
    

    // a.top = ft_lstnew(&z);
    // a.top->next = ft_lstnew(&b);
    // a.top->next->next = ft_lstnew(&k);
    // a.top->next = NULL;
    // if (*(int*)a.top->content > *(int*)a.top->next->content)
    //     ft_swap_stack(&a, "sa");
    // stack_a.top = &a1;
    // stack_b.top = NULL;
    // printf("%d\n", *(int*)a.top->content);



}