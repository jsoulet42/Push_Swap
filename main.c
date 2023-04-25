/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:07:20 by jsoulet           #+#    #+#             */
/*   Updated: 2023/04/24 15:33:59 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define couleur(param) printf("\033[%sm",param)

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
	/*printf("\nline = ");
	while (tabm && k < tabm[pos_line]->lens)
	{
		printf("%d ", tabm[pos_line]->tabs[k]);
		k++;
	}*/
	make_index_a(tabm[pos_line], &a);
	make_index_b(tabm[pos_line], &a);
	//printf("\n\n");
	tabi = index_tab(a, tabm[pos_line]);
	if (!tabi || tabi[0] == -1)
	{
		clear_all(a, tabm, pos_line, tabi);
		ft_printf("la creation de tabi a echouee\n");
		return (0);
	}
	/*int k = 0;
	while (tabi[k] != -1)
	{
		printf("tabi[%d] = %d\n", k, tabi[k]);
		k++;
	}*/
	make_jtab(a, &jtab, tabi, tabm[pos_line]->lens);
	if (!jtab)
	{
		clear_all(a, tabm, pos_line, tabi);
		printf("la creation de jtab a echouee\n");
		return (0);
	}

	fill_exclu(&a, jtab);
	fill_inclu(jtab);
	make_p_line(jtab);

	//print_tabj(jtab);
	//printf("tabi_len = %d\n", tabi_len(tabi));
	//make_best_all(jtab, tabi_len(tabi));
	print_tabj(jtab);
	manager_friend(&a, &b, jtab);
	//a_replace(&a, &b);
	//replace_a(&a, &b, remontada(&a, &b, tabm[pos_line]->tabs[tabm[pos_line]->lens - 1]));
	//printf("//////////////////////\n");
	/*
	printf("lst a = \n");
	print_lst(a);
	printf("lst b = \n");
	print_lst(b);*/


	clear_jtab(jtab);
	ft_lstclear(&b);
	clear_all(a, tabm, pos_line, tabi);
	return (0);
}

void print_lst(t_list *a) // a supprimer
{
	if (!a)
		return ;
	while (a)
	{
		printf("content = %d ", a->content);
		printf("index = %d\n", a->index);
		a = a->next;
	}
	printf("////////////////////////\n");
}

void print_tabj(j_tab **jtab) // a supprimer
{
	int i;
	int j;
	int len;
	int p_lin_len;

	i = 0;

	printf("//////////////////////\n");
	int slen = 0;
	while (jtab[i])
	{
		slen += jtab[i]->s_len;
		i++;
	}
	printf("slen = %d\n", slen);
	i = 0;
	while (jtab[i])
	{
		j = 0;
		len = jtab[i]->s_len;
		printf("jtab[%d]->tabs   = ", i);
		while (len != 0)
		{
			printf("%d ", jtab[i]->tabs[j]);
			len --;
			j++;
		}
		printf("\njtab[%d]->index  = %d\n", i, jtab[i]->index);

		/*if (jtab[i]->s_len >= slen % 60)
			couleur("31"); // rouge
		if (jtab[i]->s_len < slen % 60 && jtab[i]->s_len >= slen % 30)
			couleur("33"); // jaune
		else if (jtab[i]->s_len < slen % 30)
			couleur("32"); // vert*/
		printf("jtab[%d]->s_len  = %d\n", i, jtab[i]->s_len);
		//couleur("0");
		int h = 0;
		printf("jtab[%d]->exclu  =", i);
		while (jtab[i]->exclu[h] != -1)
		{
			printf(" %d;", jtab[i]->exclu[h]);
			h++;
		}
		printf("\n");
		h = 0;
		printf("jtab[%d]->inclu  =", i);
		while (jtab[i]->inclu[h] != -1)
		{
			printf(" %d;", jtab[i]->inclu[h]);
			h++;
		}
		printf("\n");
		h = 0;
		printf("jtab[%d]->p_line =", i);

		p_lin_len = 0;

		while (jtab[i]->p_line[h] != -1)
		{
			couleur("31"); // rouge
			//if (jtab[i]->p_line[h] != -1)
			p_lin_len += jtab[jtab[i]->p_line[h]]->s_len;

			if (jtab[i]->p_line[h] == -1)
				couleur("33"); // jaune
			printf(" %d;", jtab[i]->p_line[h]);
			couleur("0");
			h++;
		}

		printf("\np_line s_len    = %d\n", p_lin_len);
		i++;
		printf("----------------------\n");
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
