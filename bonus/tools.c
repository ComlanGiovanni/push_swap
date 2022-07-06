/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:47:16 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/06 12:06:13 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	ft_check_sorted(t_info *info)
{
	t_stack	*curr;
	t_stack	*curr_next;

	curr = info->top_a->next;
	curr_next = info->top_a->next->next;
	while (curr_next != NULL)
	{
		if (curr->nbr < curr_next->nbr)
		{
			curr = curr_next;
			curr_next = curr_next->next;
		}
		else
			return (0);
	}
	return (1);
}

void	ft_print_res_commands(t_info *info)
{
	if (ft_check_sorted(info))
		write(STDERR_FILENO, BONUS_OK, ft_strlen(BONUS_OK));
	else
		write(STDERR_FILENO, BONUS_KO, ft_strlen(BONUS_KO));
	/*
	if (stack_a)
		free_list(stack_a);
	if (stack_b)
		free_list(stack_b);
	*/
}
