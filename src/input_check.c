/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:57:58 by smallem           #+#    #+#             */
/*   Updated: 2023/06/26 13:40:02 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_valid_int(char *argv)
{
	int		nbr;
	char	*tmp;
	int		val;
	int		i;

	i = 0;
	if (argv[i] == '\0')
		return (0);
	nbr = ft_atoi(argv);
	tmp = ft_itoa(nbr);
	val = !ft_strncmp(argv, tmp, ft_strlen(argv));
	free(tmp);
	return (val);
}

int	dup_present(int	*arr, int n)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n)
	{
		j = i;
		while (++j < n)
			if (arr[i] == arr[j])
				return (1);
	}
	return (0);
}

int	*build_arr(int argc, char **argv, int i)
{
	int	*arr;
	int	j;

	arr = (int *)malloc((argc - 1) * sizeof(int));
	if (arr == NULL)
		return (NULL);
	j = -1;
	while (argv[++i])
		arr[++j] = ft_atoi(argv[i]);
	return (arr);
}

int	*build(char *argv)
{
	int		size;
	char	**mat;
	int		*arr;

	mat = ft_split(argv, ' ');
	if (mat == NULL || *mat == NULL || conseq_spaces(argv))
		return (NULL);
	size = 0;
	while (mat[size])
	{
		if (!is_valid_int(mat[size]))
		{
			size = 0;
			while (mat[size])
				free(mat[size++]);
			return (free(mat), NULL);
		}
		size++;
	}
	arr = build_arr(size + 1, mat, -1);
	f_split(mat);
	if (dup_present(arr, size))
		return (free(arr), NULL);
	return (arr);
}

int	run_checks(int argc, char **argv)
{
	int	i;
	int	*arr;

	if (argc <= 1)
		return (0);
	i = 0;
	if (argc == 2)
	{
		arr = build(argv[1]);
		if (arr == NULL)
			return (0);
	}
	else
	{
		while (argv[++i])
			if (!is_valid_int(argv[i]))
				return (0);
		arr = build_arr(argc, argv, 0);
	}
	if (arr == NULL)
		return (0);
	if (dup_present(arr, argc - 1))
		return (free(arr), 0);
	return (free(arr), 1);
}
