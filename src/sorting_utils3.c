/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:20:24 by smallem           #+#    #+#             */
/*   Updated: 2023/06/18 14:58:50 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_number_elems(t_stack *stack)
{
	int	n;

	n = 0;
	while (stack)
	{
		n++;
		stack = stack->next;
	}
	return (n);
}

void	bubble_sort(t_stack **stack)
{
	int		swapped;
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*stack == NULL)
		return ;
	tmp2 = NULL;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		tmp = *stack;
		while (tmp->next != tmp2)
		{
			if (tmp->content > tmp->next->content)
			{
				swap(&tmp, 'c');
				swapped = 1;
			}
			tmp = tmp->next;
		}
		tmp2 = tmp;
	}
}

t_stack	*copy_stack(t_stack *stack)
{
	t_stack	*copy;

	copy = NULL;
	while (stack)
	{
		add_2stack(&copy, ft_stcknew(stack->content));
		stack = stack->next;
	}
	return (copy);
}

void	copy_content(t_stack *copy, t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (copy)
	{
		tmp->content = copy->content;
		tmp = tmp->next;
		copy = copy->next;
	}
}

void	map_stack(t_stack *copy, t_stack **stack_a)
{
	int		ind;
	t_stack	*tmp;
	t_stack	*cp;

	cp = copy;
	while (copy)
	{
		ind = 0;
		tmp = *stack_a;
		while (tmp)
		{
			if (tmp->content == copy->content)
			{
				copy->content = ind;
				break ;
			}
			tmp = tmp->next;
			ind++;
		}
		copy = copy->next;
	}
	copy_content(cp, stack_a);
}
