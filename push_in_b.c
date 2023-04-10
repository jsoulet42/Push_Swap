/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:50:05 by jsoulet           #+#    #+#             */
/*   Updated: 2023/04/10 10:50:15 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	manager_friend(t_list **a, t_list **b, j_tab **jtab)
{
	int	pos_next_big;
	int	pos_big_len;
	int	current_p;
	int count;

	pos_big_len = found_big_len(jtab);
	pos_next_big = next_big(jtab, pos_big_len);
	while (verif(jtab) == 0)
	{
		count = 1;
		while (count == 1)
		{
			if (jtab[pos_big_len]->s_len == 0 || jtab[pos_next_big]->s_len == 0)
				count = 2;
			current_p = push_in_b(&a, &b, jtab[pos_big_len]->index, jtab[pos_next_big]->index);
			if (current_p == 1)
				jtab[pos_big_len]->s_len--;
			else if (current_p == 2)
				jtab[pos_next_big]->s_len--;
		}
		if (jtab[pos_big_len]->s_len == 0)
			pos_big_len = next_big(jtab, pos_next_big);
		else if (jtab[pos_next_big]->s_len == 0)
			pos_next_big = next_big(jtab, pos_big_len);
	}
}


int	verif(j_tab **jtab)
{
	int i;
	i = 0;
	while (jtab[i])
	{
		if (jtab[i]->s_len != 0)
			return (0);
		i++;
	}
	return (1);
}

int	next_big(j_tab **jtab, int curent_big)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while(jtab[i])
	{
		if(jtab[res]->s_len <= jtab[i]->s_len)
		{
			if (i != curent_big)
				res = i;
		}
		i++;
	}
	return (res);
}

int	push_in_b(t_list ***a, t_list ***b, int id1, int id2)
{
	if ((**a)->index == id1)
	{
		ft_p(a, b, 1);
		push_in_b_suit(a, b, id1);
		return (1);
	}
	else if ((**a)->index == id2)
	{
		/*if ((**a)->next->index == id2)
		{
			ft_p(a, b, 1);
			ft_p(a, b, 1);
			push_in_b_suit(a, b, id1, id2);
		}
		else*/
			ft_p(a, b, 1);
		if ((**b)->index == id2 && (**a)->index != id1 && (**a)->index != id2)
			ft_rr(a, b, 3);
		else
			ft_rr(a, b, 2);
		return (2);
	}
	else
	{
		if (chx_rotate(**a, id1, id2) == 1)
			ft_rr(a, b, 1);
		else
			ft_rrr(a, b, 1);
	}
	return (0);
}

void push_in_b_suit(t_list ***a, t_list ***b, int id1)
{
	if (!(**b) || !(**b)->next)
		return ;
	if (((**b)->index && (**b)->next->index == id1)
		&& ((**b)->content < (**b)->next->content))
	{
		if (((**a)->index && (**a)->next->index == id1)
			&& ((**a)->content > (**a)->next->content))
			ft_ss(a, b, 3);
	}
	/*else if (((**b)->index && (**b)->next->index == id2)
		&& ((**b)->content > (**b)->next->content))
	{
		if (((**a)->index && (**a)->next->index == id2)
			&& ((**a)->content < (**a)->next->content))
			ft_ss(a, b, 3);
	}*/
	push_in_b_suit2(a, b, id1);
}

void push_in_b_suit2(t_list ***a, t_list ***b, int id1)
{
	if (((**b)->index && (**b)->next->index == id1)
		&& ((**b)->content < (**b)->next->content))
	{
		if (((**a)->index && (**a)->next->index != id1)
			 && ((**a)->content > (**a)->next->content))
			ft_ss(a, b, 3);
	}
	/*else if (((**b)->index && (**b)->next->index == id2)
		&& ((**b)->content > (**b)->next->content))
	{
		if (((**a)->index && (**a)->next->index != id2)
			&& ((**a)->content > (**a)->next->content))
			ft_ss(a, b, 3);
	}*/
}

int chx_rotate(t_list *a, int index1, int index2)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = ft_lstsize(a) / 2;
	while(a && i < len)
	{
		if (a->index == index1 || a->index == index2)
			i++;
		a = a->next;
	}
	while(a)
	{
		if (a->index == index1 || a->index == index2)
			j++;
		a = a->next;
	}
	if (j / 4 >= i)
		return (0);
	else
		return (1);
}
