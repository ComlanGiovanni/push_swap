/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 14:57:37 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/02 00:33:01 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/**
 * @brief
 * 
 * we make sure that if the first nbr is > second_nbr
 * we swap_stack_a
 * 
 * we call ft_sort_stack_of_three if 3elem (5 case hard coded)
 * 
 * @param info 
 */
void	ft_sort_stack(t_info *info)
{
	if (info->size_a == 2)
	{
		if (info->top_a->nbr > info->top_a->next->nbr)
			swap_stack_a(info);
	}
	else if (info->size_a == 3)
		ft_sort_stack_of_three(info);
    else
		ft_sort_big_stack(info);
}
