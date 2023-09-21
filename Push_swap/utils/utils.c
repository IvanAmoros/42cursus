/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:25:28 by ivanamoros        #+#    #+#             */
/*   Updated: 2023/09/21 23:05:18 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*head;

	head = stack;
	while (head && head->next)
	{
		printf("VALUE: %i", head->value);
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
	t_stack *first_temp;
	t_stack *second_temp;
	int	i;


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

void	smallest_to_b(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_b)
	{}
	printf("\n\nSMALLEST POSITION: %i\n\n", find_smallest(stack_a));
}

int	find_smallest(t_stack **stack)
{
	t_stack	*temp;
	int smallest_position;
	int position;
	int temp_index;

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
		temp =temp->next;
	}
	return (smallest_position);
}
