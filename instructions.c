 #include "push_swap.h"

void sa(t_list **a)
{
    t_list  *temp1; 

    if (!a || !(*a)->next)
        return ;
    temp1 = (*a)->next;
    (*a)->next = temp1->next;
    temp1->next = *a;
    *a = temp1;


}
                                            
void    ss(t_list **a, t_list **b)
{
    if (!a || !b || !(*a) || !(*b))
        return ;
    sa(a);
    sa(b);
}

void    pa(t_list **a, t_list **b)
{
    t_list  *temp;

    if (!b || !(*b))
        return ;
    temp = *b;
    *b = (*b)->next;
    temp->next = *a;
    *a = temp;
}

void    pb(t_list **a, t_list **b)
{
    t_list  *temp;

    if (!a || !(*a))
        return ;
    temp = *a;
    *a = (*a)->next;
    temp->next = *b;
    *b = temp;
}

void    ra(t_list **a)
{
    t_list  *temp;
    t_list  *last;

    if (!a || !(*a)->next)
        return ;
    temp = *a;
    last = ft_lstlast(*a);
    *a = (*a)->next;
    last->next = temp;
    temp->next = NULL;
}

void    rr(t_list **a, t_list **b)
{
    if (!a || !b || !(*a) || !(*b))
        return ;
    ra(a);
    ra(b);
}

void    rra(t_list **a)
{
    t_list  *temp;
    t_list  *last;

    if (!a || !(*a)->next)
        return ;
    temp = *a;
    last = ft_lstlast(*a);
    while (temp->next != last)
        temp = temp->next;
    last->next = *a;
    temp->next = NULL;
    *a = last;
}

void    rrr(t_list **a, t_list **b)
{
    if (!a || !b || !(*a) || !(*b))
        return ;
    rra(a);
    rra(b);
}
