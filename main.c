/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:37:51 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/07 23:12:48 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pushswap.h"

/**
 * @brief 
 * 
 * We exit if yu have less the 2 argument
 * we init the info struct get the size of
 * the str_nbr or proper malloc
 * we then put the numbers in a tab with 
 * proper check max/min(int) +/- etc
 * then check for doublon and sort with a
 * bubble sort
 * 
 * argc meaning is argument count
 * argv meaning is argument vector
 * 
 * i am wondering if i should stop using 3 char var name
 * --- You should name a variable using the same care ---
 * 	  --- with which you name a first-born child ---
 * 				[Robert C. Martin]
 * 
 * idx -> index;
 * tmp -> temp;
 * 
 * Think its would be more cleat
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
		ft_print_error(-1);
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

comment for ft_free_a and b
check all free
and all argument for defense
if " 43" p 43 problematique do old parsing
bonus

reverse sorted stack A

./push_swap "45 5 13 26 9 1" "412 1 68 36" no dounlon error why

https://www.calculatorsoup.com
/calculators/statistics/random-number-generator.php

*/