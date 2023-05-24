/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:20:33 by julien            #+#    #+#             */
/*   Updated: 2023/05/24 12:56:29 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_tabs(t_tab **tabm, t_tab **pos_line, int offset)
{
	int	i;

	i = 0;
	if (offset == 1)
	{
		free((*pos_line)->tabs);
		free(*pos_line);
		free (tabm);
		return ;
	}
	while (tabm[i] != NULL)
	{
		if (tabm[i] == *pos_line)
		{
			if (tabm[i + 1] == NULL)
				break ;
			else
				i++;
		}
		free(tabm[i]->tabs);
		free(tabm[i]);
		i++;
	}
}

void	clear_jtab(t_jtb **jtab)
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
	free (jtab);
}
