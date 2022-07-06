/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:29:46 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/06 12:58:09 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

/**
 * @brief 
 * 
 * TODO
 * fct for while
 *	//replace 2 by variable strlen tooe
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	main(int argc, char **argv)
{
	char		*line;
	int			tab_size;
	int			*tab_nbr;
	t_info		*info;

	if (argc < 2)
		ft_print_error(-1);
	tab_size = 0;
	info = ft_init_info();
	tab_size = ft_get_str_size(argc, argv);
	tab_nbr = ft_argv_in_tab(argc, argv, tab_size);
	ft_tab_in_info(info, tab_nbr, tab_size);
	ft_check_tab_sorted(info, tab_nbr, tab_size, 0);
	info->tab = tab_nbr;
	while (get_next_line(0, &line))
	{
		if (ft_commands(info, line))
		{
			write(2, ERROR_MSG, ft_strlen(ERROR_MSG));
			if (ft_check_sorted(info))
				ft_print_res_commands(info);
			return (-1);
		}
		free(line);
	}
	return (0);
}

/*

let pb 2*

9 8 3 4 2
33 44 22	35 26
22 33 44 	35 26		1 OU 2 MOVE

pa 

O 	-	-	- 	O
O 	-	- 	-	O
O	-	O	- 	O
O	-	O	O	O
O	-	O	O	O


int ft_check_sorted(t_info info)
{
	
}
*/