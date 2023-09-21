/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanamoros <ivanamoros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:20:47 by iamoros-          #+#    #+#             */
/*   Updated: 2023/09/21 14:50:08 by ivanamoros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack_a)
{
	t_stack	*temp;

	temp = stack_a;
	if (temp->value > temp->next->value && temp->value < temp->next->next->value)
		sa(&stack_a);
	else if (temp->next->value < temp->value && temp->next->value > temp->next->next->value)
	{
		print_stack("\nSTACK A:\n", &stack_a);
		sa(&stack_a);
		rra(&stack_a);
	}
	else if (temp->next->next->value < temp->value && temp->next->next->value > temp->next->value)
		ra(&stack_a);
	else if (temp->next->next->value > temp->value && temp->next->next->value < temp->next->value)
	{
		sa(&stack_a);
		ra(&stack_a);
	}
	else if (temp->value < temp->next->value && temp->value > temp->next->next->value)
		rra(&stack_a);

	/*while (temp)
	{
		printf("VALUE A: %i\n", temp->value);
		temp = temp->next;
	}*/
}

void	simple_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b)
	{}

	if (ft_lstsize_push_swap(stack_a) == 2)
		sa(&stack_a);
	else if (ft_lstsize_push_swap(stack_a) == 3)
		sort_3(stack_a);
}
