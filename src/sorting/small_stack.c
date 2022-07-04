/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:35:36 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/01 19:02:27 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/**
 * @brief
 * 
 * We hard code all the possibility for 3 numbers
 * 
 * we get the first the second and the third  (nbr/value)
 * 
 * 	    3 2 1   =>  sa   =>   2 3 1   rra   =>  1 3 1
 *      5 1 3   =>  ra   =>   1 3 5
 *      4 8 7   =>  sa   =>   8 4 7   ra    =>  4 7 8
 *      3 2 6   =>  sa   =>   2 3 6
 *      2 7 1   =>  rra  =>   1 2 7    
 * 
 * 
 * @param info 
 */
void	ft_sort_stack_of_three(t_info *info)
{
	int	first;
	int	second;
	int	third;

	first = info->top_a->nbr;
	second = info->top_a->next->nbr;
	third = info->top_a->next->next->nbr;
	if ((first > second) && (second > third) && (third < first))
	{
		swap_stack_a(info);
		reverse_rotate_a(info);
	}
	else if ((first > second) && (second < third) && (third < first))
		rotate_stack_a(info);
	else if ((first < second) && (second > third) && (third > first))
	{
		swap_stack_a(info);
		rotate_stack_a(info);
	}
	else if ((first > second) && (second < third) && (third > first))
		swap_stack_a(info);
	else if ((first < second) && (second > third) && (third < first))
		reverse_rotate_a(info);
}
