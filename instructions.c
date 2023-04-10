/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:57:56 by julien            #+#    #+#             */
/*   Updated: 2023/04/03 12:27:17 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void    ft_ss(t_list ***a, t_list ***b, int ist)
{
	if (ist == 1)
    {
		if (!a || !(**a) || !(**a)->next)
			return ;
		sa(*a);
		printf("sa\n");
	}
	if (ist == 2)
	{
		if (!b || !(*b) || !(**b)->next)
			return ;
		sa(*b);
		printf("sb\n");
	}
	if (ist == 3)
	{
		if (!a || !b || !(**a) || !(**b))
			return ;
		sa(*a);
		sa(*b);
		printf("ss\n");
	}
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

void	ft_p(t_list ***a, t_list ***b, int ist)
{
	if (ist == 1)
	{
		if (!a || !(**a))
			return ;
		pa(*b, *a);
		printf("pb\n");
	}
	else if (ist == 2)
	{
		if (!b || !(**b))
			return ;
		pa(*a, *b);
		printf("pa\n");
	}
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

void    ft_rr(t_list ***a, t_list ***b, int ist)
{
	if (ist == 1)
	{
		if (!a || !(**a))
			return ;
		ra(*a);
		printf("ra\n");
	}
	else if (ist == 2)
	{
		if (!b || !(**b))
			return ;
		ra(*b);
		printf("rb\n");
	}
	else if (ist == 3)
	{
		if (!a || !b || !(**a) || !(**b))
			return ;
		ra(*a);
		ra(*b);
		printf("rr\n");
	}
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

void    ft_rrr(t_list ***a, t_list ***b, int ist)
{
	if (ist == 1)
	{
		if (!a || !(**a))
			return ;
		rra(*a);
		printf("rra\n");
	}
	if (ist == 2)
	{
		if (!b || !(**b))
			return ;
		rra(*b);
		printf("rrb\n");
	}
	if (ist == 3)
	{
		if (!a || !b || !(**a) || !(**b))
			return ;
		rra(*a);
		rra(*b);
		printf("rrr\n");
	}
}
