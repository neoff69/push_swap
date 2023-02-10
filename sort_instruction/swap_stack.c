/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:01:18 by vgonnot           #+#    #+#             */
/*   Updated: 2022/12/07 08:33:25 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

void	single_swap(t_stack *stack, char name_stack)
{
	t_stack	next;
	int		temp;

	if (check_null(*stack))
		return ;
	next = (*stack)->next;
	temp = (*stack)->content;
	(*stack)->content = next->content;
	next->content = temp;
	if (name_stack == 'a')
		write(1, "sa\n", 3);
	if (name_stack == 'b')
		write(1, "sb\n", 3);
}

void	double_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (check_null(*stack_a))
		return ;
	if (check_null(*stack_b))
		return ;
	single_swap(stack_a, 0);
	single_swap(stack_b, 0);
	write(1, "ss\n", 3);
}
