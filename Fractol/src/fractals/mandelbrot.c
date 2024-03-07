/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:16:27 by iamoros-          #+#    #+#             */
/*   Updated: 2024/03/07 21:14:19 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	function(t_fractol fractol, int pix_x, int pix_y, float x_temp)
{
	float	x;
	float	y;
	int		iter;
	float	x_re;
	float	x_im;

	x = 0.0;
	y = 0.0;
	iter = 0;
	x_re = (((fractol.val.max_x - fractol.val.min_x)
				/ fractol.win.width) * (float)pix_x) + fractol.val.min_x;
	x_im = (((fractol.val.max_y - fractol.val.min_y)
				/ fractol.win.height) * (float)pix_y) + fractol.val.min_y;
	while (((x * x) + (y * y)) <= 4 && iter < fractol.val.iter)
	{
		x_temp = (x * x) - (y * y) + x_re;
		y = 2 * x * y + x_im;
		x = x_temp;
		iter++;
	}
	color_grad(&fractol, iter, pix_x, pix_y);
}

void	mandelbrot(t_fractol fractol)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	fractol.val.iter = 50 * log10(fractol.val.zoom + 10);
	while (y < fractol.win.height)
	{
		while (x < fractol.win.width)
		{
			function(fractol, x, y, 0.0);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(fractol.win.mlx_ptr,
		fractol.win.win_ptr, fractol.img.img_ptr, 0, 0);
}
