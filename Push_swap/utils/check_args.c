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

#include "push_swap.h"

void	ft_check_args2(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc < 3)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
			{
				write(1, "Error\n", 6);
				exit(-1);
			}
			j++;
		}
		i++;
	}
}

void	ft_check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 3)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	while (i < argc)
	{
		if (!ft_isdigit(ft_atoi(argv[i])))
		{
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
