/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:20:47 by iamoros-          #+#    #+#             */
/*   Updated: 2023/09/15 18:21:32 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void simple_sort(t_stack *stack_a, t_stack *stack_b)
{
    if (ft_lstsize_push_swap(stack_a) == 2)
        sa(&stack_a);
    else if (ft_lstsize_push_swap(stack_b) == 2)
        write(1, "ELSEIF STACK B SIMPLE SORT\n", 27);
    
}