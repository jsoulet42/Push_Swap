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
