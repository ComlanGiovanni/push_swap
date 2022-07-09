/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:50:14 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/08 23:29:30 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/**
 * @brief CEST LHEURE DU REWIIIIINNND
 * 
 * Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
 * 
 * We can not push in bif is empty/ size is less than 1
 * 
 * we save the top elem of stack b and if there is more than 1 elem
 * we put the cursor in it and put NULL at prev to delete the elem
 * we just save,,,, if the nothing in stack A we create a tnp like this
 * [save]tmp(value/nbr)->[[NULL]] //tmp->next   then but it in top_a
 * and the bottom_a too,,, we link the tmp to top_a //->next ->prev
 * then we affect the linkage at top_a
 * 
 * wee dont forget to update the size of each stack
 * 
 * @param info 
 */
void	pa(t_info *info)
{
	t_stack	*tmp;

	if (info->size_b < 1)
		return ;
	tmp = info->top_b;
	if (info->size_b > 1)
	{
		info->top_b = info->top_b->next;
		info->top_b->prev = NULL;
	}
	if (info->size_a == 0)
	{
		tmp->next = NULL;
		info->top_a = tmp;
		info->bottom_a = tmp;
	}
	else
	{
		tmp->next = info->top_a;
		info->top_a->prev = tmp;
		info->top_a = tmp;
	}
	info->size_a++;
	info->size_b--;
}

/**
 * @brief
 * 
 * Call of pa and write pa string
 * 
 * @param info 
 */
void	push_stack_a(t_info *info)
{
	pa(info);
	write(STDOUT_FILENO, PA_MSG, ft_strlen(PA_MSG));
}

/**
 * @brief TERRA LE PB LE DD LE PB
 * 
 * Take the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty.
 * 
 * We can not push in a if is empty/size is less than 1
 * 
 * Same as pa just replace [a/b] [b/a]
 * 
 * we save the top elem of stack b and if there is more than 1 elem
 * we put the cursor in it and put NULL at prev to delete the elem
 * we just save,,,, if the nothing in stack A we create a tnp like this
 * [save]tmp(value/nbr)->[[NULL]] //tmp->next   then but it in top_a
 * and the bottom_a too,,, we link the tmp to top_a //->next ->prev
 * then we affect the linkage at top_a
 * 
 * wee dont forget to update the size of each stack
 * 
 * @param info 
 */
void	pb(t_info *info)
{
	t_stack	*tmp;

	if (info->size_a < 1)
		return ;
	tmp = info->top_a;
	if (info->size_a > 1)
	{
		info->top_a = info->top_a->next;
		info->top_a->prev = NULL;
	}
	if (info->size_b == 0)
	{
		tmp->next = NULL;
		info->top_b = tmp;
		info->bottom_b = tmp;
	}
	else
	{
		tmp->next = info->top_b;
		info->top_b->prev = tmp;
		info->top_b = tmp;
	}
	info->size_a--;
	info->size_b++;
}

/**
 * @brief 
 * 
 * Call of pb and write pb string
 * 
 * @param info 
 */
void	push_stack_b(t_info *info)
{
	pb(info);
	write(STDOUT_FILENO, PB_MSG, ft_strlen(PB_MSG));
}
