/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:37:51 by gcomlan           #+#    #+#             */
/*   Updated: 2022/06/28 17:28:54 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/*
	
*/

t_list	*init_list_of_link(int nbr)
{
	t_node	*node;
	t_list	*list;

	list = malloc(sizeof(*list));
	node = malloc(sizeof(*node));
	if (list == NULL || node == NULL)
	{
		write(2, ERROR_MSG, 7);
		return (NULL);
	}
	node->value = nbr;
	node->next = NULL;
	list->first = node;
	list->nbr_elm = 1;
	return (list);
}

//
int	add_front(t_list *list, int nbr)
{
	t_node	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (list == NULL || new_node == NULL)
	{
		write(2, ERROR_MSG, 7);
		return (0);
	}
	new_node->value = nbr;
	new_node->next = list->first;
	list->first = new_node;
	list->nbr_elm++;
	return (0);
}

/*
	THIS FCT JUST FREE ALL THE NODE
	IN THE LIST AND PUT IT AT NULL
*/

void	free_list(t_list *list)
{
	t_node	*current;

	if (list == NULL)
		return ;
	current = list->first;
	while (list->first != NULL)
	{
		list->first = list->first->next;
		free(current);
		current = list->first;
	}
	free(list);
	list = NULL;
}

/*
	THIS FCT CHECK IF a IS VALID OUT I NOT
	WE INIT THE DUP STASH LOL TROP DE 2B2T
	WITH THE FIRST NBR
	THEN STORE THE INDX/POS FOR THE CHECK
	WHEN WE ADD AT END
	SO WE LOOP IN A/TO_COPY AND WE SEND
	THE DUP THE POS AND THE NBR TO COPY IN
*/

t_list	*duplicate_list(t_list *a)
{
	t_list		*duplicate;
	t_node		*to_cpy;
	t_node		*idx;

	if (a == NULL)
	{
		write(2, "Error\n", 7);
		return (NULL);
	}
	duplicate = init_list_of_link(a->first->value);
	idx = duplicate->first;
	to_cpy = a->first->next;
	while (to_cpy != NULL)
	{
		add_at_the_end(duplicate, idx, to_cpy->value);
		idx = idx->next;
		to_cpy = to_cpy->next;
	}
	duplicate->nbr_elm = a->nbr_elm;
	return (duplicate);
}

/*
	THIS FCT CHECK THE MALLOC OF THE NEW_NODE / QUIT
	WE GO AT THE POS WE NEED TO INSERT THE NEW NBR
	IF INT THE LIST WE ARE AT THE POS WE STORE NEW NBR
	TO PUT IT INT THE END OF THE CURRENT NODE

	THOSE FCT ADD LIKE THAT

	[15]-[12]-[45]-[12]-[NULL]
	4 elm

	[15]-[]-[]-[]-[NULL]
	1 elm
	
	-------------------------
	Looping [12]-[++]

	[15]-[12]-[]-[]-[NULL]
	2 elm
	-------------------------
	
*/

void	add_at_the_end(t_list *list, t_node *idx, int nbr)
{
	t_node	*current;
	t_node	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (list == NULL || new_node == NULL)
	{
		write(2, ERROR_MSG, 7);
		return ;
	}
	current = list->first;
	while (current != idx)
		current = current->next;
	if (current == idx)
	{
		new_node->value = nbr;
		new_node->next = current->next;
		current->next = new_node;
		list->nbr_elm++;
	}
}
