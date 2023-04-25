/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pattern.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:10:08 by jsoulet           #+#    #+#             */
/*   Updated: 2023/04/21 16:07:27 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_best_index(t_list **a,t_list **b, int index_best1, int index_best2)
{
	t_list	*tmp;

	tmp = ft_lstlast(*a);
	while ((*a)->content != tmp->content)
	{
		if ((*a)->index == index_best1)
			ft_p(&a, &b, 1);
		else if ((*a)->index == index_best2)
		{
			ft_p(&a, &b, 1);
			ft_rr(&a, &b, 2);
		}
		else
			ft_rr(&a, &b, 1);
	}
}
