/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_number_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:48:16 by vgonnot           #+#    #+#             */
/*   Updated: 2022/12/12 10:37:16 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

void	copy_and_sort_list(int content, t_stack *stack, t_stack *source_stack)
{
	t_stack	previous;
	t_stack	temp;
	t_stack	node;

	previous = NULL;
	node = create_node(content, *stack, *source_stack);
	temp = *stack;
	if (temp == NULL)
		return (free(node), stack_add_front(stack, content));
	while (temp != NULL && content > temp->content)
	{
		previous = temp;
		temp = temp->next;
	}
	if (previous)
	{
		previous->next = node;
		node->next = temp;
	}
	else
	{
		node->next = temp;
		*stack = node;
	}
}

t_stack	put_index_list(t_stack stack, t_stack sorted_stack)
{
	t_stack	temp;
	t_stack	begin_sorted_s;
	int		i;

	temp = stack;
	begin_sorted_s = sorted_stack;
	while (stack)
	{
		sorted_stack = begin_sorted_s;
		i = 0;
		while (stack->content != sorted_stack->content)
		{
			i++;
			sorted_stack = sorted_stack->next;
		}
		stack->content = i;
		stack = stack->next;
	}
	stack = temp;
	return (stack);
}

t_stack	replace_number_by_index(t_stack stack)
{
	t_stack	sorted_stack;
	t_stack	temp;

	temp = stack;
	sorted_stack = new_stack();
	while (stack != NULL)
	{
		copy_and_sort_list(stack->content, &sorted_stack, &stack);
		stack = stack->next;
	}
	stack = temp;
	stack = put_index_list(stack, sorted_stack);
	free_stack_function(sorted_stack);
	return (stack);
}
