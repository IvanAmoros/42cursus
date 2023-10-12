/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:11:14 by iamoros-          #+#    #+#             */
/*   Updated: 2023/10/12 21:41:15 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_init_stack(int argc, char **argv, t_stack **stack_a)
{
	t_stack	*tmp;

	while (argc > 1)
	{
		tmp = malloc(sizeof(t_stack));
		if (!tmp)
			return (-1);
		tmp->value = ft_atoi(argv[argc - 1]);
		tmp->next = *stack_a;
		*stack_a = tmp;
		argc--;
	}
	ft_index(stack_a);
	return (0);
}

static	void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize_push_swap(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		complex_sort(stack_a, stack_b);
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
	free_stack(stack_a);
	return (0);
}
