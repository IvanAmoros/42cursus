/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanamoros <ivanamoros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:20:47 by iamoros-          #+#    #+#             */
/*   Updated: 2023/09/26 20:00:00 by ivanamoros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (tmp->value > tmp->next->value && tmp->value < tmp->next->next->value)
		sa(stack_a);
	else if (tmp->next->value < tmp->value && tmp->next->value > tmp->next->next->value)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (tmp->next->next->value < tmp->value && tmp->next->next->value > tmp->next->value)
		ra(stack_a);
	else if (tmp->next->next->value > tmp->value && tmp->next->next->value < tmp->next->value)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (tmp->value < tmp->next->value && tmp->value > tmp->next->next->value)
		rra(stack_a);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		smallest_position;
	int		i;

	tmp = *stack_a;
	i = 0;
	smallest_position = find_smallest(stack_a);
	while (i <= smallest_position)
	{
		if (i == smallest_position)
			pb(&tmp, stack_b);
		tmp = tmp->next;
		i++;
	}


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
}
