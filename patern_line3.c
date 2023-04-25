/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patern_line3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:19:38 by jsoulet           #+#    #+#             */
/*   Updated: 2023/04/24 15:41:28 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	best_p_line(j_tab **jtab)
{
	int i;
	int j;
	int k;
	int best;
	int best_tmp;

	i = -1;
	best_tmp = 0;
	while (jtab[++i])
	{
		j = -1;
		while (jtab[i]->p_line[++j] != -1)
		{
			best_tmp += jtab[jtab[i]->p_line[j]]->s_len;
			if (best_tmp > best)
			{
				k = i;
				best = best_tmp;
			}
		}
		maj_exclu(jtab, k);
	}
	return (k);
}

void	maj_exclu(j_tab **jtab, int pos_pline)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (jtab[i])
	{
		j = tab_len(jtab[i]->excl_2);
		k = -1;
		ft_printf("jt[%d]->excl_2 = ", i);
		ft_print_tab(jtab[i]->excl_2);
		while(jtab[pos_pline]->p_line[++k] != -1)
		{
			if (sch_int(jtab[i]->excl_2, jtab[pos_pline]->p_line[k]) != jtab[pos_pline]->p_line[k])
				jtab[i]->excl_2[j] = jtab[pos_pline]->p_line[k];
			j++;
		}
		i++;
	}
}

int	*copie_current(int *current)
{
	int	i;
	int	*new;

	i = 0;
	while (current[i] != -1)
		i++;
	new = (int *)malloc(sizeof(int) * (i + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (current[i] != -1)
	{
		new[i] = current[i];
		i++;
	}
	new[i] = -1;
	return (new);
}

int	p_line_len(j_tab **jtab, int *p_line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!p_line)
		return (-1);
	while (p_line[i] != -1)
	{
		len += jtab[p_line[i]]->s_len;
		i++;
	}
	return (len);
}
