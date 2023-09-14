/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 23:17:18 by ivanamoros        #+#    #+#             */
/*   Updated: 2023/09/14 21:18:34 by iamoros-         ###   ########.fr       */
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

t_elem	*add_node(t_stack *stack, int value, int i)
{
	t_elem	*new_elem;
	t_elem	*temp;

	new_elem = malloc(sizeof(t_elem));
	if (!new_elem)
		return (NULL);
	new_elem->value = value;
	new_elem->index = i;
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

int	ft_lstsize_push_swap(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_elem	*ft_lstlast_push_swap(t_elem *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
