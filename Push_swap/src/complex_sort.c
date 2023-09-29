/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 21:25:04 by iamoros-          #+#    #+#             */
/*   Updated: 2023/09/28 22:08:48 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void complex_sort(t_stack **stack_a, t_stack **stack_b)
{
    int stack_size;

    stack_size = ft_lstsize_push_swap(*stack_a);
    while(ft_lstsize_push_swap(*stack_a) != 0)
    {
        smallest_to_b(stack_a, stack_b);
    }
    while(ft_lstsize_push_swap(*stack_b) != 0)
    {
        pa(stack_a, stack_b);
    }
}
