/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:14:40 by iamoros-          #+#    #+#             */
/*   Updated: 2024/03/07 20:30:46 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define VIOLET 0.8055
#define BLUE 0.6111
#define RED 0.9583
#define GREEN 0.3888
#define YELLOW 0.1388

static int	*assign_rgb(float r, float g, float b)
{
	int	*rgb;

	rgb = (int *)malloc(sizeof(int) * 3);
	rgb[0] = (int)(r * 255);
	rgb[1] = (int)(g * 255);
	rgb[2] = (int)(b * 255);
	return (rgb);
}

static int	*hsv_to_rgb(float h, float s, float v)
{
	int		*rgb;
	float	values[5];

	values[0] = floor(h * 6);
	values[1] = (h * 6) - values[0];
	values[2] = v * (1 - s);
	values[3] = v * (1 - (values[1] * s));
	values[4] = v * (1 - ((1 - values[1]) * s));
	if (((int)values[0] % 6) == 0)
		rgb = assign_rgb(v, values[4], values[2]);
	if (((int)values[0] % 6) == 1)
		rgb = assign_rgb(values[3], v, values[2]);
	if (((int)values[0] % 6) == 2)
		rgb = assign_rgb(values[2], v, values[4]);
	if (((int)values[0] % 6) == 3)
		rgb = assign_rgb(values[2], values[3], v);
	if (((int)values[0] % 6) == 4)
		rgb = assign_rgb(values[4], values[2], v);
	if (((int)values[0] % 6) == 5)
		rgb = assign_rgb(v, values[2], values[3]);
	return (rgb);
}

void	color_grad(t_fractol *vars, int i, int col, int row)
{
	int		*rgb;
	float	light;

	light = (float)i / (float)vars->val.iter;
	if (i < vars->val.iter)
	{
		rgb = hsv_to_rgb(light, 1.0, 1.0);
	}
	else
		rgb = hsv_to_rgb(360, 1.0, 0.0);
	my_mlx_pixel_put(&vars->img, col, row, (((0 & 0xff) << 24)
			+ ((rgb[0] & 0xff) << 16) + ((rgb[1] & 0xff) << 8)
			+ ((rgb[2] & 0xff))));
	free(rgb);
	rgb = NULL;
}
