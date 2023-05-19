#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // a virer avant de push
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_tab
{
	int *tabs;
	int lens;
}			t_tab;

typedef  struct k_tab
{
    int	*tabs;
	int	*p_line;
	int	*pl_temp;
	int	*exclu;
	int	*inclu;
	int	*excl_2;
	int *tab_f;
	int	s_len;
	int	index;
	int	pl_len;
	t_list *a;
}			j_tab;

typedef struct l_tab
{
	int *current1;
	int *current2;
	int current1_len;
	int current2_len;
}			m_tab;

typedef struct s_opti
{
	int rra;
	int rrb;
	int ra;
	int rb;
}			r_opti;

//---------------------------- instructions -----------------------------------//

void	print_nbr_instruction();

void	sa(t_list **a);

void	ft_ss(t_list ***a, t_list ***b, int ist);

void	pa(t_list **a, t_list **b);

void	ra(t_list **a);

void	ft_rr(t_list ***a, t_list ***b, int ist);

void	rra(t_list **a);

void	ft_rrr(t_list ***a, t_list ***b, int ist);

void	ft_p(t_list ***a, t_list ***b, int ist);

void	ft_list_instruction(int instruction);

void	ft_lstprint2(t_list *list);

void	ft_lstprint2_next(int instruction);

void	make_opti(r_opti *opti);

void	ft_print_opti_rrr(r_opti *opti);

void	ft_print_opti_rr(r_opti *opti);


//----------------------------- manager_tab ----------------------------------//

t_tab	**make_tab(t_list *a);

int		*index_tab(t_list *a,t_tab *tabm);

int		in_tabi(t_list *a, t_tab *tabm, int *tabi);

int		in_tab(t_list *a, t_tab *tabm);

//----------------------------- manager_tab2 ---------------------------------//

void	make_jtab(t_list **a, j_tab ***jtab, int *tabi, int t_len);

int		tabi_len(int *tabi);

void	mall_jtab(t_list *a, j_tab ***jtab, int len, int t_len);

int		make_jtab2(t_list *a, j_tab *jtab, int index);

void	mall_jtab3(j_tab **jtab, int len);


//----------------------------- manager_min ---------------------------------//

void	replace_a(t_list **a, t_list **b, int action);

int		remontada_2(t_list **a, t_list **b, int chearch, int i);

void	chearch_add_min(t_list *a, t_tab **tabm);

int		remontada(t_list **a, t_list **b, int chearch);

//------------------------------ free_all -----------------------------------//

void	clear_tabs(t_tab **tabm, int pos_line, int offset);

void	clear_jtab(j_tab **jtab);

void	clear_all(t_list *a, t_tab **tabm, int pos_line, int *tabi);

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

void	print_lst(t_list *a, int index1, int index2); // a supprimer

void 	print_tabj(j_tab **jtab); // a supprimer

void	ft_print_tab(int *tab);

//------------------------------ push_in_b.c ---------------------------------//

void	manager_friend(t_list **a, t_list **b, j_tab **jtab);

int		push_in_b(t_list ***a, t_list ***b, int *best1, int *best2);

void	pushb_2(t_list ***a, t_list ***b, int id1, int id2);

int		verif(t_list *a);

void	push_in_b_suit2(t_list ***a, t_list ***b, int id1, int id2);

void	maj_m_tab(j_tab **jtab, m_tab **mtab);

m_tab	*make_mtab(j_tab **jtab, t_list *a);

//------------------------------ conditions ----------------------------------//

int		found_double(int argc, char **argv);

int		found_char(int argc, char **argv);

int		found_int(int argc, char **argv);

int 	found_conditions(int argc, char **argv);


//------------------------------ push_in_a ----------------------------------//

void a_replace(t_list **a, t_list **b, int index);

//------------------------------- pattern_line -------------------------------//
int		verif_exclu(int *exclu, int index);

int		found_first_in_a(j_tab *jtab, t_list *a);

int		found_index(j_tab **jtab, int index);

void	fill_exclu(t_list *a, j_tab **jtab, int *p_line);

void	fill_inclu(j_tab **jtab);

//------------------------------- patern_line2 -------------------------------//

int		*make_p_line(j_tab **jtab);

int		tab_len(int *tab);

void	clear_pl_temp(int *pl_temp, int i);

int		sch_int(int *tab, int nb);

int		*m_p_line(j_tab **jtab, int current, int next, int step);

int		*best_s_len(j_tab **jtab, int current);

int		*chx_best_pl(j_tab **jtab, int current);

int		jtab_len(j_tab **jtab);

void	sch_diff_pline(int *tab1, int *tab2);


//------------------------------- patern_line3 -------------------------------//

int		*copie_current(j_tab **jtab, int *current);

int		p_line_len(j_tab **jtab, int *p_line);

int		best_p_line(j_tab **jtab);

void	maj_exclu(j_tab **jtab, int pos_pline);

void	copy_pl(j_tab ** jtab, int *src, int dest);

void	rest_s_len(j_tab **jtab, int *pos_p_line);

void sort_p1(j_tab **t2, t_list *a);

void	choice_p(t_list **a, t_list **b, j_tab **jtab);

void	replace_s_len(j_tab **jtab, t_list *b);

void	open_door(t_list **a, t_list **b, int pos_p);

void	b_replace(t_list **a, t_list **b, int index);


int		min_nb(j_tab **t2, int i);

int		next_min(j_tab **t2, int i, int nb);

#endif
