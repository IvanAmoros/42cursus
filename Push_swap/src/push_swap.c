/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanamoros <ivanamoros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:11:14 by iamoros-          #+#    #+#             */
/*   Updated: 2023/09/19 17:55:32 by ivanamoros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_init_stack(int argc, char **argv, t_stack **stack_a)
{
	t_stack	*tmp;

	while (argc > 1)
	{
		tmp = malloc(sizeof(t_stack));
		if (!tmp)
			return (0);
		tmp->value = ft_atoi(argv[argc - 1]);
		tmp->next = *stack_a;
		*stack_a = tmp;
		argc--;
	}
	ft_index(stack_a);
	return (0);
}

static void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_lstsize_push_swap(stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	/*else
		complex sort*/
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	ft_check_args(argc, argv);
	if (ft_init_stack(argc, argv, &stack_a) == -1)
		return (-1);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		write(1, "SORTED!!\n", 9);
		return (0);
	}
	ft_sort(stack_a, stack_b);
	write(1, "STACK A:\n", 9);
	t_stack *tmp_elem_a = stack_a;
	while (tmp_elem_a != NULL)
	{
		printf("Value: %i Index: %i\n", tmp_elem_a->value, tmp_elem_a->index);
		tmp_elem_a = tmp_elem_a->next;
	}
	write(1, "\nSTACK B:\n", 10);
	t_stack *tmp_elem_b = stack_b;
	while (tmp_elem_b != NULL)
	{
		printf("Value: %i Index: %i\n", tmp_elem_b->value, tmp_elem_b->index);
		tmp_elem_b = tmp_elem_b->next;
	}
	free_stack(stack_a);
	//free_stack(stack_b);
	return (0);
}
