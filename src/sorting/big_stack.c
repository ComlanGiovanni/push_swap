/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:45:56 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/28 17:18:20 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/*
	THIS FCT
	
	The trickiest part must be the condition if ((num>>i)&1 == 1).
	The result of (num>>i)&1 must be 0 or 1, 
	which is the value of the (i + 1)-th bit of num.
	https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
	// faire linverse == 1 rotate et apres push //si cest zero
*/
void	push_last_bit_one(t_list *a, t_list *b, int size, int bit_max)
{
	int		idx;
	int		nbr;

	idx = 0;
	while (idx < size)
	{
		nbr = a->first->value;
		if (((nbr >> bit_max) & 1) == 0)
			push_stack_b(a, b);
		else
			rotate_stack_a(a);
		idx++;
	}
}

/*
	
*/
void	big_stack(t_list *a)
{
	t_list		*b;
	int			size;
	int			max_num;
	int			bit_max;

	b = init_list_of_link(-1);
	size = a->nbr_elm;
	max_num = size - 1;
	bit_max = 0;
	sort_and_attribute_idx(a);
	while (max_num >> bit_max != 0)
	{
		push_last_bit_one(a, b, size, bit_max);
		empty_stack_b(a, b);
		bit_max++;
	}
	free_list(b);
}

/*

t_list		*b;
	int			size;
	int			max_num;
	int			bit_max;
	int			idx[2];
	idx[0] = 0;
	idx[1] = 0;
	b = init_list_of_link(-1);
	size = a->nbr_elm;
	max_num = size - 1;
	bit_max = 0;
	sort_and_attribute_idx(a);
	while (max_num >> bit_max != 0)
	{
		push_last_bit_one(a, b, size, bit_max);
		empty_stack_b(a, b);
		bit_max++;
	}
	while (max_num >> bit_max != 0)
		bit_max++;
	
	while (idx[0] < bit_max)
	{
		idx[1] = 0;
		while (idx[1] < size / 2)
		{
			if ((( a->first->value >> idx[0]) & 1) == 0)
				push_stack_b(a, b);
			else
				rotate_stack_a(a);
			++idx[1];
		}
		while (b->first)
		{
			push_stack_a(a, b);
		}
		++idx[0];
	}
	*/
