/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_sort_a_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:32:23 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/24 12:55:27 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choice_between_500_or_100(t_list *b, int bool)
{
	int	len;

	len = ft_lstsize(b);
	if (bool == 0)
	{
		if (len < 100)
			return (len / 7);
		return (len / 8);
	}
	if (len < 100)
		return ((len / 10) * 9);
	return ((len / 8) * 7);
}

int	found_len_max(t_jtb **jtab)
{
	int	res;
	int	i;

	i = 0;
	while (jtab[i])
	{
		if (jtab[i]->s_len != 0)
		{
			res = i;
			break ;
		}
		i++;
	}
	while (jtab[i])
	{
		if (jtab[i]->s_len < jtab[res]->s_len && jtab[i]->s_len != 0)
			res = i;
		i++;
	}
	return (jtab[res]->index);
}

int	found_index_max(t_list *b)
{
	int	res;

	res = b->index;
	while (b)
	{
		if (b->index > res)
			res = b->index;
		b = b->next;
	}
	return (res);
}

void	open_door(t_list **a, t_list **b, int pos_p)
{
	int		i;
	t_list	*tmp;

	tmp = *a;
	i = 0;
	pos_p = verif_idx_a(*a, pos_p);
	while (tmp->index != pos_p)
	{
		tmp = tmp->next;
		i++;
	}
	if (i > (ft_lstsize(*a) / 2))
		while ((*a)->index != pos_p)
			ft_rrr(&a, &b, 1);
	else if (i <= (ft_lstsize(*a) / 2))
		while ((*a)->index != pos_p)
			ft_rr(&a, &b, 1);
}

int	verif_idx_a(t_list *a, int pos_p)
{
	t_list	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->index == pos_p + 1)
			return (pos_p + 1);
		tmp = tmp->next;
	}
	return (0);
}
