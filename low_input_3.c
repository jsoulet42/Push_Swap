/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_input_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:27:42 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/23 11:13:32 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three_arg_2(char **argv)
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

void	ft_four_arg_2(char **argv)
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
	ft_three_arg_2(argv);
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

void	ft_low_input_2(int argc, char **argv, int on)
{
	if (argc == 2)
	{
		if (ft_atoi(argv[0]) > ft_atoi(argv[1]))
			ft_printf("sa\n");
	}
	else if (argc == 3)
		ft_three_arg_2(argv);
	else if (argc == 4)
		ft_four_arg_2(argv);
	else if (argc == 5)
		ft_five_arg(argv, on);
}
