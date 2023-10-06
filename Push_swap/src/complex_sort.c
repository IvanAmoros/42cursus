/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 21:25:04 by iamoros-          #+#    #+#             */
/*   Updated: 2023/10/06 18:57:19 by iamoros-         ###   ########.fr       */
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
		if (tmp->index < to_chunk)
		{
			hold_second_tmp = hold_second;
		}
		hold_second++;
		tmp = tmp->next;
	}
	return (hold_second - 1);
}

int	first_a_smaller_first_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;
	int		smaller_in_b;
	int		first_b_smaller;

	//sleep(1);
	tmp = stack_a;
	smaller_in_b = 0;
	first_b_smaller = 0;
	if (ft_lstsize_push_swap(stack_b) > 1)
	{
		while (tmp)
		{
			if (stack_a->value < tmp->value)
			{
				smaller_in_b = 1;
				break ;
			}
			tmp = tmp->next;
		}
		//printf("STACK A: %i\nSTACK B: %i\n", stack_b->value, stack_b->value);
		if (stack_a->value < stack_b->value)
			first_b_smaller = 1;
	}
	if (smaller_in_b == 1 && first_b_smaller == 1)
		return (1);
	return (0);
}

void	sort_100(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	hold_first;
	int	hold_second;
	int	i;

	stack_size = ft_lstsize_push_swap(*stack_a);
	i = 1;
	while (ft_lstsize_push_swap(*stack_a) != 0)
	{
		while (hold_first_position(stack_a, 100 / 5 * i) != -1)
		{
			if (hold_first_position(stack_a, 100 / 5 * i) >= ft_lstsize_push_swap(*stack_a) - hold_second_position(stack_a, 100 / 5 * i))
				ra(stack_a);
			else
				rra(stack_a);
			if (hold_first_position(stack_a, 100 / 5 * i) == 0)
			{
				pb(stack_a, stack_b);
				//printf("NUMEROO; %i\n", (100 / 5 * i) - 10);
				//printf("INDICE; %i\n", (*stack_b)->index);
				if ((*stack_b)->index < (100 / 5 * i) - 10 && i != 1)
					rb(stack_b);
			}
		}
		i++;
	}
}

void	complex_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;

	stack_size = ft_lstsize_push_swap(*stack_a);
	if (stack_size <= 100)
	{
		sort_100(stack_a, stack_b);
	}
}
