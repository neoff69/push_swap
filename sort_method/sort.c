/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 08:03:31 by vgonnot           #+#    #+#             */
/*   Updated: 2022/12/17 15:34:55 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

int	get_number_element(int argc, t_stack stack_a)
{
	int	number_element;

	if (argc > 2)
		number_element = argc - 1;
	else
	{
		number_element = count_node(stack_a);
	}
	return (number_element);
}

void	sort_method(t_stack *stack_a, t_stack *stack_b, int argc)
{
	int	nbr_element;

	nbr_element = get_number_element(argc, *stack_a);
	if (nbr_element <= 1)
		return ;
	else if (nbr_element <= 5)
		return (hard_sort(stack_a, stack_b, nbr_element));
	radix_sort(stack_a, stack_b);
}
