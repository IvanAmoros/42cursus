/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:42:22 by iamoros-          #+#    #+#             */
/*   Updated: 2023/10/12 21:36:29 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_repeated(long num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			ft_error("Error\n");
		i++;
	}
}

// void	correct_values(int argc, char **argv)
// {
// 	int		i;
// 	size_t	j;
// 	size_t	len;
// 	long	num;

// 	i = 1;
// 	while (i < argc)
// 	{
// 		len = ft_strlen(argv[i]);
// 		if ((!ft_isdigit(argv[i][0]) && argv[i][0] != '-' && argv[i][0] != '+'))
// 			ft_error("Error\n");
// 		j = 1;
// 		while (j < len)
// 		{
// 			if (!ft_isdigit(argv[i][j]))
// 				ft_error("Error\n");
// 			j++;
// 		}
// 		num = ft_atoi(argv[i]);
// 		if (num < INT_MIN || num > INT_MAX)
// 			ft_error("Error\n");
// 		is_repeated(num, argv, i);
// 		i++;
// 	}
// }

void	correct_values(int argc, char **argv)
{
	int		i;
	size_t	j;
	size_t	len;
	long	num;

	i = 1;
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		if ((!ft_isdigit(argv[i][0]) && (argv[i][0] == '-' || argv[i][0] == '+')))
		{
			if (len == 1)
				ft_error("Error\n");
		}
		else if (!ft_isdigit(argv[i][0]))
		{
			ft_error("Error\n");
		}
		j = 1;
		while (j < len)
		{
			if (!ft_isdigit(argv[i][j]))
				ft_error("Error\n");
			j++;
		}
		num = ft_atoi(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			ft_error("Error\n");
		is_repeated(num, argv, i);
		i++;
	}
}


void	ft_check_args(int argc, char **argv)
{
	if (argc < 2)
		ft_error("Error\n");
	correct_values(argc, argv);
}
