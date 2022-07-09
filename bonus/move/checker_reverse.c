/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 04:27:32 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/09 16:50:34 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

/**
 * @brief 
 * 
 * REVERSE OF ROTATE COMMENT
 * 
 * @param stack 
 */
void	ft_rra(t_stack_a_b *stack)
{
	int	tmp;

	tmp = stack->stack_a.tab[stack->stack_a.used - 1];
	ft_push_down(stack->stack_a.tab, stack->stack_a.used);
	stack->stack_a.tab[0] = tmp;
}

/**
 * @brief 
 * 
 * REVERSE OF ROTATE COMMENT
 * 
 * @param stack 
 */
void	ft_rrb(t_stack_a_b *stack)
{
	int	tmp;

	tmp = stack->stack_b.tab[stack->stack_b.used - 1];
	ft_push_down(stack->stack_b.tab, stack->stack_b.used);
	stack->stack_b.tab[0] = tmp;
}

/**
 * @brief 
 * 
 * REVERSE OF ROTATE COMMENT
 * 
 * @param stack 
 */
void	ft_rrr(t_stack_a_b *stack)
{
	ft_rra(stack);
	ft_rrb(stack);
}
