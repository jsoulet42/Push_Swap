/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patern_line2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:00:44 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/24 12:56:46 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*make_p_line(t_jtb **jtab)
{
	int	i;
	int	j;
	int	best_pl;

	i = 0;
	while (jtab[i])
	{
		j = 0;
		if (jtab[i]->s_len != 0)
		{
			while (jtab[i]->inclu[j] != -1)
			{
				jtab[i]->p_line = m_p_line(jtab, i, jtab[i]->inclu[j], 1);
				j++;
			}
		}
		i++;
	}
	best_pl = best_p_line(jtab);
	if (best_pl == -1)
		return (jtab[0]->inclu);
	return (jtab[best_pl]->p_line);
}

int	*m_p_line(t_jtb **jtab, int current, int next, int step)
{
	int	i;
	int	tmp;

	i = 1;
	while (jtab[next]->inclu[i] != -1)
	{
		tmp = sch_int(jtab[current]->inclu, jtab[next]->inclu[i]);
		if (tmp != -1 && sch_int(jtab[current]->pl_temp, tmp) != tmp)
		{
			jtab[current]->pl_temp[step] = tmp;
			clear_pl_temp(jtab[current]->pl_temp, step + 1);
			m_p_line(jtab, current, tmp, step + 1);
		}
		i++;
	}
	return (best_s_len(jtab, current));
}

int	*best_s_len(t_jtb **jtab, int current)
{
	int	len_pl;
	int	len_pl_temp;
	int	i;

	i = -1;
	len_pl = 0;
	len_pl_temp = 0;
	while (jtab[current]->pl_temp[++i] != -1)
		len_pl_temp += jtab[jtab[current]->pl_temp[i]]->s_len;
	jtab[current]->pl_temp[0] = current;
	i = -1;
	while (jtab[current]->p_line[++i] != -1)
		len_pl += jtab[jtab[current]->p_line[i]]->s_len;
	return (chx_best_pl(jtab, current));
	if (len_pl_temp > len_pl)
	{
		clear_pl_temp(jtab[current]->p_line, 0);
		i = -1;
		while (jtab[current]->pl_temp[++i] != -1)
			jtab[current]->p_line[i] = jtab[current]->pl_temp[i];
	}
	return (jtab[current]->p_line);
}

// division
int	*chx_best_pl(t_jtb **t, int cr)
{
	int		i;
	int		j;
	int		pl_pos;
	int		pl_pos_tmp;
	t_list	*tmp;

	tmp = t[0]->a;
	pl_pos = t[cr]->p_line[tab_len(t[cr]->p_line) - 1];
	pl_pos_tmp = t[cr]->pl_temp[tab_len(t[cr]->pl_temp) - 1];
	if (pl_pos == pl_pos_tmp)
		return (t[cr]->p_line);
	i = 0;
	j = 0;
	while (i < t[pl_pos]->s_len || j < t[pl_pos_tmp]->s_len)
	{
		if (tmp->index == t[pl_pos]->index)
			i++;
		if (tmp->index == t[pl_pos_tmp]->index)
			j++;
		tmp = tmp->next;
	}
	if (i > j)
		chx_best_pl2(t[cr]->pl_temp, t[cr]->p_line, i);
	return (t[cr]->p_line);
}

int	*chx_best_pl2(int *pl_temp, int *p_line, int i)
{
	clear_pl_temp(p_line, 1);
	i = 0;
	while (pl_temp[++i] != -1)
		p_line[i] = pl_temp[i];
	return (p_line);
}
