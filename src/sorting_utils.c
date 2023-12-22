/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:43:30 by smallem           #+#    #+#             */
/*   Updated: 2023/06/20 10:26:03 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	if (get_max_ind(*stack_a) == 0)
	{
		rot(stack_a, 'a');
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap(stack_a, 'a');
	}
	else if (get_max_ind(*stack_a) == 1)
	{
		rev_rot(stack_a, 'a');
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap(stack_a, 'a');
	}
	else
		swap(stack_a, 'a');
}

void	print_cmd(t_stack **stack_a, t_stack **stack_b, int pos)
{	
	if (pos == 1)
		rot(stack_a, 'a');
	if (pos == 2)
	{
		rot(stack_a, 'a');
		rot(stack_a, 'a');
	}
	if (pos == 3)
		rev_rot(stack_a, 'a');
	push(stack_b, ft_stcknew(pop(stack_a)), 'b');
	if (!ft_is_sorted(*stack_a))
		sort_three(stack_a);
	push(stack_a, ft_stcknew(pop(stack_b)), 'a');
	rot(stack_a, 'c');
}

void	sort_five(t_stack **stack_a, t_stack **stack_b, int pos)
{
	if (pos == 1)
		rot(stack_a, 'a');
	if (pos == 2)
	{
		rot(stack_a, 'a');
		rot(stack_a, 'a');
	}
	if (pos == 3)
	{
		rev_rot(stack_a, 'a');
		rev_rot(stack_a, 'a');
	}
	if (pos == 4)
	{
		rev_rot(stack_a, 'a');
	}
	push(stack_b, ft_stcknew(pop(stack_a)), 'b');
	print_cmd(stack_a, stack_b, get_min_ind(*stack_a));
	push(stack_a, ft_stcknew(pop(stack_b)), 'a');
}

void	sort_small(t_stack **stack_a, t_stack **stack_b, int argc)
{
	if (argc == 4)
		sort_three(stack_a);
	else if (argc == 5)
		print_cmd(stack_a, stack_b, get_min_ind(*stack_a));
	else
		sort_five(stack_a, stack_b, get_min_ind(*stack_a));
}

void	ft_sort(int argc, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*stack_copy;

	if (argc == 3)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			ft_putstr_fd("sa\n", 1);
		return ;
	}
	else if (argc <= 6)
		sort_small(stack_a, stack_b, argc);
	else
	{
		stack_copy = copy_stack(*stack_a);
		bubble_sort(stack_a);
		map_stack(stack_copy, stack_a);
		free_stack(&stack_copy);
		if (!ft_is_sorted(*stack_a))
			sort_big(stack_a, stack_b);
	}
}
