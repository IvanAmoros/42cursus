/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanamoros <ivanamoros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:11:14 by iamoros-          #+#    #+#             */
/*   Updated: 2023/08/08 18:31:12 by ivanamoros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_init_stack(int argc, char **argv, t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 1;
	*stack_a = create_stack();
	*stack_b = create_stack();
	while (i < argc)
	{
		if (!add_node(*stack_a, ft_atoi(argv[i]), i - 1))
		{
			stack_error(*stack_a, *stack_b);
			return (-1);
		}
		i++;
	}
	return (0);
}

static void	ft_sort(t_elem **stack_a, t_elem **stack_b)
{
	if (ft_lstsize_push_swap(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	ft_check_args(argc, argv);
	if (ft_init_stack(argc, argv, &stack_a, &stack_b) == -1)
		return (-1);
	if (ft_is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	ft_sort(stack_a, stack_b);


	write(1, "STACK A:\n", 9);
	t_elem *tmp_elem_a = stack_a->node;
	while (tmp_elem_a != NULL)
	{
		printf("Value: %i Index: %i\n", tmp_elem_a->value, tmp_elem_a->index);
		tmp_elem_a = tmp_elem_a->next;
	}
	write(1, "\nSTACK B:\n", 10);
	t_elem *tmp_elem_b = stack_b->node;
	while (tmp_elem_b != NULL)
	{
		printf("Value: %i Index: %i\n", tmp_elem_b->value, tmp_elem_b->index);
		tmp_elem_b = tmp_elem_b->next;
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
