/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:51:02 by smallem           #+#    #+#             */
/*   Updated: 2023/06/18 14:57:24 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_max_ind(t_stack *stack)
{
	int	i;
	int	index;
	int	max;

	index = 0;
	i = 0;
	max = stack->content;
	while (stack)
	{
		if (max < stack->content)
		{
			max = stack->content;
			index = i;
		}
		i++;
		stack = stack->next;
	}
	return (index);
}

int	get_min_ind(t_stack *stack)
{
	int	i;
	int	index;
	int	min;

	index = 0;
	i = 0;
	min = stack->content;
	while (stack)
	{
		if (min > stack->content)
		{
			min = stack->content;
			index = i;
		}
		i++;
		stack = stack->next;
	}
	return (index);
}

int	get_max(t_stack *stack_a)
{
	int	max;

	max = stack_a->content;
	while (stack_a)
	{
		if (max < stack_a->content)
			max = stack_a->content;
		stack_a = stack_a->next;
	}
	return (max);
}

void	counting_sort(t_stack **stack_a, t_stack **stack_b, int exp)
{
	int	count;
	int	n;

	n = get_number_elems(*stack_a);
	count = 0;
	while (n--)
	{
		if ((((*stack_a)->content >> exp) & 1) == 0)
		{
			count++;
			push(stack_b, ft_stcknew(pop(stack_a)), 'b');
		}
		else
			rot(stack_a, 'a');
	}
	while (count--)
		push(stack_a, ft_stcknew(pop(stack_b)), 'a');
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	exp;
	int	bitc;

	max = get_max(*stack_a);
	bitc = 0;
	while (max > 0)
	{
		max /= 2;
		bitc++;
	}
	exp = 0;
	while (exp < bitc)
	{
		if (ft_is_sorted(*stack_a))
			break ;
		counting_sort(stack_a, stack_b, exp);
		exp++;
	}
}
