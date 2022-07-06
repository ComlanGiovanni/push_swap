/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:50:20 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/28 17:41:30 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/*
    THIS FCT STORE THE LAST NODE
    IN TMP NULL THE VARIABLE WHO
    STORE IT BEFORE AND THEN PUT
    THE FIRST ELEM OF A AT THE
    SECOND POS OF TMP

    WE CHECK BEFORE IF THER IS A
    LEAST 2 ELEM NULL EXCLUDED

	if (a == NULL || a->first == NULL)
		return ;

	 //my old check
	 //write(2, "Error\n", 7);
	 //meed to clean the tmp ?
*/
void	reverse_stack(t_list *a)
{
	t_node	*last_node;
	t_node	*tmp;

	last_node = a->first;
	while (last_node->next->next != NULL)
		last_node = last_node->next;
	tmp = last_node->next;
	last_node->next = NULL;
	tmp->next = a->first;
	a->first = tmp;
}

//reverse_rotate_stack_a
void	reverse_rotate_stack_a(t_list *a)
{
	reverse_stack(a);
	write(1, "rra\n", 5);
}

/*
	THIS FONCTION CALL RRA BECAUSE IT THE SAME OPERATION
*/
void	reverse_rotate_stack_b(t_list *b)
{
	reverse_stack(b);
	write(1, "rrb\n", 5);
}

/*
	THIS FCT CALL RRA AND RRB AT THE SAME TIME
*/
void	reverse_rotate_stack_a_and_stack_b(t_list *a, t_list *b)
{
	reverse_rotate_stack_a(a);
	reverse_rotate_stack_b(b);
}
