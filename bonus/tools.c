/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:47:16 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/29 11:04:15 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0 && n != -2147483648)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

int	print_list(t_list *list)
{
	t_node	*node;

	if (list == NULL)
		return (1);
	node = list->first;
	while (node != NULL)
	{
		write(1, " [", 3);
		ft_putnbr_fd(node->value, 1);
        write(1, "]", 2);
        write(1, " -> ", 5);
		node = node->next;
	}
    write(1, "NULL\n", 6);
	return (0);
}

int	check_sorted(t_list *nbr_list)
{
	t_node	*c;
	t_node	*d;

	c = nbr_list->first;
	d = nbr_list->first->next;
	while (d != NULL)
	{
		if (c->value < d->value)
		{
			c = d;
			d = d->next;
		}
		else
			return (0);
	}
	return (1);
}

void	print_res_commands(t_list *stack_a, t_list *stack_b)
{
	if (check_sorted(stack_a))
		write(2, "OK\n", 7);
	else
		write(2, "KO\n", 7);

	if (stack_a)
		free_list(stack_a);
	if (stack_b)
		free_list(stack_b);
}
