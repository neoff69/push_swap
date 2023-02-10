/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:40:50 by vgonnot           #+#    #+#             */
/*   Updated: 2022/12/12 10:40:25 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		return (-1);
	stack_a = put_number_stack(argv, argc);
	stack_a = replace_number_by_index(stack_a);
	stack_b = new_stack();
	if (check_if_stack_sorted(stack_a))
		sort_method(&stack_a, &stack_b, argc);
	free_stack_function(stack_a);
	return (0);
}
