/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanamoros <ivanamoros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:58:48 by ivanamoros        #+#    #+#             */
/*   Updated: 2023/05/13 15:11:02 by ivanamoros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_elem **stack)
{
	t_elem	*head;
	t_elem	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize_push_swap(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		ft_error("Error\n");
	tmp_val = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (0);
}

int	sa(t_elem **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_elem **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_elem **stack_a, t_elem **stack_b)
{
	if ((ft_lstsize_push_swap(*stack_a) < 2)
		|| (ft_lstsize_push_swap(*stack_b) < 2))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}
