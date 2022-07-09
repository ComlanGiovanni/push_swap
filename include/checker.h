/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 02:12:03 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/09 23:57:02 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include "../lib/libft.h"

# define ERROR_MSG			"Error\n"
# define BONUS_OK			"OK\n"
# define BONUS_KO			"KO\n"
# define SA_MSG_CHECK		"sa"
# define SB_MSG_CHECK		"sb"
# define SS_MSG_CHECK		"ss"
# define PA_MSG_CHECK		"pa"
# define PB_MSG_CHECK		"pb"
# define RA_MSG_CHECK		"ra"
# define RB_MSG_CHECK		"rb"
# define RR_MSG_CHECK		"rr"
# define RRA_MSG_CHECK		"rra"
# define RRB_MSG_CHECK		"rrb"
# define RRR_MSG_CHECK		"rrr"

typedef struct s_pile
{
	int	*tab;
	int	size;
	int	used;
}	t_pile;

typedef struct s_stack_a_b
{
	struct s_pile		stack_a;
	struct s_pile		stack_b;
}	t_stack_a_b;

//../bonus/checker.c

void		ft_execute_commands(char *line, t_stack_a_b *stack);
int			ft_check_sorted_stack_a(t_stack_a_b *stack);

//../bonus/tools.c

char		*ft_move_to_str(char **argv);
int			ft_check_arg(char *str);
t_stack_a_b	ft_str_to_stack(char *nbr_joined);
char		**ft_init_stack_checker(char *nbr_joined, t_stack_a_b *stack);
int			ft_doublon_tab_nbr(t_stack_a_b *stack, int nbr);

//../bonus/free.c

int			ft_free_checker(t_stack_a_b *stack);
void		ft_free_fail_init(t_stack_a_b *stack);
void		ft_print_ok(void);
void		ft_print_ko(void);

//../bonus/move/checker_swap.c

void		ft_sa(t_stack_a_b *stack);
void		ft_sb(t_stack_a_b *stack);
void		ft_ss(t_stack_a_b *stack);

//../bonus/move/checker_push.c

void		ft_pa(t_stack_a_b *stack);
void		ft_pb(t_stack_a_b *stack);
void		ft_pp(t_stack_a_b *stack);

//../bonus/move/checker_rotate.c

void		ft_ra(t_stack_a_b *stack);
void		ft_rb(t_stack_a_b *stack);
void		ft_rr(t_stack_a_b *stack);

//../bonus/move/checker_reverse.c

void		ft_rra(t_stack_a_b *stack);
void		ft_rrb(t_stack_a_b *stack);
void		ft_rrr(t_stack_a_b *stack);

//../bonus/move/move_tools.c

void		ft_push_down(int *tab, int used);
void		ft_pop_up(int *tab, int used);

#endif
