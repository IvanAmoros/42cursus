/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanamoros <ivanamoros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:39:05 by ivanamoros        #+#    #+#             */
/*   Updated: 2023/07/05 18:57:01 by ivanamoros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_elem **to_stack, t_elem **from_stack)
{
	t_elem	*head_to;
	t_elem	*head_from;
	t_elem	*tmp;

	if (ft_lstsize_push_swap(*from_stack) == 0)
		return (-1);
	head_to = *to_stack;
	head_from = *from_stack;
	tmp = head_from;
	head_from = head_from->next;
	*from_stack = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*to_stack = head_to;
	}
	else
	{
		tmp->next = head_to;
		*to_stack = tmp;
	}
	return (0);
}

int	pa(t_elem **stack_a, t_elem **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_elem **stack_a, t_elem **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
