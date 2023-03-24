#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // a virer avant de push
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include "libft.h"

typedef  struct s_tab
{
    int *tabs;
    int lens;
}               t_tab;

/*typedef struct s_list
{
    int             content;
    unsigned int    index; // index of the element in the stack
    struct s_list   *next;
}          t_list;*/

void	creat_list(t_list **a, char **argv, int argc);

void	first_sort(t_list **a, t_list **b, t_tab **tabm, int pos_line);

void	clear_tabs(t_tab **tabm, int pos_line, int offset);

t_tab    **make_tab(t_list *a);

void fusion_tab(t_tab **struc, int len_max, int pos_struc, int i);

int	found_line(t_tab **struc);

void    make_line(t_tab **struc, t_list *a);

void chearch_line(t_tab **struc, int i);

void 	sa(t_list **a);

void    ss(t_list **a, t_list **b);

void    pa(t_list **a, t_list **b);

void    pb(t_list **a, t_list **b);

void    ra(t_list **a);

void    rr(t_list **a, t_list **b);

void    rra(t_list **a);

void    rrr(t_list **a, t_list **b);

#endif