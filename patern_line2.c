/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patern_line2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:00:44 by jsoulet           #+#    #+#             */
/*   Updated: 2023/04/24 15:12:21 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*make_p_line(j_tab **jtab)
{
	int	i;
	int	j;

	i = 0;
	if (tab_len(jtab[0]->excl_2) == jtab_len(jtab))
		return (NULL);
	while (jtab[i])
	{
		j = 0;
		while (jtab[i]->inclu[j] != -1)
		{
			jtab[i]->p_line = m_p_line(jtab, i, jtab[i]->inclu[j], 1);
			j++;
		}
		i++;
	}
	return(jtab[best_p_line(jtab)]->p_line);
}

int jtab_len(j_tab **jtab)
{
	int	i;

	i = 0;
	while (jtab[i])
		i++;
	return (i);
}

int	*m_p_line(j_tab **jtab, int current, int next, int step)
{
	int	i;
	int	tmp;

	i = 1;
	while (jtab[next]->inclu[i] != -1)
	{
		tmp = sch_int(jtab[current]->inclu, jtab[next]->inclu[i]);
		if (tmp != -1 && sch_int(jtab[current]->pl_temp, tmp) != tmp)
		{
			if (jtab[current]->pl_temp[step + 1] != tmp)
				jtab[current]->pl_temp[step] = tmp;
			m_p_line(jtab, current, tmp, step + 1);
		}
		i++;
	}
	return (best_s_len(jtab, current));
}

void	clear_pl_temp(int *pl_temp, int i)
{
	while (pl_temp[i] != -1)
	{
		pl_temp[i] = -1;
		i++;
	}
}

int	*best_s_len(j_tab **jtab, int current)
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
	if (len_pl_temp == len_pl)
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

int	*chx_best_pl(j_tab **t, int cr)
{
	int	i;
	int	j;
	int	pl_len;
	int	pl_len_tmp;

	pl_len = tab_len(t[cr]->p_line);
	pl_len_tmp = tab_len(t[cr]->pl_temp);
	i = 0;
	j = 0;
	while (t[cr]->inclu[t[i]->index] != t[cr]->p_line[t[pl_len]->index])
		i++;
	while (t[cr]->inclu[t[j]->index] != t[cr]->pl_temp[t[pl_len_tmp]->index])
		j++;
	if (i > j)
	{
		clear_pl_temp(t[cr]->p_line, 0);
		i = 0;
		while (t[cr]->pl_temp[i] != -1)
		{
			t[cr]->p_line[i] = t[cr]->pl_temp[i];
			i++;
		}
	}
	return (t[cr]->p_line);
}

int	tab_len(int *tab)
{
	int	i;

	i = 0;
	while (tab[i] != -1)
		i++;
	return (i);
}

int	sch_int(int *tab, int nb)
{
	int	i;

	i = 0;
	while (tab[i] != -1)
	{
		if (tab[i] == nb)
			return (nb);
		i++;
	}
	return (-1);
}
