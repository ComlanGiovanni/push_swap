/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 04:27:41 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/09 16:53:22 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

/**
 * @brief 
 * 
 * if we used less than 2 idx we do nothing
 * else we swap with a tmp the 0 and the 1
 * 
 * @param stack 
 */
void	ft_sa(t_stack_a_b *stack)
{
	int	tmp;

	tmp = 0;
	if (stack->stack_a.used < 2)
		return ;
	tmp = stack->stack_a.tab[0];
	stack->stack_a.tab[0] = stack->stack_a.tab[1];
	stack->stack_a.tab[1] = tmp;
}

/**
 * @brief 
 * 
 * same logic with ft_sa
 * 
 * @param stack 
 */
void	ft_sb(t_stack_a_b *stack)
{
	int	tmp;

	tmp = 0;
	if (stack->stack_b.used < 2)
		return ;
	tmp = stack->stack_b.tab[0];
	stack->stack_b.tab[0] = stack->stack_b.tab[1];
	stack->stack_b.tab[1] = tmp;
}

/**
 * @brief
 * 
 * call bot function nothing much
 * 
 * @param stack
 */
void	ft_ss(t_stack_a_b *stack)
{
	ft_sa(stack);
	ft_sb(stack);
}
