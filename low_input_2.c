/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_input_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:09:56 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/25 17:44:09 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min2_in_a(t_list *a, int min)
{
	int	min2;

	while (a)
	{
		if (a->content > min)
		{
			min2 = a->content;
			break ;
		}
		a = a->next;
	}
	while (a)
	{
		if (a->content < min2 && a->content > min)
			min2 = a->content;
		a = a->next;
	}
	return (min2);
}

int	ft_pos_in_a(t_list *a, int min)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->content == min)
			return (i);
		i++;
		a = a->next;
	}
	return (-1);
}

void	ft_three_arg_lst(t_list **a)
{
	if ((*a)->content < (*a)->next->content
		&& (*a)->content > (*a)->next->next->content)
		ft_rrr(&a, NULL, 1);
	else if ((*a)->content > (*a)->next->next->content
		&& (*a)->next->next->content > (*a)->next->content)
		ft_rr(&a, NULL, 1);
	else if ((*a)->content > (*a)->next->content
		&& (*a)->content < (*a)->next->next->content)
		ft_ss(&a, NULL, 1);
	else if ((*a)->content < (*a)->next->next->content
		&& (*a)->next->content > (*a)->next->next->content)
	{
		ft_ss(&a, NULL, 1);
		ft_rr(&a, NULL, 1);
	}
	else if ((*a)->content > (*a)->next->content
		&& (*a)->content > (*a)->next->next->content)
	{
		ft_ss(&a, NULL, 1);
		ft_rrr(&a, NULL, 1);
	}
}

void	ft_three_arg(char **argv)
{
	if (ft_atoi(argv[0]) > ft_atoi(argv[2])
		&& ft_atoi(argv[1]) > ft_atoi(argv[0]))
		ft_printf("rra\n");
	else if (ft_atoi(argv[1]) < ft_atoi(argv[2])
		&& ft_atoi(argv[0]) > ft_atoi(argv[2]))
		ft_printf("ra\n");
	else if (ft_atoi(argv[0]) > ft_atoi(argv[1])
		&& ft_atoi(argv[0]) < ft_atoi(argv[2]))
		ft_printf("sa\n");
	else if (ft_atoi(argv[0]) < ft_atoi(argv[1])
		&& ft_atoi(argv[1]) > ft_atoi(argv[2]))
		ft_printf("sa\nra\n");
	else if (ft_atoi(argv[0]) > ft_atoi(argv[1])
		&& ft_atoi(argv[0]) > ft_atoi(argv[2]))
		ft_printf("sa\nrra\n");
}

void	ft_four_arg(char **argv)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = ft_atoi(argv[0]);
	b = ft_atoi(argv[1]);
	c = ft_atoi(argv[2]);
	d = ft_atoi(argv[3]);
	if (a < b && b < c && c < d)
		return ;
	ft_printf("rra\npb\n");
	ft_three_arg(argv);
	if (d < a && d < b && d < c)
		ft_printf("pa\n");
	else if (d > a && d > b && d > c)
		ft_printf("pa\nra\n");
	else if ((d > b && d > c && d < a) || (d > a && d > b && d < c)
		|| (d > a && d > c && d < b))
		ft_printf("rra\npa\nra\nra\n");
	else
		ft_printf("pa\nsa\n");
}
