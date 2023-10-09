/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanamoros <ivanamoros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 21:25:04 by iamoros-          #+#    #+#             */
/*   Updated: 2023/10/09 15:00:08 by ivanamoros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_a_smaller_first_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;
	int		smaller_in_b;
	int		first_b_smaller;

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
		if (stack_a->value < stack_b->value)
			first_b_smaller = 1;
	}
	if (smaller_in_b == 1 && first_b_smaller == 1)
		return (1);
	return (0);
}

int	find_biggest_index(t_stack *stack)
{
	int		max_index;
	int		max_value;

	max_index = 0;
	max_value = stack->value;
	while (stack)
	{
		if (stack->value > max_value)
		{
			max_value = stack->value;
			max_index = stack->index;
		}
		stack = stack->next;
	}
	return (max_index);
}

void	back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	biggest_position;
	int	biggest_index;

	while (ft_lstsize_push_swap(*stack_b) > 0)
	{
		biggest_position = find_biggest(*stack_b);
		biggest_index = find_biggest_index(*stack_b);
		if (biggest_position == 0 || (*stack_b)->index == biggest_index - 1 || (*stack_b)->index == biggest_index - 2)
		{
			pa(stack_a, stack_b);
			if ((*stack_a)->index == biggest_index - 2)
			{
				// write(1, "\n\n", 2);

				// write(1,ft_itoa((*stack_a)->index), 2);
				// write(1, "\n\n", 2);
				ra(stack_a);
			}
			if (biggest_position == 0)
			{
				if (ft_lstsize_push_swap(*stack_a) > 1 && (*stack_a)->index == (*stack_a)->next->index + 1)
				{
					sa(stack_a);
				}
				if (ft_lstlast_push_swap((*stack_a))->index < (*stack_a)->index)
				{
					rra(stack_a);
				}
			}
		}
		else if (biggest_position <= ft_lstsize_push_swap(*stack_b) / 2)
			rb(stack_b);
		else if (biggest_position > ft_lstsize_push_swap(*stack_b) / 2)
			rrb(stack_b);
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b, int chunk)
{
	int	stack_size;
	int	i;

	stack_size = ft_lstsize_push_swap(*stack_a);
	i = 1;
	while (ft_lstsize_push_swap(*stack_a) > 3)
	{
		while (first_position(stack_a, chunk * i) != -1 && ft_lstsize_push_swap(*stack_a) > 3)
		{
			if (first_position(stack_a, chunk * i)
				>= ft_lstsize_push_swap(*stack_a)
				- second_position(stack_a, chunk * i))
				ra(stack_a);
			else
				rra(stack_a);
			if (ft_lstsize_push_swap(*stack_a) > 3 && first_position(stack_a, chunk * i) == 0)
			{
				if (find_biggest_index((*stack_a)) != (*stack_a)->index || find_biggest_index((*stack_a)) != (*stack_a)->index - 1 || find_biggest_index((*stack_a)) != (*stack_a)->index - 2)
					pb(stack_a, stack_b);
				else
					break ;
				if ((*stack_b)->index < (chunk * i) - (chunk / 2) && i != 1)
					rb(stack_b);
			}
		}
		i++;
	}
	sort_3(stack_a);
	back_to_a(stack_a, stack_b);
}

void	complex_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;

	stack_size = ft_lstsize_push_swap(*stack_a);
	if (stack_size <= 100)
		sort(stack_a, stack_b, 20);
	else
		sort(stack_a, stack_b, 62);
}
