/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:53:35 by jsoulet           #+#    #+#             */
/*   Updated: 2023/03/31 18:02:52 by jsoulet          ###   ########.fr       */
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
