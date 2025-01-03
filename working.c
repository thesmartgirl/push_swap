/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   working.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <ataan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:27:28 by ataan             #+#    #+#             */
/*   Updated: 2025/01/03 21:05:48 by ataan            ###   ########.fr       */
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

void ft_init_stack(t_stack *stack_x /* ac av*/)
{
    int size = ac - 1;
    while (size)
    {
        ft_lstadd_back(stack_x, ft_lstnew(av[size]));
        size--;
    }
}
int main(void)
{
    t_stack a;
    int z = 1;
    int b = -1;
    // int k = 2;
    a.top = ft_lstnew(&z);
    a.top->next = ft_lstnew(&b);
    // a.top->next->next = ft_lstnew(&k);
    // a.top->next = NULL;
    if (*(int*)a.top->content > *(int*)a.top->next->content)
        ft_swap_stack(&a, "sa");
    // stack_a.top = &a1;
    // stack_b.top = NULL;
    // printf("%d\n", *(int*)a.top->content);
    print_stack(&a);



}