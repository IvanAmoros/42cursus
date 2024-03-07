/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:46:36 by iamoros-          #+#    #+#             */
/*   Updated: 2024/03/07 21:08:16 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	float	width;
	float	height;
}		t_win;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

typedef struct s_val
{
	int		iter;
	float	max_x;
	float	max_y;
	float	min_x;
	float	min_y;
	float	zoom;
	float	j_r;
	float	j_i;
}		t_val;

typedef struct s_fractol
{
	t_win	win;
	t_img	img;
	t_val	val;
	int		color;
	char	*argv;
}		t_fractol;

t_win	new_program(int w, int h, char *str);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		key_hook(int key, t_fractol *fractol);
int		mouse_hook(int key, int x, int y, t_fractol *fractol);
int		check_args(int argc, char **argv, t_fractol *fractol);
int		error(int error);
void	mandelbrot(t_fractol fractol);
void	julia(t_fractol fractol);
int		ft_atof(char *str, float *value);
void	color_grad(t_fractol *vars, int i, int col, int row);

#endif