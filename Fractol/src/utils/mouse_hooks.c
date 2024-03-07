/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:41:10 by iamoros-          #+#    #+#             */
/*   Updated: 2024/03/07 20:52:52 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_in(t_fractol *fractol, float x_per, float y_per)
{
	fractol->val.max_x -= x_per;
	fractol->val.max_y -= y_per;
	fractol->val.min_x += x_per;
	fractol->val.min_y += y_per;
	fractol->val.zoom *= 1.25;
}

static void	zoom_out(t_fractol *fractol, float x_per, float y_per)
{
	fractol->val.max_x += x_per;
	fractol->val.max_y += y_per;
	fractol->val.min_x -= x_per;
	fractol->val.min_y -= y_per;
	fractol->val.zoom /= 1.25;
}

int	mouse_hook(int key, int x, int y, t_fractol *fractol)
{
	float	x_per;
	float	y_per;

	(void)x;
	(void)y;
	x_per = (fractol->val.max_x - fractol->val.min_x) / 100 * 4;
	y_per = (fractol->val.max_y - fractol->val.min_y) / 100 * 4;
	if (key == 5)
		zoom_in(fractol, x_per, y_per);
	else if (key == 4)
		zoom_out(fractol, x_per, y_per);
	if (!ft_strncmp(fractol->argv, "julia", ft_strlen(fractol->argv)))
		julia(*fractol);
	else
		mandelbrot(*fractol);
	return (0);
}
