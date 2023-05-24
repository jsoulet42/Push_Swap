/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:50:05 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/24 12:55:19 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_mtab(m_tab **mtab);
int		maj_m_tab(t_jtb **jtab, m_tab **mtab);
void	maj_m_tab_2(t_jtb **jtab, m_tab **mtab);

int	verif(t_list *a)
{
	while (a)
	{
		if (a->index % 2 == 1)
			return (0);
		a = a->next;
	}
	return (1);
}

int	push_in_b(t_list ***a, t_list ***b, int *id1, int *id2)
{
	if ((**a)->index == sch_int(id1, (**a)->index))
	{
		ft_p(a, b, 1);
		pushb_2(a, b, sch_int(id1, (**b)->index), sch_int(id2, (**b)->index));
		return (1);
	}
	else if ((**a)->index == sch_int(id2, (**a)->index))
	{
		ft_p(a, b, 1);
		if ((**a)->index != sch_int(id1, (**a)->index)
			&& (**a)->index != sch_int(id2, (**a)->index))
			ft_rr(a, b, 3);
		else
			ft_rr(a, b, 2);
		return (2);
	}
	else
		ft_rr(a, b, 1);
	return (0);
}

void	pushb_2(t_list ***a, t_list ***b, int id1, int id2)
{
	if (!(**b) || !(**b)->next)
		return ;
	if (((**b)->index == id1 && (**b)->next->index == id1)
		&& ((**b)->content < (**b)->next->content))
	{
		if (((**a)->index == id1 && (**a)->next->index == id1)
			&& ((**a)->content > (**a)->next->content))
			ft_ss(a, b, 3);
	}
	push_in_b_suit2(a, b, id1, id2);
}

void	push_in_b_suit2(t_list ***a, t_list ***b, int id1, int id2)
{
	if (((**b)->index == id1 && (**b)->next->index == id1)
		&& ((**b)->content < (**b)->next->content))
	{
		if (((**a)->index != id1 && (**a)->next->index == id1)
			|| ((**a)->index != id2 && (**a)->next->index == id2))
			ft_ss(a, b, 3);
	}
}

void	manager_friend(t_list **a, t_list **b, t_jtb **jtab)
{
	m_tab	*mtab;
	int		pib;

	mtab = make_mtab(jtab, *a);
	if (!mtab)
		return ;
	while (!verif(*a))
	{
		pib = push_in_b(&a, &b, mtab->current1, mtab->current2);
		if (pib == 1)
			mtab->current1_len--;
		else if (pib == 2)
			mtab->current2_len--;
		if (mtab->current1_len == 0 || mtab->current2_len == 0)
		{
			jtab[0]->a = *a;
			if (mtab->current1_len == 0)
				fill_exclu(*a, jtab, mtab->current2);
			else
				fill_exclu(*a, jtab, mtab->current1);
			if (maj_m_tab(jtab, &mtab) == 1)
				maj_m_tab_2(jtab, &mtab);
		}
	}
	clear_mtab(&mtab);
}
