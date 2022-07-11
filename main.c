/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:37:51 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/10 20:30:32 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pushswap.h"

/**
 * @brief 
 * 
 * We exit if less the 2 argument
 * we init the info struct 
 * get the size of all nbr for proper malloc
 * we then put the numbers in a tab with 
 * proper check max/min(int) +/- etc
 * then check for doublon and sort with a
 * bubble sort that we will put in tab of info
 * info->tab = tab_nbr;
 * then get the sort move for the stack A
 * and then free everything at the end
 * 
 * argc meaning is argument count
 * argv meaning is argument vector
 * 
 * 
 * --- You should name a variable using the same care ---
 * 	  --- with which you name a first-born child ---
 * 				[Robert C. Martin]
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	main(int argc, char **argv)
{
	int			tab_size;
	int			*tab_nbr;
	t_info		*info;

	if (argc < 2)
		exit(EXIT_FAILURE);
	tab_size = 0;
	info = ft_init_info();
	tab_size = ft_get_str_size(info, argc, argv);
	tab_nbr = ft_argv_in_tab(info, argc, argv, tab_size);
	ft_tab_in_info(info, tab_nbr, tab_size);
	ft_check_tab_sorted(info, tab_nbr, tab_size, 0);
	info->tab = tab_nbr;
	ft_sort_stack(info);
	ft_free_a(info, tab_size);
	free(tab_nbr);
	free(info);
	return (EXIT_SUCCESS);
}

/*
https://www.calculatorsoup.com
/calculators/statistics/random-number-generator.php
*/