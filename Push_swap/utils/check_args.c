/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:42:22 by iamoros-          #+#    #+#             */
/*   Updated: 2023/04/14 18:46:12 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"
#include "libft.h"

void ft_single_arg(char** argv)
{
    write(1, argv[1], ft_strlen(argv[1]));
}

void ft_check_args(int argc, char** argv)
{
	if (argc == 2)
	{
        ft_single_arg(argv);
	}
    else
    {

	}
}