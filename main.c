/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:37:51 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/04 18:10:40 by gcomlan          ###   ########.fr       */
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
	tab_size = ft_get_str_size(argc, argv);
	tab_nbr = ft_argv_in_tab(argc, argv, tab_size);
	ft_tab_in_info(info, tab_nbr, tab_size);
	ft_check_tab_already_sorted(tab_nbr, tab_size, 0);
	info->tab = tab_nbr;
	ft_sort_stack(info);
	ft_free_a(info);
	ft_free_b(info);
	free(info);
	free(tab_nbr);
	return (EXIT_SUCCESS);
}
