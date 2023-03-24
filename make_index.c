/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:38:58 by mdiamant          #+#    #+#             */
/*   Updated: 2023/03/24 17:33:30 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    make_index_b(t_tab *t, t_list **b)
{
    t_list  *temp;
    int     i;

    if (!b || !*b || !t || !t->tabs)
        return ;
	temp = *b;
	if (t->lens == 1)
	{
		make_index_b2(t, b);
		return ;
	}
    while (temp)
    {
        i = 0;
        while (i < t->lens)
        {
            if (temp->content > t->tabs[i] && temp->content < t->tabs[i + 1])
                temp->index = i * 2 + 1;
            i++;
        }
		if (temp->content > t->tabs[i - 1])
			temp->index = i * 2 + 1;
        temp = temp->next;
    }
}

void make_index_b2(t_tab *t, t_list **b)
{
	t_list	*temp;
	int		i;

	if (!b || !*b || !t || !t->tabs)
		return ;
	temp = *b;
		while (temp)
		{
			temp->index = 1;
			temp = temp->next;
		}
}

void	make_index_a(t_list **a)
{
	t_list	*temp;
	int		i;

	if (!a || !*a)
		return ;
	temp = *a;
	i = 0;
	while (temp)
	{
		temp->index = i * 2;
		temp = temp->next;
		i++;
	}
}