/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:29:46 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/29 11:06:13 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

t_list	*init_list()
{
	t_node	*node;
	t_list	*list;

	list = malloc(sizeof(*list));
	node = malloc(sizeof(*node));
	if (list == NULL || node == NULL)
	{
		write(2, ERROR_MSG, 7);
		return (NULL);
	}
	//node->value = nbr;
	//node->next = NULL;
	list->first = node;
	list->nbr_elm = 0;
	return (list);
}

int	main(int argc, char **argv)
{
    char	*line;
    t_list	*stack_a;
    t_list	*stack_b;

	stack_a = (t_list *)malloc(sizeof(t_list));
	stack_b = (t_list *)malloc(sizeof(t_list));

	stack_a = NULL;
	stack_b = init_list();

	if (argc < 2)
		return (0);
    if (argc > 2)
	{
        stack_a = parsing_arg(argc, argv);
	}

    if (stack_a == NULL)
	{
		write(2, ERROR_MSG, 7);
		return (-1);
	}

	while (get_next_line(0, &line))
	{
		if (commands(stack_a, stack_b, line))
		{
			write(2, ERROR_MSG, 7);
			if(check_sorted(stack_a) && (stack_b == NULL)) 
				print_res_commands(stack_a, stack_b);
			return (-1);
		}
		free(line);
	}

	//print_res_commands(stack_a, stack_b);
	return (0);
}
