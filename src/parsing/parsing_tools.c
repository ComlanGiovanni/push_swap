/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:37:51 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/04 15:53:49 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/**
 * @brief 
 * 
 * we loop 0 to count arg and break while inc vector idx,
 * if we found issplace char, so print erro if end of file
 * then we spliit by space evry char to get the size
 * we free the str en return the size - 1(enf of tab)
 * we need it to malloc proprely in the next fct
 * 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int		ft_get_str_size(int argc, char **argv)
{
	int		idx;
	int		size;
	int		vector;
	char	**str_nbr_splitted;

	idx = 0;
	size = 0;
	while (idx < argc)
	{
		vector = 0;
		while (argv[idx][vector])
		{
			if (!ft_isspace(argv[idx][vector]))
				break ;
			vector++;
		}
		if (argv[idx][vector] == '\0')
			ft_print_error(1);
		str_nbr_splitted = ft_split(argv[idx], ' ');
		size += ft_get_size_of(str_nbr_splitted);
		ft_free_str(str_nbr_splitted);
		idx++;
	}
	return (size - 1);
}

/**
 * @brief 
 * 
 * we malloc the right memory with the size get by
 * ft_get_str_size, print error if the malloc fail
 * we spit again by space and but at the same time
 * int the tab so 123(space) put int tab with a check
 * max/min in digit + - etc aka sanitarized for defense
 * 
 * @param argc 
 * @param argv 
 * @param tab_size 
 * @return int* 
 */
int		*ft_argv_in_tab(int argc, char **argv, int tab_size)
{
	int		idx;
	int		tab_idx;
	int		*tab_nbr;
	char	**str_nbr_splitted;

	idx = 1;
	tab_idx = 0;
	tab_nbr = (int *)malloc(sizeof(int *) * tab_size + 1);
	if (!tab_nbr)
		ft_print_error(1);
	while (idx < argc)
	{
		str_nbr_splitted = ft_split(argv[idx], ' ');
		ft_nbr_in_tab(tab_nbr, &tab_idx, str_nbr_splitted);
		ft_free_str(str_nbr_splitted);
		idx++;
	}
	tab_nbr[tab_idx] = '\0';
	return (tab_nbr);
}

/**
 * @brief 
 * 
 * we loop int the splitted str to found if the str
 * is a digit and pass the rule for a int etc
 * we alors in the value o the pointer tab_idx pass
 * in param, we need it to put endtab after
 * fiilling the tab
 * 
 * @param tab_nbr 
 * @param tab_idx 
 * @param str_nbr_splitted 
 */
void	ft_nbr_in_tab(int *tab_nbr, int *tab_idx, char **str_nbr_splitted)
{
	int	tmp;
	int	idx;

	idx = 0;
	while (str_nbr_splitted[idx])
	{
		tmp = ft_atoll_check_max_int(str_nbr_splitted[idx]);
		tab_nbr[*tab_idx] = tmp;
		(*tab_idx)++;
		idx++;
	}
}

/**
 * @brief 
 * 
 * we simply add the number by the bottom/back
 * we init a stack [NULL]-0-[NULL]
 * then inc the size evry time we loop in the tab
 * so we put the nbr in bottom put int not bottom at first
 * bu wil be in the future so we link the next o the bottom
 * at stack a then we link the prev(NULL) at the bottom we just
 * create then we but a int the bottom so first (4)-[0]-[NULL]
 * (4)-[9]-[0]-[NULL]
 * 
 * we remove the 0 put when we init the a stack
 *  
 * 				   prev<-*->next
 * then (4)-[9]-[1]-[6]-[0]-[NULL] = (4)-[9]-[1]-[6]-[NULL/0]
 * 
 * @param info 
 * @param tab_nbr 
 * @param tab_size 
 */
void	ft_tab_in_info(t_info *info, int *tab_nbr, int tab_size)
{
	t_stack		*a;
	int			idx;

	idx = 0;
	while (idx < tab_size)
	{
		a = ft_init_stack();
		info->size_a++;
		info->bottom_a->nbr = tab_nbr[idx];
		info->bottom_a->next = a;
		a->prev = info->bottom_a;
		info->bottom_a = a;
		idx++;
	}
	info->bottom_a = info->bottom_a->prev;
	free(a);
}

/**
 * @brief 
 * 
 * A simple strlen but fort a char **
 * nothing much
 * 
 * @param str_nbr_splitted 
 * @return int 
 */
int		ft_get_size_of(char **str_nbr_splitted)
{
	int	idx;

	idx = 0;
	while (str_nbr_splitted[idx])
		idx++;
	return (idx);
}
