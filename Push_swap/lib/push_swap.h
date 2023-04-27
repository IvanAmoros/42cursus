/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanamoros <ivanamoros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:44:24 by iamoros-          #+#    #+#             */
/*   Updated: 2023/04/27 15:10:51 by ivanamoros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_elem
{
	int				value;
	int				index;
	struct s_elem	*next;
}	t_elem;

typedef struct s_stack
{
	t_elem	*node;
	int		size;
}	t_stack;

void	ft_check_args(int argc, char **argv);
void	ft_error(char *error);
t_stack	*create_stack(void);
t_elem	*add_node(t_stack *stack, int value);
void	stack_error(t_stack *stack_a, t_stack *stack_b);
void	free_stack(t_stack *stack);

#endif