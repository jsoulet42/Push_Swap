/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:46:41 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/23 10:05:20 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_list ***a, t_list ***b, int ist)
{
	if (ist == 1)
	{
		if (!a || !(**a))
			return ;
		ra(*a);
		ft_list_instruction(1);
	}
	else if (ist == 2)
	{
		if (!b || !(**b))
			return ;
		ra(*b);
		ft_list_instruction(2);
	}
	else if (ist == 3)
	{
		if (!a || !b || !(**a) || !(**b))
			return ;
		ra(*a);
		ra(*b);
		ft_list_instruction(3);
	}
}

void	rra(t_list **a)
{
	t_list	*temp;
	t_list	*last;

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

void	ft_rrr(t_list ***a, t_list ***b, int ist)
{
	if (ist == 1)
	{
		if (!a || !(**a))
			return ;
		rra(*a);
		ft_list_instruction(4);
	}
	if (ist == 2)
	{
		if (!b || !(**b))
			return ;
		rra(*b);
		ft_list_instruction(5);
	}
	if (ist == 3)
	{
		if (!a || !b || !(**a) || !(**b))
			return ;
		rra(*a);
		rra(*b);
		ft_list_instruction(6);
	}
}

void	ft_list_instruction(int instruction)
{
	static t_list	*list;

	if (instruction > 0)
		ft_lstadd_back(&list, ft_lstnew(instruction));
	else
	{
		ft_lstprint2(list);
		ft_lstclear(&list);
	}
}
