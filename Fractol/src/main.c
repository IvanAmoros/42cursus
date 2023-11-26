/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:25:37 by iamoros-          #+#    #+#             */
/*   Updated: 2023/11/26 19:57:18 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static int	fractol(char *argv)
{
	t_fractol	fractol;

	fractol.win = new_program(1920, 1080, "Fractol");
	if (!fractol.win.mlx_ptr || !fractol.win.win_ptr)
		return (1);
	fractol.img.img_ptr = mlx_new_image(fractol.win.mlx_ptr,
			fractol.win.width, fractol.win.height);
	fractol.img.addr = mlx_get_data_addr(fractol.img.img_ptr,
			&(fractol.img.bpp), &(fractol.img.line_len), &(fractol.img.endian));
	fractol.img.w = fractol.win.width;
	fractol.img.h = fractol.win.width;
	if (!ft_strncmp(argv, "mandelbrot", ft_strlen(argv)))
		ft_mandelbrot(fractol);
	mlx_key_hook(fractol.win.win_ptr, key_hook, &fractol);
	mlx_loop(fractol.win.mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	if (check_args(argc, argv[1]))
		return (error(1));
	if (fractol(argv[1]))
		return (error(2));
	return (0);
}
