/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanamoros <ivanamoros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:20:47 by iamoros-          #+#    #+#             */
/*   Updated: 2023/09/30 14:06:59 by ivanamoros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack_a)
{
	t_stack	*top;
	t_stack	*middle;
	t_stack	*bottom;

	top = *stack_a;
	middle = top->next;
	bottom = middle->next;
	if (top->value > middle->value && top->value < bottom ->value)
		sa(stack_a);
	else if (middle->value < top->value && middle->value > bottom->value)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (bottom->value < top->value && bottom->value > middle->value)
		ra(stack_a);
	else if (bottom->value > top->value && bottom->value < middle->value)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (top->value < middle->value && top->value > bottom->value)
		rra(stack_a);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	smallest_to_b(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	smallest_to_b(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;

	stack_size = ft_lstsize_push_swap(*stack_a);
	if (stack_size == 2)
		sa(stack_a);
	else if (stack_size == 3)
		sort_3(stack_a);
	else if (stack_size == 4)
		sort_4(stack_a, stack_b);
	else if (stack_size == 5)
		sort_5(stack_a, stack_b);
}
