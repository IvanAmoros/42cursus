/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:16:27 by iamoros-          #+#    #+#             */
/*   Updated: 2023/11/27 20:32:09 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	function(t_fractol fractol, int pix_x, int pix_y)
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
	iter = 0;
	max_iter = 50;
	while (((x * x) + (y * y)) <= 4 && iter < max_iter)
	{
		x_temp = (x * x) - (y * y) + x_re;
		y = 2 * x * y + x_im;
		x = x_temp;
		iter++;
	}
	if (iter == max_iter)
		my_mlx_pixel_put(&fractol.img, pix_x, pix_y, 0x000000);
	else
		my_mlx_pixel_put(&fractol.img, pix_x, pix_y, 0xFF0000);
}

void	mandelbrot(t_fractol fractol)
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