#include "push_swap.h"

void	clear_tabs(t_tab **tabm, int pos_line, int offset)
{
	int	i;

	i = 0;
	if (offset == 1)
	{
		free(tabm[pos_line]->tabs);
		free(tabm[pos_line]);
		free (tabm);
		return ;
	}
	while (tabm[i])
	{
		if (pos_line != i)
		{
			free(tabm[i]->tabs);
			free(tabm[i]);
		}
		i++;
	}
}

void	chearch_add_min(t_list *a, t_tab **tabm)
{
	int	min;

	if (!a)
		return ;
	min = a->content;
	while (a)
	{
		if (min > a->content)
			min = a->content;
		a = a->next;
	}
	(*tabm)->tabs[(*tabm)->lens] = min;
	(*tabm)->lens++;
	
}

int	in_tab(t_list **a, t_tab **tabm)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (j < (*tabm)->lens)
	{
		if ((*a)->content == (*tabm)->tabs[i])
			return (1);
		if ((*a)->content != (*tabm)->tabs[i])
		{
			i++;
			j++;
		}
	}
	return (0);
}

void	first_sort(t_list **a, t_list **b, t_tab **tabm, int pos_line)
{
	int j;
	int temp;

	temp = ft_lstlast(a);
	j = 0;
	while (j < (*tabm)->lens)
	{
		if (in_tab(a, tabm) == 1)
		{
			ra(a);
		}
		else
		{
			pb(a, b);
			j++;
		}
	}
}
