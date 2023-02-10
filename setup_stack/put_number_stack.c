/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_number_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:40:50 by vgonnot           #+#    #+#             */
/*   Updated: 2022/12/21 13:17:19 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

static void	check_double_nbr(t_stack st)
{
	int	temp;

	if (st == NULL)
		return ;
	temp = st->content;
	while (st->next)
	{
		st = st->next;
		if (temp == st->content)
			quit_function(&st, NULL, 1);
	}
}

static int	check_number(char c, char before_c, int i)
{
	if ((!(before_c >= '0' && before_c <= '9') && before_c != ' ') && c == '\0')
		return (1);
	else if (c == '\0')
		return (0);
	if ((before_c == '+' || before_c == '-') && c == ' ')
		return (1);
	if (!(c >= '0' && c <= '9'))
	{
		if (c != ' ' && c != '+' && c != '-')
			return (1);
		if (i > 0 && (c == '+' || c == '-') && before_c != ' ')
			return (1);
	}
	return (0);
}

static char	*copy_number(char *str, int *index, int sign)
{
	int		i;
	char	*temp;

	i = 0;
	if (sign == -1)
	{
		temp = malloc(sizeof(char) * ft_strlen(str) + 2);
		if (temp == NULL)
			exit(write(1, "Error\n", 7));
		temp[i] = '-';
		i++;
	}
	else
		temp = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (temp == NULL)
		exit(write(1, "Error\n", 7));
	while ((str[i + sign] >= '0' && str[i + sign] <= '9'))
	{
		temp[i] = str[i + sign];
		i++;
	}
	temp[i] = '\0';
	*index += i + sign;
	return (temp);
}

static t_stack	two_arg_stack(char *str, t_stack stack)
{
	int			i;
	char		*temp;
	int			number_value;

	i = -1;
	while (str[++i])
	{
		if (check_number(str[i], str[i - 1], i))
			quit_function(&stack, NULL, 1);
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (i > 0 && str[i - 1] == '-')
				temp = copy_number(&str[i], &i, -1);
			else
				temp = copy_number(&str[i], &i, 0);
			number_value = ft_atoi(temp, &stack, 1, 1);
			stack_add_front(&stack, number_value);
			check_double_nbr(stack);
		}
		if (str[i] == '\0')
			return (stack = reverse_list(stack), stack);
	}
	if (check_number(str[i], str[i - 1], i))
		quit_function(&stack, NULL, 1);
	return (stack = reverse_list(stack), stack);
}

t_stack	put_number_stack(char **argv, int argc)
{
	int		i;
	int		number_value;
	t_stack	stack;

	i = 0;
	argc -= 1;
	stack = new_stack();
	if (argc == 1)
		stack = two_arg_stack(argv[1], stack);
	else
	{
		while (i < argc)
		{
			number_value = ft_atoi(argv[argc], &stack, 0, 1);
			stack_add_front(&stack, number_value);
			check_double_nbr(stack);
			argc--;
		}
	}
	return (stack);
}
