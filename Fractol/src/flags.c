/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:10:01 by iamoros-          #+#    #+#             */
/*   Updated: 2023/11/26 19:31:35 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	brazilian(t_win windows, t_img *image)
{
	int	w;
	int	h;
	int	mid_h;
	int	mid_w;
	int	i;
	int	condition1;
	int	condition2;

	ft_printf("BRAZILIAN FLAG DISPLAYED!\n");
	w = 0;
	h = 0;
	mid_h = windows.height / 2;
	mid_w = windows.width / 2;
	i = 0;
	while (h < windows.height)
	{
		while (w < windows.width)
		{
			condition1 = w > mid_w - (1 * i) && w < mid_w + (1 * i);
			condition2 = h > 50 && h < windows.height - 50;
			if (condition1 && condition2)
				my_mlx_pixel_put(image, w, h, 0xFEDD00);
			else
				my_mlx_pixel_put(image, w, h, 0x009739);
			w++;
		}
		if (h > 50 && h < mid_h)
			i += 2;
		else
			i -= 2;
		w = 0;
		h++;
	}
	mlx_put_image_to_window(windows.mlx_ptr, windows.win_ptr, image->img_ptr , 0, 0);
}

void	barcelona(t_win windows, t_img *image)
{
	int	w;
	int	h;
	int	franja;

	ft_printf("BARÇA FLAG DISPLAYED!\n");
	w = 0;
	h = 0;
	franja = windows.width / 7;
	while (h < windows.height)
	{
		while (w < windows.width)
		{
			if (w < franja || (w > franja * 2 && w < franja * 3)
				|| (w > franja * 4 && w < franja * 5) || (w > franja * 6))
				my_mlx_pixel_put(image, w, h, 0x00158c);
			else
				my_mlx_pixel_put(image, w, h, 0x9e0505);
			w++;
		}
		w = 0;
		h++;
	}
	mlx_put_image_to_window(windows.mlx_ptr, windows.win_ptr, image->img_ptr , 0, 0);
}

void	portuguese(t_win windows, t_img *image)
{
	int	w;
	int	h;
	int	franja;

	ft_printf("PORTUGUESE FLAG DISPLAYED!\n");
	w = 0;
	h = 0;
	franja = windows.width / 3;
	while (h < windows.height)
	{
		while (w < windows.width)
		{
			if (w < franja)
				my_mlx_pixel_put(image, w, h, 0x1e4f00);
			else
				my_mlx_pixel_put(image, w, h, 0xd10026);
			w++;
		}
		w = 0;
		h++;
	}
	mlx_put_image_to_window(windows.mlx_ptr, windows.win_ptr, image->img_ptr , 0, 0);
}
