/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_input_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:08:23 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/23 11:14:15 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_low_input_2(int argc, char **argv, int on);

void	ft_low_input(int argc, char **argv, int on)
{
	if (on == 0)
	{
		if (argc <= 2)
			return ;
		else if (argc == 3)
		{
			if (ft_atoi(argv[1]) > ft_atoi(argv[2]))
				ft_printf("sa\n");
		}
		else if (argc == 4)
			ft_three_arg(argv);
		else if (argc == 5)
			ft_four_arg(argv);
		else if (argc == 6)
			ft_five_arg(argv, on);
		return ;
	}
	ft_low_input_2(argc, argv, on);
}

void	ft_five_arg_end(t_list **a, t_list **b)
{
	ft_p(&a, &b, 2);
	ft_p(&a, &b, 2);
	ft_list_instruction(0);
}

void	ft_five_arg(char **argv, int on)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	creat_list(&a, argv, on);
	if (ft_five_arg_2(&a, &b) == 1)
		ft_five_arg_3(&a, &b);
	ft_three_arg_lst(&a);
	ft_five_arg_end(&a, &b);
	ft_lstclear(&a);
	ft_lstclear(&b);
}

int	ft_five_arg_2(t_list **a, t_list **b)
{
	int	min;
	int	min2;

	min = ft_min_in_a(*a);
	min2 = ft_min2_in_a(*a, min);
	if (ft_pos_in_a(*a, min) > 3 && ft_pos_in_a(*a, min2) > 3)
	{
		ft_rrr(&a, &b, 2);
		ft_p(&a, &b, 2);
		ft_rrr(&a, &b, 2);
		ft_p(&a, &b, 2);
	}
	else if ((ft_pos_in_a(*a, min) == 1 && ft_pos_in_a(*a, min2) == 5)
		|| (ft_pos_in_a(*a, min) == 5 && ft_pos_in_a(*a, min2) == 1))
	{
		ft_p(&a, &b, 2);
		ft_rrr(&a, &b, 2);
		ft_p(&a, &b, 2);
	}
	else
		return (1);
	if ((*b)->content < (*b)->next->content)
		ft_ss(&a, &b, 2);
	return (0);
}

void	ft_five_arg_3(t_list **a, t_list **b)
{
	int	min;
	int	min2;

	min = ft_min_in_a(*a);
	min2 = ft_min2_in_a(*a, min);
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->content == min || (*a)->content == min2)
			ft_p(&a, &b, 1);
		else
			ft_rr(&a, &b, 1);
	}
	if ((*b)->content < (*b)->next->content)
		ft_ss(&a, &b, 2);
}
