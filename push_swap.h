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

typedef  struct k_tab
{
    int *tabs;
    int s_len;
	int	note;
	int index;
}               j_tab;

//---------------------------- instructions -----------------------------------//

void 	sa(t_list **a);

void    ft_ss(t_list **a, t_list **b, int ist);

void    pa(t_list **a, t_list **b);

void    ra(t_list **a);

void    ft_rr(t_list **a, t_list **b, int ist);

void    rra(t_list **a);

void    ft_rrr(t_list **a, t_list **b, int ist);

void	ft_p(t_list **a, t_list **b, int ist);

//----------------------------- manager_tab ----------------------------------//

t_tab	**make_tab(t_list *a);

int		*index_tab(t_list *a,t_tab *tabm);

int		in_tabi(t_list *a, t_tab *tabm, int *tabi);

int		in_tab(t_list *a, t_tab *tabm);

//----------------------------- manager_tab2 ---------------------------------//

void	make_jtab(t_list *a, j_tab ***jtab, int *tabi, int t_len);

int		tabi_len(int *tabi);

void	mall_jtab(t_list *a, j_tab ***jtab, int len, int t_len);

int		make_jtab2(t_list *a, j_tab *jtab, int index);

//----------------------------- manager_min ---------------------------------//

void	replace_a(t_list **a, t_list **b, int action);

int		remontada_2(t_list **a, t_list **b, int chearch, int action, int i);

void	chearch_add_min(t_list *a, t_tab **tabm);

int		remontada(t_list **a, t_list **b, int chearch);

//------------------------------ free_all -----------------------------------//

void	clear_tabs(t_tab **tabm, int pos_line, int offset);

void	clear_jtab(j_tab **jtab);

void clear_all(t_list *a, t_tab **tabm, int pos_line, int *tabi);

//------------------------------ make_index ---------------------------------//

void	make_index_b(t_tab *t, t_list **b);

void	make_index_a(t_tab *tabm, t_list **a);

void	make_index_b2(t_tab *t, t_list **b);

//------------------------------- make_line ---------------------------------//

void	fusion_tab(t_tab **struc, int len_max, int pos_struc, int i);

int		found_line(t_tab **struc);

void	make_line(t_tab **struc, t_list *a);

void	chearch_line(t_tab **struc, int i);

//------------------------------- main --------------------------------------//

void	creat_list(t_list **a, char **argv, int argc);

void	print_lst(t_list *a); // a supprimer

void 	print_tabj(j_tab **jtab); // a supprimer

void clear_jtab(j_tab **jtab);

//void	first_sort(t_list **a, t_list **b, t_tab **tabm);

//------------------------------- notation -----------------------------------//

void algo_note(t_list *a, j_tab **jtab);

int	algo_note2(t_list *a, int index);

#endif
