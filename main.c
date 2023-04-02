#include "push_swap.h"

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
	int k;

	a = NULL;
	b = NULL;
	jtab = NULL;
	if (argc <= 2)
		return (0);
	creat_list(&a, argv, argc);
	if (!a)
		return (0);
	tabm = make_tab(a);
	make_line(tabm, a);
	pos_line = found_line(tabm);
	k = 0;
	clear_tabs(tabm, pos_line, 0);
	chearch_add_min(a, &tabm[pos_line]);
	printf("\nline = ");
	while (tabm && k < tabm[pos_line]->lens)
	{
		printf("%d ", tabm[pos_line]->tabs[k]);
		k++;
	}
	make_index_a(tabm[pos_line], &a);
	make_index_b(tabm[pos_line], &a);
	// first_sort(&a, &b, &tabm[pos_line]);
	printf("\n\n");
	replace_a(&a, &b, remontada(&a, &b, tabm[pos_line]->tabs[tabm[pos_line]->lens - 1]));
	tabi = index_tab(a, tabm[pos_line]);
	if (!tabi || tabi[0] == -1)
	{
		clear_all(a, tabm, pos_line, tabi);
		return (0);
	}
	k = 0;
	while (tabi[k] != -1)
	{
		printf("tabi[%d] = %d\n", k, tabi[k]);
		k++;
	}

	make_jtab(a, &jtab, tabi, tabm[pos_line]->lens);

	algo_note(a, jtab);
	printf("//////////////////////\n");
	print_tabj(jtab);
	clear_jtab(jtab);
	clear_all(a, tabm, pos_line, tabi);
	return (0);
}

void print_lst(t_list *a) // a supprimer
{
	while (a)
	{
		printf("content = %d ", a->content);
		printf("index = %d\n", a->index);
		a = a->next;
	}
	printf("////////////////////////\n");
}

void print_tabj(j_tab **jtab)
{
	int i;
	int j;

	i = 0;
	printf("//////////////////////\n");
	while (jtab[i])
	{
		j = 0;
		printf("jtab[%d]->tabs = ", i);
		while (jtab[i]->tabs[j])
		{
			printf("%d ", jtab[i]->tabs[j]);
			j++;
		}
		printf("\njtab[%d]->index = %d\n", i, jtab[i]->index);
		printf("jtab[%d]->s_len = %d\n", i, jtab[i]->s_len);
		printf("jtab[%d]->note = %d\n", i, jtab[i]->note);
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
