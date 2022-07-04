/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 14:57:37 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/26 15:26:57 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/*
	
*/
void	top_is_greater(t_list *a, int s)
{
	if (a->first->next->value == s)
		rotate_stack_a(a);
	else
	{
		rotate_stack_a(a);
		swap_stack_a(a);
	}
}

/*
	
*/
void	top_is_median(t_list *a, int s)
{
	if (a->first->next->value == s)
		swap_stack_a(a);
	else
		reverse_rotate_stack_a(a);
}

/*
	
*/
void	top_is_smallest(t_list *a)
{
	swap_stack_a(a);
	rotate_stack_a(a);
}
