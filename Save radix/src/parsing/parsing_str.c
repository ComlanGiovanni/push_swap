/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:37:51 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/30 21:02:14 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/*
	ouais jai la flemme ta capter ono vas clean et evaluer YOLO
*/
t_list	*parsing_str(int nbr_int, char **tab_int)
{
	t_list	*nbr_list;
	int		check;
	int		nbr_in;
	char	**tab_in;

	check = 0;
	tab_in = ft_split(tab_int[1], ' ');
	nbr_in = ft_count_str(tab_int[1], ' ');
	(void)nbr_int;
	if (check_digit_str(nbr_in, tab_in))
		check = 1;
	if (check_overflow_str(nbr_in, tab_in))
		check = 1;
	if (check_doublon_str(nbr_in, tab_in))
		check = 1;
	if (check != 0)
	{
		ft_free_tab(tab_in);
		return (NULL);
	}
	nbr_list = tab_to_list_str(nbr_in, tab_in);
	ft_free_tab(tab_in);
	return (nbr_list);
}

/*
	
*/
int	check_digit_str(int nbr_int, char **tab_int)
{
	int	idx;
	int	j;

	idx = 0;
	j = 0;
	while (idx < nbr_int && tab_int[idx] != NULL)
	{
		if (tab_int[idx][j] == '-' && ft_strlen(tab_int[idx]) == 1)
			return (1);
		if (tab_int[idx][0] == '-')
			j++;
		while (ft_isdigit(tab_int[idx][j]) == 1)
			j++;
		if ((int)ft_strlen(tab_int[idx]) == j)
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
	
*/
int	check_overflow_str(int nbr_int, char **tab_int)
{
	int				idx;
	long long int	nbr;

	idx = 0;
	while (idx < nbr_int && tab_int[idx] != NULL)
	{
		nbr = ft_atol(tab_int[idx]);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (1);
		else
			idx++;
	}
	return (0);
}

/*
	//ft_strcmp(av[i], av[j]) == 0 && i != j
	ft_atoi(tab_int[idx]) == ft_atoi(tab_int[j])
*/
int	check_doublon_str(int nbr_int, char **tab_int)
{
	int	idx;
	int	j;

	idx = 0;
	while (idx < nbr_int)
	{
		j = idx + 1;
		while (j < nbr_int)
		{
			if (ft_strcmp(tab_int[idx], tab_int[j]) == 0 && idx != j)
				return (1);
			j++;
		}
		idx++;
	}
	return (0);
}

/*
	inser by the back of tab
*/
t_list	*tab_to_list_str(int nbr_int, char **tab_int)
{
	t_list	*nbr_list;
	int		idx;
	int		nbr;

	idx = nbr_int - 1;
	nbr = ft_atoi(tab_int[idx]);
	idx--;
	nbr_list = init_list_of_link(nbr);
	while (idx >= 0)
	{
		nbr = ft_atoi(tab_int[idx]);
		add_front(nbr_list, nbr);
		idx--;
	}
	nbr_list->nbr_elm = nbr_int;
	return (nbr_list);
}
