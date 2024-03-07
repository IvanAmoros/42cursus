/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:25:37 by iamoros-          #+#    #+#             */
/*   Updated: 2024/03/07 21:09:49 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_values(t_fractol *fractol)
{
	fractol->win = new_program(800, 800, "Fractol");
	fractol->val.max_x = 1.50;
	fractol->val.max_y = 2.00;
	fractol->val.min_x = -2.50;
	fractol->val.min_y = -2.00;
	fractol->color = 5;
	if (!ft_strncmp(fractol->argv, "julia", 6))
	{
		fractol->val.min_x += 0.5;
		fractol->val.max_x += 0.5;
	}
	fractol->val.zoom = 1.00;
	fractol->val.iter = 50;
}

static int	fractol(t_fractol fractol)
{
	set_values(&fractol);
	if (!fractol.win.mlx_ptr || !fractol.win.win_ptr)
		return (1);
	fractol.img.img_ptr = mlx_new_image(fractol.win.mlx_ptr,
			fractol.win.width, fractol.win.height);
	fractol.img.addr = mlx_get_data_addr(fractol.img.img_ptr,
			&(fractol.img.bpp), &(fractol.img.line_len), &(fractol.img.endian));
	if (!ft_strncmp(fractol.argv, "mandelbrot", ft_strlen(fractol.argv)))
		mandelbrot(fractol);
	else
		julia(fractol);
	mlx_hook(fractol.win.win_ptr, 17, 1L << 0, (void *)exit, &fractol);
	mlx_key_hook(fractol.win.win_ptr, key_hook, &fractol);
	mlx_mouse_hook(fractol.win.win_ptr, mouse_hook, &fractol);
	mlx_loop(fractol.win.mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	fract;

	fract.argv = argv[1];
	if (check_args(argc, argv, &fract))
		return (error(1));
	if (fractol(fract))
		return (error(2));
	return (0);
}
