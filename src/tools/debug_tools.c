/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:24:49 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/10 17:40:35 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/**
 * @brief 
 * 
 * If the error value is >= 1
 * 	print Error in standard error
 * else 0 -1 etc
 * 	just exit the code
 * 
 * EXIT_SUCCESS = 0
 * EXIT_FAILURE = 1;
 *
 * STDIN_FILENO    Standard input value, stdin. Its value is 0.
 * STDOUT_FILENO   Standard output value, stdout. Its value is 1.
 * STDERR_FILENO   Standard error value, stderr. Its value is 2.
 * 
 * @param error_code 
 * @return int 
 */
int	ft_print_error(int error_code)
{
	if (error_code >= 1)
		write(STDERR_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
	exit(EXIT_FAILURE);
	return (-1);
}

/**
 * @brief
 * 
 * We initialized a malloc info stuct 
 * and put a malloc stack a in it
 * the size is 0 the nbr is 0;
 * 
 * a = [NULL]-0-[NULL]
 * 
 * prev and next is NULL
 * top and bottom equal malloc_a because
 * There is nothing in it (not more than 1)
 * 
 * we only initialized stack A
 * 
 * @return t_info* 
 */
t_info	*ft_init_info(void)
{
	t_stack	*malloc_a;
	t_info	*malloc_info;

	malloc_info = NULL;
	malloc_info = (t_info *)malloc(sizeof(t_info));
	malloc_a = ft_init_stack();
	malloc_info->tab = NULL;
	malloc_info->size_a = 0;
	malloc_info->size_b = 0;
	malloc_info->top_a = malloc_a;
	malloc_info->bottom_a = malloc_a;
	return (malloc_info);
}

/**
 * @brief 
 * 
 * We initialized a struct stack aka A at 0
 * and malloc it with nbr 0 and prev next NULL
 * 
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
 * Same as(s) atoi but(t) but we add
 * a len_nbr_check(print error) at the end
 * + max int check
 * INT_MAX	2147483647
 * INT_MIN	-2147483648
 * 
 * ft_isspace ft_is_sign ft_isdigit
 * [check sign check space transform in digit]
 * 
 * we also check but the len of the nbr in case
 * split is for str_nbr_splitted
 * 

 * 
 * @param str 
 * @return int 
 */
int	ft_check_int(t_info *info, int *tab_nbr, char **split, const char *str)
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
		|| res > INT_MAX || res < INT_MIN)
		ft_free_maxint(1, info, tab_nbr, split);
	return ((int)res);
}

/**
 * @brief 
 * 
 * in fact you realy dont need to send tab_size you can
 * strlen in when need
 * 
 * so this fct its the fucking leaks debugging
 * 
 * we free the stack A of all the number
 * we free the tab of nbr that we malloc in the main
 * we free the big stack who got stack A B we only free
 * it at the end to avoid still reachable
 * 
 * @param error_code 
 * @param info 
 * @param tab_nbr 
 * @param tab_size 
 */
void	ft_free_if_err(int err_code, t_info *info, int *tab_nbr, int tab_size)
{
	ft_free_a(info, tab_size);
	free(tab_nbr);
	free(info);
	ft_print_error(err_code);
}
