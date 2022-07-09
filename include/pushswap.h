/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:37:51 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/09 03:56:47 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../lib/libft.h"

/* Define of move string */

# define ERROR_MSG	"Error\n"
# define SA_MSG		"sa\n"
# define SB_MSG		"sb\n"
# define SS_MSG		"ss\n"
# define PA_MSG		"pa\n"
# define PB_MSG		"pb\n"
# define RA_MSG		"ra\n"
# define RB_MSG		"rb\n"
# define RR_MSG		"rr\n"
# define RRA_MSG	"rra\n"
# define RRB_MSG	"rrb\n"
# define RRR_MSG	"rrr\n"

/* Node of a doubly linked list */

typedef struct s_stack
{
	int					nbr;
	struct s_stack		*prev;
	struct s_stack		*next;
}	t_stack;

typedef struct s_info
{
	int					*tab;
	int					size_a;
	int					size_b;
	struct s_stack		*top_a;
	struct s_stack		*top_b;
	struct s_stack		*bottom_a;
	struct s_stack		*bottom_b;
}	t_info;

//main.c

//src/operation/pa_pb.c

void	pa(t_info *info);
void	push_stack_a(t_info *info);
void	pb(t_info *info);
void	push_stack_b(t_info *info);

//src/operation/ra_rb.c

void	ra(t_info *info);
void	rotate_stack_a(t_info *info);
void	rb(t_info *info);
void	rotate_stack_b(t_info *info);

//src/operation/rr_rrr.c

void	rr(t_info *info);
void	rotate_stack_a_and_b(t_info *info);
void	rrr(t_info *info);
void	reverse_rotate_stack_a_and_b(t_info *info);

//src/operation/rra_rrb.c

void	rra(t_info *info);
void	reverse_rotate_a(t_info *info);
void	rrb(t_info *info);
void	reverse_rotate_b(t_info *info);

//src/operation/sa_sb.c

void	sa(t_info *info);
void	swap_stack_a(t_info *info);
void	sb(t_info *info);
void	swap_stack_b(t_info *info);

//src/operation/ss.c

void	ss(t_info *info);
void	swap_stack_a_and_b(t_info *info);

//src/parsing/parsing_tools.c

int		ft_get_str_size(t_info *info, int argc, char **argv);
int		*ft_argv_in_tab(t_info *info, int argc, char **argv, int tab_size);
void	ft_nbr_in_tab(t_info *info, int *tab_nbr, int *tab_idx, char **split);
void	ft_tab_in_info(t_info *info, int *tab_nbr, int tab_size);
int		ft_get_size_of(char **splitted_nbr_str);

//src/sorting/big_stack_tools.c

int		ft_set_location_in_a(int number, t_info *info);
int		ft_set_a_location_min(t_info *info);
int		ft_set_a_location_max(t_info *info);
int		ft_set_a_location_mid(int number, t_info *info);
void	ft_shift_a_and_b(t_info *info, int *move_for_a, int *move_for_b);

//src/sorting/big_stack.c

void	ft_sort_big_stack(t_info *info);
void	ft_get_pivot_and_split(t_info *info);
void	ft_split_by_three(t_info *info, int pivot_1, int pivot_2);
void	ft_sort_last_chunk(t_info *info);
void	ft_get_min_move(t_info *info, int *move_for_a, int *move_for_b);

//src/sorting/stack_tools.c

void	ft_sort_stack_of_three(t_info *info);
void	ft_print_stack_a(t_info *info);
void	ft_print_stack_b(t_info *info);
void	ft_free_maxint(int err_code, t_info *info, int *tab_nbr, char **split);
void	ft_free_no_dig(int err_code, t_info *info);

//src/sorting/small_stack.c

void	ft_sort_stack(t_info *info);

//src/tools/debug_tools.c

int		ft_print_error(int error_code);
t_info	*ft_init_info(void);
t_stack	*ft_init_stack(void);
int		ft_check_int(t_info *info, int *tab_nbr, char **split, const char *str);
void	ft_free_if_err(int err_code, t_info *info, int *tab_nbr, int tab_size);

//src/tools/linked_list_tools.c

void	ft_check_tab_sorted(t_info *info, int *tab_nbr, int tab_size, int idx);
void	ft_free_str(char **str);
void	ft_free_a(t_info *info, int tab_size);
void	ft_free_b(t_info *info, int tab_size);

//src/tools/sorting_tools.c

int		ft_get_stack_min_nbr(t_stack *stack);
int		ft_get_stack_max_nbr(t_stack *stack);
int		ft_get_min(int move_for_a, int move_for_b, int idx_in_a, int idx_in_b);
void	ft_shift_a(t_info *info, int move_for_a);
void	ft_shift_b(t_info *info, int move_for_b);

#endif
