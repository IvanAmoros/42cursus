/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:58:17 by iamoros-          #+#    #+#             */
/*   Updated: 2024/03/07 21:00:35 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	end_program(t_fractol *fractol)
{
	if (fractol->win.mlx_ptr && fractol->img.img_ptr)
		mlx_destroy_image(fractol->win.mlx_ptr, fractol->img.img_ptr);
	if (fractol->win.mlx_ptr && fractol->win.win_ptr)
		mlx_destroy_window(fractol->win.mlx_ptr, fractol->win.win_ptr);
	ft_printf("END OF FRACTOL\n");
	exit(0);
}

static void	check_key(int key, t_fractol *fractol, float y_per, float x_per)
{
	if (key == 126)
	{
		fractol->val.max_y -= y_per;
		fractol->val.min_y -= y_per;
	}
	else if (key == 125)
	{
		fractol->val.max_y += y_per;
		fractol->val.min_y += y_per;
	}
	else if (key == 124)
	{
		fractol->val.max_x += x_per;
		fractol->val.min_x += x_per;
	}
	else if (key == 123)
	{
		fractol->val.max_x -= x_per;
		fractol->val.min_x -= x_per;
	}
}

int	key_hook(int key, t_fractol *fractol)
{
	float	x_per;
	float	y_per;

	x_per = (fractol->val.max_x - fractol->val.min_x) / 100 * 2;
	y_per = (fractol->val.max_y - fractol->val.min_y) / 100 * 2;
	if (key == 53)
		end_program(fractol);
	check_key(key, fractol, y_per, x_per);
	if (!ft_strncmp(fractol->argv, "julia", ft_strlen(fractol->argv)))
		julia(*fractol);
	else
		mandelbrot(*fractol);
	return (0);
}
