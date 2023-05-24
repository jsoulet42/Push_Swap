/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <jsoulet@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:42:08 by jsoulet           #+#    #+#             */
/*   Updated: 2023/05/24 13:02:56 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_tab
{
	int	*tabs;
	int	lens;
}			t_tab;

typedef struct k_tab
{
	int		*tabs;
	int		*p_line;
	int		*pl_temp;
	int		*exclu;
	int		*inclu;
	int		*excl_2;
	int		s_len;
	int		index;
	int		pl_len;
	t_list	*a;
}			t_jtb;

typedef struct l_tab
{
	int	*current1;
	int	*current2;
	int	current1_len;
	int	current2_len;
}			t_mtb;

typedef struct s_opti
{
	int	rra;
	int	rrb;
	int	ra;
	int	rb;
}			t_ropti;

//---------------------------- instructions ----------------------------------//

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

void	ft_print_opti_rr(t_ropti *opti, int bool);

void	ft_print_opti_rrr(t_ropti *opti, int bool);

void	make_opti(t_ropti *opti);

//----------------------------- manager_tab ----------------------------------//

t_tab	**make_tab(t_list *a);

int		*index_tab(t_list *a, t_tab *tabm);

int		in_tabi(t_list *a, t_tab *tabm, int *tabi);

int		in_tab(t_list *a, t_tab *tabm);

//----------------------------- manager_tab2 ---------------------------------//

void	make_jtab(t_list **a, t_jtb ***jtab, int *tabi, int t_len);

int		tabi_len(int *tabi);

void	mall_jtab(t_list *a, t_jtb ***jtab, int len, int t_len);

int		make_jtab2(t_list *a, t_jtb *jtab, int index);

void	mall_jtab3(t_jtb **jtab, int len);

//----------------------------- manager_min ---------------------------------//

void	replace_a(t_list **a, t_list **b, int action);

int		remontada_2(t_list **a, t_list **b, int chearch, int i);

void	chearch_add_min(t_list *a, t_tab **tabm);

int		rmtada(t_list **a, t_list **b, int chearch);

//------------------------------ free_all -----------------------------------//

void	clear_tabs(t_tab **tabm, t_tab **pos_line, int offset);

void	clear_jtab(t_jtb **jtab);

void	clear_all(t_list *a, t_tab **tabm, t_tab **pos_line, int *tabi);

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

void	creat_list(t_list **a, char **argv, int on);

void	push_swap(char **argv, int on);

//------------------------------ push_in_b.c ---------------------------------//

void	manager_friend(t_list **a, t_list **b, t_jtb **jtab);

int		push_in_b(t_list ***a, t_list ***b, int *best1, int *best2);

void	pushb_2(t_list ***a, t_list ***b, int id1, int id2);

int		verif(t_list *a);

void	push_in_b_suit2(t_list ***a, t_list ***b, int id1, int id2);

t_mtb	*make_mtab(t_jtb **jtab, t_list *a);

//------------------------------ conditions ----------------------------------//

int		found_double(int argc, char **argv);

int		found_char(int argc, char **argv);

int		found_int(int argc, char **argv);

void	found_conditions(int argc, char **argv, int on, int i);

//------------------------------ push_in_a ----------------------------------//

void	a_replace(t_list **a, t_list **b, int index);

void	copy_tabs(int *src, int *dest, int len);

//------------------------------- pattern_line -------------------------------//
int		verif_exclu(int *exclu, int index);

int		found_first_in_a(t_jtb *jtab, t_list *a);

int		found_index(t_jtb **jtab, int index);

void	fill_exclu(t_list *a, t_jtb **jtab, int *p_line);

void	fill_inclu(t_jtb **t);

//------------------------------- patern_line2 -------------------------------//

int		*make_p_line(t_jtb **jtab);

int		tab_len(int *tab);

void	clear_pl_temp(int *pl_temp, int i);

int		sch_int(int *tab, int nb);

int		*m_p_line(t_jtb **jtab, int current, int next, int step);

int		*best_s_len(t_jtb **jtab, int current);

int		*chx_best_pl(t_jtb **jtab, int current);

int		jtab_len(t_jtb **jtab);

int		*chx_best_pl2(int *pl_temp, int *p_line, int i);

//------------------------------- patern_line3 -------------------------------//

int		*copie_current(t_jtb **jtab, int *current);

int		p_line_len(t_jtb **jtab, int *p_line);

int		best_p_line(t_jtb **jtab);

void	copy_pl(t_jtb **jtab, int *src, int dest);

void	rest_s_len(t_jtb **jtab, int *pos_p_line);
void	sort_p1(t_jtb **t2, t_list *a);
void	choice_p(t_list **a, t_list **b, t_jtb **jtab, int i);
void	replace_s_len(t_jtb **jtab, t_list *b);
void	open_door(t_list **a, t_list **b, int pos_p);
void	b_replace(t_list **a, t_list **b, int index);
int		min_nb(t_jtb **t2, int i);
int		next_min(t_jtb **t2, int i, int nb);
void	sort_p(t_list ***a, t_list ***b, t_jtb **jtab, int i);
int		last_rotate(t_list **b, int *tabs, int j, int l);
int		verif_rotate(t_list *b, int *tabs, int j, int l);
int		verif_rotate2(t_list *b, int i, int k);
int		verif_idx_a(t_list *a, int pos_p);
int		found_index_max(t_list *b);
int		sort_p_suit(t_list ***b, int *tabs, int j, int l);
int		found_len_max(t_jtb **jtab);
int		*quart(t_list *b, int len);
void	quart2(t_list *b, int i, int index_tmp, int **tab_quart);
int		choice_between_500_or_100(t_list *b, int bool);
void	free_argv(char **argv, int on);
void	ft_low_input(int argc, char **argv,	int on);
void	ft_three_arg(char **argv);
void	ft_four_arg(char **argv);
void	ft_three_arg_lst(t_list **a);
void	ft_five_arg(char **argv, int on);
int		ft_min_in_a(t_list *a);
int		ft_min2_in_a(t_list *a, int min);
int		ft_pos_in_a(t_list *a, int min);
int		ft_five_arg_2(t_list **a, t_list **b);
void	ft_five_arg_3(t_list **a, t_list **b);
void	ft_five_arg_end(t_list **a, t_list **b);
void	ft_tabi_empty(t_list **a, t_list **b);
void	verif_end(t_list *a);
void	make_tabi_jtab(t_list **a, t_list **b, t_tab **tabm, t_tab *line);
void	choice_p_2(t_list **a, t_list **b, t_jtb **jtab);

//------------------------------- low_input -------------------------------//

void	ft_three_arg_2(char **argv);
void	ft_four_arg_2(char **argv);
void	ft_low_input_2(int argc, char **argv, int on);
int		verif_order_input(t_list *a);
void	ft_low_input_2(int argc, char **argv, int on);

#endif
