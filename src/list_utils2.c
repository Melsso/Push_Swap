/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:37:44 by smallem           #+#    #+#             */
/*   Updated: 2023/06/22 10:20:04 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_stcknew(int content)
{
	t_stack	*tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	if (tmp == NULL)
		return (NULL);
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}

void	add_2stack(t_stack **stack, t_stack *node)
{
	t_stack	*tmp;

	if (node == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = node;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void	push(t_stack **stack, t_stack *node, char c)
{
	if (node == NULL)
		return ;
	if (stack == NULL)
	{
		*stack = node;
		return ;
	}
	node->next = *stack;
	*stack = node;
	if (c == 'a')
		ft_putstr_fd("pa\n", 1);
	if (c == 'b')
		ft_putstr_fd("pb\n", 1);
}

int	pop(t_stack **stack)
{
	int		content;
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	content = tmp->content;
	free(tmp);
	tmp = NULL;
	return (content);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
