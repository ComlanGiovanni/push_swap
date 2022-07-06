/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:50:18 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/05 23:28:16 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/**
 * @brief 
 * 
 * Shift up all elements of stack  by 1.
 * The first element becomes the last one.
 * 
 * Same process of rra read doc overthere
 * 
 * save the first elem but it the bottom
 * attach it to null same for the top->next
 * 
 * MIND BLOWING
 *
 * https://media.geeksforgeeks.org/wp-content/uploads/
 * 20200318150826/ezgif.com-gif-maker1.gif
 * 
 * we dont reverse if top_a->next-> == NULL
 * meaning that the size of the stack is >= 2
 * 
 * @param info 
 */
void	ra(t_info *info)
{
	t_stack	*tmp;

	if (info->size_a < 2)
		return ;
	tmp = info->top_a;
	info->top_a = info->top_a->next;
	info->top_a->prev = NULL;
	info->bottom_a->next = tmp;
	tmp->prev = info->bottom_a;
	info->bottom_a = tmp;
	info->bottom_a->next = NULL;
}

/**
 * @brief 
 * 
 * Call of ra and write ra string
 * 
 * @param info 
 */
void	rotate_stack_a(t_info *info)
{
	ra(info);
	write(STDOUT_FILENO, RA_MSG, ft_strlen(RA_MSG));
}

/**
 * @brief 
 * 
 * Shift up all elements of stack  by 1.
 * The first element becomes the last one.
 * 
 * Same process of rra read doc overthere
 * 
 * save the first elem but it the bottom
 * attach it to null same for the top->next
 * 
 * MIND BLOWING
 *
 * https://media.geeksforgeeks.org/wp-content/uploads/
 * 20200318150826/ezgif.com-gif-maker1.gif
 * 
 * we dont reverse if top_b->next-> == NULL
 * meaning that the size of the stack is >= 2
 * 
 * 
 * 
 * @param info 
 */
void	rb(t_info *info)
{
	t_stack	*tmp;

	if (info->size_b < 2)
		return ;
	tmp = info->top_b;
	info->top_b = info->top_b->next;
	info->top_b->prev = NULL;
	info->bottom_b->next = tmp;
	tmp->prev = info->bottom_b;
	info->bottom_b = tmp;
	info->bottom_a->next = NULL;
}

/**
 * @brief 
 * 
 * Call of rb and write rb string
 * 
 * @param info 
 */
void	rotate_stack_b(t_info *info)
{
	rb(info);
	write(STDOUT_FILENO, RB_MSG, ft_strlen(RB_MSG));
}
