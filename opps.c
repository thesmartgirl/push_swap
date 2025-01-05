#include "push_swap.h"

void swap(t_stack *stack_x, char *op)
{
    if (!stack_x->top || !stack_x->top->next)
        return;
    ft_printf("%s\n", op);
    void *temp;
    temp = stack_x->top->content;
    stack_x->top->content = stack_x->top->next->content;
    stack_x->top->next->content = temp;
}

void push(t_stack *a, t_stack *b, char op)
{
    if(op == 'a')
    {
        if(b->top == NULL)
            return;
        ft_printf("pa\n");
        ft_lstadd_front(&a->top, ft_lstnew(b->top->content));
        t_list *temp = b->top->next;
        free(b->top);
        b->top = temp;
    }
    if(op == 'b')
    {
        if(a->top == NULL)
            return;
        ft_printf("pb\n");
        ft_lstadd_front(&b->top, ft_lstnew(a->top->content));
        t_list *temp = a->top->next;
        free(a->top);
        a->top = temp;
    }
}

// void rotate(t_stack *x, char *op)
// {
//     ft_printf("%s\n", op) ;

//     t_list  temp;
//     temp.content = x->top->content;

//     *(int *)x->top->content = *(int *)x->top->next->content;
    
//     x->top->next->content = temp.content;
// }

void rotate(t_stack *x, char *op)
{
        if(x->top == NULL || x->top->next == NULL)
            return;
        ft_printf("%s\n", op);
        t_list *last = x->top; // stack a
        while(last->next)
            last = last->next; // 9
        
        last->next = x->top; // NULL -> 1 234567891
        x->top = x->top->next; // 1 -> 2 23456789
        last->next->next = NULL; // element 10, 11 = NULL;
}