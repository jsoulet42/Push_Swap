/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_a_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:39:42 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/23 09:40:18 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_tabs(int *src, int *dest, int len)
{
	int	i;

	if (!src || !dest)
		return ;
	i = -1;
	while (++i < len)
		dest[i] = src[i];
}
