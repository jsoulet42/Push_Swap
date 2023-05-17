/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patern_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:03:09 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/01 17:43:24 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	g_fill_exclu_debug = 0;
int	g_fill_exclu_debug2;
int	g_fill_inclu_debug = 0;
int	g_fill_inclu_debug2 = 0;*/

void	fill_exclu(t_list *a, j_tab **jtab, int *p_line)
{
	int	i;
	int	k;
	int	index_exclu;

	//print_tabj(jtab);


	i = 0;
	if (!a)
		return ;
	while (jtab[i])
	{
		clear_pl_temp(jtab[i]->inclu, 0);
		clear_pl_temp(jtab[i]->p_line, 0);
		clear_pl_temp(jtab[i]->pl_temp, 0);
		clear_pl_temp(jtab[i]->p_line, 0);
		index_exclu = -2;
		copy_pl(jtab, p_line, i);
		k = tab_len(jtab[i]->exclu);
		//ft_printf("-----------\nfill_exclu %d\n", g_fill_exclu_debug++);
		//ft_print_tab(jtab[i]->exclu);
		//g_fill_exclu_debug2 = 0;
		while (index_exclu != -1)
		{
			index_exclu = found_first_in_a(jtab[i], a);
			jtab[i]->exclu[k] = index_exclu;
			k++;
			/*if (g_fill_exclu_debug2++ > 1000)
			{
				ft_printf("Boucle infini fill exclu g_fill_exclu_debug2\n");
				exit(0);
			}*/
		}
		//ft_printf("jtab[%d]->exclu = ", i);
		//ft_print_tab(jtab[i]->exclu);
		i++;
	}
	fill_inclu(jtab);
	/*if (g_fill_exclu_debug > 1000)
	{
		ft_printf("Boucle infini fill exclu\n");
		exit(0);
	}*/
}

void	fill_inclu(j_tab **jtab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (jtab[i])
	{
		j = 0;
		k = 0;



		if (jtab[i]->s_len != 0)
		{
			while (jtab[k])
			{
				if (jtab[k]->index != verif_exclu(jtab[i]->exclu, jtab[k]->index))
					jtab[i]->inclu[j++] = k;
				k++;
				//ft_printf("jtab[%d]->inclu = ", k);
				//ft_print_tab(jtab[i]->inclu);
			}
			jtab[i]->p_line[0] = i;
			jtab[i]->pl_temp[0] = i;
		}
		i++;
	}

	/*if(g_fill_inclu_debug2++ < 1)
	{
		print_tabj(jtab);
		ft_printf("\n\n\ng_fill_inclu_debug2\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	}
	if (g_fill_inclu_debug++ > 10000)
	{
		ft_printf("Boucle infini fill_inclu\n");
		exit(0);
	}*/

}

int	found_first_in_a(j_tab *jtab, t_list *a)
{
	int	temp_len;

	temp_len = jtab->s_len;
	while (a && temp_len > 0)
	{
		if (a->index % 2 == 1 && a->index != jtab->index)
		{
			if (a->index != verif_exclu(jtab->exclu, a->index))
				return (a->index);
		}
		if (a->index == jtab->index)
			temp_len--;
		a = a->next;
	}
	return (-1);
}

int	verif_exclu(int *exclu, int index)
{
	int	i;

	i = 0;
	while (exclu[i] != -1)
	{
		if (exclu[i] == index)
			return (exclu[i]);
		i++;
	}
	return (-1);
}

int	sch_int(int *tab, int nb)
{
	int	i;

	i = 0;
	while (tab[i] != -1)
	{
		if (tab[i] == nb)
			return (nb);
		i++;
	}
	return (-1);
}

int	found_index(j_tab **jtab, int index)
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
