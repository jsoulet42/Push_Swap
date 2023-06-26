/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patern_line3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:19:38 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/29 14:07:42 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	best_p_line(t_jtb **jtab)
{
	int	i;
	int	j;
	int	k;
	int	best;
	int	best_tmp;

	i = -1;
	k = -1;
	best = -1;
	while (jtab[++i])
	{
		j = -1;
		best_tmp = 0;
		while (jtab[i]->p_line[++j] != -1)
		{
			best_tmp += jtab[jtab[i]->p_line[j]]->s_len;
			if (best_tmp > best)
			{
				k = i;
				best = best_tmp;
			}
		}
	}
	return (k);
}

void	rest_s_len(t_jtb **jtab, int *pos_pline)
{
	int	i;

	i = 0;
	while (pos_pline[i] != -1)
	{
		jtab[pos_pline[i]]->s_len = 0;
		clear_pl_temp(jtab[pos_pline[i]]->inclu, 0);
		i++;
	}
	i--;
	while (i > 0)
	{
		clear_pl_temp(jtab[pos_pline[i]]->p_line, 0);
		--i;
	}
}

int	p_line_len(t_jtb **jtab, int *p_line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!p_line)
		return (-1);
	while (p_line[i] != -1)
	{
		len += jtab[found_index(jtab, p_line[i])]->s_len;
		i++;
	}
	return (len);
}

void	copy_pl(t_jtb **jtab, int *pline_current, int dest)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	if (!pline_current)
		return ;
	clear_pl_temp(jtab[dest]->exclu, 0);
	if (pline_current[0] == -1 || !pline_current || jtab[dest]->s_len == 0)
		return ;
	while (pline_current[++i] != -1)
	{
		if (jtab[dest]->index != sch_int(pline_current, jtab[dest]->index))
			jtab[dest]->exclu[j++] = pline_current[i];
	}
	i = -1;
	while (jtab[++i])
	{
		if (jtab[i]->s_len == 0 && jtab[i]->index
			!= sch_int(jtab[dest]->exclu, jtab[i]->index))
			jtab[dest]->exclu[j++] = jtab[i]->index;
	}
}

void	replace_s_len(t_jtb **jtab, t_list *b)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = 0;
	while (jtab[i])
	{
		j = 0;
		tmp = b;
		while (tmp)
		{
			if (jtab[i]->index == tmp->index)
				j++;
			tmp = tmp->next;
		}
		jtab[i]->s_len = j;
		i++;
	}
}
