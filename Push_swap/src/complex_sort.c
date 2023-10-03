/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 21:25:04 by iamoros-          #+#    #+#             */
/*   Updated: 2023/10/03 23:08:16 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	hold_first_position(t_stack **stack, int to_chunk)
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

int	hold_second_position(t_stack **stack, int to_chunk)
{
	t_stack	*tmp;
	int		hold_second;
	int		hold_second_tmp;

	tmp = *stack;
	hold_second = 0;
	hold_second_tmp = 0;
	while (tmp)
	{
		if (tmp->index <= to_chunk)
		{
			hold_second_tmp = hold_second;
		}
		hold_second++;
		tmp = tmp->next;
	}
	return (hold_second - 1);
}

void	sort_100(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	hold_first;
	int	hold_second;

	stack_size = ft_lstsize_push_swap(*stack_a);
	printf("FIRST CHUNK: %i\n\n", hold_first_position(stack_a, 19));
	printf("LAST CHUNK: %i\n\n", hold_second_position(stack_a, 19));
}

	/*while (ft_lstsize_push_swap(*stack_a) != 0)
	{
		smallest_to_b(stack_a, stack_b);
	}
	while (ft_lstsize_push_swap(*stack_b) != 0)
	{
		pa(stack_a, stack_b);
	}*/
void	complex_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;

	stack_size = ft_lstsize_push_swap(*stack_a);
	if (stack_size <= 100)
	{
		sort_100(stack_a, stack_b);
	}
}
