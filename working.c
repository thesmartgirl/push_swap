/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   working.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <ataan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:27:28 by ataan             #+#    #+#             */
/*   Updated: 2025/01/06 19:13:39 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


void print_stack(t_stack *stack_x)
{
    t_list *current = stack_x->top;
    while (current) {
        printf("%d\n", *(int *)current->content);
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

void ft_stack(t_stack *stack_x, int ac, char **av)
{
    char **nums;
    int i = 0;
    if (ac == 2)
    {
        nums = ft_split(av[1], ' ');
        while (nums[i])
        {
            int nnums = ft_atoi(nums[i]);
            int *nnnums = malloc(sizeof(int));
            *nnnums = nnums;
            ft_lstadd_back(&stack_x->top, ft_lstnew(nnnums));
            i++;
        }
        clean_array(nums);
    }
    else
    {
        i = 1;
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
            ft_lstadd_back(&stack_x->top, ft_lstnew(k_ptr));
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
void del(void *content)
{
    if (content)
        free(content);  // Free the dynamically allocated content
}

void algo(t_stack *a, t_stack *b)
{
    // 14367
    //
    while(a->top != NULL && a->top->next != NULL)
    {
        if (*(int *)a->top->content > *(int *)a->top->next->content)
            swap(a, "sa", 1);
        else
            push(a, b, 'b');
        // if(b->top->next != NULL)
        // {
            if (b->top != NULL && b->top->next != NULL && *(int *)b->top->content < *(int *)b->top->next->content)
                swap(b, "sb", 1);
        // }
    }
    int last = *(int *)a->top->content;
    push(a, b, 'b');
    printf("last %d\n", last);
    int min = *(int *)b->top->content;
    while(b->top != NULL && b->top->next != NULL)
    {
        if(*(int *)b->top->content > last)
        {
            r_rotate(b, "rrb", 1);
        }
        if (*(int *)b->top->content < min)
        {
            rotate(b, "rb", 1);
            min = *(int *)b->top->content;
        }
        if (*(int *)b->top->content < *(int *)b->top->next->content)
            swap(b, "sb", 1);
        else
            push(a, b, 'a');
        if (*(int *)b->top->content > *(int *)a->top->content)
        {
            printf("<push_swap>\n");
            push(a, b, 'a');
            swap(a,"sa", 1);
            printf("</push_swap>\n");
        }
        if (a->top != NULL && a->top->next != NULL && *(int *)a->top->content > *(int *)a->top->next->content)
            swap(a, "sa", 1);
        // ft_printf("current value  = %d,\n" ,*(int *)b->top->content);
    }
    push(a, b, 'a');
}

int main(int ac, char **av)
{
    t_stack a = {NULL};
    t_stack b = {NULL};
    
    check_args(ac, av, &a);
    // print_stack(&a);
    // printf("-----------------------------------------------------------------\n");
    algo(&a, &b);
    print_stack(&a);
    // print_stack(&b);

    ft_lstclear(&b.top, del);
    ft_lstclear(&a.top, del); 

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