/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:11:19 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/24 12:55:43 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tabi_empty(t_list **a, t_list **b)
{
	if ((*a)->next != 0)
	{
		a_replace(a, b, 0);
		if ((*a)->next != 0)
		{
			ft_p(&a, &b, 1);
			a_replace(a, b, 2);
			ft_p(&a, &b, 2);
		}
		ft_list_instruction(0);
	}
}

void	verif_end(t_list *a)
{
	int	tmp;

	tmp = a->content;
	a = a->next;
	while (a)
	{
		if (tmp > a->content)
		{
			ft_printf("KO\n");
			return ;
		}
		a = a->next;
	}
}

void	clear_all(t_list *a, t_tab **tabm, t_tab **pos_line, int *tabi)
{
	clear_tabs(tabm, pos_line, 1);
	ft_lstclear(&a);
	free(tabi);
}

void	creat_list(t_list **a, char **argv, int on)
{
	int	i;

	if (on == 1)
		i = 0;
	else
		i = 1;
	while (argv[i])
	{
		ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	if (!*a)
	{
		ft_printf("Error in creat_list\n");
		exit(0);
	}
}

int	ft_min_in_a(t_list *a)
{
	int	min;

	min = a->content;
	while (a)
	{
		if (a->content < min)
			min = a->content;
		a = a->next;
	}
	return (min);
}
