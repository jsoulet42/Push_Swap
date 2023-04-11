/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiamant <mdiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:50:05 by jsoulet           #+#    #+#             */
/*   Updated: 2023/04/11 09:25:39 by mdiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int next_big(j_tab **jtab, int curent_big);
int next_big_note(j_tab **jtab, t_list *a, int curent_big);
int *tab_pat(j_tab **jtab);




void	manager_friend(t_list **a, t_list **b, j_tab **jtab)
{
	int	pos_next_big;
	int	pos_big_len;
	int	current_p;
	int count;

	pos_big_len = next_big(jtab, -1);//found_big_len(jtab);
	pos_next_big = next_big(jtab, pos_big_len);
	while (verif(*a) == 0)
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
			pos_big_len = next_p(jtab, a, pos_next_big); //next_big(jtab, pos_next_big);
		else if (jtab[pos_next_big]->s_len == 0)
			pos_next_big = next_p(jtab, a, pos_big_len);
	}
}

int	next_p(j_tab **jtab, t_list **a, int curent_big)
{
	int	i;
	int	j;
	int	*tab_p;
	t_list *temp;

	i = 0;
	while (jtab[i])
	{
		jtab[i]->note = jtab[i]->s_len;
		i++;
	}
	i = 0;
	while (jtab[i])
	{
		tab_p = tab_pat(jtab);
		temp = *a;
		j = 0;
		while (temp)
		{
			if (temp->index % 2 == 1 && temp->index != jtab[i]->index)
			{
				while (tab_p[j] != 0)
				{
					if (temp->index == tab_p[j])
					{
						tab_p[j] = 0;
						jtab[i]->note -= 1;
					}
					j++;
				}
			}
			temp = temp->next;
		}
		free(tab_p);

		//printf("La note de jtab[%d]->note = %d\n", i, jtab[i]->note);
		i++;
	}
	return (next_big_note(jtab, *a, curent_big));
}

int *tab_pat(j_tab **jtab)
{
	int	*res;
	int i;
	int j;

	i = 0;
	j = 0;
	while(jtab[i])
	{
		if (jtab[i]->index % 2 == 1 && jtab[i]->s_len > 0)
			j++;
		i++;
	}
	res = (int *)malloc(sizeof(int) * (j + 1));
	if (!res)
		return(NULL);
	res[j] = 0;
	i = 0;
	j = 0;
	while(jtab[i])
	{
		if (jtab[i]->index % 2 == 1 && jtab[i]->s_len > 0)
		{
			res[j] = jtab[i]->index;
			j++;
		}
		i++;
	}
	return (res);
}

int next_big_note(j_tab **jtab, t_list *a, int curent_big)
{
	int i;
	int res;

	i = 0;
	res = jtab[0]->note;
	while(jtab[i])
	{
		if(jtab[i]->note > res)
		{
			if (i != curent_big)
				res = jtab[i]->note;
		}
		i++;
	}
	while(a)
	{
		i = 0;
		while (jtab[i])
		{
			if (a->index == jtab[i]->index && jtab[i]->note == res)
				return (i);
			i++;
		}
		a = a->next;
	}
	return (curent_big);
}

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

int next_big(j_tab **jtab, int curent_big)
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
		/*if ((**b) && (**b)->next && (**a) && (**a)->next)
			push_in_b_suit(a, b, id1, id2);*/
		return (1);
	}
	else if ((**a)->index == id2)
	{
		ft_p(a, b, 1);
		ft_rr(a, b, 2);
		return (2);

		/*if ((**a)->next->index == id2 && (**b) && (**b)->next && (**a) && (**a)->next)
		{
			ft_p(a, b, 1);
			ft_p(a, b, 1);
			push_in_b_suit(a, b, id1, id2);
		}
		else
			ft_p(a, b, 1);
		if ((**b)->index == id2 && (**a)->index != id1 && (**a)->index != id2)
			ft_rr(a, b, 3);
		else
			ft_rr(a, b, 2);*/
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

void push_in_b_suit(t_list ***a, t_list ***b, int id1, int id2)
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
	else if (((**b)->index == id2 && (**b)->next->index == id2)
		&& ((**b)->content < (**b)->next->content))
	{
		if (((**a)->index == id2 && (**a)->next->index == id2)
			&& ((**a)->content > (**a)->next->content))
			ft_ss(a, b, 3);
	}
	/*if ((**b) && (**b)->next && (**a) && (**a)->next)
		push_in_b_suit2(a, b, id1, id2);*/
}

/*void push_in_b_suit2(t_list ***a, t_list ***b, int id1, int id2)
{
	if (((**b)->index == id1 && (**b)->next->index == id1)
		&& ((**b)->content < (**b)->next->content))
	{
		if (((**a)->index == id1 && (**a)->next->index != id1)
			 && ((**a)->content > (**a)->next->content))
			ft_ss(a, b, 3);
	}
	else if (((**b)->index == id2 && (**b)->next->index == id2)
		&& ((**b)->content > (**b)->next->content))
	{
		if (((**a)->index == id2 && (**a)->next->index != id2)
			&& ((**a)->content > (**a)->next->content))
			ft_ss(a, b, 3);
	}
}*/

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
