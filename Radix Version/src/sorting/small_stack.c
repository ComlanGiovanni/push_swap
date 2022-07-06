/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:35:36 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/28 17:23:40 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/*
	THIS FCT MANAGE SMALL STACK BY
	SA IF => 7 9
	CALLING FCT BY THE NUNBER OF ELEM
*/
void	small_stack(t_list *a)
{
	t_list	*copy_of_a;
	t_node	*first;
	t_node	*second;

	copy_of_a = duplicate_list(a);
	first = copy_of_a->first;
	second = copy_of_a->first->next;
	bubble_sort(a, first, second);
	true_idx(a, copy_of_a);
	free_list(copy_of_a);
	if (a->nbr_elm == 2)
		swap_stack_a(a);
	else if (a->nbr_elm == 3)
		stack_of_three(a);
	else if (a->nbr_elm == 4)
		stack_of_four(a);
	else if (a->nbr_elm == 5)
		stack_of_five(a);
}

/*
	
*/
t_list	*sort_and_attribute_idx(t_list *a)
{
	t_list	*copy_of_a;
	t_node	*first;
	t_node	*second;

	copy_of_a = duplicate_list(a);
	first = copy_of_a->first;
	second = copy_of_a->first->next;
	bubble_sort(a, first, second);
	true_idx(a, copy_of_a);
	free_list(copy_of_a);
	return (a);
}

/*
	THIS FCT HARD CODE OPTION LIKE 
	3 1 5  => sa  => 987 677 44 ra sa
	5 1 3  => ra  => 1  5  3  sa ra
	2 15 1 => rra
*/
void	stack_of_three(t_list *a)
{
	if (a->first->value == 2)
	{
		if (a->first->next->value == 0)
			rotate_stack_a(a);
		else
		{
			rotate_stack_a(a);
			swap_stack_a(a);
		}
	}
	else if (a->first->value == 1)
	{
		if (a->first->next->value == 0)
			swap_stack_a(a);
		else
			reverse_rotate_stack_a(a);
	}
	else if (a->first->value == 0)
	{
		swap_stack_a(a);
		rotate_stack_a(a);
	}
}

/*
		A		     B
	3  9  4  7 
	3  9  4  7  pb   3
	9  4  7    stof3 
	s  m  g
*/
void	stack_of_four(t_list *a)
{
	t_list	*b;

	b = init_list_of_link(-1);
	if (a->first->value == 0)
		top_is_first(a, b);
	else if (a->first->value == 1)
		top_is_second(a, b);
	else if (a->first->value == 2)
		top_is_third(a, b);
	else if (a->first->value == 3)
		top_is_fourth(a, b);
	free_list(b);
}

/*

*/
void	stack_of_five(t_list *a)
{
	t_list	*b;

	b = init_list_of_link(-1);
	push_stack_b_if_top_is_first(a, b);
	push_stack_b_if_top_is_second(a, b);
	stack_of_three_custom(2, 3, 4, a);
	push_stack_a(b, a);
	push_stack_a(b, a);
	free_list(b);
}
