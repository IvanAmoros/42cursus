/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:16:27 by iamoros-          #+#    #+#             */
/*   Updated: 2023/11/26 20:16:41 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	function(t_fractol fractol, int pix_x, int pix_y)
{
	int		iter;
	int		max_iter;
	float	x;
	float	y;
	float	x_re;
	float	x_im;
	float	x_temp;

	x_re = ((3.00 / fractol.win.width) * (float)pix_x) - 2.00;
	x_im = ((2.00 / fractol.win.height) * (float)pix_y) - 1.00;
	x = 0.0;
	y = 0.0;
	// x_re = ((3.00 / fractol.win.width) * (float)pix_x) - 2.00;
	// x_im = ((2.00 / fractol.win.height) * (float)pix_y) - 1.00;
	// x = x_re;
	// y = x_im;
	iter = 0;
	max_iter = 50;
	// printf("X: %f\tY: %f\n", x_re, x_im);
	while (((x * x) + (y * y)) <= 4 && iter < max_iter)
	{
		x_temp = (x * x) - (y * y) + x_re;
		y = 2 * x * y + x_im;
		// x_temp = (x * x) - (y * y) + 0.285;
		// y = 2 * x * y - 0.01;
		x = x_temp;
		iter++;
	}
	// if (pix_x > 500 && pix_y > 500)
		// return ;
	if (iter == max_iter)
		my_mlx_pixel_put(&fractol.img, pix_x, pix_y, 0x000000);
	else
		my_mlx_pixel_put(&fractol.img, pix_x, pix_y, 0xFF0000);
}

void	ft_mandelbrot(t_fractol fractol)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < fractol.win.height)
	{
		while (x < fractol.win.width)
		{
			function(fractol, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(fractol.win.mlx_ptr, fractol.win.win_ptr, fractol.img.img_ptr, 0, 0);
}