/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:20:47 by iamoros-          #+#    #+#             */
/*   Updated: 2023/09/21 22:55:04 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack_a)
{
	t_stack	*temp;

	temp = *stack_a;
	if (temp->value > temp->next->value && temp->value < temp->next->next->value)
		sa(stack_a);
	else if (temp->next->value < temp->value && temp->next->value > temp->next->next->value)
	{
		print_stack("\nSTACK A:\n", stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (temp->next->next->value < temp->value && temp->next->next->value > temp->next->value)
		ra(stack_a);
	else if (temp->next->next->value > temp->value && temp->next->next->value < temp->next->value)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (temp->value < temp->next->value && temp->value > temp->next->next->value)
		rra(stack_a);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int smallest_position;

	if (stack_b)
	{}
	write(1, "\n\nSORT 4\n\n", 10);
	smallest_position = find_smallest(stack_a);
	printf("\n\nSMALLES POSITION: %i\n\n", smallest_position);
	
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int stack_size;

	stack_size = ft_lstsize_push_swap(*stack_a);
	

	if (stack_b)
	{}


	if (stack_size == 2)
		sa(stack_a);
	else if (stack_size == 3)
		sort_3(stack_a);
	else if (stack_size == 4)
		sort_4(stack_a, stack_b);
}
