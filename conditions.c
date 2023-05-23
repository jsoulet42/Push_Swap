/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:26:47 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/23 11:18:33 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	found_conditions(int argc, char **argv, int on, int i)
{
	if (argc == 1)
	{
		i = 1;
	}
	if (argc == 2 && on == 1 && ft_atoi(argv[0]) > ft_atoi(argv[1]))
	{
		free_argv(argv, on);
		ft_printf("sa\n");
		exit(0);
	}
	if (found_double(argc, argv) == 1)
		i = 1;
	if (found_char(argc, argv) == 1)
		i = 1;
	if (found_int(argc, argv) == 1)
		i = 1;
	if (i == 1)
	{
		free_argv(argv, on);
		ft_printf("Error\n");
		exit(0);
	}
}

int	found_double(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	found_char(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != '-')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	found_int(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
