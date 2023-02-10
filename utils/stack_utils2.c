/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:30:04 by vgonnot           #+#    #+#             */
/*   Updated: 2022/12/21 13:19:11 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

t_stack	ft_lstlast(t_stack lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

t_stack	get_before_last(t_stack lst)
{
	t_stack	previous;

	previous = lst;
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		previous = lst;
		lst = lst->next;
	}
	return (previous);
}

int	count_node(t_stack lst)
{
	int	count;

	if (lst == NULL)
		return (0);
	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

t_stack	create_node(int value, t_stack st, t_stack st2)
{
	t_stack	element;

	element = malloc(sizeof(*element));
	if (element == NULL)
		quit_function(&st, &st2, 2);
	element->next = NULL;
	element->content = value;
	return (element);
}

int	check_null(t_stack st)
{
	if (st == NULL)
		return (1);
	if (st->next == NULL)
		return (1);
	return (0);
}
