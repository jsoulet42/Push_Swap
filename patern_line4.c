/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patern_line4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:42:17 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/24 12:54:52 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	found_index(t_jtb **jtab, int index)
{
	int	i;

	i = 0;
	while (jtab[i])
	{
		if (jtab[i]->index == index)
			return (i);
		i++;
	}
	return (-1);
}

int	*copie_current(t_jtb **jtab, int *current)
{
	int	i;
	int	*new;

	i = tab_len(current);
	new = (int *)malloc(sizeof(int) * (i + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (current[i] != -1)
	{
		new[i] = jtab[current[i]]->index;
		i++;
	}
	new[i] = -1;
	return (new);
}

int	jtab_len(t_jtb **jtab)
{
	int	i;

	i = 0;
	while (jtab[i])
		i++;
	return (i);
}

void	clear_pl_temp(int *pl_temp, int i)
{
	while (pl_temp[i] != -1)
	{
		pl_temp[i] = -1;
		i++;
	}
}

int	tab_len(int *tab)
{
	int	i;

	i = 0;
	while (tab[i] != -1)
		i++;
	return (i);
}
