/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:34:01 by vgonnot           #+#    #+#             */
/*   Updated: 2022/12/21 13:18:32 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

static int	size_malloc(int value)
{
	int	i;

	i = 2;
	if (value < 0)
		value *= -1;
	if (value == 0)
		return (i + 1);
	while (value > 0)
	{
		value /= 2;
		i++;
	}
	return (i);
}

static void	reverse_tab(int len, char *str)
{
	int		i;
	char	temp;

	len -= 1;
	i = 0;
	while (i < len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		i++;
		len--;
	}
}

int	convert(int value)
{	
	char	*result;
	int		i;

	i = 0;
	result = malloc(sizeof(char) * size_malloc(value));
	if (result == NULL)
		return (0);
	if (value == 0)
	{
		free(result);
		return (0);
	}
	while (value > 0)
	{
		result[i] = value % 2 + '0';
		value /= 2;
		i++;
	}
	result[i] = '\0';
	reverse_tab(i, result);
	i = ft_atoi(result, NULL, 0, 0);
	free(result);
	return (i);
}

void	convert_binar(t_stack *stack_a)
{
	t_stack	temp;

	temp = *stack_a;
	while (*stack_a != NULL)
	{
		(*stack_a)->content = convert((*stack_a)->content);
		*stack_a = (*stack_a)->next;
	}
	*stack_a = temp;
}
