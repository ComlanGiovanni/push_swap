/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 02:11:26 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/09 23:57:45 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../include/get_next_line.h"

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	main(int argc, char **argv)
{
	char		*str;
	char		*line;
	t_stack_a_b	stack;

	if (argc == 1)
		return (EXIT_SUCCESS);
	line = NULL;
	str = ft_move_to_str(argv);
	stack = ft_str_to_stack(str);
	while (get_next_line(0, &line) == 1)
	{
		ft_execute_commands(line, &stack);
		free(line);
	}
	free(line);
	if (ft_check_sorted_stack_a(&stack) && !stack.stack_b.used)
		ft_print_ok();
	else
		ft_print_ko();
	return (ft_free_checker(&stack));
}
