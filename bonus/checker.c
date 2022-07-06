/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:06:59 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/06 13:01:19 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	ft_commands(t_info *info, char *line)
{
	if (!(ft_strcmp(line, "sa")))
	{
		sa(info);
		write(1, "A : ", 3);
		ft_print_stack_a(info);
		return (0);
	}
	if (!(ft_strcmp(line, "sb")))
	{
		sb(info);
		write(1, "B : ", 3);
		ft_print_stack_b(info);
		return (0);
	}
	if (!(ft_strcmp(line, "ss")))
	{
		ss(info);
		write(1, "A : ", 3);
		ft_print_stack_a(info);
		write(1, "B : ", 3);
		ft_print_stack_b(info);
		return (0);
	}
	if (!(ft_strcmp(line, "pa")))
	{
		pa(info);
		write(1, "A : ", 3);
		ft_print_stack_a(info);
		write(1, "B : ", 3);
		ft_print_stack_b(info);
		return (0);
	}
	if (!(ft_strcmp(line, "pb")))
	{
		pb(info);
		write(1, "A : ", 3);
		ft_print_stack_a(info);
		write(1, "B : ", 3);
		ft_print_stack_b(info);
		return (0);
	}
	if (!(ft_strcmp(line, "ra")))
	{
		ra(info);
		write(1, "A : ", 3);
		ft_print_stack_a(info);
		return (0);
	}
	if (!(ft_strcmp(line, "rb")))
	{
		rb(info);
		write(1, "B : ", 3);
		ft_print_stack_b(info);
		return (0);
	}
	if (!(ft_strcmp(line, "rr")))
	{
		rr(info);
		write(1, "A : ", 3);
		ft_print_stack_a(info);
		write(1, "B : ", 3);
		ft_print_stack_b(info);
		return (0);
	}
	if (!(ft_strcmp(line, "rra")))
	{
		rra(info);
		write(1, "A : ", 3);
		ft_print_stack_a(info);
		return (0);
	}
	if (!(ft_strcmp(line, "rrb")))
	{
		rrb(info);
		write(1, "B : ", 3);
		ft_print_stack_b(info);
		return (0);
	}
	if (!(ft_strcmp(line, "rrr")))
	{
		rrr(info);
		write(1, "A : ", 3);
		ft_print_stack_a(info);
		write(1, "B : ", 3);
		ft_print_stack_b(info);
		return (0);
	}
	return (1);
}
