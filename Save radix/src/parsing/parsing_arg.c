/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:55:58 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/28 17:31:10 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/*
		// make a big fct
*/
t_list	*parsing_arg(int ac, char **av)
{
	t_list	*nbr_list;
	int		check;

	check = 0;
	if (check_digit_arg(ac, av))
		check = 1;
	if (check_overflow_arg(ac, av))
		check = 1;
	if (check_doublon_arg(ac, av))
		check = 1;
	if (check != 0)
		return (NULL);
	nbr_list = tab_to_list_arg(ac, av);
	return (nbr_list);
}

/*
	
*/
int	check_digit_arg(int ac, char **av)
{
	int	idx;
	int	j;

	idx = 1;
	j = 0;
	while (idx < ac && av[idx] != NULL)
	{
		if (av[idx][j] == '-' && ft_strlen(av[idx]) == 1)
			return (1);
		if (av[idx][0] == '-')
			j++;
		while (ft_isdigit(av[idx][j]) == 1)
			j++;
		if ((int)ft_strlen(av[idx]) == j)
		{
			idx++;
			j = 0;
		}
		else
			return (1);
	}
	return (0);
}

/*
	//atoi if problem
*/
int	check_overflow_arg(int ac, char **av)
{
	int				idx;
	long long int	nbr;

	idx = 1;
	while (idx < ac && av[idx] != NULL)
	{
		nbr = ft_atol(av[idx]);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (1);
		else
			idx++;
	}
	return (0);
}

/*
	
*/
int	check_doublon_arg(int ac, char **av)
{
	int	idx;
	int	j;

	idx = 1;
	while (idx < ac)
	{
		j = idx + 1;
		while (j < ac)
		{
			if (ft_atoi(av[idx]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		idx++;
	}
	return (0);
}

/*
	// fin de tab
	//nbr a la fin
	// idx = 0 is name of programm
	//name of programme
*/
t_list	*tab_to_list_arg(int nbr_int, char **tab_int)
{
	t_list	*nbr_list;
	int		idx;
	int		nbr;

	idx = nbr_int - 1;
	nbr = ft_atoi(tab_int[idx]);
	idx--;
	nbr_list = init_list_of_link(nbr);
	while (idx >= 1)
	{
		nbr = ft_atoi(tab_int[idx]);
		add_front(nbr_list, nbr);
		idx--;
	}
	nbr_list->nbr_elm = nbr_int - 1;
	return (nbr_list);
}
