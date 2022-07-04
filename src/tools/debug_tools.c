/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:24:49 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/04 17:48:07 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/**
 * @brief 
 * 
 * If the error value is >= 1 print Error in standard error
 * else 0 -1 etc just exit the code
 * 
 * EXIT_SUCCESS = 0
 * EXIT_FAILURE = 1;
 *
 * STDIN_FILENO    Standard isignut value, stdin. Its value is 0.
 * STDOUT_FILENO   Standard output value, stdout. Its value is 1.
 * STDERR_FILENO   Standard error value, stderr. Its value is 2.
 * 
 * @param error_code 
 * @return int 
 */
int		ft_print_error(int error_code)
{
	if (error_code >= 1)
		write(STDERR_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
	exit(EXIT_FAILURE);
	return (-1);
}

/**
 * @brief
 * 
 * We iniatiliazed a malloc info stuct 
 * and put a malloc stack a in it
 * the size is 0 the nbr is 0;
 * a = [NULL]-0-[NULL]
 * prev and next is NULL
 * top and bottom equal a because
 * There is nothing in it (not more than 1)
 * 
 * @return t_info* 
 */
t_info	*ft_init_info(void)
{
	t_stack 	*malloc_a;
	t_info		*malloc_info;

	malloc_info = NULL;
	malloc_info = (t_info *)malloc(sizeof(t_info));
	malloc_a = ft_init_stack();
	malloc_info->tab = NULL;
	malloc_info->size_a = 0;
	malloc_info->top_a = malloc_a;
	malloc_info->bottom_a = malloc_a;
	malloc_info->size_b = 0;
	return (malloc_info);
}

/**
 * @brief 
 * 
 * We initialiazed a struc stack aka a at 0
 * and malloc it with nbr 0 and prev next NULL
 * a = [NULL]-0-[NULL]
 * 
 * @return t_stack* 
 */
t_stack	*ft_init_stack(void)
{
	t_stack	*malloc_a;

	malloc_a = NULL;
	malloc_a = (t_stack *)malloc(sizeof(t_stack));
	malloc_a->prev = NULL;
	malloc_a->nbr = 0;
	malloc_a->next = NULL;
	return (malloc_a);
}


/**
 * @brief 
 * 
 * same ass atoi but is atoll but we add
 * len nbr check(pint error)
 * max/min int check
 * 
 * [check sign check space transform in digit]
 * 
 * @param str 
 * @return int 
 */
int		ft_atoll_check_max_int(const char *str)
{
	long long	res;
	int			sign;
	int			len_res;

	res = 0;
	sign = 1;
	len_res = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
		len_res++;
	}
	res = res * sign;
	if (*str != '\0' || len_res > 10
		|| res > 2147483647 || res < -2147483648)
		ft_print_error(1);
	return ((int)res);
}