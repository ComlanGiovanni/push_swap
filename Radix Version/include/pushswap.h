/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:37:51 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/28 19:59:13 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define ERROR_MSG	"Error\n"

# include "../lib/libft.h"

typedef struct s_node
{
	int				value;
	int				idx;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	t_node	*first;
	int		nbr_elm;
}	t_list;

//main.c
int		check_already_sorted(t_list *nbr_list);

//src/parsing/parsing_str.c
t_list	*parsing_str(int nbr_int, char **tab_int);
int		check_digit_str(int nbr_int, char **tab_int);
int		check_overflow_str(int nbr_int, char **tab_int);
int		check_doublon_str(int nbr_int, char **tab_int);
t_list	*tab_to_list_str(int nbr_int, char **tab_int);

//src/parsing/parsing_arg.c
t_list	*parsing_arg(int ac, char **av);
int		check_digit_arg(int ac, char **av);
int		check_overflow_arg(int ac, char **av);
int		check_doublon_arg(int ac, char **av);
t_list	*tab_to_list_arg(int nbr_int, char **tab_int);

//src/tools/linkedlist_tools.c
t_list	*init_list_of_link(int nbr);
int		add_front(t_list *list, int nbr);
void	free_list(t_list *list);
t_list	*duplicate_list(t_list *a);
void	add_at_the_end(t_list *list, t_node *idx, int nbr);

//src/tools/debug_tools.c
//int	print_list(t_list *list);
int		len_of_list(t_node *list);
void	swap_node(t_node *a, t_node *b);
//void show_list(t_node *list);

//src/tools/sorting_tools.c  
void	true_idx(t_list *a, t_list *sorted);
void	replace_value_by_idx(t_list *a);
void	stack_of_three_custom(int s, int m, int g, t_list *a);
void	empty_stack_b(t_list *a, t_list *b);
void	empty_stack_a(t_list *a, t_list *b);

//src/sorting/small_stack.c
void	small_stack(t_list *a);
t_list	*sort_and_attribute_idx(t_list *a);
void	stack_of_three(t_list *a);
void	stack_of_four(t_list *a);
void	stack_of_five(t_list *a);

//src/operation/sa_sb_ss.c
void	swap_stack(t_list *a);
void	swap_stack_a(t_list *a);
void	swap_stack_b(t_list *b);
void	swap_stack_a_and_stack_b(t_list *a, t_list *b);
void	bubble_sort(t_list *a, t_node *first, t_node *second);

//src/operation/rra_rrb_rrr.c
void	reverse_stack(t_list *a);
void	reverse_rotate_stack_a(t_list *a);
void	reverse_rotate_stack_b(t_list *b);
void	reverse_rotate_stack_a_and_stack_b(t_list *a, t_list *b);

//src/operation/ra_rb_rr.c
void	rotate_stack(t_list *a);
void	rotate_stack_a(t_list *a);
void	rotate_stack_b(t_list *b);
void	rotate_stack_a_and_stack_b(t_list *a, t_list *b);

//src/sorting/stack_tools.c
void	top_is_greater(t_list *a, int s);
void	top_is_median(t_list *a, int s);
void	top_is_smallest(t_list *a);

//src/sorting/small_stack_tools.c
void	top_is_first(t_list *a, t_list *b);
void	top_is_second(t_list *a, t_list *b);
void	top_is_third(t_list *a, t_list *b);
void	top_is_fourth(t_list *a, t_list *b);

//src/operation/pa_pb.c
void	push_stack(t_list *a, t_list *b);
void	push_stack_a(t_list *a, t_list *b);
void	push_stack_b(t_list *a, t_list *b);
void	push_stack_b_if_top_is_first(t_list *a, t_list *b);
void	push_stack_b_if_top_is_second(t_list *a, t_list *b);

//src/sorting/big_stack.c
void	push_last_bit_one(t_list *a, t_list *b, int size, int bit_max);
void	big_stack(t_list *a);

#endif
