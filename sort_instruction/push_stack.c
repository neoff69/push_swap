/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:46:48 by vgonnot           #+#    #+#             */
/*   Updated: 2022/12/11 14:23:08 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

void	push_elem(t_stack *destination, t_stack *source, char stack_name)
{
	t_stack	delete;

	if (*source == NULL)
		return ;
	stack_add_front(destination, (*source)->content);
	delete = *source;
	*source = (*source)->next;
	free(delete);
	if (stack_name == 'a')
		write(1, "pa\n", 3);
	if (stack_name == 'b')
		write(1, "pb\n", 3);
}
