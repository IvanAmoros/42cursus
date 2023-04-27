/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanamoros <ivanamoros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 01:04:46 by ivanamoros        #+#    #+#             */
/*   Updated: 2023/04/27 11:27:14 by ivanamoros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *error)
{
	write(1, error, ft_strlen(error));
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}

void	stack_error(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
	{
		free_stack(stack_a);
	}
	if (stack_b)
	{
		free_stack(stack_b);
	}
	ft_error("Error");
}

void	free_stack(t_stack *stack)
{
	t_elem	*temp_node;
	t_elem	*temp_next_node;

	temp_node = stack->node;
	while (temp_node)
	{
		temp_next_node = temp_node->next;
		free(temp_node);
		temp_node = temp_next_node;
	}
	free(stack);
}
