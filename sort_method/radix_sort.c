/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:41:08 by vgonnot           #+#    #+#             */
/*   Updated: 2022/12/17 15:34:46 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

static	int	is_sort(t_stack stack_a)
{
	int		i;
	t_stack	next;

	i = 0;
	next = stack_a->next;
	while (stack_a->next)
	{
		if (stack_a->content > next->content)
			return (0);
		stack_a = stack_a->next;
		next = next->next;
	}
	return (1);
}

int	modulo_digit(int division, int content)
{
	int	result;

	result = content / division % 2;
	return (result);
}

int	push(t_stack *stack_a, t_stack *stack_b, int number_node, int division)
{
	int		i;

	i = 0;
	number_node = count_node(*stack_a);
	while (number_node > 0)
	{
		if (modulo_digit(division, (*stack_a)->content))
		{
			single_rotate(stack_a, 'a');
			i++;
		}
		else
			push_elem(stack_b, stack_a, 'b');
		number_node--;
	}
	while (*stack_b)
		push_elem(stack_a, stack_b, 'a');
	return (i);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	one_finder;
	int	division;
	int	number_node;

	number_node = count_node(*stack_a);
	convert_binar(stack_a);
	one_finder = 1;
	division = 1;
	while (one_finder > 0)
	{
		one_finder = push(stack_a, stack_b, number_node, division);
		if (is_sort(*stack_a))
			return ;
		division *= 10;
	}
}
