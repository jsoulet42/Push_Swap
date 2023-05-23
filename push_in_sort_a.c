/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_sort_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:23:32 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/23 09:35:33 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_p(t_list ***a, t_list ***b, j_tab **jtab, int i)
{
	int	j;
	int	l;

	j = jtab[i]->s_len - 1;
	l = 0;
	while (jtab[i]->s_len > 0)
	{
		if ((**b)->content == jtab[i]->tabs[j]
			|| (**b)->content == jtab[i]->tabs[l])
		{
			jtab[i]->s_len--;
			ft_p(a, b, 2);
			if ((**a)->content == jtab[i]->tabs[j])
				j--;
			else if ((**a)->content == jtab[i]->tabs[l++])
				ft_rr(a, b, 1);
		}
		else
		{
			if (sort_p_suit(b, jtab[i]->tabs, j, l) == 2)
				ft_rr(a, b, 2);
			else if (sort_p_suit(b, jtab[i]->tabs, j, l) == 4)
				ft_rrr(a, b, 2);
		}
	}
}

int	sort_p_suit(t_list ***b, int *tabs, int j, int l)
{
	int	k;

	k = verif_rotate(**b, tabs, j, l);
	if (k == 2 || k == 4)
		return (k);
	return (last_rotate(*b, tabs, j, l));
}

int	last_rotate(t_list **b, int *tabs, int j, int l)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		i;
	int		k;

	tmp = *b;
	tmp2 = *b;
	i = 0;
	k = 0;
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

int	verif_rotate(t_list *b, int *tabs, int j, int l)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		i;
	int		k;

	tmp = b;
	i = 0;
	while (tmp->next)
	{
		if (tmp->content == tabs[j])
			break ;
		tmp = tmp->next;
		i++;
	}
	tmp2 = b;
	k = 0;
	while (tmp->next)
	{
		if (tmp2->content == tabs[l])
			break ;
		tmp2 = tmp2->next;
		k++;
	}
	return (verif_rotate2(b, i, k));
}

int	verif_rotate2(t_list *b, int i, int k)
{
	if (i <= ft_lstsize(b) / 2 && k <= ft_lstsize(b) / 2)
		return (2);
	else if (i > ft_lstsize(b) / 2 && k > ft_lstsize(b) / 2)
		return (4);
	else
		return (3);
}
