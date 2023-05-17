/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_sort_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:23:32 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/16 18:03:10 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_p(t_list ***a, t_list ***b, j_tab **jtab, int i);
int last_rotate(t_list **b, int *tabs, int j, int l);
int verif_rotate(t_list *b, int *tabs, int j, int l);
int verif_rotate2(t_list *b, int i, int k);
int verif_idx_a(t_list *a, int pos_p);
int found_index_max(t_list *b);
int sort_p_suit(t_list ***b, int *tabs, int j, int l);
int found_len_max(j_tab **jtab);
void sort_p__len_3(t_list ***a, t_list ***b);




int g_sort_p = 0;

void sort_p(t_list ***a, t_list ***b, j_tab **jtab, int i)
{
	int j;
	int l;
	int k;

	j = jtab[i]->s_len -1;
	l = 0;
	while (jtab[i]->s_len > 0)
	{
		if (g_sort_p++ > 100000)
		{
			ft_printf("sort_p : index = %d j = %d, l = %d\n",jtab[i]->index, j, l);
			ft_printf("b->content = %d\n", (**b)->content);
			ft_printf("boucle infini dans sort_p\n");
			exit(0);
		}
		if ((**b)->content == jtab[i]->tabs[j])
		{
			jtab[i]->s_len--;
			ft_p(a, b, 2);
			j--;

		}
		else if ((**b)->content == jtab[i]->tabs[l])
		{
			jtab[i]->s_len--;
			ft_p(a, b, 2);
			ft_rr(a, b, 1);
			l++;
		}
		else
		{
			k = sort_p_suit(b, jtab[i]->tabs, j, l);
			if (k == 2)
				ft_rr(a, b, 2);
			if (k == 4)
				ft_rrr(a, b, 2);
		}
	}
}

int sort_p_suit(t_list ***b, int *tabs, int j, int l)
{
	int k;
	//int h;

	k = verif_rotate(**b, tabs, j, l);
	if (k == 2 || k == 4)
		return (k);
	return (last_rotate(*b, tabs, j, l));
}

int g_last_rotate_debug = 0;
int last_rotate(t_list **b, int *tabs, int j, int l)
{
	t_list *tmp;
	t_list *tmp2;
	int i;
	int k;

	tmp = *b;
	tmp2 = *b;
	i = 0;
	k = 0;
	g_last_rotate_debug++;
	//ft_printf("last_rotate\n");
	while (tmp->content != tabs[j])
	{
		tmp = tmp->next;
		i++;
	}
	while (tmp2->content != tabs[l])
	{
		tmp2 = tmp2->next;
		k++;
	}
	k = ft_lstsize(*b) - k;
	if (i > k)
		return (4);
	return (2);
}

int verif_rotate(t_list *b, int *tabs, int j, int l)
{
	t_list *tmp;
	t_list *tmp2;
	int i;
	int k;

	tmp = b;
	i = 0;
	//ft_printf("verif_rotate\n");
	while (tmp->next)
	{
		if (tmp->content == tabs[j])
			break;
		tmp = tmp->next;
		i++;
	}
	tmp2 = b;
	k = 0;
	while (tmp->next)
	{
		if (tmp2->content == tabs[l])
			break;
		tmp2 = tmp2->next;
		k++;
	}
	return (verif_rotate2(b, i, k));
}
int verif_rotate2(t_list *b, int i, int k)
{
	//ft_printf("verif_rotate2\n");
	if (i <= ft_lstsize(b) / 2 && k <= ft_lstsize(b) / 2)
		return (2);
	else if (i > ft_lstsize(b) / 2 && k > ft_lstsize(b) / 2)
		return (4);
	else
		return (3);
}

void choice_p(t_list **a, t_list **b, j_tab **jtab)
{
	int	j;
	int	index_max;

	j = jtab_len(jtab);
	index_max = -1;

	while (j > 0)
	{
		//index_max = found_len_max(jtab);
		index_max = found_index_max(*b);
		b_replace(a, b, index_max);
		open_door(a, b, (*b)->index);
		if (jtab[found_index(jtab, index_max)]->s_len == 3)
		{
			jtab[found_index(jtab, index_max)]->s_len = 0;
			sort_p__len_3(&a, &b);
		}
		else
			sort_p(&a, &b, jtab, found_index(jtab, (*b)->index));
		j--;
	}
}


void sort_p__len_3(t_list ***a, t_list ***b)
{
	if ((**b)->content > (**b)->next->content && (**b)->content > (**b)->next->next->content) // 3 * *
	{
		ft_p(a, b, 2);
		if ((**b)->content > (**b)->next->content) //2 1
		{
			ft_p(a, b, 2);
			ft_p(a, b, 2);
		}
		else // 1 2
		{
			ft_ss(a, b, 2);
			ft_p(a, b, 2);
			ft_p(a, b, 2);
		}
	}
	else if((**b)->content < (**b)->next->content && (**b)->content < (**b)->next->next->content)
	{
		ft_p(a, b, 2);
		ft_rr(a, b, 1);
		if ((**b)->content > (**b)->next->content)
		{
			ft_p(a, b, 2);
			ft_p(a, b, 2);
		}
		else
		{
			ft_p(a, b, 2);
			ft_rr(a, b, 1);
			ft_p(a, b, 2);
		}
	}
	else if ((**b)->content > (**b)->next->content && (**b)->content < (**b)->next->next->content) //2 1 3
	{
		ft_p(a, b, 2);
		ft_p(a, b, 2);
		ft_rr(a, b, 1);
		ft_rr(a, b, 1);
		ft_p(a, b, 2);
	}
	else if ((**b)->content < (**b)->next->content && (**b)->content > (**b)->next->next->content) //2 3 1
	{
		ft_ss(a, b, 2);
		ft_p(a, b, 2);
		ft_p(a, b, 2);
		ft_p(a, b, 2);
	}
}

int found_len_max(j_tab **jtab)
{
	int res;
	int i;

	i = 0;
	while (jtab[i])
	{
		if (jtab[i]->s_len != 0)
		{
			res = i;
			break;
		}
		i++;
	}
	while (jtab[i])
	{
		if (jtab[i]->s_len < jtab[res]->s_len && jtab[i]->s_len != 0)
			res = i;
		i++;
	}
	return (jtab[res]->index);
}

int found_index_max(t_list *b)
{
	int res;

	res = b->index;
	while (b)
	{
		if (b->index > res)
			res = b->index;
		b = b->next;
	}
	return (res);
}

void open_door(t_list **a, t_list **b, int pos_p)
{
	int i;
	t_list *tmp;

	tmp = *a;
	i = 0;

	pos_p = verif_idx_a(*a, pos_p);
	while (tmp->index != pos_p)
	{
		tmp = tmp->next;
		i++;
	}
	if (i > (ft_lstsize(*a) / 2))
		while ((*a)->index != pos_p)
			ft_rrr(&a, &b, 1);
	else if (i <= (ft_lstsize(*a) / 2))
		while ((*a)->index != pos_p)
			ft_rr(&a, &b, 1);
}

int verif_idx_a(t_list *a, int pos_p)
{
	t_list *tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->index == pos_p + 1)
			return (pos_p + 1);
		tmp = tmp->next;
	}
	return (0);
}

