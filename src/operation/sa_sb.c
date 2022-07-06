/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:50:23 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/05 23:27:57 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/**
 * @brief 
 * 
 * Swap the first 2 elements at the top of the stack.
 * Do nothing if there is only one or no elements.
 * 
 * we dont swap is top_a->next-> == NULL
 * meaning that the size of the stack is >= 2
 * so we do a simple swap with a tmp variable
 * 
 * @param info 
 */
void	sa(t_info *info)
{
	int	tmp;

	if (info->size_a < 2)
		return ;
	tmp = info->top_a->nbr;
	info->top_a->nbr = info->top_a->next->nbr;
	info->top_a->next->nbr = tmp;
}

/**
 * @brief 
 * 
 * Call of sa and write sa string
 * 
 * @param info 
 */
void	swap_stack_a(t_info *info)
{
	sa(info);
	write(STDOUT_FILENO, SA_MSG, ft_strlen(SA_MSG));
}

/**
 * @brief 
 * 
 * Swap the first 2 elements at the top of the stack
 * 
 * we dont swap is top_a->next-> == NULL
 * meaning that the size of the stack is >= 2
 * so we do a simple swap with a tmp variable
 * 
 * @param info 
 */
void	sb(t_info *info)
{
	int	tmp;

	if (info->size_b < 2)
		return ;
	tmp = info->top_b->nbr;
	info->top_b->nbr = info->top_b->next->nbr;
	info->top_b->next->nbr = tmp;
}

/**
 * @brief 
 * 
 * Call of sb and write sb string
 * 
 * @param info 
 */
void	swap_stack_b(t_info *info)
{
	sb(info);
	write(STDOUT_FILENO, SB_MSG, ft_strlen(SB_MSG));
}
