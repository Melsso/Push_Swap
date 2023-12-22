/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:55:17 by smallem           #+#    #+#             */
/*   Updated: 2023/06/26 13:40:31 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	f_split(char **set)
{
	int	i;

	i = 0;
	while (set[i])
		free(set[i++]);
	free(set);
}

int	conseq_spaces(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == ' ' || argv[i] == '\n' || argv[i] == '\t'
		|| argv[i] == '\v' || argv[i] == '\r' || argv[i] == '\f')
		return (1);
	while (argv[i])
	{
		if (argv[i] == ' ' || argv[i] == '\n' || argv[i] == '\t'
			|| argv[i] == '\v' || argv[i] == '\r' || argv[i] == '\f')
		{
			i++;
			if (argv[i] == ' ' || argv[i] == '\n' || argv[i] == '\t'
				|| argv[i] == '\v' || argv[i] == '\r' || argv[i] == '\f'
				|| argv[i] == '\0')
				return (1);
		}
		else
			i++;
	}
	return (0);
}
