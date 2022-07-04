/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:37:51 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/04 18:09:08 by gcomlan          ###   ########.fr       */
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
void	ft_check_tab_already_sorted(int *tab_nbr, int tab_size, int idx)
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
			ft_print_error(1);
		idx++;
	}
	if (check == 0)
		ft_print_error(-1);
}

/**
 * @brief 
 * 
 * We free evry single element in the str
 * and at the end we free the whole str
 * 
 * @param str 
 */
void	ft_free_str(char **str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		free(str[idx]);
		idx++;
	}
	free(str);
}


void	free_info_a(t_info *info)
{
	t_stack	*current;

	if (info == NULL)
		return ;
	current = info->top_a;
	while (info->top_a != NULL)
	{
		info->top_a = info->top_a->next;
		free(current);
		current = info->top_a->next;
	}
	free(info);
	info = NULL;
}


void	ft_free_a(t_info *info)
{
	if (info->top_a == NULL)
		return ;
	while (info->size_a)
	{
		t_stack *current = info->top_a;
		free(current);
		info->top_a = info->top_a->next;
		info->size_a--;
	}
}

void	ft_free_b(t_info *info)
{
	if (info->top_a == NULL)
		return ;
	while (info->size_b)
	{
		t_stack *current = info->top_b;
		free(current);
		info->top_b = info->top_b->next;
		info->size_b--;
	}
}
