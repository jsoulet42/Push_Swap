/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:53:35 by jsoulet           #+#    #+#             */
/*   Updated: 2023/04/02 14:53:22 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void algo_note(t_list *a, j_tab **jtab)
{
	int i;

	i = 0;
	while (jtab[i] != NULL)
	{
		jtab[i]->note = algo_note2(a, jtab[i]->index);
		i++;
	}
}

int	algo_note2(t_list *a, int index)
{
	int	i;
	int	j;
	int	rslt;

	i = 0;
	j = 0;
	rslt = 0;
	while (a)
	{
		while(a->next && a->index != index)
		{
			a = a->next;
			i++;
		}
		if (!a->next)
			break ;
		rslt += i - j;
		j = i;
		a = a->next;
		i++;
	}
	return (rslt);
}

void found_best(j_tab **jtab)
{
	int best1;
	int best2;
	int temp;
	int i;

	i = 0;
	best1 = jtab[i]->s_len;
	best2 = jtab[i + 1]->s_len;
	if (best2 > best1)
	{
		temp = best1;
		best1 = best2;
		best2 = temp;
	}
	while (jtab[i])
	{
		if (jtab[i]->s_len > best1 && jtab[i]->s_len > best2)
		{
			best1 = jtab[i]->s_len;
		}
		else if (jtab[i]->s_len > best2 && jtab[i]->s_len < best1)
		{
			best2 = jtab[i]->s_len;
		}
		i++;
	}
	best_is(jtab, best1, best2);
}

void best_is(j_tab **jtab, int best1, int best2)
{
	int i;

	i = 0;
	while (jtab[i])
	{
		if (jtab[i]->s_len == best1)
			jtab[i]->best = 1;
		else if (jtab[i]->s_len == best2)
			jtab[i]->best = 2;
		i++;
	}
}
