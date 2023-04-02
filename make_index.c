/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:38:58 by mdiamant          #+#    #+#             */
/*   Updated: 2023/03/30 11:50:31 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    make_index_b(t_tab *t, t_list **b)
{
    t_list  *temp;
    int     i;
	
	if (!*b || !t || !t->tabs || !b)
		return ;
	temp = *b;
	if (t->lens == 1)
	{
		make_index_b2(t, b);
		return ;
	}
    while (temp)
    {
        i = 1;
        while (i <= t->lens)
        {
            if (temp->content < t->tabs[i - 1] && temp->content > t->tabs[i])
            {
				temp->index = (t->lens - i) * 2 - 1;
				break ;
			}
            i++;
        }
		if (temp->content > t->tabs[0])
			temp->index = t->lens * 2 - 1;
        temp = temp->next;
    }
}

void make_index_b2(t_tab *t, t_list **b)
{
	t_list	*temp;

	if (!b || !*b || !t || !t->tabs)
		return ;
	temp = *b;
		while (temp)
		{
			temp->index = 1;
			temp = temp->next;
		}
}

void	make_index_a(t_tab *tabm, t_list **a)
{
	t_list	*temp;
	int		i;
	int		j;

	if (!a || !*a)
		return ;
	temp = *a;
	i = 0;
	while (temp)
	{
		j = 0;
		while (j < tabm->lens)
		{
			if (temp->content == tabm->tabs[j])
			{
				temp->index = (tabm->lens - j - 1) * 2;
				break ;
			}
			j++;
		}
		temp = temp->next;
		i++;
	}
}