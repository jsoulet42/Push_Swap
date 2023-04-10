/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:53:35 by jsoulet           #+#    #+#             */
/*   Updated: 2023/04/07 10:30:13 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	found_big_len(j_tab **jtab)
{
	int best1;
	int i;
	int pos_big_len;

	if (!jtab || !jtab[0])
		return (0);

	i = 0;
	best1 = jtab[0]->s_len;
	while (jtab[i])
	{
		if (jtab[i]->s_len >= best1)
		{
			best1 = jtab[i]->s_len;
			pos_big_len = i;
		}
		i++;
	}
	return (pos_big_len);
}

int	found_next_index(j_tab **jtab, int index)
{
	int i;
	int	index_next;

	if (!jtab || !jtab[0] || index == found_index_max(jtab))
		return (0);
	index_next = -1;
	i = 0;
	while (jtab[i])
	{
		if (index_next == -1 && jtab[i]->index > jtab[index]->index)
			index_next = i;
		if (jtab[i]->index > jtab[index]->index && jtab[i]->index < jtab[index_next]->index)
			index_next = i;
		i++;
	}
		return (index_next);
}

int found_index_min(j_tab **jtab) // surement a supprimer
{
	int i;
	int index_min;

	if (!jtab || !jtab[0] || !jtab[1])
		return (0);
	i = 0;
	index_min = found_index_max(jtab);
	while (jtab[i])
	{
		if (jtab[i]->index < jtab[index_min]->index)
			index_min = i;
		i++;
	}
	return(index_min);
}

int	found_index_max(j_tab **jtab) // surement a supprimer
{
	int i;
	int res;

	i = 0;
	res = 0;
	if (!jtab || !jtab[0])
		return (0);
	while (jtab[i])
	{
		if (jtab[i]->index > jtab[res]->index)
			res = i;
		i++;
	}
	return (res);
}
