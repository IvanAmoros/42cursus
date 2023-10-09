/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:44:24 by iamoros-          #+#    #+#             */
/*   Updated: 2023/10/08 19:14:30 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	ft_check_args(int argc, char **argv);
void	ft_error(char *error);
t_stack	*ft_lstlast_push_swap(t_stack *lst);
void	stack_error(t_stack *stack_a, t_stack *stack_b);
void	free_stack(t_stack *stack);
int		ft_lstsize_push_swap(t_stack *lst);
int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ss(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
int		rrr(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack *stack);
void	simple_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_index(t_stack **stack_a);
void	print_stack(char *tittle, t_stack *stack);
int		find_smallest(t_stack **stack);
void	smallest_to_b(t_stack **stack_a, t_stack **stack_b);
void	complex_sort(t_stack **stack_a, t_stack **stack_b);
int		find_biggest(t_stack *stack);
int		first_position(t_stack **stack, int to_chunk);
int		second_position(t_stack **stack, int to_chunk);

#endif