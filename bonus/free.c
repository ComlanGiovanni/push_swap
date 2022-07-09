/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 03:21:15 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/09 23:56:17 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

/**
 * @brief 
 * 
 * if stack != NULL
 * free stack a and b if they exist
 * 
 * //ft_putendl_fd(NULL, 2);
 * @param stack 
 * @return int 
 */
int	ft_free_checker(t_stack_a_b *stack)
{
	if (stack)
	{
		if (stack->stack_a.tab)
			free(stack->stack_a.tab);
		if (stack->stack_b.tab)
			free(stack->stack_b.tab);
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief 
 * 
 * this fct free if init faill
 * so we free the stack exit
 * and write error wite a exit failure
 * 
 * @param stack 
 */
void	ft_free_fail_init(t_stack_a_b *stack)
{
	if (stack)
	{
		if (stack->stack_a.tab)
			free(stack->stack_a.tab);
		if (stack->stack_b.tab)
			free(stack->stack_b.tab);
	}
	write(STDERR_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
	exit(EXIT_FAILURE);
}

void	ft_print_ok(void)
{
	write(STDIN_FILENO, BONUS_OK, ft_strlen(BONUS_OK));
	exit(EXIT_SUCCESS);
}

void	ft_print_ko(void)
{
	write(STDIN_FILENO, BONUS_KO, ft_strlen(BONUS_KO));
	exit(EXIT_FAILURE);
}
