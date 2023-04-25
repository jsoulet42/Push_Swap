/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patern_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:03:09 by jsoulet           #+#    #+#             */
/*   Updated: 2023/04/24 09:22:31 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_exclu(t_list **a, j_tab **jtab)
{
	int	i;
	int	k;
	int	index_exclu;

	i = 0;
	while (jtab[i])
	{
		k = 0;
		index_exclu = -2;
		while (index_exclu != -1)
		{
			index_exclu = found_first_in_a(jtab[i], *a);
			jtab[i]->exclu[k] = index_exclu;
			k++;
		}
		i++;
	}
}

void	fill_inclu(j_tab **jtab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (jtab[i])
	{
		j = 0;
		k = 0;
		while (jtab[k])
		{
			if (jtab[k]->index != verif_exclu(jtab[i]->exclu, jtab[k]->index) &&
				jtab[k]->index != verif_exclu(jtab[i]->excl_2, jtab[k]->index))
				jtab[i]->inclu[j++] = k;
			k++;
		}
		jtab[i]->p_line[0] = i;
		jtab[i]->pl_temp[0] = i;
		i++;
	}
}

int	found_first_in_a(j_tab *jtab, t_list *a)
{
	int	temp_len;

	temp_len = jtab->s_len;
	while (a && temp_len > 0)
	{
		if (a->index % 2 == 1 && a->index != jtab->index
			&& a->index != verif_exclu(jtab->exclu, a->index))
			return (a->index);
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

int	found_index(j_tab **jtab, int index)
{
	int	i;

	i = 0;
	while (jtab[i])
	{
		if (jtab[i]->index == index)
			return (i);
		i++;
	}
	return (-1);
}
