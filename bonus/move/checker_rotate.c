/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 04:28:29 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/09 17:17:20 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

/**
 * @brief 
 * 
 * we save the first elm and push up all the elm
 *  tmp = 1;
 *  1 2 3 4    2 3 4 4
 * 
 * and the replace 4 by tmp so
 * 
 * 2 3 4 1
 * 
 * 
 * @param stack 
 */
void	ft_ra(t_stack_a_b *stack)
{
	int	tmp;

	tmp = stack->stack_a.tab[0];
	ft_pop_up(stack->stack_a.tab, stack->stack_a.used);
	stack->stack_a.tab[stack->stack_a.used - 1] = tmp;
}

/**
 * @brief 
 * 
 * read ft_ra doc
 * 
 * @param stack 
 */
void	ft_rb(t_stack_a_b *stack)
{
	int	tmp;

	tmp = stack->stack_b.tab[0];
	ft_pop_up(stack->stack_b.tab, stack->stack_b.used);
	stack->stack_b.tab[stack->stack_b.used - 1] = tmp;
}

/**
 * @brief 
 * 
 * call ft_ra and ft_rb
 * 
 * @param stack 
 */
void	ft_rr(t_stack_a_b *stack)
{
	ft_ra(stack);
	ft_rb(stack);
}
