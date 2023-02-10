/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:33:43 by vgonnot           #+#    #+#             */
/*   Updated: 2022/12/13 18:12:19 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	check_sign(char *sign, int *i)
{
	while ((sign[*i] >= 9 && sign[*i] <= 13) || sign[*i] == 32)
	{
		*i += 1;
	}
	if (sign[*i] == '-')
	{
		*i += 1;
		return (-1);
	}
	if (sign[*i] == '+')
		*i += 1;
	return (1);
}

int	ft_atoi(char *str, t_stack *st, int need_free, int check_error)
{
	long long int			result;
	int						negative;
	int						i;

	i = 0;
	result = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1] == '\0')
		quit_function(st, NULL, 1);
	negative = check_sign(&str[i], &i);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			quit_function(st, NULL, 1);
		result += (str[i] - '0');
		result *= 10;
		i++;
	}
	result = result / 10 * negative;
	if ((result > 2147483647 || result < -2147483648) && check_error)
		quit_function(st, NULL, 1);
	if (need_free)
		free(str);
	return (result);
}

void	quit_function(t_stack *st, t_stack *st2, int nbr_free)
{
	if (nbr_free > 0 && *st != NULL)
		*st = free_stack_function(*st);
	if (nbr_free > 2 && *st2 != NULL)
		*st2 = free_stack_function(*st2);
	write(1, "Error\n", 7);
	exit(-1);
}

int	check_if_stack_sorted(t_stack st)
{
	t_stack	next;

	if (st == NULL)
		return (0);
	while (st->next != NULL)
	{
		next = st->next;
		if (st->content > next->content)
			return (1);
		st = next;
	}
	return (0);
}
