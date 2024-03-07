/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:46:32 by iamoros-          #+#    #+#             */
/*   Updated: 2024/03/07 20:32:31 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_args(int argc, char **argv, t_fractol *fractol)
{
	if (argc == 1)
		return (1);
	if ((ft_strncmp(argv[1], "mandelbrot", 11)
			&& ft_strncmp(argv[1], "julia", 6))
		|| (!ft_strncmp(argv[1], "mandelbrot", 11) && argc != 2)
		|| (!ft_strncmp(argv[1], "julia", 11) && (argc != 2 && argc != 4)))
		return (1);
	if (!ft_strncmp(argv[1], "julia", 11) && argc == 2)
	{
		fractol->val.j_r = 0.285;
		fractol->val.j_i = -0.01;
	}
	else if (!ft_strncmp(argv[1], "julia", 11) && argc == 4)
	{
		if (ft_atof(argv[2], &fractol->val.j_r)
			|| ft_atof(argv[3], &fractol->val.j_i))
			return (1);
	}
	return (0);
}
