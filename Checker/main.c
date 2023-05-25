/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:29:54 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/25 16:57:06 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	char	*line;

	line = NULL;
	if (argc == 1)
		return (0);
	argv = make_argv(argc, argv);
	argc = 0;
	while (argv[argc])
		argc++;
	found_conditions(argc, argv, 0);
	checker(argv, line);
	free_argv(argv);
	return (0);
}

void	checker(char **argv, char *line)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	creat_list(&a, argv);
	line = get_next_line(0);
	while (line != NULL)
	{
		if (checker_1(&a, &b, line) == 0 && checker_2(&a, &b, line) == 0
			&& checker_3(&a, &b, line) == 0)
		{
			ft_printf("ERROR\n");
			exit(0);
		}
		free(line);
		line = get_next_line(0);
	}
	verif_end(a);
	ft_lstclear(&a);
}

int	checker_1(t_list **a, t_list **b, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
	{
		sa(a);
		return (1);
	}
	else if (ft_strncmp(line, "ss\n", 3) == 0)
	{
		sa(a);
		sa(b);
		return (1);
	}
	else if (ft_strncmp(line, "pa\n", 3) == 0)
	{
		pa(a, b);
		return (1);
	}
	else if (ft_strncmp(line, "pb\n", 3) == 0)
	{
		pa(b, a);
		return (1);
	}
	return (0);
}

int	checker_2(t_list **a, t_list **b, char *line)
{
	if (ft_strncmp(line, "sb\n", 3) == 0)
	{
		sa(b);
		return (1);
	}
	else if (ft_strncmp(line, "rr\n", 3) == 0)
	{
		ra(a);
		ra(b);
		return (1);
	}
	else if (ft_strncmp(line, "rra\n", 4) == 0)
	{
		rra(a);
		return (1);
	}
	return (0);
}

int	checker_3(t_list **a, t_list **b, char *line)
{
	if (ft_strncmp(line, "rrb\n", 4) == 0)
	{
		rra(b);
		return (1);
	}
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
	{
		rra(a);
		rra(b);
		return (1);
	}
	else if (ft_strncmp(line, "ra\n", 3) == 0)
	{
		ra(a);
		return (1);
	}
	else if (ft_strncmp(line, "rb\n", 3) == 0)
	{
		ra(b);
		return (1);
	}
	return (0);
}
