/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:57:56 by julien            #+#    #+#             */
/*   Updated: 2023/05/23 10:05:22 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{
	t_list	*temp1;

	if (!a || !(*a)->next)
		return ;
	temp1 = (*a)->next;
	(*a)->next = temp1->next;
	temp1->next = *a;
	*a = temp1;
}

void	ft_ss(t_list ***a, t_list ***b, int ist)
{
	if (ist == 1)
	{
		if (!a || !(**a) || !(**a)->next)
			return ;
		sa(*a);
		ft_list_instruction(9);
	}
	if (ist == 2)
	{
		if (!b || !(*b) || !(**b)->next)
			return ;
		sa(*b);
		ft_list_instruction(10);
	}
	if (ist == 3)
	{
		if (!a || !b || !(**a) || !(**b))
			return ;
		sa(*a);
		sa(*b);
		ft_list_instruction(11);
	}
}

void	pa(t_list **a, t_list **b)
{
	t_list	*temp;

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
		ft_list_instruction(8);
	}
	else if (ist == 2)
	{
		if (!b || !(**b))
			return ;
		pa(*a, *b);
		ft_list_instruction(7);
	}
}

void	ra(t_list **a)
{
	t_list	*temp;
	t_list	*last;

	if (!a || !(*a)->next)
		return ;
	temp = *a;
	last = ft_lstlast(*a);
	*a = (*a)->next;
	last->next = temp;
	temp->next = NULL;
}
