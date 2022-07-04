/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:27:54 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/03 23:55:20 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"


/**
 * @brief 
 * 
 * Read rra and rrb comment
 * 
 * @param info 
 */
void	rr(t_info *info)
{
	t_stack	*tmp;

	if (info->size_b < 2 || info->size_a < 2)
		return ;
	tmp = info->top_a;
	info->top_a = info->top_a->next;
	info->top_a->prev = NULL;
	info->bottom_a->next = tmp;
	tmp->prev = info->bottom_a;
	info->bottom_a = tmp;
	info->bottom_a->next = NULL;
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
 * Call of rr and write rr string
 * 
 * @param info 
 */
void	rotate_stack_a_and_b(t_info *info)
{
    rr(info);
    write(STDOUT_FILENO, RR_MSG, ft_strlen(RR_MSG));
}

/**
 * @brief
 * 
 * [Wondering if ss can do one if the other did no success ?]
 * 
 * @param info 
 */
void	rrr(t_info *info)
{
	t_stack	*tmp;

	if (info->size_b < 2 || info->size_a < 2)
		return ;
	tmp = info->bottom_a;
	info->bottom_a = info->bottom_a->prev;
	info->bottom_a->next = NULL;
	info->top_a->prev = tmp;
	tmp->next = info->top_a;
	info->top_a = tmp;
	info->top_a->prev = NULL;
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
 * Call of rrr and write rrr string
 * 
 * @param info 
 */
void	reverse_rotate_stack_a_and_b(t_info *info)
{
    rrr(info);
    write(STDOUT_FILENO, RRR_MSG, ft_strlen(RRR_MSG));
}
