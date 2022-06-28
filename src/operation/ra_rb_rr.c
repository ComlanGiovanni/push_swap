/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:50:18 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/27 20:45:48 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/*
	THIS FCT SHIFT UP ALL ELM BY 1
    BY SAVING IN tmp_first_node THE
    FIRST NBR OF A AND PUT IT A THE
    LAST POS OF THE current VARIABLE
    WHO IS THE A STARTING BY THE
    SECOND

    return ;//write(2, "Error\n", 7);???
    
    end file
    need to assign the new list to a
    no dead ass it a pointer
    meed to clean the tmp

    	//if (a == NULL)
		//return ;
*/
void	rotate_stack(t_list *a)
{
	t_node	*tmp_first_node;
	t_node	*current;

	tmp_first_node = a->first;
	a->first = a->first->next;
	tmp_first_node->next = NULL;
	current = a->first;
	while (current->next != NULL)
		current = current->next;
	current->next = tmp_first_node;
}

//CALL ROTATE STACK AND WRITE RA
void	rotate_stack_a(t_list *a)
{
	rotate_stack(a);
	write(1, "ra\n", 4);
}

/*
    DELETE AFTER

void my_ra(struct node **list)
{
    struct node *current = *list;
    struct node *tmp = NULL;

    if (current == NULL) return;
    tmp = current;
    while (current->next != NULL)
        current = current->next;

    current->next = *list;
    *list = tmp->next;
    tmp->next = NULL;
}

*/

/*
	SHIFT UP ALL ELEMENT OF STACK BY 1
*/
void	rotate_stack_b(t_list *b)
{
	rotate_stack(b);
	write(1, "rb\n", 4);
}

/*
	RA AND RB AT THE SAME TIME
*/
void	rotate_stack_a_and_stack_b(t_list *a, t_list *b)
{
	rotate_stack_a(a);
	rotate_stack_b(b);
}
