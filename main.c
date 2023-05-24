/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:07:20 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/24 12:53:54 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	on;

	on = 0;
	if (argc == 1)
		return (0);
	if (argc <= 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = 0;
		if (argv[0] == NULL)
		{
			free(argv);
			return (0);
		}
		while (argv[argc])
			argc++;
		on = 1;
	}
	found_conditions(argc, argv, on, 0);
	if (argc <= 6 && on == 0)
		ft_low_input(argc, argv, on);
	else
		push_swap(argv, on);
	free_argv(argv, on);
	return (0);
}

void	push_swap(char **argv, int on)
{
	t_list	*a;
	t_list	*b;
	t_tab	**tabm;
	int		line;

	a = NULL;
	b = NULL;
	creat_list(&a, argv, on);
	tabm = make_tab(a);
	make_line(tabm, a);
	line = found_line(tabm);
	clear_tabs(tabm, &tabm[line], 0);
	chearch_add_min(a, &tabm[line]);
	make_index_a(tabm[line], &a);
	make_index_b(tabm[line], &a);
	make_tabi_jtab(&a, &b, tabm, tabm[line]);
}

void	make_tabi_jtab(t_list **a, t_list **b, t_tab **tabm, t_tab *line)
{
	t_jtb	**jtab;
	int		*tabi;

	jtab = NULL;
	tabi = index_tab(*a, line);
	if (!tabi || tabi[0] == -1)
	{
		if ((*a)->index != 0)
			ft_tabi_empty(a, b);
		clear_all(*a, tabm, &line, tabi);
		return ;
	}
	make_jtab(a, &jtab, tabi, line->lens);
	sort_p1(jtab, *a);
	manager_friend(a, b, jtab);
	a_replace(a, b, 2);
	replace_a(a, b, rmtada(a, b, line->tabs[line->lens - 1]));
	replace_s_len(jtab, *b);
	choice_p(a, b, jtab, jtab_len(jtab));
	a_replace(a, b, 0);
	clear_jtab(jtab);
	ft_list_instruction(0);
	clear_all(*a, tabm, &line, tabi);
}

void	free_argv(char **argv, int on)
{
	int	i;

	if (argv[1] == NULL || argv[2] == NULL)
		return ;
	if (on == 0)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
