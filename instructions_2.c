/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:46:25 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/23 09:52:59 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstprint2(t_list *list)
{
	r_opti	opti;

	make_opti(&opti);
	while (list)
	{
		if (list->content == 1)
			ft_print_opti_rrr(&opti, 1);
		else if (list->content == 2)
			ft_print_opti_rrr(&opti, 2);
		else if (list->content == 4)
			ft_print_opti_rr(&opti, 1);
		else if (list->content == 5)
			ft_print_opti_rr(&opti, 2);
		else if (list->content >= 6 || list->content == 3)
		{
			ft_print_opti_rr(&opti, 0);
			ft_print_opti_rrr(&opti, 0);
			ft_lstprint2_next(list->content);
		}
		list = list->next;
	}
	ft_print_opti_rr(&opti, 0);
	ft_print_opti_rrr(&opti, 0);
}

void	ft_print_opti_rr(r_opti *opti, int bool)
{
	if (opti->ra > 0 || opti->rb > 0)
	{
		while (opti->ra > 0 && opti->rb > 0)
		{
			opti->ra--;
			opti->rb--;
			ft_printf("rr\n");
			if (opti->ra == 0 || opti->rb == 0)
				break ;
		}
		while (opti->rb > 0)
		{
			opti->rb--;
			ft_printf("rb\n");
		}
		while (opti->ra > 0)
		{
			opti->ra--;
			ft_printf("ra\n");
		}
	}
	if (bool == 1)
		opti->rra++;
	else if (bool == 2)
		opti->rrb++;
}

void	ft_print_opti_rrr(r_opti *opti, int bool)
{
	if (opti->rra > 0 || opti->rrb > 0)
	{
		while (opti->rra > 0 && opti->rrb > 0)
		{
			opti->rra--;
			opti->rrb--;
			ft_printf("rrr\n");
			if (opti->rra == 0 || opti->rrb == 0)
				break ;
		}
		while (opti->rrb > 0)
		{
			opti->rrb--;
			ft_printf("rrb\n");
		}
		while (opti->rra > 0)
		{
			opti->rra--;
			ft_printf("rra\n");
		}
	}
	if (bool == 1)
		opti->ra++;
	else if (bool == 2)
		opti->rb++;
}

void	make_opti(r_opti *opti)
{
	opti->ra = 0;
	opti->rb = 0;
	opti->rra = 0;
	opti->rrb = 0;
}

void	ft_lstprint2_next(int instruction)
{
	if (instruction == 3)
		ft_printf("rr\n");
	if (instruction == 6)
		ft_printf("rrr\n");
	if (instruction == 7)
		ft_printf("pa\n");
	if (instruction == 8)
		ft_printf("pb\n");
	if (instruction == 9)
		ft_printf("sa\n");
	if (instruction == 10)
		ft_printf("sb\n");
	if (instruction == 11)
		ft_printf("ss\n");
}
