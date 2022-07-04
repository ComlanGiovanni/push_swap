/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:56:23 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/28 23:18:09 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	p_stack(t_list *a, t_list *b)
{
	t_node	*tmp;

	tmp = a->first;
	a->first = a->first->next;
	tmp->next = b->first;
	b->first = tmp;
	b->nbr_elm--;
	a->nbr_elm++;
}

void	p_stack_a(t_list *a, t_list *b)
{
	p_stack(a, b);
}

void	p_stack_b(t_list *a, t_list *b)
{
	t_node	*tmp;

	tmp = a->first;
	a->first = a->first->next;
	tmp->next = b->first;
	b->first = tmp;
	a->nbr_elm--;
	b->nbr_elm++;
}
