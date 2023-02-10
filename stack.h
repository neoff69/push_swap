/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <vgonnot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:40:58 by vgonnot           #+#    #+#             */
/*   Updated: 2022/12/17 15:34:34 by vgonnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <unistd.h>
# include <stdlib.h>

typedef struct t_stack_elem
{
	int					content;
	struct t_stack_elem	*next;
}*t_stack;

/*libft utils*/
int		ft_atoi(char *str, t_stack *st, int need_free, int check_error);
size_t	ft_strlen(const char *s);
void	quit_function(t_stack *st, t_stack *st2, int nbr_free);
void	convert_binar(t_stack *stack_a);
int		check_if_stack_sorted(t_stack st);

/*stack utils*/
t_stack	new_stack(void);
void	pop_element(t_stack *st);
t_stack	free_stack_function(t_stack st);
void	stack_add_front(t_stack *st, int number);
t_stack	put_number_stack(char **argv, int argc);
t_stack	reverse_list(t_stack current);
t_stack	ft_lstlast(t_stack lst);
int		count_node(t_stack lst);
int		check_null(t_stack st);
t_stack	create_node(int value, t_stack st, t_stack st2);
t_stack	get_before_last(t_stack lst);

/*setup number in stack*/
t_stack	put_number_stack(char **argv, int argc);
t_stack	replace_number_by_index(t_stack stack);

/*sort intruction*/
void	single_swap(t_stack *stack, char name_stack);
void	double_swap(t_stack *stack_a, t_stack *stack_b);
void	push_elem(t_stack *destination, t_stack *source, char stack_name);
void	single_rotate(t_stack *stack, char stack_name);
void	double_rotate(t_stack *stack_a, t_stack *stack_b);
void	single_reverse_rotate(t_stack *stack, char stack_name);
void	double_reverse_rotate(t_stack *stack_a, t_stack *stack_b);

/*sort method*/
void	sort_method(t_stack *stack_a, t_stack *stack_b, int argc);
void	hard_sort(t_stack *stack_a, t_stack *stack_b, int nbr_elem);
void	hard_sort_stack_b(t_stack *stack_b);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);

#endif