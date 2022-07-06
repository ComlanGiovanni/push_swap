/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:50:14 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/28 12:13:51 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/*
	THIS FONCTON SAVE THE FIRST ELE
	OF A PUT THE SECOND ELM OF A AT 
	THE FIRST AND THEN PUT THE FIRST 
	ELM OF B AT THE SECOND POS OF TMP
	THEN CHANGE THE NUMBER OF NBR_ELM 
*/

//no NULL MANAGEMENT ? //else write(2, "Error\n", 7);???
void	push_stack(t_list *a, t_list *b)
{
	t_node	*tmp;

	tmp = a->first;
	a->first = a->first->next;
	tmp->next = b->first;
	b->first = tmp;
	b->nbr_elm--;
	a->nbr_elm++;
}

/*
	CEST LHEURE DU REWIND
*/
void	push_stack_a(t_list *a, t_list *b)
{
	push_stack(a, b);
	write(1, "pa\n", 4);
}

/*
	TERRA LE PB LE DD LE PB
*/
void	push_stack_b(t_list *a, t_list *b)
{
	t_node	*tmp;

	tmp = a->first;
	a->first = a->first->next;
	tmp->next = b->first;
	b->first = tmp;
	a->nbr_elm--;
	b->nbr_elm++;
	write(1, "pb\n", 4);
}

/*
	
*/
void	push_stack_b_if_top_is_first(t_list *a, t_list *b)
{
	if (a->first->value == 0)
		push_stack_b(a, b);
	else if (a->first->next->value == 0)
	{
		swap_stack_a(a);
		push_stack_b(a, b);
	}
	else if (a->first->next->next->value == 0)
	{
		rotate_stack_a(a);
		rotate_stack_a(a);
		push_stack_b(a, b);
	}
	else if (a->first->next->next->next->value == 0)
	{
		reverse_rotate_stack_a(a);
		reverse_rotate_stack_a(a);
		push_stack_b(a, b);
	}
	else if (a->first->next->next->next->next->value == 0)
	{
		reverse_rotate_stack_a(a);
		push_stack_b(a, b);
	}
}

/*
	
*/
void	push_stack_b_if_top_is_second(t_list *a, t_list *b)
{
	if (a->first->value == 1)
		push_stack_b(a, b);
	else if (a->first->next->value == 1)
	{
		swap_stack_a(a);
		push_stack_b(a, b);
	}
	else if (a->first->next->next->value == 1)
	{
		rotate_stack_a(a);
		rotate_stack_a(a);
		push_stack_b(a, b);
	}
	else if (a->first->next->next->next->value)
	{
		reverse_rotate_stack_a(a);
		push_stack_b(a, b);
	}
}
