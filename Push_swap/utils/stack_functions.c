/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanamoros <ivanamoros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 23:17:18 by ivanamoros        #+#    #+#             */
/*   Updated: 2023/04/27 11:11:03 by ivanamoros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->node = NULL;
	new_stack->size = 0;
	return (new_stack);
}

t_elem	*add_node(t_stack *stack, int value)
{
	t_elem	*new_elem;
	t_elem	*temp;

	new_elem = malloc(sizeof(t_elem));
	if (!new_elem)
		return (NULL);
	new_elem->value = value;
	new_elem->index = 0;
	new_elem->next = NULL;
	temp = stack->node;
	if (!temp)
		stack->node = new_elem;
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_elem;
	}
	return (new_elem);
}
