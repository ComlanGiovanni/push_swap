/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 14:57:37 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/08 00:35:22 by gcomlan          ###   ########.fr       */
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

/**
 * @brief 
 * 
 * We dont print if NULL
 * 
 * save the first elem in current
 * while we are not at the end
 * we print the number with 
 * ft_putnbr_fd in 1
 * the move the cursor of the current
 * at the next elm
 * print NULL at the end because we are
 * not at the end
 * 
 * 
 * @param info 
 */
void	ft_print_stack_a(t_info *info)
{
	t_stack	*current;

	if (info == NULL && info->top_a == NULL )
		return ;
	current = info->top_a;
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

/**
 * @brief 
 * 
 * We dont print if NULL
 * 
 * save the first elem in current
 * while we are not at the end
 * we print the number with 
 * ft_putnbr_fd in 1
 * the move the cursor of the current
 * at the next elm
 * print NULL at the end because we are
 * not at the end
 * 
 * 
 * @param info 
 */
void	ft_print_stack_b(t_info *info)
{
	t_stack	*current;

	if (info == NULL && info->top_b == NULL )
		return ;
	current = info->top_b;
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

/**
 * @brief 
 * 
 * Copy past comment from ft_free_if_err
 * same vibe just free for spacific case
 * 
 * in fact you realy dont need to send tab_size you can
 * strlen in when need
 * 
 * so this fct its the fucking leaks debugging
 * 
 * we free the stack A of all the number
 * we free the tab of nbr that we malloc in the main
 * we free the big stack who got stack A B we only free
 * it at the end to avoid still reachable
 * 
 * @param error_code 
 * @param info 
 * @param tab_nbr
 */
void	ft_free_maxint(int err_code, t_info *info, int *tab_nbr, char **split)
{
	ft_free_str(split);
	free(info->top_a);
	free(tab_nbr);
	free(info);
	ft_print_error(err_code);
}

/**
 * @brief 
 * 
 * Copy past comment from ft_free_if_err
 * same vibe just free for spacific case
 * 
 * in fact you realy dont need to send tab_size you can
 * strlen in when need
 * 
 * so this fct its the fucking leaks debugging
 * 
 * we free the stack A of all the number
 * we free the tab of nbr that we malloc in the main
 * we free the big stack who got stack A B we only free
 * it at the end to avoid still reachable
 * 
 * @param error_code 
 * @param info 
 */
void	ft_free_no_dig(int err_code, t_info *info)
{
	free(info->top_a);
	free(info);
	ft_print_error(err_code);
}
