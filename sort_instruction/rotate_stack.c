/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:01:33 by vgonnot           #+#    #+#             */
/*   Updated: 2022/12/11 14:23:02 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

void	single_rotate(t_stack *stack, char stack_name)
{
	t_stack	last;
	t_stack	next_elem;

	last = *stack;
	next_elem = (*stack)->next;
	if (check_null(*stack))
		return ;
	last = ft_lstlast(last);
	last->next = *stack;
	(*stack)->next = NULL;
	*stack = next_elem;
	if (stack_name == 'a')
		write(1, "ra\n", 3);
	if (stack_name == 'b')
		write(1, "rb\n", 3);
}

void	double_rotate(t_stack *stack_a, t_stack *stack_b)
{
	if (check_null(*stack_a))
		return ;
	if (check_null(*stack_b))
		return ;
	single_rotate(stack_a, 0);
	single_rotate(stack_b, 0);
	write(1, "rr\n", 3);
}

void	single_reverse_rotate(t_stack *stack, char stack_name)
{
	t_stack	before_last;
	t_stack	last;

	before_last = *stack;
	last = *stack;
	if (check_null(*stack))
		return ;
	before_last = get_before_last(before_last);
	last = ft_lstlast(last);
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
	if (stack_name == 'a')
		write(1, "rra\n", 4);
	if (stack_name == 'b')
		write(1, "rrb\n", 4);
}

void	double_reverse_rotate(t_stack *stack_a, t_stack *stack_b)
{
	if (check_null(*stack_a))
		return ;
	if (check_null(*stack_b))
		return ;
	single_reverse_rotate(stack_a, 0);
	single_reverse_rotate(stack_b, 0);
	write(1, "rrr\n", 3);
}
