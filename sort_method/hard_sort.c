/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 07:56:24 by vgonnot           #+#    #+#             */
/*   Updated: 2022/12/10 13:37:54 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

void	first_case_sort(t_stack *stack_a, t_stack double_next)
{
	t_stack	next;

	if (double_next == NULL )
		single_swap(stack_a, 'a');
	else if ((*stack_a)->content > double_next->content)
	{
		single_rotate(stack_a, 'a');
		next = (*stack_a)->next;
		if ((*stack_a)->content > next->content)
		{
			single_swap(stack_a, 'a');
		}
	}
	else
		single_swap(stack_a, 'a');
}

void	second_case_sort(t_stack *stack_a, t_stack double_next)
{
	if ((*stack_a)->content > double_next->content)
		single_reverse_rotate(stack_a, 'a');
	else
	{
		single_reverse_rotate(stack_a, 'a');
		single_swap(stack_a, 'a');
	}
}

int	put_element_b(t_stack *a, t_stack *b, int *nbr_element, int i)
{
	push_elem(b, a, 'b');
	(*nbr_element) -= 1;
	return (i + 1);
}

void	set_and_sort_b(t_stack *stack_a, t_stack *stack_b, int nbr_elem)
{
	t_stack	next_b;
	int		i;

	i = 0;
	if (nbr_elem == 4)
	{
		while ((*stack_a)->content != 0 && *stack_a)
			single_rotate(stack_a, 'a');
		i = put_element_b(stack_a, stack_b, &nbr_elem, i);
	}
	while (nbr_elem > 3 && i < 2)
	{
		while ((*stack_a)->content != 0 && (*stack_a)->content != 1 && *stack_a)
			single_rotate(stack_a, 'a');
		i = put_element_b(stack_a, stack_b, &nbr_elem, i);
	}
	if (i == 2)
	{
		next_b = (*stack_b)->next;
		if ((*stack_b)->content < next_b->content)
			single_swap(stack_b, 'b');
	}
}

void	hard_sort(t_stack *stack_a, t_stack *stack_b, int nbr_elem)
{
	t_stack	next;
	t_stack	double_next;

	if (nbr_elem == 1)
		return ;
	next = (*stack_a)->next;
	if (nbr_elem == 2)
	{
		if ((*stack_a)->content > next->content)
			single_swap(stack_a, 'a');
		return ;
	}
	if (nbr_elem > 3)
		set_and_sort_b(stack_a, stack_b, nbr_elem);
	next = (*stack_a)->next;
	double_next = next->next;
	if ((*stack_a)->content > next->content)
		first_case_sort(stack_a, double_next);
	else if (next->content > double_next->content)
		second_case_sort(stack_a, double_next);
	while (*stack_b != NULL)
		push_elem(stack_a, stack_b, 'a');
}
