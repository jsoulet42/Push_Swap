/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:50:05 by jsoulet           #+#    #+#             */
/*   Updated: 2023/04/24 15:25:17 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		//pushb_2(a, b, sch_int(id1, (**b)->index), sch_int(id2, (**b)->index));
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


void	manager_friend(t_list **a, t_list **b, j_tab **jtab)
{
	m_tab	*mtab;

	mtab = make_mtab(jtab);
	if (!mtab)
		return ;
	maj_m_tab(jtab, &mtab);
	while (mtab->current1_len != -1 && mtab->current2_len != -1)
	{
		if (push_in_b(&a, &b, mtab->current1, mtab->current2) == 1)
			mtab->current1_len--;
		else if (push_in_b(&a, &b, mtab->current1, mtab->current2) == 2)
			mtab->current2_len--;
		if (mtab->current1_len == 0 || mtab->current2_len == 0)
			maj_m_tab(jtab, &mtab);
	}
	free(mtab);
}


void	maj_m_tab(j_tab **jtab, m_tab **mtab)
{
	if (!*mtab)
		return ;
	if ((*mtab)->current1_len == 0)
	{
		free((*mtab)->current1);
		(*mtab)->current1 = copie_current(make_p_line(jtab));
		(*mtab)->current1_len = p_line_len(jtab, (*mtab)->current1);
	}
	else if ((*mtab)->current2_len == 0)
	{
		free((*mtab)->current2);
		(*mtab)->current2 = copie_current(make_p_line(jtab));
		(*mtab)->current2_len = p_line_len(jtab, (*mtab)->current2);
	}
}

m_tab	*make_mtab(j_tab **jtab)
{
	m_tab	*mtab;
	mtab = (m_tab *)malloc(sizeof(m_tab));
	if (!mtab)
		return (NULL);
	mtab->current1 = copie_current(make_p_line(jtab));
	mtab->current1_len = p_line_len(jtab, mtab->current1);
	mtab->current2 = copie_current(make_p_line(jtab));
	mtab->current2_len = p_line_len(jtab, mtab->current2);

	if(!mtab->current1 || !mtab->current2)
		return (NULL);
	return (mtab);
}

