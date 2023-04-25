/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:20:33 by julien            #+#    #+#             */
/*   Updated: 2023/04/24 09:05:27 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_tabs(t_tab **tabm, int pos_line, int offset)
{
	int	i;

	i = 0;
	if (offset == 1)
	{
		free(tabm[pos_line]->tabs);
		free(tabm[pos_line]);
		free (tabm);
		return ;
	}
	while (tabm[i])
	{
		if (pos_line != i)
		{
			free(tabm[i]->tabs);
			free(tabm[i]);
		}
		i++;
	}
}

void	clear_jtab(j_tab **jtab)
{
	int	i;

	i = 0;
	while (jtab[i])
	{
		free(jtab[i]->tabs);
		free(jtab[i]->p_line);
		free(jtab[i]->exclu);
		free(jtab[i]->inclu);
		free(jtab[i]->pl_temp);
		free(jtab[i]->excl_2);
		free(jtab[i]);
		i++;
	}
}
