/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:57:56 by julien            #+#    #+#             */
/*   Updated: 2023/05/16 14:12:34 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int g_instruction_debug = 0;

void	sa(t_list **a)
{
	t_list	*temp1;

	if (!a || !(*a)->next)
		return ;
	temp1 = (*a)->next;
	(*a)->next = temp1->next;
	temp1->next = *a;
	*a = temp1;
}

void	ft_ss(t_list ***a, t_list ***b, int ist)
{
	if (ist == 1)
	{
		if (!a || !(**a) || !(**a)->next)
			return ;
		sa(*a);
		ft_list_instruction(9);
		//ft_printf("sa\n");
	}
	if (ist == 2)
	{
		if (!b || !(*b) || !(**b)->next)
			return ;
		sa(*b);
		ft_list_instruction(10);
		//ft_printf("sb\n");
	}
	if (ist == 3)
	{
		if (!a || !b || !(**a) || !(**b))
			return ;
		sa(*a);
		sa(*b);
		ft_list_instruction(11);
		//ft_printf("ss\n");
	}
}

void	pa(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!b || !(*b))
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
}

void	ft_p(t_list ***a, t_list ***b, int ist)
{
	if (ist == 1)
	{
		if (!a || !(**a))
			return ;
		pa(*b, *a);
		ft_list_instruction(8);
		//ft_printf("pb\n");
	}
	else if (ist == 2)
	{
		if (!b || !(**b))
			return ;
		pa(*a, *b);
		ft_list_instruction(7);
		//ft_printf("pa\n");
	}
}

void	ra(t_list **a)
{
	t_list	*temp;
	t_list	*last;

	if (!a || !(*a)->next)
		return ;
	temp = *a;
	last = ft_lstlast(*a);
	*a = (*a)->next;
	last->next = temp;
	temp->next = NULL;
}

void	ft_rr(t_list ***a, t_list ***b, int ist)
{
	if (ist == 1)
	{
		if (!a || !(**a))
			return ;
		ra(*a);
		ft_list_instruction(1);
		//ft_printf("ra\n");
	}
	else if (ist == 2)
	{
		if (!b || !(**b))
			return ;
		ra(*b);
		ft_list_instruction(2);
		//ft_printf("rb\n");
	}
	else if (ist == 3)
	{
		if (!a || !b || !(**a) || !(**b))
			return ;
		ra(*a);
		ra(*b);
		ft_list_instruction(3);
		//ft_printf("rr\n");
	}
}

void	rra(t_list **a)
{
	t_list	*temp;
	t_list	*last;

	if (!a || !(*a)->next)
		return ;
	temp = *a;
	last = ft_lstlast(*a);
	while (temp->next != last)
		temp = temp->next;
	last->next = *a;
	temp->next = NULL;
	*a = last;
}

void	ft_rrr(t_list ***a, t_list ***b, int ist)
{

	if (ist == 1)
	{
		if (!a || !(**a))
			return ;
		rra(*a);
		ft_list_instruction(4);
		//ft_printf("rra\n");
	}
	if (ist == 2)
	{
		if (!b || !(**b))
			return ;
		rra(*b);
		ft_list_instruction(5);
		//ft_printf("rrb\n");
	}
	if (ist == 3)
	{
		if (!a || !b || !(**a) || !(**b))
			return ;
		rra(*a);
		rra(*b);
		ft_list_instruction(6);
		//ft_printf("rrr\n");
	}
}

void	print_nbr_instruction()// à supprimer
{
	ft_printf("\nLe nombre d'instruction est de %d\n", g_instruction_debug);
}

void	ft_list_instruction(int instruction)
{
	if (g_instruction_debug++ > 1000000)
	{
		ft_printf("g_instruction_debug > 10000\n");
		exit(0);
	}
	static t_list	*list;
	if (instruction > 0)
		ft_lstadd_back(&list, ft_lstnew(instruction));
	else
		ft_lstprint2(list);
}


void	ft_lstprint2(t_list *list)
{
	r_opti opti;

	make_opti(&opti);
	while (list)
	{
		if (list->content == 1)
		{
			ft_print_opti_rrr(&opti);
			opti.ra++;
		}
		else if (list->content == 2)
		{
			ft_print_opti_rrr(&opti);
			opti.rb++;
		}
		else if (list->content == 4)
		{
			ft_print_opti_rr(&opti);
			opti.rra++;
		}
		else if (list->content == 5)
		{
			ft_print_opti_rr(&opti);
			opti.rrb++;
		}
		else if (list->content >= 6 || list->content == 3)
		{
			ft_print_opti_rr(&opti);
			ft_print_opti_rrr(&opti);
			ft_lstprint2_next(list->content);
		}
		list = list->next;
	}
	ft_print_opti_rr(&opti);
	ft_print_opti_rrr(&opti);
}

void	ft_print_opti_rr(r_opti *opti)
{
	if (opti->ra > 0 || opti->rb > 0)
	{
		while (opti->ra > 0 && opti->rb > 0)
		{
			opti->ra--;
			opti->rb--;
			ft_printf("rr\n");
			if (opti->ra == 0 || opti->rb == 0)
				break;
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

}
void	ft_print_opti_rrr(r_opti *opti)
{

	if (opti->rra > 0 || opti->rrb > 0)
	{
		while (opti->rra > 0 && opti->rrb > 0)
		{
			opti->rra--;
			opti->rrb--;
			ft_printf("rrr\n");
			if (opti->rra == 0 || opti->rrb == 0)
				break;
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

}

void	make_opti(r_opti *opti)
{
	//*opti = malloc(sizeof(r_opti));
	opti->ra = 0;
	opti->rb = 0;
	opti->rra = 0;
	opti->rrb = 0;
}

void ft_lstprint2_next(int instruction)
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
