/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:38:58 by mdiamant          #+#    #+#             */
/*   Updated: 2023/03/24 16:05:43 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    make_index(t_tab *t, t_list **b)
{
    t_list  *temp;
    int     i;

    if (!b || !*b)
        return ;
    temp =  b;
    while (temp)
    {
        i = 0;
        while (i < t->lens)
        {
            if (temp->content > t->tabs[i] && temp->content < t->tabs[i + 1])
                temp->index = i * 2;
            i++;
        }
        temp = temp->next;
    }
}