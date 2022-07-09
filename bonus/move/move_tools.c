/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:22:16 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/09 16:43:57 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

/**
 * @brief
 * 
 * we put evry element in at the top of the previous
 * down : 4 5 2 1 -> NULL 4 5 2 1
 * 1 because 2   2 5 and so one
 * 
 * @param tab 
 * @param used 
 */
void	ft_push_down(int *tab, int used)
{
	while (used > 0)
	{
		tab[used] = tab[used - 1];
		used--;
	}
}

/**
 * @brief 
 * 
 * we shift up all the elm until reaching the idx 0
 * 
 *  * 1 2 3 4   1 2 3 4 *
 * 
 * @param tab 
 * @param used 
 */
void	ft_pop_up(int *tab, int used)
{
	int	idx;

	idx = 0;
	while (idx < used)
	{
		tab[idx] = tab[idx + 1];
		idx++;
	}
}
