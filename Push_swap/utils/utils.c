/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanamoros <ivanamoros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:25:28 by ivanamoros        #+#    #+#             */
/*   Updated: 2023/09/19 13:34:44 by ivanamoros       ###   ########.fr       */
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
			return (0);
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
