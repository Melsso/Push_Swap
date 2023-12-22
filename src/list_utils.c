/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:07:53 by smallem           #+#    #+#             */
/*   Updated: 2023/06/22 10:20:12 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_create_stack(t_stack **stack, char **argv, int *argc)
{
	int		i;
	char	**mat;

	i = 0;
	if (*argc != 2)
	{
		while (argv[++i])
			add_2stack(stack, ft_stcknew(ft_atoi(argv[i])));
	}
	else
	{
		mat = ft_split(argv[1], ' ');
		if (mat == NULL)
			return ;
		while (mat[i])
			add_2stack(stack, ft_stcknew(ft_atoi(mat[i++])));
		*argc = ++i;
		f_split(mat);
	}
}

void	rev_rot(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*head;
	t_stack	*last;

	tmp = *stack;
	head = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = head;
	*stack = last;
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
}

void	rot(t_stack **stack, char c)
{
	t_stack	*first_node;
	t_stack	*tmp;

	first_node = *stack;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first_node;
	*stack = first_node->next;
	first_node->next = NULL;
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	if (c == 'b')
		ft_putstr_fd("rb\n", 1);
}

void	swap(t_stack **stack, char c)
{
	int	tmp;

	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	if (c == 'b')
		ft_putstr_fd("sb\n", 1);
}
