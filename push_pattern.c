/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pattern.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:10:08 by jsoulet           #+#    #+#             */
/*   Updated: 2023/04/07 12:05:50 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	found_best_index(j_tab **jtab, int best) // a modifier
{
	int	i;
	int index_best1;

	i = 0;
	while (jtab[i])
	{
		if (jtab[i]->best == best)
			index_best1 = jtab[i]->index;

		i++;
	}
	return (index_best1);
}*/

void	push_best_index(t_list **a,t_list **b, int index_best1, int index_best2) // a modifier
{
	t_list *tmp;


	// appel de la fonction qui trouve l index du best suivant
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
