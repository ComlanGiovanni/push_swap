/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:50:20 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/03 22:54:46 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/**
 * @brief 
 * 
 * Shift down all elements of stack by 1.
 * The last element becomes the first one.
 * 
 * we dont reverse_rotate if top_a->next-> == NULL
 * meaning that the size of the stack is >= 2
 * 
 * we take the bottom of the stack save it in tmp
 * shift the nbr on the prev and point the next to NULL
 * then put the tmp at the top at the place of NULL
 * so we attack the prev of top at NULL
 * the next of top_a is tmp->next of
 * prev of top_a witch is the tmp we save earlier
 * 
 * MIND BLOWING
 * 
 * https://media.geeksforgeeks.org/wp-content/uploads/
 * 20200318150826/ezgif.com-gif-maker1.gif
 * 
 * @param info 
 */
void	rra(t_info *info)
{
	t_stack	*tmp;

	if (info->size_a < 2)
		return ;
	tmp = info->bottom_a;
	info->bottom_a = info->bottom_a->prev;
	info->bottom_a->next = NULL;
	info->top_a->prev = tmp;
	tmp->next = info->top_a;
	info->top_a = tmp;
	info->top_a->prev = NULL;
}

/**
 * @brief 
 * 
 * Call of rra and write rra string
 * 
 * @param info 
 */
void	reverse_rotate_a(t_info *info)
{
    rra(info);
	write(STDOUT_FILENO, RRA_MSG, ft_strlen(RRA_MSG));
}

/**
 * @brief 
 * 
 * Shift down all elements of stack by 1.
 * The last element becomes the first one.
 * 
 * we dont reverse_rotate if top_b->next-> == NULL
 * meaning that the size of the stack is >= 2
 * 
 * we take the bottom of the stack save it in tmp
 * shift the nbr on the prev and point the next to NULL
 * then put the tmp at the top at the place of NULL
 * so we attack the prev of top at NULL
 * the next of top_b is tmp->next of
 * prev of top_b witch is the tmp we save earlier
 * 
 * MIND BLOWING
 * 
 * https://media.geeksforgeeks.org/wp-content/uploads/
 * 20200318150826/ezgif.com-gif-maker1.gif
 * 
 * @param info 
 */
void	rrb(t_info *info)
{
    t_stack	*tmp;

	if (info->size_b < 2)
		return ;
	tmp = info->bottom_b;
	info->bottom_b = info->bottom_b->prev;
	info->bottom_b->next = NULL;
	info->top_b->prev = tmp;
	tmp->next = info->top_b;
	info->top_b = tmp;
	info->top_b->prev = NULL;
}

/**
 * @brief 
 * 
 * Call of rrb and write rrb string
 * 
 * @param info 
 */
void	reverse_rotate_b(t_info *info)
{
    rrb(info);
	write(STDOUT_FILENO, RRB_MSG, ft_strlen(RRB_MSG));
}
