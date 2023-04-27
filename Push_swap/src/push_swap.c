/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanamoros <ivanamoros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:11:14 by iamoros-          #+#    #+#             */
/*   Updated: 2023/04/27 11:27:31 by ivanamoros       ###   ########.fr       */
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
		if (!add_node(*stack_a, ft_atoi(argv[i])))
		{
			stack_error(*stack_a, *stack_b);
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	ft_check_args(argc, argv);
	ft_init_stack(argc, argv, &stack_a, &stack_b);

	t_elem *tmp_elem = stack_a->node;
	while (tmp_elem != NULL)
	{
		printf("%i\n", tmp_elem->value);
		tmp_elem = tmp_elem->next;
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
