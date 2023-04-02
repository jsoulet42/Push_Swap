/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_tab2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:40:22 by julien            #+#    #+#             */
/*   Updated: 2023/04/02 14:57:56 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_jtab(t_list *a, j_tab ***jtab, int *tabi,int tabm_len)
{
	int i;

	i = 0;
	mall_jtab(a, jtab, tabi_len(tabi), tabm_len);
	while (tabi[i] != -1)
	{
		(*jtab)[i]->index = tabi[i];
		(*jtab)[i]->s_len = make_jtab2(a, (*jtab)[i], tabi[i]);
		i++;
	}
}

void	mall_jtab(t_list *a, j_tab ***jtab_real, int t_len, int tabm_len)
{
	int	i;
	j_tab	**jtab;

	i = 0;
	jtab = (j_tab **)malloc(sizeof(j_tab *) * (t_len + 1));
	if (!jtab)
		return ;
	*jtab_real = jtab;
	while (i < t_len)
	{
		jtab[i] = (j_tab *)malloc(sizeof(j_tab) * (t_len + 1));
		if (!jtab[i])
			return ;
		jtab[i]->tabs = (int *)malloc(sizeof(int) * ft_lstsize(a) - tabm_len);
		if (!jtab[i]->tabs)
			return ;
		jtab[i]->index = 0;
		jtab[i]->s_len = 0;
		jtab[i]->best = 0;
		i++;
	}
	jtab[i] = NULL;
}

int make_jtab2(t_list *a, j_tab *jtab, int index)
{
	int i;

	i = 0;
	while (a)
	{
		if (a->index == index)
		{
			jtab->tabs[i] = a->content;
			i++;
		}
		a = a->next;
	}
	jtab->tabs[i] = 0;
	return (i);
}

int	tabi_len(int *tabi)
{
	int i;

	i = 0;
	while (tabi[i] != -1)
		i++;
	return (i);
}
