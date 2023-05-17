/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:50:05 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/17 09:28:42 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_mtab(m_tab **mtab);


int	verif(t_list *a)
{
	while (a)
	{
		if (a->index % 2 == 1)
			return (0);
		a = a->next;
	}
	return (1);
}

int	g_push_in_b_debug = 0;

int	push_in_b(t_list ***a, t_list ***b, int *id1, int *id2)
{
	if (g_push_in_b_debug++ == 50000)
	{

		ft_printf("Fonction push_in_b infine\n g_push_in_b_debug = %d\n", g_push_in_b_debug);
		printf("lst a = \n");
		print_lst(**a, -1, -1);
		printf("lst b = \n");
		print_lst(**b, -1, -1);

		ft_printf("\ncurrent 1 = ");
		ft_print_tab(id1);
		ft_printf("current 2 = ");
		ft_print_tab(id2);

		return (-1);
	}
	if ((**a)->index == sch_int(id1, (**a)->index))
	{
		ft_p(a, b, 1);
		pushb_2(a, b, sch_int(id1, (**b)->index), sch_int(id2, (**b)->index));
		return (1);
	}
	else if ((**a)->index == sch_int(id2, (**a)->index))
	{
		ft_p(a, b, 1);
		if ((**a)->index != sch_int(id1, (**a)->index) && (**a)->index != sch_int(id2, (**a)->index))
			ft_rr(a, b, 3);
		else
			ft_rr(a, b, 2);
		return (2);
	}
	else
		ft_rr(a, b, 1);
	return (0);
}

void	pushb_2(t_list ***a, t_list ***b, int id1, int id2)
{
	if (!(**b) || !(**b)->next)
		return ;
	if (((**b)->index == id1 && (**b)->next->index == id1)
		&& ((**b)->content < (**b)->next->content))
	{
		if (((**a)->index == id1 && (**a)->next->index == id1)
			&& ((**a)->content > (**a)->next->content))
			ft_ss(a, b, 3);
	}
	push_in_b_suit2(a, b, id1, id2);
}

void	push_in_b_suit2(t_list ***a, t_list ***b, int id1, int id2)
{
	if (((**b)->index == id1 && (**b)->next->index == id1)
		&& ((**b)->content < (**b)->next->content))
	{
		if (((**a)->index != id1 && (**a)->next->index == id1)
			|| ((**a)->index != id2 && (**a)->next->index == id2))
			ft_ss(a, b, 3);
	}
	/*if (((**b)->index == id1 && (**b)->next->index == id1)
		&& ((**b)->content < (**b)->next->content))
	{
		if (((**a)->index != id1 && (**a)->next->index != id1)
			|| ((**a)->index != id2 && (**a)->next->index != id2))
		{
			if (((**a)->content > (**a)->next->content))
				ft_ss(a, b, 3);
		}
	}*/
}

void	manager_friend(t_list **a, t_list **b, j_tab **jtab)
{
	m_tab	*mtab;
	int		pib;

	mtab = make_mtab(jtab, *a);
	if (!mtab)
		return ;
	//while (mtab->current1_len != -1 && mtab->current2_len != -1)
	while(!verif(*a))
	{
		pib = push_in_b(&a, &b, mtab->current1, mtab->current2);
		if (pib == -1)
		{

			print_tabj(jtab);
			exit (0);
		}

		if (pib == 1)
			mtab->current1_len--;
		else if (pib == 2)
			mtab->current2_len--;
		if (mtab->current1_len == 0)
		{
			jtab[0]->a = *a;
			fill_exclu(*a, jtab, mtab->current2);
			maj_m_tab(jtab, &mtab);
		}
		else if (mtab->current2_len == 0)
		{
			jtab[0]->a = *a;
			fill_exclu(*a, jtab, mtab->current1);
			maj_m_tab(jtab, &mtab);
		}
		/*if (pib != 0)
		{
			ft_printf("\ncurrent 1 = ");
			ft_print_tab(mtab->current1);
			ft_printf("la longueur de current1 est = %d\n", mtab->current1_len);
			ft_printf("current 2 = ");
			ft_print_tab(mtab->current2);
			ft_printf("la longueur de current2 est = %d\n", mtab->current2_len);
		}*/
	}
	clear_mtab(&mtab);
}

void	clear_mtab(m_tab **mtab)
{
	if ((*mtab)->current1)
		free((*mtab)->current1);
	if ((*mtab)->current2)
		free((*mtab)->current2);
	free(*mtab);
}


void	maj_m_tab(j_tab **jtab, m_tab **mtab)
{
	int	*pos_pline;

	if (!*mtab)
		return ;
	if ((*mtab)->current1_len == 0)
	{
		free((*mtab)->current1);
		pos_pline = make_p_line(jtab);
		if (!pos_pline)
		{
			free((*mtab)->current1);
			(*mtab)->current1_len = -1;
		}
		(*mtab)->current1 = copie_current(jtab, pos_pline);
		(*mtab)->current1_len = p_line_len(jtab, (*mtab)->current1);
		rest_s_len(jtab, pos_pline);
	}
	else if ((*mtab)->current2_len == 0)
	{
		free((*mtab)->current2);
		pos_pline = make_p_line(jtab);
		if (!pos_pline)
		{
			free((*mtab)->current2);
			(*mtab)->current2_len = -1;
		}
		(*mtab)->current2 = copie_current(jtab, pos_pline);
		(*mtab)->current2_len = p_line_len(jtab, (*mtab)->current2);
		rest_s_len(jtab, pos_pline);
	}
	/*ft_printf("\ncurrent 1 = ");
	ft_print_tab((*mtab)->current1);
	//ft_printf("la longueur de current1 est = %d\n", (*mtab)->current1_len);
	ft_printf("current 2 = ");
	ft_print_tab((*mtab)->current2);*/
	//ft_printf("la longueur de current2 est = %d\n", (*mtab)->current2_len);*/

}

m_tab	*make_mtab(j_tab **jtab, t_list *a)
{
	m_tab	*mtab;
	int		*pline;

	mtab = (m_tab *)malloc(sizeof(m_tab));
	if (!mtab)
		return (NULL);
	fill_exclu(a, jtab, NULL);
	pline = make_p_line(jtab);
	mtab->current1 = copie_current(jtab, pline);
	mtab->current1_len = p_line_len(jtab, mtab->current1);
	rest_s_len(jtab, pline);
	fill_exclu(a, jtab, mtab->current1);

	pline = make_p_line(jtab);
	mtab->current2 = copie_current(jtab, pline);
	mtab->current2_len = p_line_len(jtab, mtab->current2);
	rest_s_len(jtab, pline);

	//sch_diff_pline(mtab->current1, mtab->current2); //supprimer avant push
	/*if (mtab->current2[0] == mtab->current1[0])
	{
		ft_printf("\n\nERROR make_mtab current1 == current2\ncurrent1 = ");
		ft_print_tab(mtab->current1);
		ft_printf("current2 = ");
		ft_print_tab(mtab->current2);
		exit(0);
	}*/

	/*ft_printf("mtab->current1 = ");
	ft_print_tab(mtab->current1);
	ft_printf("mtab->current2 = ");
	ft_print_tab(mtab->current2);*/
	if (!mtab->current1 || !mtab->current2)
		return (NULL);
	return (mtab);
}
