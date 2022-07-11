/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 02:28:59 by gcomlan           #+#    #+#             */
/*   Updated: 2022/07/10 17:34:55 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

/**
 * @brief 
 * 
 * if the argument is not valid we exit and print error
 * while lopping in the argument we save the join of the
 * str malloc and the argument with the tmp joinee by space
 * so we got "45 46 95 23 41 56"
 * 
 * we dont forget to free
 * 
 * @param argv 
 * @return char* 
 */
char	*ft_move_to_str(char **argv)
{
	char	*nbr_joined;
	char	*tmp;
	int		idx;

	idx = 1;
	nbr_joined = (char *)malloc(sizeof(char));
	while (argv[idx])
	{
		if (!ft_check_arg(argv[idx]))
		{
			write(STDERR_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
			exit(EXIT_FAILURE);
		}
		tmp = ft_strjoin(nbr_joined, argv[idx]);
		free(nbr_joined);
		nbr_joined = ft_strjoin(tmp, " ");
		free(tmp);
		idx++;
	}
	return (nbr_joined);
}

/**
 * @brief 
 * 
 * we loop in the string and while
 * the str is a digit valid we
 * keep going return success else failure
 * 
 * @param str 
 * @return int 
 */
int	ft_check_arg(char *str)
{
	int		idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] != ' ' && str[idx] != '-' && !(ft_isdigit(str[idx])))
			return (EXIT_SUCCESS);
		if (str[idx] == '-' && !(ft_isdigit(str[idx + 1])))
			return (EXIT_SUCCESS);
		idx++;
	}
	return (EXIT_FAILURE);
}

/**
 * @brief 
 * 
 * we init  by mallocing on the size of the len of str
 * we transform evry str(int) in each idx in tab_nbr with atoi
 * the check th max in in the fucking limits header file
 * THIS SHIT IS BROKEN
 * if max int free the stack and write error in the erro std
 * same for doublon
 * 
 * ad the nbr in the tab of stack a and ++ used
 * who is good to see where we at
 * 
 * then free the tab
 * 
 * and return the big stack
 * 
 * @param str 
 * @return t_stack_a_b 
 */
t_stack_a_b	ft_str_to_stack(char *nbr_joined)
{
	t_stack_a_b	stack;
	char		**tab_nbr;
	long		nbr;
	int			idx;

	idx = 0;
	tab_nbr = ft_init_stack_checker(nbr_joined, &stack);
	while (tab_nbr[idx])
	{
		nbr = ft_atol(tab_nbr[idx]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			ft_free_fail_init(&stack);
		if (!ft_doublon_tab_nbr(&stack, nbr))
			ft_free_fail_init(&stack);
		stack.stack_a.tab[idx] = nbr;
		stack.stack_a.used++;
		free(tab_nbr[idx]);
		idx++;
	}
	free(tab_nbr);
	return (stack);
}

/**
 * @brief 
 * 
 * we init stack with a splt by space
 * because str is " 48 55 95 32 14"
 * 
 * the malloc by the strlen of argument splitted
 * 
 * and re retunr the double table of splitted argc
 * we free the str joineed previously
 * 
 * @param str 
 * @param stack 
 * @return char** 
 */
char	**ft_init_stack_checker(char *nbr_joined, t_stack_a_b *stack)
{
	char	**splitted;
	int		size;

	size = 0;
	splitted = ft_split(nbr_joined, ' ');
	while (splitted[size])
		size++;
	stack->stack_a.tab = (int *)malloc(sizeof(int) * size);
	stack->stack_b.tab = (int *)malloc(sizeof(int) * size);
	stack->stack_a.size = size;
	stack->stack_b.size = size;
	stack->stack_a.used = 0;
	stack->stack_b.used = 0;
	free(nbr_joined);
	return (splitted);
}

/**
 * @brief 
 * 
 * we check the doublong with the number in param
 * until we rech the used index with the used varaible
 * 0 doublon 1 no doublon
 * 
 * @param stack 
 * @param nbr 
 * @return int 
 */
int	ft_doublon_tab_nbr(t_stack_a_b *stack, int nbr)
{
	int		idx;

	idx = 0;
	while (idx < stack->stack_a.used)
	{
		if (nbr == stack->stack_a.tab[idx])
			return (EXIT_SUCCESS);
		idx++;
	}
	return (EXIT_FAILURE);
}
