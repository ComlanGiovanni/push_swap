/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 04:27:35 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/09 16:48:34 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

/**
 * @brief 
 * 
 * if there is nothing is b we stop
 * if there is nothing in a we put the top
 * element b in it
 * 
 * shit down all the elem
 * put at the top the elem we want
 * pop up the stack where we take they elem 
 * we insert int the stack we push down
 * 
 * @param stack 
 */
void	ft_pa(t_stack_a_b *stack)
{
	if (stack->stack_b.size < 1)
		return ;
	if (stack->stack_a.used == 0)
		stack->stack_a.tab[0] = stack->stack_b.tab[0];
	else
	{
		ft_push_down(stack->stack_a.tab, stack->stack_a.used);
		stack->stack_a.tab[0] = stack->stack_b.tab[0];
	}
	ft_pop_up(stack->stack_b.tab, stack->stack_b.used);
	stack->stack_a.used++;
	stack->stack_b.used--;
}

/**
 * @brief 
 * 
 * Same logic for ft_pa
 * 
 * @param stack 
 */
void	ft_pb(t_stack_a_b *stack)
{
	if (stack->stack_a.size < 1)
		return ;
	if (stack->stack_b.used == 0)
		stack->stack_b.tab[0] = stack->stack_a.tab[0];
	else
	{
		ft_push_down(stack->stack_b.tab, stack->stack_b.used);
		stack->stack_b.tab[0] = stack->stack_a.tab[0];
	}
	ft_pop_up(stack->stack_a.tab, stack->stack_a.used);
	stack->stack_b.used++;
	stack->stack_a.used--;
}

/**
 * @brief
 * 
 * LOOOOOOL
 * 
 * @param stack 
 */
void	ft_pp(t_stack_a_b *stack)
{
	ft_pa(stack);
	ft_pb(stack);
}
