/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_sort_a_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:35:06 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/24 12:56:36 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choice_p(t_list **a, t_list **b, t_jtb **jtab, int i)
{
	int	*tab_quart;

	if (jtab_len(jtab) > 2)
	{
		i = 0;
		tab_quart = quart(*b, jtab_len(jtab));
		while (i < (tab_len(tab_quart) / 2))
		{
			b_replace(a, b, tab_quart[i]);
			open_door(a, b, (*b)->index);
			sort_p(&a, &b, jtab, found_index(jtab, tab_quart[i++]));
		}
		i = tab_len (tab_quart);
		while (--i >= (tab_len(tab_quart) / 2))
		{
			b_replace(a, b, tab_quart[i]);
			open_door(a, b, (*b)->index);
			sort_p(&a, &b, jtab, found_index(jtab, tab_quart[i]));
		}
		free(tab_quart);
	}
	choice_p_2(a, b, jtab);
}

void	choice_p_2(t_list **a, t_list **b, t_jtb **jtab)
{
	while (*b)
	{
		b_replace(a, b, found_index_max(*b));
		open_door(a, b, (*b)->index);
		sort_p(&a, &b, jtab, found_index(jtab, (*b)->index));
	}
}

int	*quart(t_list *b, int len)
{
	int		*tab_quart;
	int		i;
	int		j;
	int		index_tmp;
	t_list	*tmp;

	i = 0;
	j = 0;
	tmp = b;
	index_tmp = -1;
	tab_quart = (int *)malloc(sizeof(int) * len);
	while (j++ < choice_between_500_or_100(b, 0))
	{
		if (tmp->index != index_tmp)
		{
			index_tmp = tmp->index;
			tab_quart[i++] = tmp->index;
		}
		tmp = tmp->next;
	}
	tab_quart[i] = -1;
	if (ft_lstsize(b) > 100)
		quart2(b, i, index_tmp, &tab_quart);
	return (tab_quart);
}

void	quart2(t_list *tmp, int i, int index_tmp, int **tab_quart)
{
	int	j;
	int	len;
	int	tmp_index2;

	j = 0;
	len = choice_between_500_or_100(tmp, 1);
	while (j < len)
	{
		tmp = tmp->next;
		j++;
	}
	tmp_index2 = tmp->index;
	while (tmp_index2 == tmp->index)
		tmp = tmp->next;
	while (tmp)
	{
		if (tmp->index != index_tmp)
		{
			index_tmp = tmp->index;
			(*tab_quart)[i++] = tmp->index;
		}
		tmp = tmp->next;
	}
	(*tab_quart)[i] = -1;
}
