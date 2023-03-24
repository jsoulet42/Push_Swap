/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiamant <mdiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:38:58 by mdiamant          #+#    #+#             */
/*   Updated: 2023/03/24 14:14:20 by mdiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    make_index(t_list **b, t_tab *t)
{
    t_list  *temp;
    int     i;

    if (!b || !*b)
        return ;
    temp = *b;
    while (temp)
    {
        i = 0;
        while (i < t->lens)
        {
            if (temp->content > t->tabs[i] && temp->content < t->tabs[i + 1])
                temp->index = i;
            i++;
        }
        temp = temp->next;
    }
}