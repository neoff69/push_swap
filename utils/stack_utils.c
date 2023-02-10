/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:40:56 by vgonnot           #+#    #+#             */
/*   Updated: 2022/12/21 13:18:55 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

t_stack	new_stack(void)
{
	return (NULL);
}

void	pop_element(t_stack *st)
{
	t_stack	temp;

	temp = *st;
	*st = (*st)->next;
	free(temp);
}

t_stack	free_stack_function(t_stack st)
{
	t_stack	temp;

	while (st != NULL)
	{
		temp = st;
		st = st->next;
		free(temp);
	}
	return (NULL);
}

void	stack_add_front(t_stack *st, int number)
{
	t_stack	element;

	element = malloc(sizeof(*element));
	if (element == NULL)
		quit_function(st, NULL, 1);
	element->content = number;
	element->next = *st;
	*st = element;
}

t_stack	reverse_list(t_stack current)
{
	t_stack	previous;
	t_stack	next;

	if (current == NULL)
		return (NULL);
	previous = NULL;
	next = current->next;
	while (current->next)
	{
		current->next = previous;
		previous = current;
		current = next;
		next = next->next;
	}
	current->next = previous;
	return (current);
}
