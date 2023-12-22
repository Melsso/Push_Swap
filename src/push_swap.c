/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:32:29 by smallem           #+#    #+#             */
/*   Updated: 2023/06/26 13:44:46 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (1);
	if (!run_checks(argc, argv))
		return (ft_putstr_fd("Error\n", 2), 1);
	stack_a = NULL;
	stack_b = NULL;
	ft_create_stack(&stack_a, argv, &argc);
	if (ft_is_sorted(stack_a))
		return (free_stack(&stack_a), 0);
	ft_sort(argc, &stack_a, &stack_b);
	free_stack(&stack_a);
	stack_a = NULL;
	stack_b = NULL;
}
