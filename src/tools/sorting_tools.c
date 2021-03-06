/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:00:51 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/10 20:20:28 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/**
 * @brief 
 * 
 * get the minimum number
 * of a stack
 * and return it
 * 
 * @param stack 
 * @return int 
 */
int	ft_get_stack_min_nbr(t_stack *stack)
{
	int	min_nbr;

	min_nbr = stack->nbr;
	while (stack)
	{
		if (min_nbr > stack->nbr)
			min_nbr = stack->nbr;
		stack = stack->next;
	}
	return (min_nbr);
}

/**
 * @brief
 * 
 * get the maximum number of a stack
 * and return if
 * 
 * @param stack 
 * @return int 
 */
int	ft_get_stack_max_nbr(t_stack *stack)
{
	int	max_nbr;

	max_nbr = stack->nbr;
	while (stack)
	{
		if (max_nbr < stack->nbr)
		{
			max_nbr = stack->nbr;
		}
		stack = stack->next;
	}
	return (max_nbr);
}

/**
 * @brief 
 * 
 * if the move is negatif set it at pos
 * if we get the min move we return 1
 * 
 * @param move_for_a 
 * @param move_for_b 
 * @param idx_in_a 
 * @param idx_in_b 
 * @return int 
 */
int	ft_get_min(int move_for_a, int move_for_b, int idx_in_a, int idx_in_b)
{
	if (move_for_a < 0)
		move_for_a = move_for_a * -1;
	if (move_for_b < 0)
		move_for_b = move_for_b * -1;
	if (idx_in_a < 0)
		idx_in_a = idx_in_a * -1;
	if (idx_in_b < 0)
		idx_in_b = idx_in_b * -1;
	if (move_for_a + move_for_b > idx_in_a + idx_in_b)
		return (1);
	else
		return (0);
}

/**
 * @brief 
 * 
 * we need it to set the stack back
 * to put the good elem of the chunk
 * at the good pos in stack A because
 * or good sorting, or its messed
 * 
 *
 * if the move for the stack a is > 0
 * we simply rotate else we reverse
 * 
 * its more like a cypher
 * 
 * + move_for_a up
 * - move_for_b down
 * 
 * when we do the move we
 * decrease of increase move_for_a
 * 
 * do this while move_a ! = O
 * 
 * witch mean no move
 * 
 * @param info 
 * @param move_for_a 
 */
void	ft_shift_a(t_info *info, int move_for_a)
{
	while (move_for_a)
	{
		if (move_for_a > 0)
		{
			rotate_stack_a(info);
			move_for_a--;
		}
		else
		{
			reverse_rotate_a(info);
			move_for_a++;
		}
	}
}

/**
 * @brief 
 * 
 * we need it to set the stack back
 * to put the good elem of the chunk
 * at the good pos in stack A because
 * or good sorting, or its messed
 *
 * if the move for the stack a is > 0
 * we simply rotate else we reverse
 * 
 * its more like a cypher
 * 
 * + move_for_a up
 * - move_for_b down
 * 
 * when we do the move we
 * decrease of increase move_for_a
 * 
 * do this while move_a ! = O
 * 
 * witch mean no move
 * 
 * @param info 
 * @param move_for_a 
 */
void	ft_shift_b(t_info *info, int move_for_b)
{
	while (move_for_b)
	{
		if (move_for_b > 0)
		{
			rotate_stack_b(info);
			move_for_b--;
		}
		else
		{
			reverse_rotate_b(info);
			move_for_b++;
		}
	}
}
