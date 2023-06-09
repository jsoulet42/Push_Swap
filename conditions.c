/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:26:47 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/29 13:35:21 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	found_conditions(int argc, char **argv, int i)
{
	if (argc == 1)
	{
		if ((ft_atoi(argv[i]) > 2147483647 && ft_atoi(argv[i]) < -2147483648))
			i = 1;
	}
	if ((found_double(argv) == 1 || found_char(argv) == 1) && i != 1)
		i = 1;
	if (found_int(argv) == 1 && i != 1)
		i = 1;
	if (i == 1)
	{
		free_argv(argv);
		ft_printf("Error\n");
		exit(0);
	}
	if (argc == 2 && ft_atoi(argv[0]) > ft_atoi(argv[1]))
	{
		free_argv(argv);
		ft_printf("sa\n");
		exit(0);
	}
}

int	found_double(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i + 1] != NULL)
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	found_char(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != '-')
				return (1);
			if (argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	found_int(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
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
