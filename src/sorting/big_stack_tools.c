/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:55:57 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/04 12:12:52 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

int		ft_set_location_in_a(int number, t_info *info)
{
	int	location;

	if (number < ft_get_stack_min_nbr(info->top_a))
		location = ft_set_a_location_min(info);
	else if (number > ft_get_stack_max_nbr(info->top_a))
		location = ft_set_a_location_max(info);
	else
		location = ft_set_a_location_mid(number, info);
	return (location);
}

int		ft_set_a_location_min(t_info *info)
{
	int			location;
	int			idx;
	int			tmp;
	t_stack     *tmp_stack_a;

	location = 0;
	tmp = 0;
	tmp_stack_a = info->top_a;
	idx = ft_get_stack_min_nbr(tmp_stack_a);
	while (tmp_stack_a)
	{
		tmp = tmp_stack_a->nbr;
		if (tmp == idx)
			break ;
		location++;
		tmp_stack_a = tmp_stack_a->next;
	}
	if (location >= (info->size_a + 1) / 2)
		location = (info->size_a - location) * -1;
	return (location);
}

int		ft_set_a_location_max(t_info *info)
{
	int			location;
	int			idx;
	int			tmp;
	t_stack     *tmp_stack_a;

	location = 0;
	tmp = 0;
	tmp_stack_a = info->top_a;
	idx = ft_get_stack_max_nbr(tmp_stack_a);
	while (tmp_stack_a)
	{
		tmp = tmp_stack_a->nbr;
		if (tmp == idx)
			break ;
		location++;
		tmp_stack_a = tmp_stack_a->next;
	}
	location++;
	if (location >= (info->size_a + 1) / 2)
		location = (info->size_a - location) * -1;
	return (location);
}

int		ft_set_a_location_mid(int number, t_info *info)
{
	t_stack     *tmp_stack_a;
	int			location;

	tmp_stack_a = info->top_a;
	location = 1;
	while (tmp_stack_a->next)
	{
		if (number > tmp_stack_a->nbr && number < tmp_stack_a->next->nbr)
			break ;
		location++;
		tmp_stack_a = tmp_stack_a->next;
	}
	if (location >= (info->size_a + 1) / 2)
		location = (info->size_a - location) * -1;
	return (location);
}

void	ft_shift_a_and_b(t_info *info, int *move_for_a, int *move_for_b)
{
	while (*move_for_a && *move_for_b && (*move_for_a > 0 && *move_for_b > 0))
	{
		rotate_stack_a_and_b(info);
		*move_for_a = *move_for_a - 1;
		*move_for_b = *move_for_b - 1;
	}
	while (*move_for_a && *move_for_b && (*move_for_a < 0 && *move_for_b < 0))
	{
		reverse_rotate_stack_a_and_b(info);
		*move_for_a = *move_for_a + 1;
		*move_for_b = *move_for_b + 1;
	}
}