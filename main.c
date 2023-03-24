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
	t_list  *b;
	t_tab **tabm;
	int pos_line;
	int k;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	/*if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = ft_count_words(argv[1], ' ');
	}*/
	creat_list(&a, argv, argc);
	if (!a)
		return (0);
	tabm = make_tab(a);
	make_line(tabm, a);
	pos_line = found_line(tabm);
	k = 0;
	clear_tabs(tabm, pos_line, 0);
	chearch_add_min(a, &tabm[pos_line]);
		while (tabm && k < tabm[pos_line]->lens)
	{
		printf("%d ", tabm[pos_line]->tabs[k]);
		k++;
	}
	first_sort(&a, &b, tabm);
	// printf(" posline =%d\n", pos_line);
	/*for (int i = 0; i < 1; i++)
	{
		sa(&a);
	}*/
	/*while (a)
	{
		printf("%d ", a->content);
		a = a->next;
	}
	printf("\n");*/
	clear_tabs(tabm, pos_line, 1);
	ft_lstclear(&a);
	return (0);
}