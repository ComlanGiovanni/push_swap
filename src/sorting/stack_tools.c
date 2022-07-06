/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 14:57:37 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/06 12:51:41 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/**
 * @brief
 * 
 * we make sure that if the first nbr is > second_nbr
 * we swap_stack_a
 * 
 * we call ft_sort_stack_of_three if 3elem (5 case hard coded)
 * 
 * @param info 
 */
void	ft_sort_stack(t_info *info)
{
	if (info->size_a == 2)
	{
		if (info->top_a->nbr > info->top_a->next->nbr)
			swap_stack_a(info);
	}
	else if (info->size_a == 3)
		ft_sort_stack_of_three(info);
	else
		ft_sort_big_stack(info);
}

void	ft_print_stack_a(t_info *info)
{
	t_stack	*current;

	if (info == NULL && info->top_a == NULL )
		return ;
	current = info->top_a->next;
	while (current != NULL)
	{
		write(1, " [", 3);
		ft_putnbr_fd(current->nbr, 1);
		write(1, "]", 2);
		write(1, " -> ", 5);
		current = current->next;
	}
	write(1, "NULL\n", 6);
}

void	ft_print_stack_b(t_info *info)
{
	t_stack	*current;

	if (info == NULL && info->top_b == NULL )
		return ;
	current = info->top_b->next;
	while (current != NULL)
	{
		write(1, " [", 3);
		ft_putnbr_fd(current->nbr, 1);
		write(1, "]", 2);
		write(1, " -> ", 5);
		current = current->next;
	}
	write(1, "NULL\n", 6);
}
