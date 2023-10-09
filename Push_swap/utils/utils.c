/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:25:28 by ivanamoros        #+#    #+#             */
/*   Updated: 2023/10/08 17:13:55 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*head;

	head = stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
		{
			return (0);
		}
		head = head->next;
	}
	return (1);
}

void	ft_index(t_stack **stack_a)
{
	t_stack	*first_temp;
	t_stack	*second_temp;
	int		i;

	first_temp = *stack_a;
	while (first_temp)
	{
		i = 0;
		second_temp = *stack_a;
		while (second_temp)
		{
			if (first_temp->value > second_temp->value)
				i++;
			first_temp->index = i;
			second_temp = second_temp->next;
		}
		first_temp = first_temp->next;
	}
}

int	find_smallest(t_stack **stack)
{
	t_stack	*temp;
	int		smallest_position;
	int		position;
	int		temp_index;

	temp = *stack;
	position = 0;
	smallest_position = INT_MAX;
	temp_index = INT_MAX;
	while (temp)
	{
		if (temp->index < temp_index)
		{
			temp_index = temp->index;
			smallest_position = position;
		}
		position++;
		temp = temp->next;
	}
	return (smallest_position);
}

int	find_biggest(t_stack *stack)
{
	t_stack	*tmp;
	int		max_position;
	int		current_position;
	int		max_value;

	tmp = stack;
	max_position = 0;
	current_position = 0;
	max_value = stack->value;
	while (tmp)
	{
		if (tmp->value > max_value)
		{
			max_value = tmp->value;
			max_position = current_position;
		}
		current_position++;
		tmp = tmp->next;
	}
	return (max_position);
}