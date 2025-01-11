/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataan <ataan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:27:28 by ataan             #+#    #+#             */
/*   Updated: 2025/01/11 18:28:49 by ataan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void algo(t_stack *a, t_stack *b)
{
    int mina = *(int *)a->top->content;
    int maxa = *(int *)a->top->content;
    while(a->top != NULL && a->top->next != NULL)
    {
        if (*(int *)a->top->content < *(int *)a->top->next->content)
            swap(a, "sa", 1);
        else
            push(a, b, 'b');
        // if(b->top->next != NULL)
        // {
            if (b->top != NULL && b->top->next != NULL && *(int *)b->top->content > *(int *)b->top->next->content)
                swap(b, "sb", 1);
        // }
    }
    int last = *(int *)a->top->content;
    push(a, b, 'b');
    printf("last %d\n", last);
    int min = *(int *)b->top->content;
    int max = *(int *)b->top->content;
    while(b->top != NULL && b->top->next != NULL)
    {
        // if(*(int *)b->top->content < min)
        // {
        //     rotate(b, "rrb", 1);
        //     min = *(int *)b->top->content;
        // }
        if(*(int *)b->top->content > max)
        {
            r_rotate(b, "rrb", 1);
            max = *(int *)b->top->content;
        }
        // if (*(int *)b->top->content < min)
        // {
        //     rotate(b, "rb", 1);
        //     min = *(int *)b->top->content;
        // }
        if (*(int *)b->top->content > *(int *)b->top->next->content)
            swap(b, "sb", 0);
        else
            push(a, b, 'a');
        if (a->top != NULL && (*(int *)b->top->content < *(int *)a->top->content))
        {
            // printf("<push_swap>\n");
            push(a, b, 'a');
            swap(a,"sa", 1);
            // printf("</push_swap>\n");
        }
        if (a->top != NULL && a->top->next != NULL && *(int *)a->top->content < *(int *)a->top->next->content)
            swap(a, "sa", 0);
        // ft_printf("current value  = %d,\n" ,*(int *)b->top->content);
    }
    push(a, b, 'a');
    while (b->top != NULL)
    {
        push(a, b, 'a');
        if (a->top != NULL && a->top->next != NULL && *(int *)a->top->content < *(int *)a->top->next->content)
            swap(a, "sa", 0);
    }
    
}

/*sorts 3 or 4 numbers in descending order*/
void algo_alaa(t_stack *a, t_stack *b)
{
    int min = *(int *)a->top->content;
    while(a->top != NULL)
    {
        if (b->top == NULL)
            push(a, b, 'b');
        else
        {
            if (*(int *)a->top->content < *(int *)b->top->content)
            {
                if(*(int *)a->top->content < min)
                {
                    min = *(int *)a->top->content;
                    push(a, b, 'b');
                    rotate(b, "rb", 1);
                }
                else
                {
                    push(a, b, 'b');
                    swap(b, "sb", 1);
                }
            }
            else
                push(a, b, 'b');
        }
    }
}
void algo_alaa_5(t_stack *a, t_stack *b)
{
    int min = *(int *)a->top->content;
    while(a->top != NULL)
    {
        if (b->top == NULL)
            push(a, b, 'b');
        else
        {
            if (*(int *)a->top->content < *(int *)b->top->content)
            {
                if(*(int *)a->top->content < min)
                {
                    min = *(int *)a->top->content;
                    push(a, b, 'b');
                    rotate(b, "rb", 1);
                }
                else
                {
                    // ft_printf("min = %d\n", min);
                    // ft_printf("a->top = %d\n", *(int *)a->top->content);
                    // ft_printf("b->top = %d\n", *(int *)b->top->content);
                    // it is not a new min we need to find it a nice place!!
                    if ((*(int *)a->top->content - min) > (*(int *)b->top->content - *(int *)a->top->content))
                    {
                        //it is closer to the top
                        push(a, b, 'b');
                        swap(b, "sb", 1);
                    }
                    else
                    {
                        //it closer to the min
                        r_rotate(b, "rrb", 1);
                        push(a, b, 'b');
                        rotate(b, "rb", 1);
                        rotate(b, "rb", 1);                                                
                    }
                }
            }
            else
                push(a, b, 'b');
        }
    }
}

/*take 4500 moves to sort 100 numbers, uses pb, rb, rrb only*/
void algo_alaa_4500(t_stack *a, t_stack *b)
{
    int min = *(int *)a->top->content;
    int c;
    
    while(a->top != NULL)
    {
        if (b->top == NULL)
            push(a, b, 'b');
        else
        {
            if (*(int *)a->top->content < *(int *)b->top->content)
            {
                if(*(int *)a->top->content < min)
                {
                    min = *(int *)a->top->content;
                    push(a, b, 'b');
                    rotate(b, "rb", 1);
                }
                else
                {
                    c = 0;
                    while(*(int *)b->top->content > *(int *)a->top->content)
                    {
                        rotate(b, "rb", 1);
                        c++;
                    }
                    push(a, b, 'b');
                    while(c > 0)
                    {
                       r_rotate(b, "rrb", 1);
                       c--;
                    }
                }
            }       
            else
                push(a, b, 'b');
        }
    }
}
/*trying a stalin sort, takes 2900 per 100 numbers */
void algo_alaa_stalin(t_stack *a, t_stack *b)
{
    int min = *(int *)a->top->content;
    int max = *(int *)a->top->content;
    // int b_count = 0;
    // int a_count = 0;
    int start = *(int *)a->top->content;
    
    rotate(a, "ra", 1);
    
    while(a->top != NULL && *(int *)a->top->content != start)
    {
        // a_count++;
        if(*(int *)a->top->content > max) //correct order keep it in a
        {
            max = *(int *)a->top->content;
            rotate(a, "ra", 1);
        }
        else
        {
            // TODO: try to order b from here too
            // ft_printf("wrong\n");
            // if((b->top != NULL) && (*(int *)a->top->content < *(int *)b->top->content))
            // {
            //     push(a, b, 'b');
            //     swap(b, "sb", 1);
            // }
            // else
                push(a, b, 'b');
            // b_count++;
        }
    }
        ft_printf("stack a from top = ");
        print_stack(a);
        ft_printf("found max = %d\n", max);
        ft_printf("found min = %d\n", min);
        ft_printf("stack b from top = ");
        print_stack(b);
    // if(b_count > a_count)
        algo_alaa_after_stalin(a, b, min, max);
    // else   
    //     algo_alaa_after_stalin(b, a, min, max);

}
/*after a stalin sort */
void algo_alaa_after_stalin(t_stack *a, t_stack *b, int min, int max)
{
    int c;
    ft_printf("after_stalin\n");
    while(b->top != NULL)
    {   
        if(*(int *)b->top->content < min)
        {
            min = *(int *)b->top->content;
            push(a, b, 'a');
        }
        else 
        {
            if(*(int *)b->top->content - min < max - *(int *)b->top->content)
            {
                // ft_printf("closer to min, b->top = %d, min=%d, max=%d\n", *(int *)b->top->content, min, max);
                c = 0;
                while(*(int *)a->top->content < *(int *)b->top->content)
                {
                    rotate(a, "ra", 1);
                    c++;
                }
                push(a, b, 'a');
                while(c > 0)
                {
                r_rotate(a, "rra", 1);
                c--;
                }
            }
            else
            {
                // ft_printf("closer to max\n");
                r_rotate(a, "rra", 1);
                c = 0;
                while(*(int *)a->top->content > *(int *)b->top->content)
                {
                    r_rotate(a, "rra", 1);
                    c++;
                }
                rotate(a, "ra", 1);
                push(a, b, 'a');
                rotate(a, "ra", 1);
                while(c > 0)
                {
                    rotate(a, "ra", 1);
                    c--;
                }
            }
        }
    }
}

void get_all_four_ends(t_stack *a, t_stack *b)
{
    int a_bottom;
    int b_bottom;
    
    //initialize b
    push(a, b , 'b');
    if(*(int *)b->top->content > *(int *)a->top->content)
    {
        push(a, b, 'b');
        b_bottom = *(int *)b->top->content;
        swap(b, "sb", 1);
    }
    else
    {
        b_bottom = *(int *)b->top->content;
        push(a, b, 'b');
    }
    ft_printf("b top = %d, b bottom = %d\n", *(int *)b->top->content, b_bottom);
    
    //initialize a
    r_rotate(a, "ra", 1);
    a_bottom = *(int *)a->top->content;
    rotate(a, "rra", 1);
    ft_printf("a top = %d, a bottom = %d\n", *(int *)a->top->content, a_bottom);
    

    
        // ft_printf("stack a from top = ");
        // print_stack(a);
        // ft_printf("stack b from top = ");
        // print_stack(b);
}
