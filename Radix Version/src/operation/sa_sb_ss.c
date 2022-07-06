/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:50:23 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/28 17:35:40 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/*
    THIS FCT SWAP THE FIRS 2 ELEMENTS
    OF A LIST IF THIS SECOND IS NOT NULL


	//else write(2, "Error\n", 7);???
*/
void	swap_stack(t_list *a)
{
	t_node	*tmp;

	if (a->first->next != NULL)
	{
		tmp = a->first;
		a->first = a->first->next;
		tmp->next = a->first->next;
		a->first->next = tmp;
	}
}

//CALL OF SWAP_STACK AND WRITE SA
void	swap_stack_a(t_list *a)
{
	swap_stack(a);
	write(1, "sa\n", 4);
}

//CALL OF SWAP_STACK AND WRITE SB
void	swap_stack_b(t_list *b)
{
	swap_stack(b);
	write(1, "sb\n", 4);
}

// SA AND SB AT THE SAME TIME
void	swap_stack_a_and_stack_b(t_list *a, t_list *b)
{
	swap_stack_a(a);
	swap_stack_b(b);
}

/*
	THIS FCT BUBBLE SORT THE SMALL STACK
	WE LOOP UNTIL THE LIST IS SORTED
	BY MOVING THE FIST BY 1 WILL MOVING THE
	SECOND TO WE SWAP IS THE FIRST IS >
*/
void	bubble_sort(t_list *a, t_node *first, t_node *second)
{
	int	idx;

	idx = 0;
	while (idx < a->nbr_elm - 1)
	{
		while (second != NULL)
		{
			if (second->value < first->value)
			{
				swap_node(first, second);
				second = second->next;
			}
			else
				second = second->next;
		}
		idx++;
		first = first->next;
		second = first->next;
	}
}
