/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:45:26 by iamoros-          #+#    #+#             */
/*   Updated: 2024/03/07 21:11:02 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	error(int error)
{
	if (error == 1)
	{
		write(2, "\033[0;91mWrong input\033[0;39m\n", 27);
		ft_printf("\nCORRECT USE OF FRACTOL PROGRAM\n\n");
		ft_printf("make\n\n");
		ft_printf("./fractol mandelbrot\n\n");
		ft_printf("./fractol julia\n\n");
		ft_printf("./fractol julia double(real) double(img)\n\n");
	}
	else if (error == 2)
		write(2, "\033[0;91mUnexpected error\033[0;39m\n", 31);
	return (1);
}

t_win	new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win){mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}
