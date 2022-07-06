/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:00:51 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/01 16:17:09 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/*
	THIS FCT CHECK IF THE FIRST LIST
	IS SORTED BY LOOPING AND COMPARE
	VALUE IF IT A THE GOOD PLACE PUT
	THE CURRENT IDX AT THE INDEX OF
	THE VALUE ELSE GO INC THE LIST WHO
	NEED TO BE SORTED
*/
void	true_idx(t_list *a, t_list *sorted)
{
	int		idx;
	t_node	*to_sorted_node;
	t_node	*sorted_node;

	idx = 0;
	to_sorted_node = a->first;
	sorted_node = sorted->first;
	while (idx < a->nbr_elm)
	{
		if (sorted_node->value == to_sorted_node->value)
		{
			to_sorted_node->idx = idx;
			idx++;
			sorted_node = sorted_node->next;
			to_sorted_node = a->first;
		}
		else
		{
			to_sorted_node = to_sorted_node->next;
		}
	}
	replace_value_by_idx(a);
}

/*
	THIS FCT JUST REPLACE VALUE BY INDEX
	BECAUSE AFTER ALL THE VAUE GET SORTED
*/
void	replace_value_by_idx(t_list *a)
{
	int			len;
	t_node		*tmp;

	len = 0;
	tmp = a->first;
	while (len < a->nbr_elm)
	{
		tmp->value = tmp->idx;
		tmp = tmp->next;
		len++;
	}
}

/*
	s stand for smallest
	m stand for middle
	g stand for greatest
*/
void	stack_of_three_custom(int s, int m, int g, t_list *a)
{
	if (a->first->value == g)
		top_is_greater(a, s);
	else if (a->first->value == m)
		top_is_median(a, s);
	else if (a->first->value == s)
		top_is_smallest(a);
}

/*
	
*/
void	empty_stack_b(t_list *a, t_list *b)
{
	while (b->first->value != -1)
	{
		push_stack_a(b, a);
		b->nbr_elm--;
		a->nbr_elm++;
	}
}

/*
	
*/
void	empty_stack_a(t_list *a, t_list *b)
{
	while (a->first->value != -1)
	{
		push_stack_b(b, a);
		a->nbr_elm--;
		b->nbr_elm++;
	}
}
