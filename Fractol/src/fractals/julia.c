/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:22:11 by iamoros-          #+#    #+#             */
/*   Updated: 2024/03/07 21:14:49 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	function(t_fractol fractol, int pix_x, int pix_y)
{
	float	x;
	float	y;
	int		iter;
	float	x_temp;

	iter = 0;
	x = (((fractol.val.max_x - fractol.val.min_x) / fractol.win.width)
			* (float)pix_x) + fractol.val.min_x;
	y = (((fractol.val.max_y - fractol.val.min_y) / fractol.win.height)
			* (float)pix_y) + fractol.val.min_y;
	while (((x * x) + (y * y)) <= 4 && iter < fractol.val.iter)
	{
		x_temp = (x * x) - (y * y) + fractol.val.j_r;
		y = 2 * x * y + fractol.val.j_i;
		x = x_temp;
		iter++;
	}
	color_grad(&fractol, iter, pix_x, pix_y);
}

void	julia(t_fractol fractol)
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
			function(fractol, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(fractol.win.mlx_ptr, fractol.win.win_ptr,
		fractol.img.img_ptr, 0, 0);
}
