/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_b_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:37:14 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/23 09:37:55 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_mtab(m_tab **mtab)
{
	if ((*mtab)->current1)
		free((*mtab)->current1);
	if ((*mtab)->current2)
		free((*mtab)->current2);
	free(*mtab);
}

int	maj_m_tab(j_tab **jtab, m_tab **mtab)
{
	int	*pos_pline;

	if (!*mtab)
		return (-1);
	if ((*mtab)->current1_len == 0)
	{
		free((*mtab)->current1);
		pos_pline = make_p_line(jtab);
		if (!pos_pline)
		{
			free((*mtab)->current1);
			(*mtab)->current1_len = -1;
		}
		(*mtab)->current1 = copie_current(jtab, pos_pline);
		(*mtab)->current1_len = p_line_len(jtab, (*mtab)->current1);
		rest_s_len(jtab, pos_pline);
	}
	else if ((*mtab)->current2_len == 0)
		return (1);
	return (0);
}

void	maj_m_tab_2(j_tab **jtab, m_tab **mtab)
{
	int	*pos_pline;

	if (!*mtab)
		return ;
	free((*mtab)->current2);
	pos_pline = make_p_line(jtab);
	if (!pos_pline)
	{
		free((*mtab)->current2);
		(*mtab)->current2_len = -1;
	}
	(*mtab)->current2 = copie_current(jtab, pos_pline);
	(*mtab)->current2_len = p_line_len(jtab, (*mtab)->current2);
	rest_s_len(jtab, pos_pline);
}

m_tab	*make_mtab(j_tab **jtab, t_list *a)
{
	m_tab	*mtab;
	int		*pline;

	mtab = (m_tab *)malloc(sizeof(m_tab));
	if (!mtab)
		return (NULL);
	fill_exclu(a, jtab, NULL);
	pline = make_p_line(jtab);
	mtab->current1 = copie_current(jtab, pline);
	mtab->current1_len = p_line_len(jtab, mtab->current1);
	rest_s_len(jtab, pline);
	fill_exclu(a, jtab, mtab->current1);
	pline = make_p_line(jtab);
	mtab->current2 = copie_current(jtab, pline);
	mtab->current2_len = p_line_len(jtab, mtab->current2);
	rest_s_len(jtab, pline);
	if (!mtab->current1 || !mtab->current2)
		return (NULL);
	return (mtab);
}
