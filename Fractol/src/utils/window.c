/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:45:26 by iamoros-          #+#    #+#             */
/*   Updated: 2023/11/18 22:26:16 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int	key_hook(int key, t_fractol *fractol)
{
	printf("\nHello from key_hook! %d\n", key);

	if (key == 53)
	{
		if (fractol->win.mlx_ptr && fractol->img.img_ptr)
			mlx_destroy_image(fractol->win.mlx_ptr, fractol->img.img_ptr);
		if (fractol->win.mlx_ptr && fractol->win.win_ptr)
			mlx_destroy_window(fractol->win.mlx_ptr, fractol->win.win_ptr);
		printf("END OF FRACTOL\n");
		exit(0);
	}
	else if (key == 11)
	{
		brazilian(fractol->win, &fractol->img);
	}
	else if (key == 8)
	{
		barcelona(fractol->win, &fractol->img);
	}
	else if (key == 35)
	{
		portuguese(fractol->win, &fractol->img);
	}
	return (0);
}
