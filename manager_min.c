/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiamant <mdiamant@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:32:07 by julien            #+#    #+#             */
/*   Updated: 2023/04/26 10:13:53 by mdiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chearch_add_min(t_list *a, t_tab **tabm)
{
	int	min;

	if (!a)
		return ;
	min = a->content;
	while (a)
	{
		if (min > a->content)
			min = a->content;
		a = a->next;
	}
	if ((*tabm)->tabs[(*tabm)->lens - 1] != min)
	{
		(*tabm)->tabs[(*tabm)->lens] = min;
		(*tabm)->lens++;
	}
}

void	replace_a(t_list **a, t_list **b, int action)
{
	if (action == 0 || action == -1)
		return ;
	ft_p(&a, &b, 1);
	if (action > 0)
	{
		while (action > 0)
		{
			ft_rrr(&a, &b, 1);
			action--;
		}
	}
	else
	{
		while (action < -1)
		{
			ft_rr(&a, &b, 1);
			action++;
		}
	}
	ft_p(&a, &b, 2);
}

int	remontada(t_list **a, t_list **b, int chearch)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = *a;
	while (temp->next)
	{
		if (temp->content == chearch)
			break ;
		i++;
		temp = temp->next;
	}
	return (remontada_2(a, b, chearch, i));
}

int	remontada_2(t_list **a, t_list **b, int chearch, int i)
{
	int		action;

	action = 0;
	if (i <= ft_lstsize(*a) / 2)
	{
		while ((*a)->content != chearch)
		{
			ft_rr(&a, &b, 1);
			++action;
		}
	}
	else
	{
		while ((*a)->content != chearch)
		{
			ft_rrr(&a, &b, 1);
			--action;
		}
	}
	return (action);
}
