/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:51:47 by iamoros-          #+#    #+#             */
/*   Updated: 2023/10/08 17:13:48 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smallest_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int		smallest_position;

	smallest_position = find_smallest(stack_a);
	if (smallest_position <= ft_lstsize_push_swap(*stack_a) / 2)
	{
		while (smallest_position != 0)
		{
			ra(stack_a);
			smallest_position--;
		}
	}
	else
	{
		while (smallest_position != ft_lstsize_push_swap(*stack_a))
		{
			rra(stack_a);
			smallest_position++;
		}
	}
	pb(stack_a, stack_b);
}

int	first_position(t_stack **stack, int to_chunk)
{
	t_stack	*tmp;
	int		hold_first;

	tmp = *stack;
	hold_first = 0;
	while (tmp)
	{
		if (tmp->index < to_chunk)
			return (hold_first);
		hold_first++;
		tmp = tmp->next;
	}
	return (-1);
}

int	second_position(t_stack **stack, int to_chunk)
{
	t_stack	*tmp;
	int		hold_second;
	int		hold_second_tmp;

	tmp = *stack;
	hold_second = 0;
	hold_second_tmp = 0;
	while (tmp)
	{
		if (tmp->index < to_chunk)
		{
			hold_second_tmp = hold_second;
		}
		hold_second++;
		tmp = tmp->next;
	}
	return (hold_second - 1);
}
