/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:27:48 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/01 17:45:01 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/**
 * @brief 
 * 
 * Just the same code as sa and sb
 * 
 * [Wondering if ss can do one if the other did no success ?]
 * 
 * @param info 
 */
void	ss(t_info *info)
{
	int	tmp;

	if (info->size_a < 2 || info->size_b < 2)
		return ;
	tmp = info->top_a->nbr;
	info->top_a->nbr = info->top_a->next->nbr;
	info->top_a->next->nbr = tmp;
	tmp = info->top_b->nbr;
	info->top_b->nbr = info->top_b->next->nbr;
	info->top_b->next->nbr = tmp;
}

/**
 * @brief 
 * 
 * Call of ss and write ss string
 * 
 * @param info 
 */
void	swap_stack_a_and_b(t_info *info)
{
    ss(info);
    write(STDOUT_FILENO, SS_MSG, ft_strlen(SS_MSG));
}
