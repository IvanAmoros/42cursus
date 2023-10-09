/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 21:25:04 by iamoros-          #+#    #+#             */
/*   Updated: 2023/10/09 23:02:08 by iamoros-         ###   ########.fr       */
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

int	find_big_ind(t_stack *stack)
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

void	back_to_a(t_stack **stak_a, t_stack **stak_b, int big_pos, int big_ind)
{
	while (ft_lstsize_push_swap(*stak_b) > 0)
	{
		big_pos = find_biggest(*stak_b);
		big_ind = find_big_ind(*stak_b);
		if (big_pos == 0 || (*stak_b)->index == big_ind - 1
			|| (*stak_b)->index == big_ind - 2)
		{
			pa(stak_a, stak_b);
			if ((*stak_a)->index == big_ind - 2)
				ra(stak_a);
			if (big_pos == 0)
			{
				if (ft_lstsize_push_swap(*stak_a) > 1 && (*stak_a)->index
					== (*stak_a)->next->index + 1)
					sa(stak_a);
				if (ft_lstlast_push_swap((*stak_a))->index < (*stak_a)->index)
					rra(stak_a);
			}
		}
		else if (big_pos <= ft_lstsize_push_swap(*stak_b) / 2)
			rb(stak_b);
		else if (big_pos > ft_lstsize_push_swap(*stak_b) / 2)
			rrb(stak_b);
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b, int chunk)
{
	int	stack_size;
	int	i;
	int	biggest;

	stack_size = ft_lstsize_push_swap(*stack_a);
	i = 1;
	biggest = find_big_ind((*stack_a));
	while (ft_lstsize_push_swap(*stack_a) > 1)
	{
		while (first_position(stack_a, chunk * i) != -1)
		{
			if (first_position(stack_a, chunk * i) > 0)
				ra(stack_a);
			else if (first_position(stack_a, chunk * i) == 0)
			{
				pb(stack_a, stack_b);
				if ((*stack_b)->index < (chunk * i) - (chunk / 2) && i != 1)
					rb(stack_b);
			}
		}
		i++;
	}
	back_to_a(stack_a, stack_b, 0, 0);
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
