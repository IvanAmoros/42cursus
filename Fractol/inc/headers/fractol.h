/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamoros- <iamoros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:46:36 by iamoros-          #+#    #+#             */
/*   Updated: 2023/11/18 21:32:53 by iamoros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
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

typedef struct s_fractol
{
	t_win	win;
	t_img	img;
}		t_fractol;

t_win	new_program(int w, int h, char *str);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		key_hook(int key, t_fractol *fractol);
void	brazilian(t_win windows, t_img *image);
void	barcelona(t_win windows, t_img *image);
void	portuguese(t_win windows, t_img *image);
int		check_args(int argc, char *argv);

#endif