/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patern_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:03:09 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/24 12:56:47 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_exclu(t_list *a, t_jtb **jtab, int *p_line)
{
	int	i;
	int	k;
	int	index_exclu;

	i = 0;
	if (!a)
		return ;
	while (jtab[i])
	{
		clear_pl_temp(jtab[i]->inclu, 0);
		clear_pl_temp(jtab[i]->p_line, 0);
		clear_pl_temp(jtab[i]->pl_temp, 0);
		clear_pl_temp(jtab[i]->p_line, 0);
		index_exclu = -2;
		copy_pl(jtab, p_line, i);
		k = tab_len(jtab[i]->exclu);
		while (index_exclu != -1)
		{
			index_exclu = found_first_in_a(jtab[i], a);
			jtab[i]->exclu[k] = index_exclu;
			k++;
		}
		i++;
	}
	fill_inclu(jtab);
}

void	fill_inclu(t_jtb **t)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (t[i])
	{
		j = 0;
		k = 0;
		if (t[i]->s_len != 0)
		{
			while (t[k])
			{
				if (t[k]->index != verif_exclu(t[i]->exclu, t[k]->index))
					t[i]->inclu[j++] = k;
				k++;
			}
			t[i]->p_line[0] = i;
			t[i]->pl_temp[0] = i;
		}
		i++;
	}
}

int	found_first_in_a(t_jtb *jtab, t_list *a)
{
	int	temp_len;

	temp_len = jtab->s_len;
	while (a && temp_len > 0)
	{
		if (a->index % 2 == 1 && a->index != jtab->index)
		{
			if (a->index != verif_exclu(jtab->exclu, a->index))
				return (a->index);
		}
		if (a->index == jtab->index)
			temp_len--;
		a = a->next;
	}
	return (-1);
}

int	verif_exclu(int *exclu, int index)
{
	int	i;

	i = 0;
	while (exclu[i] != -1)
	{
		if (exclu[i] == index)
			return (exclu[i]);
		i++;
	}
	return (-1);
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
