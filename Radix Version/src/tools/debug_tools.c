/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:24:49 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/28 17:35:51 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/*
int	print_list(t_list *list)
{
	t_node	*node;

	if (list == NULL)
		return (1);
	node = list->first;
	while (node != NULL)
	{
		ft_putnbr_fd(node->value, 1);
        write(1, " [", 3);
		ft_putnbr_fd(node->idx, 1);
        write(1, " ]", 3);
        write(1, " -> ", 5);
		node = node->next;
	}
    write(1, "NULL\n", 6);
	return (0);
}
*/

/*
	RETURN THE LEN OF A NODE
*/

int	len_of_list(t_node *list)
{
	int	size;

	size = 0;
	if (list != NULL)
	{
		while (list != NULL)
		{
			size++;
			list = list->next;
		}
	}
	return (size);
}

/*
    SWAP 2 NODE
*/
void	swap_node(t_node *a, t_node *b)
{
	int	tmp;

	tmp = a->value;
	a->value = b->value;
	b->value = tmp;
}

/*
void show_list(t_node *list)
{
    if (list == NULL) return;

    while (list != NULL)
    {
        ft_putnbr_fd(list->value, 1);
        ft_putchar(32);
        list = list->next;
    }

    ft_putchar(10);
}
*/