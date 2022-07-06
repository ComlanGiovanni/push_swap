/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:37:51 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/06 12:40:27 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/**
 * @brief 
 * 
 * we bublle sort to check and alors check for doublon
 * we loop by decreasing by the size and also loop
 * inside it by decreasing the size
 * then swap or the bubble sort
 * exit if anything was do witch mean nothing get sorted
 * we exit and print error only if we found one doublon
 * 
 * @param tab_nbr 
 * @param tab_size 
 * @param idx 
 */
void	ft_check_tab_sorted(t_info *info, int *tab_nbr, int tab_size, int idx)
{
	int	bubble_sort;
	int	check;
	int	tmp;

	check = 0;
	while (idx < tab_size)
	{
		bubble_sort = 0;
		while (bubble_sort < tab_size - 1)
		{
			if (tab_nbr[bubble_sort] > tab_nbr[bubble_sort + 1])
			{
				tmp = tab_nbr[bubble_sort];
				tab_nbr[bubble_sort] = tab_nbr[bubble_sort + 1];
				tab_nbr[bubble_sort + 1] = tmp;
				check = 1;
			}
			bubble_sort++;
		}
		if (tab_nbr[idx] == tab_nbr[idx + 1])
			ft_free_if_err(1, info, tab_nbr, tab_size);
		idx++;
	}
	if (check == 0)
		ft_free_if_err(-1, info, tab_nbr, tab_size);
}

/**
 * @brief 
 * 
 * We free every single element in the str
 * and at the end we free the whole str
 * 
 * @param str 
 */
void	ft_free_str(char **str)
{
	int	idx;

	idx = 0;
	if (str == NULL)
		return ;
	while (str[idx])
	{
		free(str[idx]);
		idx++;
	}
	free(str);
}

/**
 * @brief 
 * 
 * 
 * 
 * @param info 
 * @param tab_size 
 */
void	ft_free_a(t_info *info, int tab_size)
{
	t_stack	*current;

	if (info->top_a == NULL)
		return ;
	current = info->top_a->next;
	while (tab_size)
	{
		free(info->top_a);
		info->top_a = current;
		if (tab_size != 1)
			current = current->next;
		tab_size--;
	}
}

/**
 * @brief 
 * 
 * 
 * 
 * 
 * @param info 
 * @param tab_size 
 */
void	ft_free_b(t_info *info, int tab_size)
{
	t_stack	*current;

	if (info->top_b == NULL)
		return ;
	current = info->top_b->next;
	while (tab_size)
	{
		free(info->top_b);
		info->top_b = current;
		if (tab_size != 1)
			current = current->next;
		tab_size--;
	}
}
