/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:07:20 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/17 09:24:40 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define couleur(param) printf("\033[%sm", param)

void print_jtab2(j_tab **jtab2);

int main(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	t_tab **tabm;
	int *tabi;
	j_tab **jtab;
	int pos_line;

	a = NULL;
	b = NULL;
	jtab = NULL;
	if (argc <= 2)
		return (0);
	if (found_conditions(argc, argv) == 1)
		return (0);
	creat_list(&a, argv, argc);
	if (!a)
		return (0);
	tabm = make_tab(a);
	make_line(tabm, a);
	pos_line = found_line(tabm);
	clear_tabs(tabm, pos_line, 0);
	chearch_add_min(a, &tabm[pos_line]);
	make_index_a(tabm[pos_line], &a);
	make_index_b(tabm[pos_line], &a);
	tabi = index_tab(a, tabm[pos_line]);
	if (!tabi || tabi[0] == -1)
	{
		clear_all(a, tabm, pos_line, tabi);
		ft_printf("la creation de tabi a echouee\n");
		return (0);
	}

	make_jtab(&a, &jtab, tabi, tabm[pos_line]->lens);
	if (!jtab)
	{
		clear_all(a, tabm, pos_line, tabi);
		printf("la creation de jtab a echouee\n");
		return (0);
	}
	sort_p1(jtab, a);
	manager_friend(&a, &b, jtab);
	/*printf("lst a = \n");
	print_lst(a, -1, -1);
	exit(0);*/
	a_replace(&a, &b, 2);
	replace_a(&a, &b, remontada(&a, &b, tabm[pos_line]->tabs[tabm[pos_line]->lens - 1]));
	replace_s_len(jtab, b);

	//print_tabj(jtab);
	choice_p(&a, &b, jtab);
	a_replace(&a, &b, 0);
	/*printf("lst a = \n");
	print_lst(a, -1, -1);
	printf("lst b = \n");
	print_lst(b, -1, -1);*/
	clear_jtab(jtab);
	ft_lstclear(&b);
	clear_all(a, tabm, pos_line, tabi);
	ft_list_instruction(0);
	//print_nbr_instruction();
	return (0);
}

void print_lst(t_list *a, int index1, int index2) // a supprimer
{
	if (!a)
		return;
	while (a)
	{

		if (a->index == index1 && index1 != index2)
			couleur("31"); // vert
		if (a->index == index2 && index1 != index2)
			couleur("33"); // jaune
		printf("content = %d ", a->content);
		printf("index = %d\n", a->index);
		couleur("0"); // blanc
		/*if(a->index == index1 && index1 == index2)
			couleur("31"); // rouge*/
		// printf("content = %d ", a->content);
		// printf("index = %d\n", a->index);
		a = a->next;
	}
	couleur("0"); // blanc

	// ft_printf("////////////////////////\n");
}

void print_tabj(j_tab **jtab) // a supprimer
{
	int i;
	int j;
	int len;
	int p_lin_len;
	int h;
	int slen;

	i = 0;
	slen = 0;
	ft_printf("//////////////////////\n");

	while (jtab[i])
	{
		slen += jtab[i]->s_len;
		i++;
	}
	ft_printf("slen = %d\n", slen);
	i = 0;
	while (jtab[i])
	{
		j = 0;
		len = jtab[i]->s_len;
		ft_printf("jtab[%d]->tabs   = ", i);
		while (len != 0)
		{
			ft_printf("%d ", jtab[i]->tabs[j]);
			len--;
			j++;
		}
		ft_printf("\njtab[%d]->index  = %d\n", i, jtab[i]->index);
		ft_printf("jtab[%d]->s_len  = %d\n", i, jtab[i]->s_len);
		h = 0;
		ft_printf("jtab[%d]->exclu  =", i);
		while (jtab[i]->exclu[h] != -1)
		{
			ft_printf(" %d;", jtab[i]->exclu[h]);
			h++;
		}
		ft_printf("\n");
		h = 0;
		ft_printf("jtab[%d]->inclu  =", i);
		while (jtab[i]->inclu[h] != -1)
		{
			ft_printf(" %d;", jtab[i]->inclu[h]);
			h++;
		}
		ft_printf("\n");
		h = 0;
		ft_printf("jtab[%d]->p_line =", i);

		p_lin_len = 0;

		while (jtab[i]->p_line[h] != -1)
		{
			couleur("31"); // rouge
			// if (jtab[i]->p_line[h] != -1)
			p_lin_len += jtab[jtab[i]->p_line[h]]->s_len;

			if (jtab[i]->p_line[h] == -1)
				couleur("33"); // jaune
			ft_printf(" %d;", jtab[i]->p_line[h]);
			couleur("0");
			h++;
		}
		ft_printf("\np_line s_len    = %d\n", p_lin_len);
		i++;
		ft_printf("----------------------\n");
	}
}

void clear_all(t_list *a, t_tab **tabm, int pos_line, int *tabi)
{
	clear_tabs(tabm, pos_line, 1);
	ft_lstclear(&a);
	free(tabi);
}

void ft_print_tab(int *tab)
{
	int i;

	i = 0;
	while (tab[i] != -1)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
}

void creat_list(t_list **a, char **argv, int argc)
{
	int i;

	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
}

void print_jtab2(j_tab **jtab2) // a supprimer
{
	int i;
	int h;


	ft_printf("//////////////////////\n");

	i = 0;
	while (jtab2[i])
	{
		ft_printf("\n");
		h = 0;
		ft_printf("jtab2[%d]->inclu  =", i);
		while (h <  jtab2[i]->s_len)
		{
			ft_printf(" %d;", jtab2[i]->inclu[h]);
			h++;
		}
		i++;
		ft_printf("\n");
	}
}
