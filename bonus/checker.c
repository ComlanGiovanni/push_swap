/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 02:22:46 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/09 23:47:57 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

/**
 * @brief 
 * 
 * 
 * we compare the ascii value of line send in par by
 * get next line who is waiting for user input
 * the if equal to on of the move sa sb rr ss etc
 * we do the move else we print error and free the stack
 * 
 * @param line 
 * @param stack 
 */
void	ft_execute_commands(char *line, t_stack_a_b *stack)
{
	if (!ft_strcmp(line, SA_MSG_CHECK))
		ft_sa(stack);
	else if (!ft_strcmp(line, SB_MSG_CHECK))
		ft_sb(stack);
	else if (!ft_strcmp(line, SS_MSG_CHECK))
		ft_ss(stack);
	else if (!ft_strcmp(line, PA_MSG_CHECK))
		ft_pa(stack);
	else if (!ft_strcmp(line, PB_MSG_CHECK))
		ft_pb(stack);
	else if (!ft_strcmp(line, RA_MSG_CHECK))
		ft_ra(stack);
	else if (!ft_strcmp(line, RB_MSG_CHECK))
		ft_rb(stack);
	else if (!ft_strcmp(line, RR_MSG_CHECK))
		ft_rr(stack);
	else if (!ft_strcmp(line, RRA_MSG_CHECK))
		ft_rra(stack);
	else if (!ft_strcmp(line, RRB_MSG_CHECK))
		ft_rrb(stack);
	else if (!ft_strcmp(line, RRR_MSG_CHECK))
		ft_rrr(stack);
	else
		ft_free_fail_init(stack);
}

/**
 * @brief 
 * 
 * We return 0 on of the elem is > at the idx+1(next)
 * While looping util the and the stack a
 * 
 * @param stack 
 * @return int 
 */
int	ft_check_sorted_stack_a(t_stack_a_b *stack)
{
	int	idx;

	idx = 0;
	while (idx < stack->stack_a.size - 1)
	{
		if (stack->stack_a.tab[idx] > stack->stack_a.tab[idx + 1])
			return (0);
		idx++;
	}
	return (1);
}
