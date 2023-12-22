/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:33:21 by smallem           #+#    #+#             */
/*   Updated: 2023/06/26 13:36:48 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "../libft/libft.h"

typedef struct s_stack	t_stack;

typedef struct s_stack
{
	int			content;
	t_stack		*next;
}				t_stack;

int			is_valid_int(char *argv);
int			*build_arr(int argc, char **argv, int i);
int			dup_present(int	*arr, int n);
int			run_checks(int argc, char **argv);
int			ft_is_sorted(t_stack *stack);
void		ft_create_stack(t_stack **stack, char **argv, int *argc);
void		rot(t_stack **stack, char c);
void		rev_rot(t_stack **stack, char c);
void		swap(t_stack **stack, char c);
int			pop(t_stack **stack);
void		ft_sort(int argc, t_stack **stack_a, t_stack **stack_b);
void		sort_small(t_stack **stack_a, t_stack **stack_b, int argc);
void		sort_big(t_stack **stack_a, t_stack **stack_b);
void		counting_sort(t_stack **stack_a, t_stack **stack_b, int exp);
int			get_max(t_stack *stack_a);
void		sort_three(t_stack **stack_a);
int			get_min_ind(t_stack *stack);
int			get_max_ind(t_stack *stack);
void		print_cmd(t_stack **stack_a, t_stack **stack_b, int pos);
void		sort_five(t_stack **stack_a, t_stack **stack_b, int pos);
t_stack		*ft_stcknew(int content);
void		push(t_stack **stack, t_stack *node, char c);
int			pop(t_stack **stack);
void		free_stack(t_stack **stack);
void		add_2stack(t_stack **stack, t_stack *node);
int			get_number_elems(t_stack *stack);
void		bubble_sort(t_stack **stack);
t_stack		*copy_stack(t_stack *stack);
void		map_stack(t_stack *copy, t_stack **stack_a);
void		copy_content(t_stack *copy, t_stack **stack_a);
int			*build(char *argv);
void		f_split(char **set);
int			conseq_spaces(char *argv);

#endif