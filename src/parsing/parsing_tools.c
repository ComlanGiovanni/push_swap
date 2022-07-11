/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:37:51 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/10 18:10:51 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/**
 * @brief 
 * 
 * we loop 0 to count arg and break while inc(++) vector idx,
 * if we found isspace char, so print error if end of file
 * then we split by space every char to get the true size.
 * after we get the size of the str splitted by space
 * we free the str en return the size - 1(enf of tab)
 * we need it to malloc properly in the next fct
 * ft_argv_in_tab,,, if there is not digit we free the
 * info struct we malloc in ft_init_info
 * we also the str we splitted.
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	ft_get_str_size(t_info *info, int argc, char **argv)
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
			ft_free_no_dig(1, info);
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
 * we spit again by space and put at the same time
 * int the tab_nbr so 123(space) put in tab with a 
 * check of max/min in digit + - etc aka sanitized
 * 
 * @param argc 
 * @param argv 
 * @param tab_size 
 * @return int* 
 */
int	*ft_argv_in_tab(t_info *info, int argc, char **argv, int tab_size)
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
		ft_nbr_in_tab(info, tab_nbr, &tab_idx, str_nbr_splitted);
		ft_free_str(str_nbr_splitted);
		idx++;
	}
	tab_nbr[tab_idx] = '\0';
	return (tab_nbr);
}

/**
 * @brief 
 * 
 * We loop in the splitted str to found if the str
 * is a digit and pass the rule for a int +/- max min
 * atoi base fct fot the check and print error in false
 * 
 * we nedd the pointer of tab_idx pass in param
 * we need it to keep track of were we at to put
 * '\0' (end_of_tab) after filling  the tab_nbr
 * 
 * split is str_nbr_splitted for 8 col norm
 * 
 * @param tab_nbr 
 * @param tab_idx 
 * @param str_nbr_splitted 
 */
void	ft_nbr_in_tab(t_info *info, int *tab_nbr, int *tab_idx, char **split)
{
	int	tmp;
	int	idx;

	idx = 0;
	while (split[idx])
	{
		tmp = ft_check_int(info, tab_nbr, split, split[idx]);
		tab_nbr[*tab_idx] = tmp;
		(*tab_idx)++;
		idx++;
	}
}

/**
 * @brief 
 * 
 * We simply add the number by the bottom/back o the stack
 * we init a stack [NULL]-0-[NULL]
 * 
 * then inc the size every time we loop in the tab
 * 
 * so we put the nbr in bottom but is not bottom at first 
 * look like we put at the top 			[56]-[NULL]
 * but will be in the future
 * 								a  ->  [NULL]-(nbr)-[NULL]
 * so we link the next of the bottom
 * 
 * 	[56]->next  ((NULL before 56 bottom nbr)) prev<-(nbr)-[NULL]
 * 
 * at stack A then we link the prev(NULL) at the bottom we just
 * create then we but a int the bottom so first
 * (4)-[0]-[NULL]    ******   (4)-[9]-[0]-[NULL]
 * 
 * we remove the 0 put when we init the a stack
 *  
 * 				   prev<-*->next
 * then (4)-[9]-[1]-[6]-[0]-[NULL] = (4)-[9]-[1]-[6]-[NULL/0]
 * 
 * we dont forget to free the node we malloc in
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
 * A simple strlen 
 * but for a char **
 * nothing much
 * 
 * while there is something idx++
 * 
 * @param str_nbr_splitted 
 * @return int 
 */
int	ft_get_size_of(char **str_nbr_splitted)
{
	int	idx;

	idx = 0;
	while (str_nbr_splitted[idx])
		idx++;
	return (idx);
}
