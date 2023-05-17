/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patern_line2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:00:44 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/02 10:17:19 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	g_debug = 0;
int	g_best_s_len_debug = 0;*/

int	*make_p_line(j_tab **jtab)
{
	int	i;
	int	j;
	int best_pl;

	i = 0;
	//ft_printf("\n-----------------------------------------------------\nmake_p_line n %d\n", g_debug);
	//g_debug++;
	/*if (tab_len(jtab[0]->excl_2) == jtab_len(jtab))
		return (NULL);*/
	while (jtab[i])
	{
		j = 0;
		if(jtab[i]->s_len != 0)
		{
			while (jtab[i]->inclu[j] != -1)
			{
				jtab[i]->p_line = m_p_line(jtab, i, jtab[i]->inclu[j], 1);
				j++;
			}
		}
		//ft_printf("test\n");
		i++;
	}
	//ft_printf("\n-----------------------------------------------------\nmake_p_line");
	best_pl = best_p_line(jtab);
	if (best_pl == -1)
		return (jtab[0]->inclu);
	return (jtab[best_pl]->p_line);
}

int	jtab_len(j_tab **jtab)
{
	int	i;

	i = 0;
	while (jtab[i])
		i++;
	return (i);
}

int	*m_p_line(j_tab **jtab, int current, int next, int step)
{
	int	i;
	int	tmp;

	i = 1;
	while (jtab[next]->inclu[i] != -1)
	{
		tmp = sch_int(jtab[current]->inclu, jtab[next]->inclu[i]);
		if (tmp != -1 && sch_int(jtab[current]->pl_temp, tmp) != tmp)
		{
			//if (jtab[current]->pl_temp[step + 1] != tmp)
			jtab[current]->pl_temp[step] = tmp;
			clear_pl_temp(jtab[current]->pl_temp, step + 1);
			m_p_line(jtab, current, tmp, step + 1);
		}
		i++;
	}
	return (best_s_len(jtab, current));
}

void	clear_pl_temp(int *pl_temp, int i)
{
	while (pl_temp[i] != -1)
	{
		pl_temp[i] = -1;
		i++;
	}
}

int	*best_s_len(j_tab **jtab, int current)
{
	int	len_pl;
	int	len_pl_temp;
	int	i;

	i = -1;
	len_pl = 0;
	len_pl_temp = 0;

	/*if (current == 7)
	{
		ft_printf("jtab[%d]->pl_temp = ", current);
		ft_print_tab(jtab[current]->pl_temp);
		ft_printf("jtab[%d]->p_line = ", current);
		ft_print_tab(jtab[current]->p_line);
		ft_printf("\n");
	}*/
	while (jtab[current]->pl_temp[++i] != -1)
		len_pl_temp += jtab[jtab[current]->pl_temp[i]]->s_len;
	jtab[current]->pl_temp[0] = current;
	i = -1;
	while (jtab[current]->p_line[++i] != -1)
		len_pl += jtab[jtab[current]->p_line[i]]->s_len;
	/*if (len_pl_temp == len_pl)
		return (chx_best_pl(jtab, current));*/
	if (len_pl_temp > len_pl)
	{
		clear_pl_temp(jtab[current]->p_line, 0);
		i = -1;
		while (jtab[current]->pl_temp[++i] != -1)
			jtab[current]->p_line[i] = jtab[current]->pl_temp[i];
	}
	/*g_best_s_len_debug++;
	if (g_best_s_len_debug > 1000)
	{= 13

		print_tabj(jtab);
		ft_printf("best_s_len est infini\n");
		ft_printf("\n\nbest_s_len de jtab[%d] = ", current);
		ft_print_tab(jtab[current]->p_line);
		exit (0);
	}*/
	return (jtab[current]->p_line);

}



int	*chx_best_pl(j_tab **t, int cr)
{
	int	i;
	int	j;
	int	pl_pos;
	int	pl_pos_tmp;
	t_list	*tmp;

	tmp = t[0]->a;
	pl_pos = t[cr]->p_line[tab_len(t[cr]->p_line) - 1];
	pl_pos_tmp = t[cr]->pl_temp[tab_len(t[cr]->pl_temp) - 1];
	print_lst(t[0]->a, t[pl_pos]->index, t[pl_pos_tmp]->index);

	if (pl_pos == pl_pos_tmp)
		return (t[cr]->p_line);

	//ft_printf("\n\nchx_best_pl de jtab[%d]\n", cr);
	/*ft_printf("jtab[0]->a = \n");
	print_lst(t[0]->a);*/

	ft_printf("----------\njtab[%d]->p_line = ", cr);
	ft_print_tab(t[cr]->p_line);
	ft_printf("pl_pos = %d\n\n", t[pl_pos]->index);


	ft_printf("jtab[%d]->pl_temp = ", cr);
	ft_print_tab(t[cr]->pl_temp);
	ft_printf("pl_pos_tmp = %d\n----------\n", t[pl_pos_tmp]->index);

	i = 0;
	j = 0;
	while (i < t[pl_pos]->s_len || j < t[pl_pos_tmp]->s_len)
	{
		if (tmp->index == t[pl_pos]->index)
			i++;
		if (tmp->index == t[pl_pos_tmp]->index)
			j++;
		tmp = tmp->next;
	}
	//ft_printf("t[pl_pos]->s_len = %d\nt[pl_pos_tmp]->s_len = %d\n", t[pl_pos]->s_len, t[pl_pos_tmp]->s_len);
	//ft_printf("i = %d\nj = %d\n", i, j);
	if (i > j)
	{
		clear_pl_temp(t[cr]->p_line, 1);
		i = 0;
		while (t[cr]->pl_temp[++i] != -1)
			t[cr]->p_line[i] = t[cr]->pl_temp[i];

		//ft_printf("tr[cr] \n");
	}

	ft_printf("La line qui a ete choisie est : ");
	ft_print_tab(t[cr]->p_line);
	ft_printf("////////////////////////\n");
	return (t[cr]->p_line);
}

int	tab_len(int *tab)
{
	int	i;

	i = 0;
	while (tab[i] != -1)
		i++;
	return (i);
}


void	sch_diff_pline(int *tab1, int *tab2)
{
	int i;

	i = 0;
	while (tab1[i] != -1)
	{
		if (tab1[i] == sch_int(tab2, tab1[i]))
		{
			printf("il y a un index commun dans les 2 p_line\n");
			exit (0);
		}
		i++;
	}
}
