/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:06:59 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/29 10:55:27 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	commands(t_list *stack_a, t_list *stack_b, char *line)
{
	if (!(ft_strcmp(line, "sa")))
	{
		s_stack_a(stack_a);
		write(1, "A : ", 3);
        print_list(stack_a);
		return (0);
	}
	if (!(ft_strcmp(line, "sb")))
	{
		s_stack_b(stack_b);
        write(1, "B : ", 3);
        print_list(stack_b);
		return (0);
	}
	if (!(ft_strcmp(line, "ss")))
	{
		s_stack_a_and_stack_b(stack_a, stack_b);
        write(1, "A : ", 3);
        print_list(stack_a);
        write(1, "B : ", 3);
        print_list(stack_b);
		return (0);
	}
	if (!(ft_strcmp(line, "pa")))
	{
		p_stack_a(stack_a, stack_b);
        write(1, "A : ", 3);
        print_list(stack_a);
        write(1, "B : ", 3);
        print_list(stack_b);
		return (0);
	}
	if (!(ft_strcmp(line, "pb")))
	{
        p_stack_b(stack_a, stack_b);
		write(1, "A : ", 3);
        print_list(stack_a);
        write(1, "B : ", 3);
        print_list(stack_b);
		return (0);
	}
	if (!(ft_strcmp(line, "ra")))
	{
		ro_stack_a(stack_a);
		write(1, "A : ", 3);
        print_list(stack_a);
		return (0);
	}
	if (!(ft_strcmp(line, "rb")))
	{
		ro_stack_b(stack_b);
		write(1, "B : ", 3);
        print_list(stack_b);
		return (0);
	}
	if (!(ft_strcmp(line, "rr")))
	{
		ro_stack_a_and_stack_b(stack_a, stack_b);
		write(1, "A : ", 3);
        print_list(stack_a);
        write(1, "B : ", 3);
        print_list(stack_b);
		return (0);
	}
	if (!(ft_strcmp(line, "rra")))
	{
		re_rotate_stack_a(stack_a);
		write(1, "A : ", 3);
        print_list(stack_a);
		return (0);
	}
	if (!(ft_strcmp(line, "rrb")))
	{
		re_rotate_stack_b(stack_b);
		write(1, "B : ", 3);
        print_list(stack_b);
		return (0);
	}	
	if (!(ft_strcmp(line, "rrr")))
	{
		re_rotate_stack_a_and_stack_b(stack_a, stack_b);
		write(1, "A : ", 3);
        print_list(stack_a);
        write(1, "B : ", 3);
        print_list(stack_b);
		return (0);
	}
	return (1);
}
