/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:44:24 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/25 16:17:33 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_list **a)
{
	t_list	*temp;
	t_list	*last;

	if (!*a || !(*a)->next)
		return ;
	temp = *a;
	last = ft_lstlast(*a);
	*a = (*a)->next;
	last->next = temp;
	temp->next = NULL;
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

void	verif_end(t_list *a)
{
	int	tmp;

	tmp = a->content;
	a = a->next;
	while (a)
	{
		if (tmp > a->content)
		{
			ft_printf("KO\n");
			return ;
		}
		tmp = a->content;
		a = a->next;
	}
	ft_printf("OK\n");
}
