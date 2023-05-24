/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pattern.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:10:08 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/24 12:40:56 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_order_input(t_list *a)
{
	int	tmp;

	tmp = a->content;
	a = a->next;
	while (a)
	{
		if (a->content < tmp)
			return (1);
		tmp = a->content;
		a = a->next;
	}
	return (0);
}
