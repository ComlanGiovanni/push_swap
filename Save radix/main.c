/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:37:51 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/28 15:38:30 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pushswap.h"

/*
	THIS FCT CHECK IF
	THE NUMBER SEND IS 
	ALREADY SORTED
*/

int	check_already_sorted(t_list *nbr_list)
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

/*
  IN THIS MAIN WE PARS BY THE TYPE WE RECIEVE
  IF WE GET "45 25 8954 5" WE SPLIT BY SPACE
  ELSE WE PUT ARGV 1 ++ BY THE END ARG

  FOR THE PARSING WE NEED THE LEN OF TAB_INT
  
  WE HANDLE ERROR I MALLOC FAIL     ERROR
  WE CHECK IF SORTED AND WE FREE WHEN ALL DONE

  WE REDIRECT AT 2 FCT BIG AND LESS THAN 5 INTEGER
*/

int	main(int argc, char **argv)
{
	t_list	*nbr_list;

	if (argc < 2)
		return (0);
	if (argc == 2)
		nbr_list = parsing_str(argc, argv);
	else
		nbr_list = parsing_arg(argc, argv);
	if (nbr_list == NULL)
	{
		write(2, ERROR_MSG, 7);
		return (1);
	}
	if (check_already_sorted(nbr_list) == 1)
	{
		free_list(nbr_list);
		return (0);
	}
	if (nbr_list->nbr_elm < 6)
		small_stack(nbr_list);
	else
		big_stack(nbr_list);
	free_list(nbr_list);
	return (0);
}

/*
LIB
ft_putstr_fd
ft_split
if const problem remove
ft_count str from lib remove if you add split
ft_strlen.c
ft_isdigit.c
ft_atoi.c
ft_atol.c
ft_putstr_fd.c
#define INT_MAX 2147483647 neg too o just put - in front
*/