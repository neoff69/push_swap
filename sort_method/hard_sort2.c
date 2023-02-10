/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:38:04 by vgonnot           #+#    #+#             */
/*   Updated: 2022/12/11 13:36:47 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

void	hard_sort_stack_b(t_stack *stack_b)
{
	t_stack	next;

	if (check_null(*stack_b))
		return ;
	next = (*stack_b)->next;
	if ((*stack_b)->content > next->content)
		single_swap(stack_b, 'b');
}
