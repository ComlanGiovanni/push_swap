/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:55:57 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/28 12:10:46 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/*
	
*/
void	top_is_first(t_list *a, t_list *b)
{
	push_stack_b(a, b);
	stack_of_three_custom(1, 2, 3, a);
	push_stack_a(b, a);
}

/*
	
*/
void	top_is_second(t_list *a, t_list *b)
{
	push_stack_b(a, b);
	stack_of_three_custom(0, 2, 3, a);
	push_stack_a(b, a);
	swap_stack_a(a);
}

/*
	
*/
void	top_is_third(t_list *a, t_list *b)
{
	swap_stack_a(a);
	free_list(b);
	stack_of_four(a);
}

/*
	
*/
void	top_is_fourth(t_list *a, t_list *b)
{
	push_stack_b(a, b);
	stack_of_three_custom(0, 1, 2, a);
	push_stack_a(b, a);
	rotate_stack_a(a);
}
