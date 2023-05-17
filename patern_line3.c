/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patern_line3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:19:38 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/11 13:48:56 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	g_best_p_line = 1;
int	g_copy_pl = 0;*/
int	g_best_p_line_debug2 = 0;

int	chx_bst(j_tab **jtab, int pos1, int pos2, int pl_slen);


int	best_p_line(j_tab **jtab)
{
	int	i;
	int	j;
	int	k;
	int	best;
	int	best_tmp;

	i = -1;
	k = -1;
	best = -1;
	while (jtab[++i])
	{
		j = -1;
		best_tmp = 0;
		while (jtab[i]->p_line[++j] != -1)
		{
			best_tmp += jtab[jtab[i]->p_line[j]]->s_len;
			if (best_tmp > best)
			{
				k = i;
				best = best_tmp;
			}
			else if (best == best_tmp)
			{
				//k = chx_bst(jtab, k, i, best);
				//k = i;
				g_best_p_line_debug2++;
			}
		}
	}
	return (k);
}

int	chx_bst(j_tab **jtab, int pos1, int pos2, int pl_slen)
{

	int	i;
	int	j;
	t_list *tmp;
	int pos;

	i = 0;
	j = 0;
	tmp = jtab[0]->a;

	//print_lst(jtab[0]->a, jtab[tab_len(jtab[pos1]->p_line)]->index, jtab[tab_len(jtab[pos2]->p_line)]->index);
	while (tmp)
	{
		pos = found_index(jtab, tmp->index);
		if (pos == sch_int(jtab[pos1]->p_line, pos))
			i++;
		if (i == pl_slen)
			return (pos1);
		if (pos == sch_int(jtab[pos2]->p_line, pos))
			j++;
		if (j == pl_slen)
			return (pos2);
		tmp = tmp->next;
	}
	ft_printf("Patern_line3 chx_bst\nErreur dans la fonction chx_bst\n");
	exit(0);
	return (0);
}

void	rest_s_len(j_tab **jtab, int *pos_pline)
{
	int	i;

	i = 0;

	/*ft_printf("\n\n\n\n\nrest_s_len = ");
	ft_print_tab(pos_pline);*/
	while (pos_pline[i] != -1)
	{
		jtab[pos_pline[i]]->s_len = 0;
		//ft_printf("jtab[pos_pline[%d]]->s_len = %d\n",i, jtab[pos_pline[i]]->s_len);
		clear_pl_temp(jtab[pos_pline[i]]->inclu, 0);


		//jtab[jtab[pos_p_line]->p_line[i]]->index = 0;
		//clear_pl_temp(jtab[jtab[pos_p_line]->p_line[i]]->inclu, 0);
		i++;
	}
	i--;
	while(i > 0)
	{
		clear_pl_temp(jtab[pos_pline[i]]->p_line, 0);
		--i;
	}
	//jtab[pos_p_line]->index = -2;

	//clear_pl_temp(jtab[pos_p_line]->p_line, 0);


}

/*void	maj_exclu(j_tab **jtab, int pos_pline)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (jtab[i])
	{
		j = tab_len(jtab[i]->excl_2);
		k = -1;
		ft_printf("jt[%d]->excl_2 = ", i);
		ft_print_tab(jtab[i]->excl_2);
		while (jtab[pos_pline]->p_line[++k] != -1)
		{
			if (sch_int(jtab[i]->excl_2, jtab[jtab[pos_pline]->p_line[k]]->index) != jtab[jtab[pos_pline]->p_line[k]]->index)
				jtab[i]->excl_2[j] = jtab[jtab[pos_pline]->p_line[k]]->index;
			j++;
		}
		i++;
	}
}*/

int	*copie_current(j_tab **jtab, int *current)
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

int	p_line_len(j_tab **jtab, int *p_line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!p_line)
		return (-1);
	while (p_line[i] != -1)
	{
		len += jtab[found_index(jtab, p_line[i])]->s_len;
		i++;
	}
	return (len);
}

void	copy_pl(j_tab **jtab, int *pline_current, int dest)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	if (!pline_current)
		return ;

	clear_pl_temp(jtab[dest]->exclu, 0);
	if (pline_current[0] == -1 || !pline_current || jtab[dest]->s_len == 0)
		return ;
	while (pline_current[++i] != -1)
	{
		if (jtab[dest]->index != sch_int(pline_current, jtab[dest]->index))
			jtab[dest]->exclu[j++] = pline_current[i];
	}
	i = -1;
	while (jtab[++i])
	{
		if (jtab[i]->s_len == 0 && jtab[i]->index != sch_int(jtab[dest]->exclu, jtab[i]->index))
				jtab[dest]->exclu[j++] = jtab[i]->index;
	}

}

void	replace_s_len(j_tab **jtab, t_list *b)
{
	int	i;
	int	j;
	t_list *tmp;

	i = 0;
	while (jtab[i])
	{
		j = 0;
		tmp = b;
		while (tmp)
		{
			if (jtab[i]->index == tmp->index)
				j++;
			tmp = tmp->next;
		}
		jtab[i]->s_len = j;
		i++;
	}
}
