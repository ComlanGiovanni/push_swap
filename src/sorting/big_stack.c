/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:45:56 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/10 20:12:41 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/**
 * @brief 
 * 
 * 
 * we push everything in B until we have 2 or 3 then sort it
 * pushing in B its by 2 pivot
 * 
 * if < piv1(1 tier) push in b and put in down (so stay down)chunk
 * if < piv2(2 tier) push in b (so stay in top)chunk
 * 2 chunk in B and one chunk in A
 * then we put the rest of A in top of B, (everything > piv1 && piv2)
 * 
 *
 * @param info 
 */
void	ft_sort_big_stack(t_info *info)
{
	int	move_for_a;
	int	move_for_b;

	ft_get_pivot_and_split(info);
	while (info->size_a > 3)
		push_stack_b(info);
	if (info->size_a == 2)
	{
		if (info->top_a->nbr > info->top_a->next->nbr)
			swap_stack_a(info);
	}
	if (info->size_a == 3)
		ft_sort_stack_of_three(info);
	while (info->size_b)
	{
		move_for_a = 0;
		move_for_b = 0;
		ft_get_min_move(info, &move_for_a, &move_for_b);
		ft_shift_a_and_b(info, &move_for_a, &move_for_b);
		ft_shift_a(info, move_for_a);
		ft_shift_b(info, move_for_b);
		push_stack_a(info);
	}
	ft_sort_last_chunk(info);
}

/**
 * @brief 
 * 
 * we just get the number at 1/3idx and 2/3idx
 * we put back the index at the size of A to 
 * split proprely
 * 
 * ex 26 elm =>  pivot1---->>8     pivot2----->17
 * 
 * @param info 
 */
void	ft_get_pivot_and_split(t_info *info)
{
	int	idx;
	int	pivot_1;
	int	pivot_2;

	idx = info->size_a / 3;
	pivot_1 = info->tab[idx];
	idx = info->size_a * 2 / 3;
	pivot_2 = info->tab[idx];
	idx = info->size_a;
	while (idx)
	{
		ft_split_by_three(info, pivot_1, pivot_2);
		idx--;
	}
}

/**
 * @brief 
 * 
 * if the number is less than the first pivot
 * we push top of a in b and but it in the bottom
 * 
 * else we just put it at the top of b
 * 
 * else if we put it a the bottom of a so
 * 
 * we can get things like that
 * 
 *  ----   -------
 *  -----  ----- 
 *  ----   --
 *  ---    --
 *         ------
 *         ---
 *         -----
 *         ---
 *   A       B
 * 
 * so we got 3 chunk
 * 
 * @param info 
 * @param pivot_1 
 * @param pivot_2 
 */
void	ft_split_by_three(t_info *info, int pivot_1, int pivot_2)
{
	if (info->top_a->nbr < pivot_1)
	{
		push_stack_b(info);
		rotate_stack_b(info);
	}
	else if (info->top_a->nbr < pivot_2)
		push_stack_b(info);
	else
		rotate_stack_a(info);
}

/**
 * @brief 
 * 
 * we found the place of the min nbr int the stack A
 * whe rotate or reverse in function of the 
 * pos of the min number in A
 * then loop if until 0 so loc 0
 * -- ++ for every move
 * 
 * if for ex the min is sup > 0
 * which mean the min pos is > at the
 * len of A / 2 ,,, so we can just rotate
 * reverse would be dumb because this can cost more than
 * need,,
 * 
 * 
 * 
 * @param info 
 */
void	ft_sort_last_chunk(t_info *info)
{
	int	min_location;

	min_location = ft_set_a_location_min(info);
	while (min_location)
	{
		if (min_location > 0)
		{
			rotate_stack_a(info);
			min_location--;
		}
		else
		{
			reverse_rotate_a(info);
			min_location++;
		}
	}
}

/**
 * @brief 
 * 
 * to get the min move we get the location
 * of the current number 
 * then we check it the idx loc in a is > at
 * sizeb / 2 then we put it in neg and by the sizeb
 * - the location in b
 * then change the move for move_for_ A B
 * 
 * @param info 
 * @param move_for_a 
 * @param move_for_b 
 */
void	ft_get_min_move(t_info *info, int *move_for_a, int *move_for_b)
{
	int			idx;
	int			number;
	int			idx_a;
	int			idx_b;
	t_stack		*tmp_stack_b;

	idx = 0;
	tmp_stack_b = info->top_b;
	while (idx < info->size_b)
	{
		number = tmp_stack_b->nbr;
		idx_a = ft_set_location_in_a(number, info);
		if (idx >= (info->size_b + 1) / 2)
			idx_b = (info->size_b - idx) * -1;
		else
			idx_b = idx;
		if (idx == 0 || ft_get_min(*move_for_a, *move_for_b, idx_a, idx_b))
		{
			*move_for_a = idx_a;
			*move_for_b = idx_b;
		}
		tmp_stack_b = tmp_stack_b->next;
		idx++;
	}
}
