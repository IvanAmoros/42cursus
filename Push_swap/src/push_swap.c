/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:11:14 by iamoros-          #+#    #+#             */
/*   Updated: 2023/09/28 21:47:33 by iamoros-         ###   ########.fr       */
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

static void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize_push_swap(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		complex_sort(stack_a, stack_b);
}

void print_stack(char *tittle, t_stack **stack)
{
	write(1, tittle, ft_strlen(tittle));
	t_stack *tmp_elem_a = *stack;
	while (tmp_elem_a != NULL)
	{
		printf("Value: %i Index: %i\n", tmp_elem_a->value, tmp_elem_a->index);
		tmp_elem_a = tmp_elem_a->next;
	}
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
		return (0);
	}
	ft_sort(&stack_a, &stack_b);
	print_stack("\nSTACK A:\n", &stack_a);
	print_stack("\nSTACK B:\n", &stack_b);
	free_stack(stack_a);
	//free_stack(stack_b);
	return (0);
}
